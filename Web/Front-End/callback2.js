function doSomthing(){
    var name = 'Yoon';

    setTimeout(function(){
        console.log('My name is '+name);
    }, 100);
}

doSomthing();

if (true) {
    var x = 5;
}
console.log(x); // js는 블록 레벨 스코프 사용 X -> 함수 밖에서 선언된 변수는 코드 블록 내에서 선언되었어도 모두 전역 스코프을 가진다. 

// js는 함수 레벨 스코프 사용, 함수 내 선언된 변수는 지역변수

var x = 'global';

function foo() {
  var x = 'local';
  console.log(x); 

  function bar() {  // 내부함수
    console.log(x);
  }

  bar();  
}
foo(); // local local
console.log(x); // global