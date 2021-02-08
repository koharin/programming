var emptyObject = {};
console.log(typeof emptyObject); // object

var person = {
    name: 'Lee',
    gender: 'male',
    sayHello: function(){
        console.log('Hi! My name is ' + this.name);
    }
};

console.log(person); // { name: 'Lee', gender: 'male', sayHello: [Function: sayHello] }
person.sayHello(); // Hi! My name is Lee

var person2 = new Object(); // new 연산자, Object 생성자 함수 사용해서 empty object 생성 
//property 추가
person2.name = 'Yoon';
person2.gender = 'male';
person2.sayHello = function(){
    console.log('Hi! My name is ' + this.name);
};

console.log(typeof person2); // object
console.log(person2); // { name: 'Yoon', gender: 'male', Hello: [Function] }
person2.sayHello(); // Hi! My name is Yoon

function Person(name, gender){
    var married = true; // private
    this.name = name; // public
    this.gender = gender; //public
    this.sayHello = function(){ //public
        console.log('Hi! My name is ' + this.name);
    };
}

var p1 = new Person('Lee', 'Male');
var p2 = new Person('Park', 'Female');
console.log('p1: ', typeof p1);
console.log('p2: ', typeof p2);
console.log('p1: ', p1);
console.log('p2: ', p2);
p1.sayHello();
p2.sayHello();
console.log(p1.married); // undefined