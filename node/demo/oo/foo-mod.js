var a = 0;

this.b = 1;

exports.Foo = class Foo {
  constructor() {
    this.a = 0;
  }

  print() {
    console.log('this.a = ' + this.a++);
  }
};

exports.foo = function() {
  this.a = 5;
  console.log('a:' + this.a++);
}

console.log('this:' + this);

console.log('this == exports: ' + (this === exports));
console.log('this == module.exports: ' + (this === module.exports));
