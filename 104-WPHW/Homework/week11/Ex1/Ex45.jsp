<%@ page contentType="text/html;charset=big5" %>
<%@ page import= "java.sql.*" %>
<html>
<head><title>Ex45</title></head><body>
<p align="center">
<font size="5"><b>Sub Page of Ex45</b></font>
</p>
<%
      String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
      String connectDB="jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\ROOT\\20151127\\Ex1\\Book09.accdb";

  Class.forName(JDriver);
  Connection con = DriverManager.getConnection(connectDB);
  Statement stmt = con.createStatement();

  request.setCharacterEncoding("big5");
  String Num = request.getParameter("num");
  String Name = request.getParameter("name");
  String Author = request.getParameter("author");
  String Price = request.getParameter("price");

  String sql="INSERT INTO Books(編號,書名," +
                "作者,書價) VALUES ('" +
                Num + "','" + Name + "','" +
                Author + "'," + Price + ")" ;
                      
  stmt.executeUpdate(sql);
  stmt.close();
  con.close();
%>
<center>
成功完成新增資料輸入
</body>
</html>