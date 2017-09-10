<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>

<html>
	<head><title>讀取 session 值</title></head>
	<body>
		
		<%
			Object id=session.getAttribute("idvalue");
			Object sex=session.getAttribute("sex");
			Object hobby=session.getAttribute("hobby");
		
			if(id!=null){
				out.println("Name:" + id.toString());
				out.println("<br>");
				out.println("Sex:" + sex.toString());
				out.println("<br>");
				out.println("Hobby:" + hobby.toString());
				out.println("<br>");
			}
			else{
				out.println("無設定 session 資料");
			}
			
		%>
	</body>
	
</html>
