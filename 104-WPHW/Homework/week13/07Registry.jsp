<%@ page contentType= "text/html;charset=big5" %>
<%@ page import= "java.sql.*" %>
<html>
<head><title>Registry</title></head><body>
<p align="left">
<%
  String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
  String connectDB="jdbc:ucanaccess:CloudShopping.accdb";

  Class.forName(JDriver);
  Connection con = DriverManager.getConnection(connectDB);
  Statement stmt = con.createStatement();

  request.setCharacterEncoding("big5");
  String numStr = request.getParameter("ID");
  String nameStr = request.getParameter("name");
  String pwdStr = request.getParameter("pwd");
  String addrStr = request.getParameter("addr");
  String telStr = request.getParameter("tel");

  String sql1= "INSERT INTO RegistryClient(����,�W��,�K�X,�a�},�q��)" +
               " VALUES('" + numStr + "','" + nameStr + "','" +
                 pwdStr + "','" + addrStr + "','" + telStr + "')";
  stmt.executeUpdate(sql1);

  out.print("�w���\�������U!! <br>");

  stmt.close();
  con.close();
%>
</body>
</html>