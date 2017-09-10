<%@ page contentType="text/html;charset=big5" %>
<%@ page import= "java.sql.*" %>
<html>
<head><title>Ex46_1</title></head><body>
<p align="center">
<font size="5"><b>Sub Page of Ex46_1</b></font>
</p><p align="left">
<B>修改下列資料</B></p>
<%
      String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
      String connectDB="jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\ROOT\\20151127\\Ex1\\Book09.accdb";

  Class.forName(JDriver);
  Connection con = DriverManager.getConnection(connectDB);
  Statement stmt = con.createStatement();

  request.setCharacterEncoding("big5");
  String Num = request.getParameter("num");

  String sql="SELECT *  FROM Books WHERE 編號='" +
                     Num + "';" ;

  ResultSet rs= stmt.executeQuery(sql);
  ResultSetMetaData rsmd = rs.getMetaData();
  int colCount = rsmd.getColumnCount();

  rs.next();
  out.print("<FORM ACTION=Ex46_2.jsp " +
                  "METHOD=post>");
  out.print("編號：<INPUT TYPE=text NAME= num_1 " +
                             "VALUE=" + Num + "><BR>");
  out.print("書名：<INPUT TYPE=text NAME= name_1 " +
                             "VALUE=" + rs.getString("書名") + "><BR>");
  out.print("作者：<INPUT TYPE=text NAME= author_1 " +
                             "VALUE=" + rs.getString("作者") + "><BR>");
  out.print("書價：<INPUT TYPE=text NAME= price_1 " +
                             "VALUE=" + rs.getString("書價") + "> <BR><BR>");
  out.print("<INPUT TYPE=submit VALUE=\"遞送\">");
  out.print("<INPUT TYPE=reset VALUE=\"取消\">");

  stmt.close();
  con.close();
%>
</body>
</html>