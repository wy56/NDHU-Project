<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>
<html>
<head><title>���o Cookie ���</title></head>
<body>
<%
Cookie cookies[] = request.getCookies();
int count = cookies.length;
String name="",sex="",color="";

for(int i=0;i<count;i++)
	if(cookies[i].getName().equals("name"))
		name=cookies[i].getValue();
	else if(cookies[i].getName().equals("sex"))
		sex=cookies[i].getValue();
	else if(cookies[i].getName().equals("color"))
		color=cookies[i].getValue();
%>
<font color="<%=color%>"size="5"><%=name%></font>
�z�n�A�H�U�O�z���ӤH���...<p>
<%
out.println("�ʧO:<br>");
if(sex.equals("M"))
out.println("�ڬO�k��..<br>");
if(sex.equals("F"))
out.println("�ڬO�k��..<br>");
%>
</body>
</html>