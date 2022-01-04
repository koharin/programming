<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@page import="java.sql.*" %>
<%
String userID=request.getParameter("user");
String userPassword=request.getParameter("userPassword");

String driver = "oracle.jdbc.driver.OracleDriver";
String url = "jdbc:oracle:thin:@localhost:1521:xe";
String user = "proj";
String passwd = "proj";
Connection myConn = null;

try{
	Class.forName(driver);
	myConn = DriverManager.getConnection(url, user, passwd);
	String mySQL = "select s_id from students where s_id=? and s_pwd=?";
	PreparedStatement pstmt = myConn.prepareStatement(mySQL);
	pstmt.setString(1, userID);
	pstmt.setString(2, userPassword);
	ResultSet result=pstmt.executeQuery();
	if(userID == null || result.isBeforeFirst() == false)
		response.sendRedirect("login.jsp");
	else{
		session.setAttribute("userID", userID);
		response.sendRedirect("main.jsp");
	}
	pstmt.close();
	myConn.close();
	
}catch(ClassNotFoundException e){
	System.err.println("jdbc driver 로딩 실패");
}catch(SQLException e){
	System.err.println("오라클 연결 실패");
}
%>
