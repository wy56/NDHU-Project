<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>

<html>
	<head><title>�]�w session ���</title></head>
	<body>
		
		<%
			session.setAttribute("idvalue","WeiYu");
			session.setAttribute("sex", "Computer Security");
			session.setAttribute("hobby", "LOL");
		%>
		
		<a href="usingSession.jsp"> ��ܤw�]�w�� session ��Ƥ��e </a>
		
	</body>
	
</html>
