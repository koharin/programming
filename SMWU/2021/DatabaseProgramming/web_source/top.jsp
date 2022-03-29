<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<html>
<body>
<% String session_id = (String) session.getAttribute("userID");
String log;
if (session_id == null)
log = "<a href=login.jsp>로그인</a>";
else log = "<a href=logout.jsp>로그아웃</a>"; 
%>
<div class="row mb-5" style="background-color:#c3bef0;">
	<div class="col-2 d-flex justify-content-center pb-2 pt-2"><b><%=log%></b></div>
	<div class="col-2 d-flex justify-content-center pb-2 pt-2"><b><a href="main.jsp">Home</a></b></div>
	<div class="col-2 d-flex justify-content-center pb-2 pt-2"><b><a href="update.jsp">사용자 정보 수정</a></b></div>
	<div class="col-2 d-flex justify-content-center pb-2 pt-2"><b><a href="insert.jsp">수강신청 입력</a></b></div>
	<div class="col-2 d-flex justify-content-center pb-2 pt-2"><b><a href="delete.jsp">수강신청 삭제</a></b></div>
	<div class="col-2 d-flex justify-content-center pb-2 pt-2"><b><a href="select.jsp">수강신청 조회</a></b></div>
</div>
</body>
</html>
