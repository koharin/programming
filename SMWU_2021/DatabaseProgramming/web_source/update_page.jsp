<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<head>
	<title> 수강신청 사용자 정보 수정 </title>
    <%@include file="header.jsp"%>
</head>
<body>
<div class="container-fluid">
	<%@include file="top.jsp" %>
	<div class="row mt-5">
		<div class="col-12 d-flex justify-content-center"><h3>사용자 정보 수정</h3></div>
	</div>
	<form method="post" action="update_verify.jsp">
	<div class="row mt-3">
		<div class="col-4"></div>
		<div class="col-4">
		<table class="table align-middle" border>
			<tr>
			<td><div class="d-flex justify-content-center">패스워드</div></td>
			<td><div class="d-flex justify-content-center">
			<input class="form-control" type="password" name="newPassword">
			</div></td>
			</tr>
			<tr>
			<td><div class="d-flex justify-content-center">주소</div></td>
			<td><div class="d-flex justify-content-center">
			<input class="form-control" type="text" name="newAddress">
			</div></td></tr>
			<tr>
			<td colspan=2>
			<div align="center">
			<INPUT class="btn btn-dark btn-sm" TYPE="SUBMIT" NAME="Submit" VALUE="변경">
			<INPUT class="btn btn-dark btn-sm" TYPE="RESET" VALUE="취소">
			</div></td>
			</tr>
		</table>
	</form>
</div>
</body>
</html>
