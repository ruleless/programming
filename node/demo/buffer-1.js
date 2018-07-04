#! /usr/bin/env node

/*
 * 'ascii' - For 7-bit ASCII data only. This encoding is fast and will strip the high bit if set.
 * 'utf8' - Multibyte encoded Unicode characters. Many web pages and other document formats use UTF-8.
 * 'utf16le' - 2 or 4 bytes, little-endian encoded Unicode characters. Surrogate pairs (U+10000 to U+10FFFF) are supported.
 * 'ucs2' - Alias of 'utf16le'.
 * 'base64' - Base64 encoding. When creating a Buffer from a string, this encoding will also correctly accept "URL and Filename Safe Alphabet" as specified in RFC4648, Section 5.
 * 'latin1' - A way of encoding the Buffer into a one-byte encoded string (as defined by the IANA in RFC1345, page 63, to be the Latin-1 supplement block and C0/C1 control codes).
 * 'binary' - Alias for 'latin1'.
 * 'hex' - Encode each byte as two hexadecimal characters.
 */

/*
 * new Buffer(array)/Buffer.from(array)
 * new Buffer(arrayBuffer[, byteOffset[, length]])/Buffer.from(arrayBuffer[, byteOffset[, length]])
 * new Buffer(buffer)/Buffer.from(buffer)
 * new Buffer(size)/Buffer.alloc()
 * new Buffer(string[, encoding])/Buffer.from(string[, encoding])
 */

// Creates a zero-filled Buffer of length 10.
const buf1 = Buffer.alloc(10);

// Creates a Buffer of length 10, filled with 0x1.
const buf2 = Buffer.alloc(10, 1);

// Creates an uninitialized buffer of length 10.
// This is faster than calling Buffer.alloc() but the returned
// Buffer instance might contain old data that needs to be
// overwritten using either fill() or write().
const buf3 = Buffer.allocUnsafe(10);

// Creates a Buffer containing [0x1, 0x2, 0x3].
const buf4 = Buffer.from([1, 2, 3]);

// Creates a Buffer containing UTF-8 bytes [0x74, 0xc3, 0xa9, 0x73, 0x74].
const buf5 = Buffer.from('tést');

// Creates a Buffer containing Latin-1 bytes [0x74, 0xe9, 0x73, 0x74].
const buf6 = Buffer.from('tést', 'latin1');

console.log('buf1:' + buf1.toString('hex') + ' len:' + Buffer.byteLength(buf1));
console.log('buf2:' + buf2.toString('ascii'));
console.log('buf3:' + buf3);
console.log('buf4:' + buf4.toString());
console.log('buf5:' + buf5.toString('ascii'));
console.log('buf6:' + buf6.toString('ascii'));

// Buffer instances can be iterated over using for..of syntax:
var buf7 = Buffer.from([1, 2, 3]);
for(var i of buf7) {
  console.log(i);
}

// Buffer.compaire(buf1, buf2)
const buf8 = Buffer.from('1234');
const buf9 = Buffer.from('2345');
var arr = [buf9, buf8];
arr.sort(Buffer.compaire);

for (i of arr) {
  console.log(i.toString());
}
