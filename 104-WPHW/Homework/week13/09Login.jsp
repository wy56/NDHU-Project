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

  String sql = "SELECT * FROM RegistryClient WHERE 證號 = '" + numStr + "'AND 密碼 ='" + pwdStr + "';";

  ResultSet rs = stmt.executeQuery(sql);
  boolean flag = false;
  while(rs.next()) flag = true;
  if(flag){
      out.print("帳號密碼正確, 成功登入雲端!! <br>");
      session = request.getSession();
      session.setAttribute("Shopping", "true");
      session.setAttribute("Cart", numStr);

      out.print("<A HREF = ");
      out.print("'10Cart.jsp'");
      out.print(">領取購物車</A></p><p>);

  }
  else{
      out.print("帳號密碼有誤, 登入雲端失敗!!<br>");
      %>
      <a href = "01ShoppingPage.jsp" target = "_top">回首頁</a>
      <%
  }
  stmt.close();
  con.close();
%>
</body>
</html> 