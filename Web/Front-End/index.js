/*
const arr = [1,2,3];
arr.forEach(alert); //alert: 브라우저에 알림창 띄우는 함수, Client-Side Web API
*/
const $counter = document.getElementById('counter');
const $increase = document.getElementById('increase');
const $decrease = document.getElementById('decrease');

let num = 0;
const render =  function(){ $counter.innerHTML = num; }
$increase.onclick = function(){
    num++;
    console.log('increase button clicked', num);
    render();
}
$decrease.onclick = function(){
    num--;
    console.log('decrease button clicked', num);
    render();
}

var foo = null;
console.log(typeof foo);