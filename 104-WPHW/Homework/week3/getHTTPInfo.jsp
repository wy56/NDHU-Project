<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>
<%@page import="java.util.*"%>
<html>
	<head><title>取得請求標頭資訊</title></head>
	<body>
	
	<table border="1">
	<tr>
	<th>標頭名稱</th>
	<th>內容</th>
	
	
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
