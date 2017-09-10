<%@page contentType="text/html;charest=big5"%>
<%@page import= "java.sql.*"%>
<html>
<head><title>Ex46_1</b></font>
</p><p align="left">
<B>修改下列資料</B></p>
<%
Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
Connection con=DriverManager.getConnection("jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\example\\BookStore.accdb");

 Statement stmt = con.createStatement();
 
 request.setCharacterEncoding("big5");
 String Num = request.getParameter("num");
 
 String sql = "SELECT * FROM Books WHERE 編號= '" + Num + "';"; 
 
 stmt.execute(sql);
 ResultSet rs = stmt.getResultSet();
 ResultSetMetaData rsmd = rs.getMetaData();
 int colCount = rsmd.getColumnCount();
 
 rs.next();
 out.print("<FORM ACTION = Ex46_2.jsp" + "METHOD = post>");
 out.print("編號: <INPUT TYPE=y\text NAME = num_1"+ "VALUE=" + Num +"><BR>");
 out.print("書名: <INPUT TYPE=y\text NAME = name_1"+ "VALUE=" + rs.getString(" 書名 ") +"><BR>");
 out.print("作者: <INPUT TYPE=y\text NAME = author_1"+ "VALUE=" + rs.getString(" 作者 ") +"><BR>");
 out.print("書價: <INPUT TYPE=y\text NAME = price_1"+ "VALUE=" + rs.getString(" 書價 ") +"><BR>");
 out.print("<INPUT TYPE=submit VALUE=\"遞送\">");
 out.print("<INPUT TYPE=reset VALUE+\"取消\">");
 
 stmt.close();
  con.close();
%>
</body>
</html>