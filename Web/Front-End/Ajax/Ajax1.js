///// Ajax 요청처리 예

// 1. XMLHttpRequest 객체 생성 -> Ajax 요청 생성
var request = new XMLHttpRequest();

// 비동기 방식으로 Request 오픈
request.open('GET', 'data/test.json', true);

//Request 전송
request.send();



///// Ajax 응답처리 예
// XMLHttpRequest.readyState 프로퍼티가 변경(이벤트 발생)될 때마다 XMLHttpRequest.onreadystatechange라는 콜백함수(이벤트 핸들러) 호출.
// Response가 클라이언트에 도달 시 호출된다.
request.onreadystatechange = function(e){
    // readyStates는 XMLHttpRequest의 상태(state) 반환
    // readyState == 4 : DONE(서버 응답 완료)
    if(request.readyState === XMLHttpRequest.DONE){
        // status는 response 상태 코드 반환
        // 200 : 정상응답
        if(request.status == 200){
            console.log(request.responseText);
        }else{
            console.log("Error!");
        }
    }
};