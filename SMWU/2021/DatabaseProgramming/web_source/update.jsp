<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<html>
<head>
	<title>사용자 정보 조회</title>
    <%@include file="header.jsp"%>
</head>
<body>
<div class="container-fluid">
	<%@include file="top.jsp"%>
	<div class="row mt-5">
		<div class="col-12 d-flex justify-content-center"><h3>사용자 정보 조회</h3></div>
	</div>
	<form method="post" action="update_page.jsp">
<% 
// 로그인 안 되어있으면 login 페이지로 이동
if (session_id==null) response.sendRedirect("login.jsp");

String driver="oracle.jdbc.driver.OracleDriver";
String url="jdbc:oracle:thin:@localhost:1521:xe";
String user ="proj";
String password="proj";
Class.forName(driver);
Connection myConn=null;
String mySQL=null;
Statement stmt=null;
ResultSet rset=null;

myConn=DriverManager.getConnection(url,user,password);
//students 테이블에서 s_addr과 s_pwd 받아오기
mySQL = "select s_addr,s_pwd from students where s_id='" + session_id + "'" ;
stmt = myConn.createStatement();
rset = stmt.executeQuery(mySQL);
//받아온 s_addr, s_pwd jsp에서 쓸 수 있게 새로 선언하기
while(rset.next()){
	String s_addr = rset.getString("s_addr");
	String s_pwd= rset.getString("s_pwd");
%>
	<div class="row mt-3">
		<div class="col-4"></div>
		<div class="col-4">
			<table class="table align-middle" border>
				<tr>
				<td><div class="d-flex justify-content-center">패스워드</div></td>
				<td><div class="d-flex justify-content-center"><%=s_pwd%></div></td>
				</tr>
				<tr>
				<td><div class="d-flex justify-content-center">주소</td>
				<td><div class="d-flex justify-content-center"><%=s_addr%></div></td>
				</tr>
			</table>
			<%
			}
			stmt.close();
			myConn.close();
			%>
		</div>
	</div>
	<div class="row d-flex justify-content-center mt-2">
		<div class="col-1 d-flex justify-content-center">
			<button class="btn btn-dark btn-sm" TYPE="SUBMIT" NAME="Submit">변경</button>
		</div>
	</div>
	</form>
</div>
</body>
</html>
