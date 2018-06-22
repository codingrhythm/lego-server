package lego

import (
	"github.com/braintree/manners"
	log "github.com/sirupsen/logrus"
	context "golang.org/x/net/context"
)

// Server defines the structure of the server and it's resources and implements the gRPC interfaces
type Server struct {
}

// Srv is the Server object for lego
var Srv *Server

func init() {
	Srv = &Server{}
}

// Close closes any open connections that's associated with the server
func (s *Server) Close() {
	log.Println("Stopping server...")
	manners.Close()
	log.Println("Server stopped.")
}

//SendRecord API
func (s *Server) SendRecord(context.Context, *LegoRecord) (*LegoResponse, error) {
	return &LegoResponse{Success: 1}, nil
}

//GetData API
func (s *Server) GetData(context.Context, *GetRequest) (*Template, error) {
	data := DataGen.GenerateData()
	return data, nil
}
