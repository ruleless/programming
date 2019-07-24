#! /usr/bin/env node

var fs = require('fs');

function copy(src, dest) {
  var rs = fs.createReadStream(src);
  var ws = fs.createWriteStream(dest);

  rs.pipe(ws);
}

if (process.argv.length != 4) {
  console.log('argument error');
  return;
}

const argv = process.argv.slice(2);
copy(argv[0], argv[1]);
