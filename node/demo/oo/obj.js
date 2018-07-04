
function Obj(a) {
  this.a = a;
}

var proto = Obj.prototype;
proto.display = function () {
  console.log('this.a=' + this.a);
}

module.exports = Obj;
