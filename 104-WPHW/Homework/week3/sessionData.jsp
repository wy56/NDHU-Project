<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>

<html>
	<head><title>設定 session 資料</title></head>
	<body>
		
		<%
			session.setAttribute("idvalue","WeiYu");
			session.setAttribute("sex", "Computer Security");
			session.setAttribute("hobby", "LOL");
		%>
		
		<a href="usingSession.jsp"> 顯示已設定之 session 資料內容 </a>
		
	</body>
	
</html>
