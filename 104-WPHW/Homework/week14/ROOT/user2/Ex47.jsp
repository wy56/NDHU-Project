<%@ page contentType="text/html;charset=big5" %>
<%@ page import= "java.sql.*" %>
<html>
<head><title>Ex47</title></head><body>
<p align="center">
<font size="5"><b>Sub Page of Ex47</b></font>
</p>
<%
Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
Connection con=DriverManager.getConnection("jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\ROOT\\20151225\\user2\\BookStore.accdb");

  Statement stmt = con.createStatement();

  request.setCharacterEncoding("big5");
  String Num = request.getParameter("num");

  String sql="DELETE FROM Books WHERE �s��='" +
                      Num + "';" ;
                      
  stmt.execute(sql);
  stmt.close();
  con.close();
%>
<center>
���\�R�����w�浧���
</body>
</html>