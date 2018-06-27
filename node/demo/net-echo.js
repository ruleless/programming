#! /usr/bin/env node

const net = require('net');

function echo_server() {
  var server = net.createServer();
  
  server.listen({port:9000});
  
  server.on('error', function(err) {
    throw err;
  });

  server.on('connection', function(socket) {
    socket.on('close', function() {
      console.log(`socket close, ${socket}`);
    });

    socket.on('data', function(buf) {
      console.log('from client:' + buf.toString());
      socket.write(buf);
    });
  });
}

function echo_client() {
  var input = process.stdin;
  var client = net.connect({port:9000});  

  client.on('error', function(err) {
    console.log('connect error' + err.message);
  });

  input.on('data', function(buf) {
    console.log(buf.toString());
  });

  // client.on('data', function(buf))
}

echo_client();
