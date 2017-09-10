<%@ page contentType="text/html;charset=utf-8" %>
<%@ page import="java.sql.*, java.util.Date" %>
<%@ page import="java.io.*" %>
<html>
<head><title>ReadResponse</title>
</head>
<body>
<p align="left">
<font size="5"><b>讀取回應意見</b></font>
</p><HR>
<%
	String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
	String connectDB = "jdbc:ucanaccess://D:\\Programs\\Java\\Apache Software Foundation\\Tomcat 7.0\\webapps\\ROOT\\CloudArticle.accdb";
	
	Class.forName(JDriver);
	Connection con = DriverManager.getConnection(connectDB);
	Statement stmt = con.createStatement();
	
	request.setCharacterEncoding("utf-8");
	String indexStr = request.getParameter("respIndex");
		
	String sql="SELECT * FROM articleINFO WHERE 編號= "
				+ indexStr + ";";
	
	if (stmt.execute(sql)) {
		ResultSet rs = stmt.getResultSet();
		while(rs.next()){
			
			String timeStr=rs.getString("時間");
			String nameStr=rs.getString("名稱");
			String emailStr=rs.getString("信箱");
			String articalStr=rs.getString("文章");
			
			out.print("編號:" + indexStr + "<BR>");
			out.print("時間:" + timeStr + "<BR>");
			out.print("名稱:" + nameStr + "<BR>");
			out.print("信箱:" + emailStr + "<BR>");
			out.print("文章<BR>:" + articalStr + "<BR>");
		}
		
	}
	
	String sql2 = "SELECT * FROM responseINFO WHERE 原文章編號=" +
						indexStr + ";" ;
	
	if (stmt.execute(sql2)) {
		ResultSet rs = stmt.getResultSet();
		while(rs.next()){
			
			String resptimeStr=rs.getString("回應時間");
			String respnameStr=rs.getString("回應者名稱");
			String respemailStr=rs.getString("回應者信箱");
			String resparticalStr=rs.getString("回應者意見");
			
			out.print("回應時間:" + resptimeStr + "<BR>");
			out.print("回應者名稱:" + respnameStr + "<BR>");
			out.print("回應者信箱:" + respemailStr + "<BR>");
			out.print("回應者意見<BR>:" + resparticalStr + "<BR>");
			
			out.print("<HR>");
		}
		
	}
	
	stmt.close();
	con.close();

	%>
</body>
</html>