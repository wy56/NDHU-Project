<%@ page contentType="text/html;charset=big5" %>
<%@ page import= "java.sql.*" %>
<html>
<head><title>Ex46_2</title></head><body>
<p align="center">
<font size="5"><b>Sub Page of Ex46_2</b></font>
</p>
<%
      String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
      String connectDB="jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\ROOT\\20151127\\Ex1\\Book09.accdb";

  Class.forName(JDriver);
  Connection con = DriverManager.getConnection(connectDB);
  Statement stmt = con.createStatement();

  request.setCharacterEncoding("big5");
  String Num_2 = request.getParameter("num_1");
  String Name_2 = request.getParameter("name_1");
  String Author_2 = request.getParameter("author_1");
  String Price_2 = request.getParameter("price_1");

  String sql="UPDATE Books SET " +
                       "�s��='" + Num_2 +
                       "', �ѦW='" + Name_2 +
                       "', �@��='" + Author_2 +
                       "', �ѻ�=" + Price_2 +
                       " WHERE �s��='" + Num_2 + "';" ;
                      
  stmt.executeUpdate(sql);
  stmt.close();
  con.close();
%>
<center>
���\�ק���
</body>
</html>