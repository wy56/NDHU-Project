<%@ page contentType="text/html;charset=big5" %>
<%@ page import= "java.sql.*" %>
<html>
<head><title>Ex46_1</title></head><body>
<p align="center">
<font size="5"><b>Sub Page of Ex46_1</b></font>
</p><p align="left">
<B>�ק�U�C���</B></p>
<%
      String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
      String connectDB="jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\ROOT\\20151127\\Ex1\\Book09.accdb";

  Class.forName(JDriver);
  Connection con = DriverManager.getConnection(connectDB);
  Statement stmt = con.createStatement();

  request.setCharacterEncoding("big5");
  String Num = request.getParameter("num");

  String sql="SELECT *  FROM Books WHERE �s��='" +
                     Num + "';" ;

  ResultSet rs= stmt.executeQuery(sql);
  ResultSetMetaData rsmd = rs.getMetaData();
  int colCount = rsmd.getColumnCount();

  rs.next();
  out.print("<FORM ACTION=Ex46_2.jsp " +
                  "METHOD=post>");
  out.print("�s���G<INPUT TYPE=text NAME= num_1 " +
                             "VALUE=" + Num + "><BR>");
  out.print("�ѦW�G<INPUT TYPE=text NAME= name_1 " +
                             "VALUE=" + rs.getString("�ѦW") + "><BR>");
  out.print("�@�̡G<INPUT TYPE=text NAME= author_1 " +
                             "VALUE=" + rs.getString("�@��") + "><BR>");
  out.print("�ѻ��G<INPUT TYPE=text NAME= price_1 " +
                             "VALUE=" + rs.getString("�ѻ�") + "> <BR><BR>");
  out.print("<INPUT TYPE=submit VALUE=\"���e\">");
  out.print("<INPUT TYPE=reset VALUE=\"����\">");

  stmt.close();
  con.close();
%>
</body>
</html>