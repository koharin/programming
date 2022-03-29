<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="EUC-KR">
	<title>데이터베이스를 활용한 수강신청 시스템입니다.</title>
    <%@include file="header.jsp"%>
</head>
<body>
<div class="container-fluid">
	<%@include file="top.jsp"%>
	<div class="row d-flex justify-content-center">
		<div class="col-3 d-flex justify-content-center"><img src="${pageContext.request.contextPath}/IMAGES/snow.jpg"/></div>
	</div>
	<div class="row justify-content-md-center mt-5">
		<div class="col-6 d-flex justify-content-center">
			<% if (session_id != null) { %>
				<h3><%=session_id%>님 방문을 환영합니다.</h3>
			<% } else { %>
				<h3>로그인한 후 사용하세요.</h3>
			<% } %>
		</div>
	</div>
</div>
</body>
</html>
