<%@ page contentType="text/html;charset=big5" %>
<%@ page import="java.sql.*" %>
<html>
<head><title>InsertStudent</title></head><body>
<%
   String JDriver="net.ucanaccess.jdbc.UcanaccessDriver";
	 String connectDB="jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\example\\2015.11.27\\Exam.accdb";

	 Class.forName(JDriver);
	 Connection con = DriverManager.getConnection(connectDB);
	 Statement stmt = con.createStatement();

	 request.setCharacterEncoding("big5");
  String numberStr = request.getParameter("num");
  String cnsStr = request.getParameter("cns");
  String engStr = request.getParameter("eng");
  String mathStr = request.getParameter("math");
  String techStr = request.getParameter("tech");
  String peopStr = request.getParameter("peop");
  
  String a = "INSERT INTO Scores(准考證號碼, 國文, 英文, 數學, 自然, 社會)";
  String b = " VALUES (";
  String c = ", ";
  String e = ")";

  String sql = a + b + numberStr + c + cnsStr + c + engStr + c + mathStr + c + techStr + c + peopStr + e ;

  session =request.getSession();
  if(session.getAttribute("Exam") == "true")
	 {
		out.print("本頁為經過認證之合法資料庫輸入網頁!!" + "<br>" );
		stmt.executeUpdate(sql);
		stmt.close();
		con.close();
		out.print("<left><p> </p><p>");
		out.print("成功完成考生資料輸入 </p>");
	 }
	 else
	 {
		 out.print("<p><A HREF= ");
		 out.print("'ExPage.jsp'");
		 out.print("TARGET=");
		 out.print("'_top'");
		 out.print(">因本頁為非合法網頁!!請按此回首頁</A></p>");
	 }
%>
</body>
</html>