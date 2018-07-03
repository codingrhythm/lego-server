package main

import (
	"crypto/rand"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"mime"
	"net"
	"net/http"
	"os"
	"path/filepath"

	"github.com/SafetyCulture/lego-server"
	grpc_middleware "github.com/grpc-ecosystem/go-grpc-middleware"
	grpc_ctxtags "github.com/grpc-ecosystem/go-grpc-middleware/tags"
	"google.golang.org/grpc"
	"google.golang.org/grpc/reflection"
)

const maxUploadSize = 20 * 1024 * 1024 // 20 mb
const uploadPath = "./tmp"
const filePath = "./files"

func main() {
	http.HandleFunc("/data", dataHandler)
	http.HandleFunc("/upload", uploadFileHandler())

	fs := http.FileServer(http.Dir(filePath))
	http.Handle("/files/", http.StripPrefix("/files", fs))
	log.Print("Server started on localhost:8512, use /upload for uploading files and /files/{fileName} for downloading")
	go setupGRPC()
	log.Fatal(http.ListenAndServe(":8512", nil))
}

func setupGRPC() {
	var gRPCServer *grpc.Server
	log.Println("Configuring server to run insecure. NO_TLS.")
	interceptorChain := grpc_middleware.ChainUnaryServer(
		grpc_ctxtags.UnaryServerInterceptor(grpc_ctxtags.WithFieldExtractor(grpc_ctxtags.CodeGenRequestFieldExtractor)),
	)
	gRPCServer = grpc.NewServer(
		grpc_middleware.WithUnaryServerChain(interceptorChain),
	)

	lego.RegisterLegoServer(gRPCServer, lego.Srv)
	reflection.Register(gRPCServer)

	// Time to start the server
	lis, _ := net.Listen("tcp", ":8513")
	log.Printf("Starting gRPC server, listening on %v", lis.Addr())
	if err := gRPCServer.Serve(lis); err != nil {
		log.Fatalf("Failed to serve: %v", err)
	}
}

func dataHandler(w http.ResponseWriter, r *http.Request) {
	log.Print("Data request")
	w.Header().Set("Content-Type", "application/json")
	if r.Method == "GET" {
		data := lego.DataGen.GenerateData()
		b, err := json.Marshal(data)

		if err != nil {
			fmt.Fprintf(w, "{\"success\": false}")
		} else {
			fmt.Fprintf(w, "%s", b)
		}
	} else {
		fmt.Fprintf(w, "{\"success\": true}")
	}
}

func uploadFileHandler() http.HandlerFunc {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		// validate file size
		r.Body = http.MaxBytesReader(w, r.Body, maxUploadSize)
		if err := r.ParseMultipartForm(maxUploadSize); err != nil {
			renderError(w, "FILE_TOO_BIG", http.StatusBadRequest)
			return
		}

		// parse and validate file and post parameters
		file, _, err := r.FormFile("uploadFile")
		if err != nil {
			renderError(w, "INVALID_FILE", http.StatusBadRequest)
			return
		}
		defer file.Close()
		fileBytes, err := ioutil.ReadAll(file)
		if err != nil {
			renderError(w, "INVALID_FILE", http.StatusBadRequest)
			return
		}

		// check file type, detectcontenttype only needs the first 512 bytes
		filetype := http.DetectContentType(fileBytes)
		log.Print(filetype)
		switch filetype {
		case "image/jpeg", "image/jpg":
		case "image/gif", "image/png":
		case "application/pdf":
			break
		default:
			renderError(w, "INVALID_FILE_TYPE", http.StatusBadRequest)
			return
		}
		fileName := randToken(12)
		log.Print(fileName)
		fileEndings, err := mime.ExtensionsByType(filetype)
		log.Print(fileEndings)
		log.Print(err)
		if err != nil {
			renderError(w, "CANT_READ_FILE_TYPE", http.StatusInternalServerError)
			return
		}
		newPath := filepath.Join(uploadPath, fileName+fileEndings[0])
		fmt.Printf("FileType: %s, File: %s\n", filetype, newPath)

		// write file
		newFile, err := os.Create(newPath)
		if err != nil {
			renderError(w, "CANT_WRITE_FILE", http.StatusInternalServerError)
			return
		}
		defer newFile.Close() // idempotent, okay to call twice
		if _, err := newFile.Write(fileBytes); err != nil || newFile.Close() != nil {
			renderError(w, "CANT_WRITE_FILE", http.StatusInternalServerError)
			return
		}
		w.Write([]byte("SUCCESS"))
	})
}

func renderError(w http.ResponseWriter, message string, statusCode int) {
	w.WriteHeader(http.StatusBadRequest)
	w.Write([]byte(message))
}

func randToken(len int) string {
	b := make([]byte, len)
	rand.Read(b)
	return fmt.Sprintf("%x", b)
}
