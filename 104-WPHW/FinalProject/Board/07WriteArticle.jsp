<%@ page contentType="text/html;charset=utf-8" %>
<%@ page import= "java.sql.*, java.util.Date" %>
<html>
<head><title>WriteArticle</title>
</head>
<body>
<p align="center">
<font size="5"><b>寫入文章資料庫</b></font>
</p>

<%
	String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
	String connectDB = "jdbc:ucanaccess://D:\\Programs\\Java\\Apache Software Foundation\\Tomcat 7.0\\webapps\\ROOT\\CloudArticle.accdb";
	
	Class.forName(JDriver);
	Connection con = DriverManager.getConnection(connectDB);
	Statement stmt = con.createStatement();
	
	request.setCharacterEncoding("utf-8");
	String MsgName = request.getParameter("msgName");
	String EMail = request.getParameter("eMail");
	String Data = request.getParameter("data");
	
	if(MsgName=="" || EMail=="" || Data==""){
		out.print("資料填寫未完成");
		stmt.close();
		con.close();
		%><br>
		<a href= "01ArticlePage" target= "_top">按此回首頁</a>
		<%
	}
	else{
		Date msgDate= new Date();
		String dateStr= msgDate.toLocaleString();
		
		String sql="INSERT INTO articleINFO(時間, 名稱, " +
							"信箱, 文章) VALUES ('" +
							dateStr + "','" + MsgName + "','" +
							EMail + "','" + Data + "')" ;
		
		stmt.executeUpdate(sql);
		out.print("成功完成文章寫入資料庫");
		
		stmt.close();
		con.close();
		
	}
	
%>


</body>
</html>