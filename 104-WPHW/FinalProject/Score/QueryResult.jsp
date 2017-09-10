<!-- QueryResult.jsp-->
<%@ page contentType="text/html;charset=utf-8" %>
<%@ page import= "java.sql.*" %>
<%@ page import= "java.io.*" %>


<HTML>
<HEAD>
<TITLE>QueryResult</TITLE>
</HEAD>
<p align="left">
<font size="5"><b>考生成績單查詢</b></font>
</p>
<%
	String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
	String connectDB = "jdbc:ucanaccess://C:\\Myprograms\\Java\\Tomcat7\\webapps\\ROOT\\yale918.github.io\\finalProject\\Score\\Exam.accdb";

	StringBuffer sb = new StringBuffer();
	
	Class.forName(JDriver);
	Connection con = DriverManager.getConnection(connectDB);
	Statement stmt = con.createStatement();
	
	request.setCharacterEncoding("utf-8");
	String numberStr=request.getParameter("num");
	
	String sql="SELECT * FROM Results WHERE 准考證號碼= " + numberStr +";";
	
	if (stmt.execute(sql)){
		ResultSet rs = stmt.getResultSet();
		ResultSetMetaData md = rs.getMetaData();
		int colCount = md.getColumnCount();
		sb.append("<TABLE CELLSPACING=10><TR>");
		for (int i = 1; i <= colCount; i++)
			sb.append("<TH>" + md.getColumnLabel(i));
		while (rs.next()){
			sb.append("<TR>");
			for(int i = 1; i<= colCount; i++){
				sb.append("<RD>");
				Object obj = rs.getObject(i);
				if (obj != null)
//out.print(obj.toString());
					sb.append(obj.toString());
				else
					sb.append("&nbsp;");
			}
		}
		sb.append("</TABLE>\n");
	}
	else
		sb.append("<B>Update Count:</B>" + stmt.getUpdateCount());
	
	String result = sb.toString();
	out.print(result);
	
	stmt.close();
	con.close();
%>
</body>
</html>