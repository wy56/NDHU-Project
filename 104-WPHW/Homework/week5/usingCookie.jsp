<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>
<html>
<head><title>¹B¥Î Cookie</title></head>
<body>
<%
String strname = request.getParameter("name");
String strsex = request.getParameter("sex");
String strcolor = request.getParameter("color");

Cookie nameCookie = new Cookie("name", strname);
Cookie sexCookie = new Cookie("sex", strsex);
Cookie colorCookie = new Cookie("color", strcolor);

response.addCookie(nameCookie);
response.addCookie(sexCookie);
response.addCookie(colorCookie);

out.println("OK..<p>");
%>
</body>
</html>
