<%@ page contentType="text/html;charset=big5" %>
<%@ page import="java.sql.*" %>
<html>
<head><title>M_AuthorityEx</title></head><body>
<p align="left">
<font size="5"><b>�޲z���ﶵ�ާ@</b></font></p><p>
<%
  session=request.getSession();
  session.setAttribute("Exam","true");
  
  String JDriver="net.ucanaccess.jdbc.UcanaccessDriver";
  String connectDB="jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\example\\2015.11.27\\Exam.accdb";

  Class.forName(JDriver);
  Connection con=DriverManager.getConnection(connectDB);
  Statement stmt=con.createStatement();
  
  request.setCharacterEncoding("big5");
  String user=request.getParameter("user");
  String pwd=request.getParameter("pwd");

  String sql="SELECT* FROM Managers WHERE �m�W='"+
                      user+"'AND �K�X='"+pwd+"';";
  
  ResultSet rs=stmt.executeQuery(sql);
  boolean flag=false;

  while(rs.next()) flag=true;
  if(flag){
	out.print("�������g�L�{�Ҥ��X�k����!!");
	out.print("</p><p>  </p><p>");
	out.print("<A HREF=");
	out.print("'InsertStudent.html'");
	out.print("TARGET=");
	out.print("'MidEx_2'");
	out.print(">�ҥͰ򥻸�ƿ�J</A></p><p>");

	out.print("<A HREF=");
	out.print("'InsertScore.html'");
	out.print("TARGET=");
	out.print("'MidEx_2'");
	out.print(">�ҥͦ��Z��J</A></p>");
  }
  else{
	out.print("<p><A HREF=");
	out.print("'ExPage.jsp'");
	out.print("TARGET=");
	out.print("'_top'");
	out.print(">�]�b���K�X���~!!�Ы����^����</A></p>");
  }
  stmt.close();
  con.close();
%>
</body>
</html>