
<%@ page contentType="text/html;charset=utf-8" %>
<%@ page import="java.sql.*" %>
<%@ page import="java.io.*" %>
<html>
<head><title>ReadArticle</title>
</head>
<body>
<p align="left">
<font size="5"><b>印出雲端全部文章</b></font>
</p><HR>
<%
	String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
	String connectDB = "jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\example\\2015.12.04\\CloudArticle.accdb";
	
	Class.forName(JDriver);
	Connection con = DriverManager.getConnection(connectDB);
	Statement stmt = con.createStatement();
	
	request.setCharacterEncoding("utf-8");
	
	String sql="SELECT * FROM articleINFO" ;
	
	if (stmt.execute(sql)) {
		ResultSet rs = stmt.getResultSet();
		while(rs.next()){
			String indexStr=rs.getString("編號");
			String timeStr=rs.getString("時間");
			String nameStr=rs.getString("名稱");
			String emailStr=rs.getString("信箱");
			String articalStr=rs.getString("文章");
			
			out.print("時間:" + timeStr + "<BR>");
			out.print("名稱:" + nameStr + "<BR>");
			out.print("信箱:" + emailStr + "<BR>");
			out.print("文章<BR>:" + articalStr + "<BR>");

			out.print("<FORM METHOD=post ACTION=09WriteResponse.jsp>");
			out.print("<INPUT TYPE=radio NAME=postIndex " +
								"VALUE=" + indexStr + ">選擇鈕點取");
			out.print("<INPUT TYPE=submit VALUE= \"寫入回應\">");
			out.print("<HR>");
		}
		
	}
	stmt.close();
	con.close();
%>


</body>
</html>