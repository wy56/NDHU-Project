<%@page contentType="text/html;charest=big5"%>
<%@page import= "java.sql.*"%>
<html>
<head><title>Ex46_1</b></font>
</p><p align="left">
<B>�ק�U�C���</B></p>
<%
Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
Connection con=DriverManager.getConnection("jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\example\\BookStore.accdb");

 Statement stmt = con.createStatement();
 
 request.setCharacterEncoding("big5");
 String Num = request.getParameter("num");
 
 String sql = "SELECT * FROM Books WHERE �s��= '" + Num + "';"; 
 
 stmt.execute(sql);
 ResultSet rs = stmt.getResultSet();
 ResultSetMetaData rsmd = rs.getMetaData();
 int colCount = rsmd.getColumnCount();
 
 rs.next();
 out.print("<FORM ACTION = Ex46_2.jsp" + "METHOD = post>");
 out.print("�s��: <INPUT TYPE=y\text NAME = num_1"+ "VALUE=" + Num +"><BR>");
 out.print("�ѦW: <INPUT TYPE=y\text NAME = name_1"+ "VALUE=" + rs.getString(" �ѦW ") +"><BR>");
 out.print("�@��: <INPUT TYPE=y\text NAME = author_1"+ "VALUE=" + rs.getString(" �@�� ") +"><BR>");
 out.print("�ѻ�: <INPUT TYPE=y\text NAME = price_1"+ "VALUE=" + rs.getString(" �ѻ� ") +"><BR>");
 out.print("<INPUT TYPE=submit VALUE=\"���e\">");
 out.print("<INPUT TYPE=reset VALUE+\"����\">");
 
 stmt.close();
  con.close();
%>
</body>
</html>