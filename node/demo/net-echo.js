#! /usr/bin/env node

const net = require('net');

function echo_server() {
  var server = net.createServer();

  server.listen({port:9000});

  server.on('listening', function () {
    console.log('create server ok');
  });

  server.on('error', function (err) {
    console.error(`create server failed, ${err.message}`);
    process.exit(1);
  });

  server.on('close', function () {
    console.log('server closed');
  });

  server.on('connection', function (socket) {
    socket.on('close', function () {
      console.log(`socket close, ${socket}`);
    });

    socket.on('data', function (buf) {
      console.log(`from client(${socket.address}): buf.toString()`);
      socket.write(buf);
    });

    socket.on('end', function () {
      console.log(`client(${socket.address}) disconnected`);
    });

    socket.on('error', function (err) {
      console.log(`client(${socket.address}) occur error, ${err.message}`);
    });
  });
}

function echo_client() {
  var input = process.stdin;
  var client = net.connect({port:9000});

  client.on('error', function (err) {
    console.log('connect error' + err.message);
  });

  input.on('data', function (buf) {
    console.log(buf.toString());
  });

  // client.on('data', function (buf))
}

echo_server();
