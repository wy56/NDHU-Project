<%@ page contentType = "text/html;charset = utf-8" %>
<%@ page import = "java.sql.*" %>
<html>
<head><title>Login</title></head><body>
<p align = "left">
<%
  String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
  String connectDB ="jdbc:ucanaccess://CloudShopping.accdb";

  Class.forName(JDriver);
  Connection con = DriverManager.getConnection(connectDB);
  Statement stmt = con.createStatement();

  request.setCharacterEncoding("utf-8");
  String numStr = request.getParameter("ID");
  String pwdStr = request.getParameter("pwd");

  String sql = "SELECT * FROM RegistryClient WHERE �Ҹ� = '" + numStr + "'AND �K�X ='" + pwdStr + "';";

  ResultSet rs = stmt.executeQuery(sql);
  boolean flag = false;
  while(rs.next()) flag = true;
  if(flag){
      out.print("�b���K�X���T, ���\�n�J����!! <br>");
      session = request.getSession();
      session.setAttribute("Shopping", "true");
      session.setAttribute("Cart", numStr);

      out.print("<A HREF = ");
      out.print("'10Cart.jsp'");
      out.print(">����ʪ���</A></p><p>);

  }
  else{
      out.print("�b���K�X���~, �n�J���ݥ���!!<br>");
      %>
      <a href = "01ShoppingPage.jsp" target = "_top">�^����</a>
      <%
  }
  stmt.close();
  con.close();
%>
</body>
</html> 