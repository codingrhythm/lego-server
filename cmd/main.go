package main

import (
	"crypto/rand"
	"fmt"
	"io/ioutil"
	"log"
	"mime"
	"net/http"
	"os"
	"path/filepath"
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
	log.Fatal(http.ListenAndServe(":8512", nil))
}

// Question data struct
type Question struct {
	Id           string
	Title        string
	ResponseType int8
	Description  string
	Order        int8
}

// Page data struct
type Page struct {
	Id        string
	Title     string
	Order     int8
	Questions []Question
}

// Template data struct
type Template struct {
	Id    string
	Name  string
	Pages []Page
}

func loadPage(title string) (*Page, error) {
	filename := title + ".json"
	body, err := ioutil.ReadFile(filename)
	if err != nil {
		return nil, err
	}
	return &Page{Title: title, Body: body}, nil
}

func dataHandler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	if r.Method == "GET" {
		page, _ := loadPage("data")
		fmt.Fprintf(w, "%s", page.Body)
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
