<%@ page contentType="text/html;charset=big5" %>
<%@ page import="java.sql.*" %>
<%@ page import="java.io.*" %>
<%@ page import="net.ucanaccess.jdbc.UcanaccessDriver" %>
<html>
<head><title>QueryResult</title></head><body>
<p align="left">
<font size="5"><b>考生成績單查詢</b></font>
</p>
<%

	 String connectDB="jdbc:ucanaccess://" + currentDir + "Exam.accdb";
	 StringBuffer sb = new StringBuffer();

     Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
	 Connection con = DriverManager.getConnection(connectDB);
	 Statement stmt = con.createStatement();

	request.setCharacterEncoding("big5");
	String numberStr = request.getParameter("num");

	String a = "SELECT * FROM Results WHERE 准考證號碼= ";
	String b = ";";
	String sql=  a + numberStr + b ;

	if(stmt.execute(sql))
	{
		ResultSet rs = stmt.getResultSet();
		ResultSetMetaData md = rs.getMetaData();
		int colCount = md.getColumnCount();
		sb.append("<TABLE CELLSPACING=10><TR>");
		for(int i=1;i<=colCount;i++)
			sb.append("<TH>" + md.getColumnLabel(i));
		while(rs.next())
		{
			sb.append("<TR>");
			for(int i=1;i<=colCount;i++)
			{
				sb.append("<TD>");
				Object obj = rs.getObject(i);
				if(obj != null)
					sb.append(obj.toString());
				else 
					sb.append("&nbsp;");
			}		
		}
		sb.append("</TABLE>\n");
	}
	else 
		sb.append("<B>Update Count:</B> " + stmt.getUpdateCount());

	String result = sb.toString();
	out.print(result);

	stmt.close();
	con.close();
%>
</body>
</html>