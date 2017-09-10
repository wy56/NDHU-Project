<%@ page contentType="text/html;charset=big5" %>
<%@ page import="java.sql.*" %>
<%@ page import="java.io.*" %>
<html>
<head><title>Ex44</title></head>
<p align="left">
<font page="5"><b>Sub Page of Ex44</b></font>
<p>
<%
	StringBuffer sb = new StringBuffer();
	
	Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
	Connection con = DriverManager.getConnection("jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\example\\2015.10.23\\BookStore.accdb");
	
	Statement stmt = con.createStatement();
	
	request.setCharacterEncoding("big5");
	String StartNum = request.getParameter("StartNum");
	String EndNum = request.getParameter("EndNum");
	
	String sql = "SELECT * FROM Books WHERE ½s¸¹>='" + StartNum + "' AND ½s¸¹<='"+ EndNum + "';";
	
	if(stmt.execute(sql))
	{
		ResultSet rs = stmt.getResultSet();
		ResultSetMetaData md = rs.getMetaData();
		int colCount = md.getColumnCount();
		sb.append("<table cellspacing=10><tr>");
		for(int i=1; i<=colCount; i++)
			sb.append("<th>" + md.getColumnLabel(i));
		while(rs.next())
		{
			sb.append("<tr>");
			for(int i=1; i<=colCount; i++)
			{
				sb.append("<td>");
				Object obj = rs.getObject(i);
				if(obj != null)
					sb.append(obj.toString());
				else
					sb.append("&nbsp;");
			}
		}
		sb.append("</table>\n");
	}
	else
		sb.append("<b>Update Count:</b>" + stmt.getUpdateCount());
	
	String result = sb.toString();
	out.print(result);
	
	stmt.close();
	con.close();
%>
</body>
</html>
