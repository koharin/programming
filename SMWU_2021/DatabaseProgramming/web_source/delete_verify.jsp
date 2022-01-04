<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>수강신청 취소</title>
</head>
<body>

<%
String s_id = (String)session.getAttribute("userID");
String c_id = request.getParameter("c_id"); 

String driver = "oracle.jdbc.driver.OracleDriver";
String url = "jdbc:oracle:thin:@localhost:1521:xe";
String user = "proj";
String passwd = "proj";
Connection myConn = null;

// driver 로딩 & db 연결
try{
	Class.forName(driver);
	myConn = DriverManager.getConnection(url, user, passwd);
}catch(ClassNotFoundException e){
	System.err.println("driver 로딩 실패: "+ e.getMessage());
}catch(SQLException e){
	System.err.println("SQLException: " + e.getMessage());
}
try{
	// enroll에서 지정한 c_id와 s_id에 대한 레코드를 삭제한다.
	String mySQL = "delete from enroll where c_id=? and s_id=?";
	PreparedStatement pstmt = myConn.prepareStatement(mySQL);
	pstmt.setString(1, c_id);
	pstmt.setString(2, s_id);
	ResultSet res=pstmt.executeQuery();
	
%>
<script>
<!-- 취소 결과를 alert 창으로 보여준다. -->
alert("해당 과목 수강신청이 취소되었습니다.");
<!-- delete.jsp 페이지로 이동 -->
location.href="delete.jsp";
</script>
<%	
pstmt.close();
myConn.close();
}catch(SQLException e){
	System.err.println("SQLException: " + e.getMessage());
}
%>

</body>
</html>
