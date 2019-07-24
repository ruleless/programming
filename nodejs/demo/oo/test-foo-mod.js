foo = require('./foo-mod').foo;
Foo = require('./foo-mod').Foo;

console.log('typeof foo-mode.js: ' + typeof require('./foo-mod'));
console.log('typeof foo: ' + typeof foo);
new foo();
new foo();

console.log('typeof Foo: ' + typeof Foo);
foo_obj1 = new Foo;
foo_obj2 = new Foo();
foo_obj1.print();
foo_obj2.print();
