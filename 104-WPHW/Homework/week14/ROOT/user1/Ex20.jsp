<%@ page contentType="text/html;charset=big5" %>
<html>
<head><title>Ex20</title></head><body>
<%
  request.setCharacterEncoding("big5");
  String[] val = request.getParameterValues("course");
  out.println("���w���ҥءG " + "<br>");
  for(int i=0; i<val.length; i++)
      out.println(val[i] + "<br>");
%>
</body>
</html>