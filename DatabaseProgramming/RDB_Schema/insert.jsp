<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
	<title>수강신청 입력</title>
    <%@include file="header.jsp"%>
</head>
<body>
<div class="container-fluid">
	<%@include file="top.jsp" %>
	// 로그인 안 되어있으면 login 페이지로 이동
	<% if(session_id == null) response.sendRedirect("login.jsp"); %>
	<div class="row mt-5">
		<div class="col-12 d-flex justify-content-center"><h3>수강신청 가능 과목 조회</h3></div>
	</div>
	<div class="row mt-3">
		<div class="col-2"></div>
		<div class="col-8">
			<table class="table align-middle table-striped" border>
			<tbody>
			<tr>
			<th class="text-center" scope="col">과목번호</th>
			<th class="text-center" scope="col">분반</th>
			<th class="text-center" scope="col">과목명</th>
			<th class="text-center" scope="col">학점</th>
			<th class="text-center" scope="col">교수명</th>
			<th class="text-center" scope="col">수강신청</th>
			</tr>
<%
Connection myConn = null;
String driver = "oracle.jdbc.driver.OracleDriver";
String url = "jdbc:oracle:thin:@localhost:1521:xe";
String user = "proj";
String passwd = "proj";

try{
	Class.forName(driver);
	// DB 연결
	myConn = DriverManager.getConnection(url, user, passwd); 
	//수강신청 가능 과목 조회
}catch(ClassNotFoundException e){
	System.err.println("jdbc driver 로딩 실패: " + e.getMessage());
}catch(SQLException e){
	System.err.println("SQLException1: "+e.getMessage());
}
	
try{
	// enroll에서 s_id가 수강한 과목 제외한 과목 조회
	String mySQL = "select c_id, c_id_no, c_name, c_unit, t_name from COURSE where c_id not in (select c_id from ENROLL where s_id=" + session_id + ")"; 
	PreparedStatement pstmt = myConn.prepareStatement(mySQL);
	ResultSet result = pstmt.executeQuery(mySQL);
	
	if(result != null){
		while(result.next()){
			
			String c_id = result.getString("c_id");
			int c_id_no = result.getInt("c_id_no");
			String c_name = result.getString("c_name");
			int c_unit = result.getInt("c_unit");
			String t_name = result.getString("t_name");
			if(!result.wasNull()){
%>
			<tr>
			<td align="center"><%=c_id%></td>
			<td align="center"><%=c_id_no%></td>
			<td align="center"><%=c_name%></td>
			<td align="center"><%=c_unit%></td>
			<td align="center"><%=t_name%></td>
			<td align="center"><a href="insert_verify.jsp?c_id=<%=c_id%>&c_id_no=<%=c_id_no%>">신청</a></td>
			</tr>
<%	
			}
		}
	}	
}catch(SQLException e){
	System.err.println("SQLException2: "+e.getMessage());
}

%>
			</tbody>
			</table>
		</div>
	</div>
</div>
</body>
</html>
