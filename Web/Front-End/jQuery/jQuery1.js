$(function(){
    $('h1').text('Hello'); 
});
/* 
$('h1') : jQuery() 함수 인수로 CSS의 태그 선택자 지정
선택자에 의해 선택된 요소들을 jQuery 객체
text() : 메소드. 해당 요소(Matched set)의 텍스트 반환
$('h1').text('Hello!'); : h1 요소의 텍스트 변경
$('h1')에 의해 생성된 Matched set이 여러 개의 요소를 담고 있으면, jQuery는 반복문 없이 모든 요소에 접근할 수 있다. => 묵시적 반복(Implicit iteration)
*/
// HTML을 인수로 전달받아 새로운 HTML 요소를 생성한다.
$('<p id="test">My <em>new</em> text</p>').appendTo('body');

// JavaScript 객체를 인수로 전달받을 때 
// - JavaScript 객체 (plain object, DOM element, array 등)를 인수로 받으면 그 객체를 jQuery 객체로 wrap한 객체 반환
$('div.foo').click(function(){
    $(this).slideUp();
});
var foo = {foo: 'bar', hello: 'world'};
var $foo = $(foo);
var test1 = $foo.prop('foo');
console.log(test1) // bar

$foo.prop('foo', 'foobar'); // Setting property value from bar to foobar

var test2 = $foo.prop('foo');
console.log(test2); // foobar
