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
	 String nameStr = request.getParameter("name");
	 String addressStr = request.getParameter("address");
	 
	 String a = "INSERT INTO Students(准考證號碼, 姓名, 地址) ";
	 String b = " VALUES (";
	 String c = ",'";
	 String d = "','";
	 String e = "')";

	 String sql = a + b + numberStr + c + nameStr + d + addressStr + e ;

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