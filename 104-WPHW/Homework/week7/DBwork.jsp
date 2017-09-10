<%@ page contentType="text/html;charset=big5" %>
<html>
<head><title>Database Work</title></head>
<body>
<p align="left">
<font size="5"><b>Sub Page of Database Work</b></font>
</p>
<jsp:useBean id="DBwork" scope="session" class="DatabaseLib.DBworkBean"/>
<%
	request.setCharacterEncoding("big5");
	String DBname = request.getParameter("DBname");
	String SQLcmd = request.getParameter("SQLcmd");
	
	DBwork.setDBname(DBname);
	DBwork.setSQLcmd(SQLcmd);
	out.print(DBwork.getResult());
%>
</body>
</html>
