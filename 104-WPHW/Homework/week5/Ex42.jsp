<%@ page contentType = "text/html;charset=big5" %>
<html>
<head><title>Ex42</title></head><body>
<p align = "left">
<font size= "5"><b>Sub Page of Ex42</b></font>
</p>
<%
   request.setCharacterEncoding("big5");
   String Name = request.getParameter("name");
   int Price= Integer.parseInt(request.getParameter("price"));
   int Number = Integer.parseInt(request.getParameter("number"));
%>
<jsp:useBean id="beanID" scope="session" class="beanLib.valueBean" />
<%
   beanID.setPrice(Price);
   beanID.setNumber(Number);
   
   out.print(Name + "單價: " + beanID.getPrice() + "<br>");
   out.print(Name + "數量: " + beanID.getNumber() + "<br>");
   out.print(Name + "總價: " + beanID.gettotalValue());
%>
</body>
</html>