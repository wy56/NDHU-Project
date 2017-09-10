<%@ page contentType="text/html;charset=big5" %>
<%@ page import="java.sql.*" %>
<html>
<head><title>M_AuthorityEx</title></head><body>
<p align="left">
<font size="5"><b>管理員選項操作</b></font></p><p>
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

  String sql="SELECT* FROM Managers WHERE 姓名='"+
                      user+"'AND 密碼='"+pwd+"';";
  
  ResultSet rs=stmt.executeQuery(sql);
  boolean flag=false;

  while(rs.next()) flag=true;
  if(flag){
	out.print("本頁為經過認證之合法網頁!!");
	out.print("</p><p>  </p><p>");
	out.print("<A HREF=");
	out.print("'InsertStudent.html'");
	out.print("TARGET=");
	out.print("'MidEx_2'");
	out.print(">考生基本資料輸入</A></p><p>");

	out.print("<A HREF=");
	out.print("'InsertScore.html'");
	out.print("TARGET=");
	out.print("'MidEx_2'");
	out.print(">考生成績輸入</A></p>");
  }
  else{
	out.print("<p><A HREF=");
	out.print("'ExPage.jsp'");
	out.print("TARGET=");
	out.print("'_top'");
	out.print(">因帳號密碼有誤!!請按此回首頁</A></p>");
  }
  stmt.close();
  con.close();
%>
</body>
</html>