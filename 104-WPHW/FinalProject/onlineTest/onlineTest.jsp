<%@ page contentType = "text/html;charset=utf-8"%>
<%@ page import="java.sql.*"%>
<html>
<head>
<title>線上考試</title>
</head>
<body>
<%
	Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
	Connection con = DriverManager.getConnection("jdbc:ucanaccess://D:\\Programs\\Java\\Apache Software Foundation\\Tomcat 7.0\\webapps\\ROOT\\yale918.github.io\\finalProject\\onlineTest\\onlineTest.accdb");
	Statement stmt = con.createStatement();
	
	request.setCharacterEncoding("utf-8");
	String id = request.getParameter("id");
	String pd = request.getParameter("pd");
	String sql = "SELECT * FROM idTable where id='"+ id + "' AND pd='" + pd+ "'";
	ResultSet rs = stmt.executeQuery(sql);
	//ResultSet rs = stmt.executeQuery("SELECT * FROM idTable WHERE id = 'cc' AND pd = 'cc';");

	boolean flag=false;
	while(rs.next()) flag=true;
	if(flag){
		out.print("<meta http-equiv=\'refresh\' content=\'1;url=questionPage.jsp\'>");
		//out.print("測試OK!");
	}
	else{
		out.print("帳號輸入不對唷!<br>");
		out.print("<a href=");
		out.print("./onlineTest.html>回登入頁面");
	}
	
	stmt.close();
	con.close();
%>





</body>

<html>