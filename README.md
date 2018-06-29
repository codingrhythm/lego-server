# lego-server

This is a demo server written in Golang. It performs some basic tasks such as image upload/download, post/get large data payload. It serves as normal HTTP/1.1 server as well as GRPC server. Default Restful APIs are served via port `8512`, GRPC APIs are served via port `8513`.

Image upload/download endpoints are only supported via HTTP/1.1.

## Endpoints

### GET /data/

Request data, returns a JSON object.

### POST /data/

Send data to server

### POST /upload/

Upload file to server

### GET /files/{file_id}

Download file from server. supported file ids: `1.jpg`, `2.jpg`, `3.jpg`, `4.jpg`, `5.jpg`,

## GRPC

Use following command to generate your GRPC clients.

### Generate for go
```
protoc --go_out=plugins=grpc:./ ./lego.proto
```

### Generate for c++
```
protoc --grpc_out=./generated --cpp_out=./generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ./lego.proto
```

### Generate for Objective-C
```
protoc --objc_out=./generated --grpc_out=./generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_objective_c_plugin ./lego.proto
```