var thrift = require('thrift');
var foo = require('./Foo');
var sample = require('./Sample');
const assert = require('assert');

var transport = thrift.TFramedTransport;
var protocol  = thrift.TBinaryProtocol;

var connection = thrift.createConnection("localhost", 8888, {
    transport : transport,
    protocol : protocol
});

connection.on('error', function(err) {
    assert(false, err);
});

var multiplexer = new thrift.Multiplexer();
var foo_client = multiplexer.createClient('foo', foo, connection);
var sample_client = multiplexer.createClient('sample', sample, connection);

foo_client.echoStr(function () {
  console.log(JSON.stringify(arguments));
  connection.end();
});

foo_client.echoVoid(function () {
  console.log('echoVoid return');
  connection.end();
});

sample_client.echoStruct(function () {
  console.log(JSON.stringify(arguments));
  connection.end();
});
