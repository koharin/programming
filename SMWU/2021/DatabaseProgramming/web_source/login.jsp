<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"> 
	<title>수강신청 시스템 로그인</title>
    <%@include file="header.jsp"%>
</head>
<body>
<div class="container-fluid">
	<%@include file="top.jsp" %>
	<div class="row mb-5">
		<div class="col-12 d-flex justify-content-center"><h3>사용자 계정 로그인</h3></div>
	</div>
	<form method="post" action="login_verify.jsp">
	<div class="row mt-5">
		<div class="col-4"></div>
		<div class="col-1">아이디</div>
		<div class="col-3">
			<input class="form-control" type="text" name="user">
		</div>
	</div>
	<div class="row mt-2">
		<div class="col-4"></div>
		<div class="col-1">패스워드</div>
		<div class="col-3">
			<input class="form-control" type="password" name="userPassword">
		</div>
	</div>
	<div class="row mt-5">
		<div class="col-5"></div>
		<div class="col-2 d-flex justify-content-around">
			<INPUT class="btn btn-dark btn-sm" TYPE="SUBMIT" NAME="Submit" VALUE="로그인">
			<INPUT class="btn btn-dark btn-sm" TYPE="RESET" VALUE="취소">
		</div>
	</div>
	</form>
</div>
</body>
</html>
