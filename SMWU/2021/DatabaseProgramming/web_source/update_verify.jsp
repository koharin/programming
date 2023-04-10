<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<%   
String newAddress=new String(request.getParameter("newAddress").getBytes("8859_1"),"UTF-8");
String newPassword=request.getParameter("newPassword");
String session_id =(String)session.getAttribute("userID");
String driver="oracle.jdbc.driver.OracleDriver";
String url="jdbc:oracle:thin:@localhost:1521:xe";
String user ="proj";
String password="proj";
Connection myConn=null;
Statement stmt=null;

try{
	Class.forName(driver);
	myConn=DriverManager.getConnection(url,user,password);
//studentview에 있는 s_pwd, s_addr 값 수정하기, 이때 trigger.sql 사용
	String mySQL="update studentview set s_pwd='"+newPassword+"', s_addr='"+newAddress+"' where s_id='"+session_id+"'";
	stmt = myConn.createStatement();
	int res = stmt.executeUpdate(mySQL);
	if(res!=0){
		//성공적으로 수정됐을 경우 수정된 정보를 확인할 수 있게 update.jsp로 보내기
		response.sendRedirect("update.jsp");
	}
	stmt.close();
	myConn.close();
} catch(SQLException ex) {
	String sMessage;
//trigger.sql에 의한 에러
	if (ex.getErrorCode() == 20002) sMessage="암호는 4자리 이상이어야 합니다";
	else if (ex.getErrorCode() == 20003) sMessage="암호에 공란은 입력되지 않습니다.";
	else sMessage="잠시 후 다시 시도하십시오";
	System.err.println(sMessage);
	//오류가 있을 경우 update_page.jsp로 이동
	response.sendRedirect("update_page.jsp");
}

%>
