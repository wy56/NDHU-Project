<%@ page contentType="text/html;charset=big5" %>
<%@ page import= "java.sql.*" %>
<html>
<head><title>Ex47</title></head><body>
<p align="center">
<font size="5"><b>Sub Page of Ex47</b></font>
</p>
<%
      String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
      String connectDB="jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\ROOT\\20151127\\Ex1\\Book09.accdb";

  Class.forName(JDriver);
  Connection con = DriverManager.getConnection(connectDB);
  Statement stmt = con.createStatement();

  request.setCharacterEncoding("big5");
  String Num = request.getParameter("num");

  String sql="DELETE FROM Books WHERE 編號='" +
                      Num + "';" ;
                      
  stmt.execute(sql);
  stmt.close();
  con.close();
%>
<center>
成功刪除指定單筆資料
</body>
</html>