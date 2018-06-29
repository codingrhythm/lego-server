# lego-server

```
protoc --go_out=plugins=grpc:./ ./lego.proto
```

```
protoc --grpc_out=./generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ./lego.proto
protoc --cpp_out=./generated ./lego.proto
```

## Objective-C

```
protoc --objc_out=./generated --grpc_out=./generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_objective_c_plugin ./lego.proto
```