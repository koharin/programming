<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" import="java.sql.*"%>
<%@page import="java.util.Date" %>
<%@page import="java.text.SimpleDateFormat" %>
<!DOCTYPE html>
<html>
<head>
	<title>수강신청 조회</title>
    <%@include file="header.jsp"%>
</head>
<body>
<div class="container-fluid">
	<%@include file="top.jsp" %>
<%
if(session_id == null) response.sendRedirect("login.jsp"); 

String s_id = (String)session.getAttribute("userID");
int e_year=0;
int e_semester=0;
int t_time; // 교시
String c_id; // 과목번호
int c_id_no; // 분반
int c_unit=0; // 학점
String c_name; // 과목명
String t_name; // 교수명
String c_place; // 장소
int total_cnt=0; // 총 과목 수
int total_unit=0; // 학점

Connection myConn = null;
String driver = "oracle.jdbc.driver.OracleDriver";
String url = "jdbc:oracle:thin:@localhost:1521:xe";
String user = "proj";
String passwd = "proj";
CallableStatement cstmt = null;
try{
	Class.forName(driver);
	myConn = DriverManager.getConnection(url, user, passwd);
}catch(ClassNotFoundException e){
	System.err.println("driver 로딩 실패: "+ e.getMessage());
}catch(SQLException e){
	System.err.println("SQLException: " + e.getMessage());
}

// convert java.util.Date to java.sql.Date
java.util.Date date = new java.util.Date();
java.sql.Date sqlDate = new java.sql.Date(date.getTime());
// 년도 구하기
cstmt = myConn.prepareCall("{? = call Date2EnrollYear(?)}");
cstmt.registerOutParameter(1, java.sql.Types.INTEGER);
cstmt.setDate(2, sqlDate);
try{
	cstmt.execute();
	e_year = cstmt.getInt(1);
}catch(SQLException e){
	System.err.println("SQLException: " + e.getMessage());
}
// 학기 구하기
cstmt = myConn.prepareCall("{?=call Date2EnrollSemester(?)}");
cstmt.registerOutParameter(1, java.sql.Types.INTEGER);
cstmt.setDate(2, sqlDate);
try{
	cstmt.execute();
	e_semester = cstmt.getInt(1);
}catch(SQLException e){
	System.err.println("SQLException: " + e.getMessage());
}

%>
	<div class="row mt-5">
		<div class="col-12 d-flex justify-content-center"><h3><%=s_id %>의 <%=e_year %>년도 <%=e_semester %>학기 수강신청 조회</h3></div>
	// 신청한 과목 출력 테이블
	</div>
	<div class="row mt-3">
		<div class="col-2"></div> 
		<div class="col-8">
			<table class="table align-middle table-striped" border>
			<tr>
			<th class="text-center">과목번호</th>
			<th class="text-center">과목명</th>
			<th class="text-center">분반</th>
			<th class="text-center">학점</th>
			<th class="text-center">교수명</th>
			<th class="text-center">교시</th>
			<th class="text-center">장소</th>
			</tr>

<% 
//저장 프로시저 SelectTimeTable 사용해서 신청한 과목 조회
cstmt = myConn.prepareCall("{call SelectTimeTable(?,?,?,?)}");
cstmt.setString(1, s_id);
cstmt.setInt(2, e_year);
cstmt.setInt(3, e_semester);
cstmt.registerOutParameter(4, oracle.jdbc.OracleTypes.CURSOR);

try{
	cstmt.execute();
	ResultSet rs = (ResultSet)cstmt.getObject(4);
	
	
	if(rs != null){
		while(rs.next()){
			c_id = rs.getString("c_id");
			c_name = rs.getString("c_name");
			c_id_no = rs.getInt("c_id_no");
			c_unit = rs.getInt("c_unit");
			t_name = rs.getString("t_name");
			t_time = rs.getInt("t_time");
			c_place = rs.getString("c_place");
			total_cnt = total_cnt + 1;
%>
			<tr>
			<td align="center"><%=c_id%></td>
			<td align="center"><%=c_name%></td>
			<td align="center"><%=c_id_no%></td>
			<td align="center"><%=c_unit%></td>
			<td align="center"><%=t_name%></td>
			<td align="center"><%=t_time%></td>
			<td align="center"><%=c_place%></td>
			</tr>
			<%		}
					// 총 신청 학점 구하기
					total_unit = total_cnt*c_unit; 
			%>
			</table>
		</div>
	</div>
	// 신청 과목 수, 총 신청 학점 출력 테이블
	<div class="row mt-5">
		<div class="col-4"></div>
		<div class="col-4">
			<table class="table align-middle table-striped" width="30%" border>
			<tr>
			<th class="text-center">총 과목 수</th>
			<th class="text-center">학점</th>
			</tr>
			<tr>
			<td align="center"><%=total_cnt %></td>
			<td align="center"><%=total_unit %></td>
			</tr>
			</table>
<%
	}
}catch(SQLException e){
	System.err.println("SQLException: " + e.getMessage());
}finally{
	if(cstmt != null){
		try{
			myConn.commit();
			cstmt.close();
			myConn.close();
		}catch(SQLException e){
			System.err.println("SQLException: " + e.getMessage());
		}
	}
}
%>
		</div>
	</div>
</div>
</body>
</html>
