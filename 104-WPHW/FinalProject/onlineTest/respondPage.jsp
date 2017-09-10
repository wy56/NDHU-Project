<!--testPage.jsp-->
<%@page contentType = "text/html; charset=utf-8"%>
<%@page import="java.sql.*"%>
<html>
<head><title>onlineTest</title>
</head>
<body>

<%
	Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
	Connection con = DriverManager.getConnection("jdbc:ucanaccess://C:\\Myprograms\\Java\\Tomcat7\\webapps\\ROOT\\yale918.github.io\\finalProject\\onlineTest\\onlineTest.accdb");
	Statement stmt = con.createStatement

	request.setEncoding("utf-8");
	
	
%>


</body>
</html>