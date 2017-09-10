<%@ page contentType="text/html;charset=utf-8" %>
<%@ page import="java.io.*" %>
<%@ page import="java.sql.*" %>
<html>
<head><title>ReadForm</title></head><body>
<p align="left">
<font size ="5"><b>選取品目</b></font>
</p>
<%
	String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
	String connectDB = "jdbc:ucanaccess:CloudShopping.accdb"

	Class.forName(JDriver);
	Connection con = DriverManager.getConnection(connectDB);
	Statement stmt = con.createStatement();
	
	request.setCharacterEncoding("utf-8");
	String sql = "SELECT * FROM Informations";
	
	boolean flag = false;
	session = request.getSession();
	if(session.getAttribute("Shopping") == "true") flag = true;
	
	if(stmt.execute(sql) && flag)
	{
		ResultSet rs = stmt.getResultSet();
		out.print("<form method=post action=12WriteForm.jsp>");
		%>
		<table border="1">
		<tr><td>勾選</td><td>編號</td>
		<td>品名</td><td>單價</td>
		</tr><%
		while(rs.next())
		{
			String indexStr = rs.getString("編號");
			String nameStr = rs.getString("品名");
			String priceStr = rs.getString("單價");
			
			out.print("<tr>");
			out.print("<td>");
			out.print("<input type = checkbox name = itemSelect " + "value = " + indexStr + ">");
			
			out.print("<tr>");
			out.print("<td>");
			out.print(indexStr);
			out.print("<tr>");
			out.print("<td>");
			out.print(nameStr);
			out.print("<tr>");
			out.print("<td>");
			out.print(priceStr);
			out.print("<tr>");
			out.print("<td>");
		}
		out.print("<table>");
		out.print("<input type = submit value ="\勾選物品\">");
	}
	stmt.close();
	con.close();
%>
</body>
</html>
