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
  
  String a = "INSERT INTO Scores(����Ҹ��X, ���, �^��, �ƾ�, �۵M, ���|)";
  String b = " VALUES (";
  String c = ", ";
  String e = ")";

  String sql = a + b + numberStr + c + cnsStr + c + engStr + c + mathStr + c + techStr + c + peopStr + e ;

  session =request.getSession();
  if(session.getAttribute("Exam") == "true")
	 {
		out.print("�������g�L�{�Ҥ��X�k��Ʈw��J����!!" + "<br>" );
		stmt.executeUpdate(sql);
		stmt.close();
		con.close();
		out.print("<left><p> </p><p>");
		out.print("���\�����ҥ͸�ƿ�J </p>");
	 }
	 else
	 {
		 out.print("<p><A HREF= ");
		 out.print("'ExPage.jsp'");
		 out.print("TARGET=");
		 out.print("'_top'");
		 out.print(">�]�������D�X�k����!!�Ы����^����</A></p>");
	 }
%>
</body>
</html>