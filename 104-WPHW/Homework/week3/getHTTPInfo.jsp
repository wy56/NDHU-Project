<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>
<%@page import="java.util.*"%>
<html>
	<head><title>���o�ШD���Y��T</title></head>
	<body>
	
	<table border="1">
	<tr>
	<th>���Y�W��</th>
	<th>���e</th>
	
	
	<%
		Enumeration headers=request.getHeaderNames();
		
		while(headers.hasMoreElements()){
			String name=(String)headers.nextElement();
			String content=request.getHeader(name);
			out.println("<tr><th>"+ name +"</th>");
			out.println("<td>" + content + "</td></tr>");
		}
	%>
	
	</table>
	</body>
	
</html>
