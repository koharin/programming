<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>수강신청 입력</title>
</head>
<body>
<%
String s_id = (String)session.getAttribute("userID");
// insert.jsp에서 매개변수로 넘긴 c_id 받아오기
String c_id = request.getParameter("c_id");
// insert.jsp에서 매개변수로 넘긴 c_id_no 받아오기
int c_id_no = Integer.parseInt(request.getParameter("c_id_no")); 

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
	System.err.println("SQLException1: " + e.getMessage());
}
//저장 프로시저 InsertEnroll 사용해서 수강신청
cstmt = myConn.prepareCall("{call InsertEnroll(?,?,?,?)}");
cstmt.setString(1, s_id);
cstmt.setString(2, c_id);
cstmt.setInt(3, c_id_no);
cstmt.registerOutParameter(4, java.sql.Types.VARCHAR);

try{
	cstmt.execute();
	String result = cstmt.getString(4);
%>
<script>
<!-- 결과를 alert 창으로 보여준다. -->
alert("<%=result%>");
<!-- insert.jsp 페이지로 이동 -->
location.href="insert.jsp";
</script>
<%	
}catch(SQLException e){
	System.err.println("SQLException2: " + e.getMessage());
}finally{
	if(cstmt != null){
		try{
			// db 변경 사항 commit
			myConn.commit(); 
			cstmt.close();
			myConn.close();
		}catch(SQLException e){
			System.err.println("SQLException3: " + e.getMessage());
		}
	}
}
%>
</body>
</html>
