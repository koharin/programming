function square(number){
    console.log(arguments); // Arguments] { '0': 2 }
    console.log(this); // 함수 호출 방식에 따라 this에 바인딩되는 객체가 달라진다.
    return number*number;
}
square(2);
/* 결과
[Arguments] { '0': 2 }
Object [global] {
  global: [Circular],
  clearInterval: [Function: clearInterval],
  clearTimeout: [Function: clearTimeout],
  setInterval: [Function: setInterval],
  setTimeout: [Function: setTimeout] {
    [Symbol(nodejs.util.promisify.custom)]: [Function]
  },
  queueMicrotask: [Function: queueMicrotask],
  clearImmediate: [Function: clearImmediate],
  setImmediate: [Function: setImmediate] {
    [Symbol(nodejs.util.promisify.custom)]: [Function]
  }
}
*/

console.log('-----------------------------------------');
var foo = function(){
    console.dir(this);
};

foo(); // 1. 함수 호출 (window)
console.log(this === global);
console.log('-----------------------------------------');
var obj = {a: foo}; // 2. 메소드 호출
obj.a(); // { a: [Function: foo] } (obj)
console.log('-----------------------------------------');
var instance = new foo(); // 3. 생성자 함수 호출 -> foo {} (instance) 
console.log('-----------------------------------------');
var bar = {name: 'bar'};
foo.call(bar); // { name: 'bar' }
foo.apply(bar); // { name: 'bar' }
foo.bind(bar)(); // { name: 'bar' }
console.log('-----------------------------------------');
var value = 1;
var obj = {
    value: 100,
    foo: function(){
        console.log("foo's this: ", this); // { value: 100, foo: [Function: foo] }
        console.log("foo's this.value: ", this.value); // 100
        function bar(){
            console.log("bar's this: ", this);
            /*
            Object [global] {
                global: [Circular],
                clearInterval: [Function: clearInterval],
                clearTimeout: [Function: clearTimeout],
                setInterval: [Function: setInterval],
                setTimeout: [Function: setTimeout] {
                    [Symbol(nodejs.util.promisify.custom)]: [Function]
                },
                queueMicrotask: [Function: queueMicrotask],
                clearImmediate: [Function: clearImmediate],
                setImmediate: [Function: setImmediate] {
                    [Symbol(nodejs.util.promisify.custom)]: [Function]
                }
            }
            */
            console.log("bar's this.value: ", this.value); // undefined
        }
        bar();
    }
};
obj.foo();
console.log('-----------------------------------------');
var value = 1;
var obj = {
    value: 100,
    foo: function(){
        var that = this;
        setTimeout(function(){
            console.log("callback's this: ", this);
            console.log("callback's this.value: ", this.value); // 1
        }, 100);
    }
};
obj.foo();
console.log('-----------------------------------------');
var obj1 = {
    name: 'Lee',
    sayName: function(){
        console.log(this.name);
    }
}

var obj2 = {
    name: 'Kim'
}

obj2.sayName = obj1.sayName;
obj1.sayName(); // Lee
obj2.sayName(); // Kim

// 생성자 함수 호출 - 객체의 프로토타입 객체는 Person.prototype
function Person(name) {
    // 생성자 함수 코드 실행 전 -------- 1
    this.name = name;  // --------- 2
    // 생성된 함수 반환 -------------- 3
  }
  
var me = new Person('Lee');
console.log(me.name); // Lee

var Person = function (name) {
  this.name = name;
};
  
var foo = {};

// apply 메소드는 생성자함수 Person을 호출한다. 이때 this에 객체 foo를 바인딩한다.
Person.apply(foo, ['name']);
  
console.log(foo); // { name: 'name' }

var x = 'xxx';

function foo2 () {
  var y = 'yyy';

  function bar () {
    var z = 'zzz';
    console.log(x + y + z);
  }
  bar();
}
foo2();