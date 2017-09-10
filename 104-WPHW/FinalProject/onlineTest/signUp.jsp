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
	String _name = request.getParameter("_name");
	
	
	String sql = "INSERT  INTO idTable(id,pd,_name) VALUES ('" + id +"','" + pd +"','"+_name+"')" ;
	stmt.executeUpdate(sql);
	//out.print("註冊完成!!");
	//out.print("<a href= ./onlineTest.html>"); 
	//out.print("<br>回登入頁面</a>");
	//session = request.getSession();
	//session.setAttribute("signUp", "true");
	
	
	stmt.close();
	con.close();
%>

<div align="center" >
註冊完成
<br>
<A href = "onlineTest.html">回登入頁面</A>
</div>


</body>

<html>