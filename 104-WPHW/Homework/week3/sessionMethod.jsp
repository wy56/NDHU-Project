<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>

<html>
	<head><title>引用 session 方法</title></head>
	<body>
		
		<table>
			<tr><th align = "left"> session 的建立時間 </th>
				<td><%=session.getCreationTime()%></td></tr>
			<tr><th align = "left"> session 的識別字串 </th>
				<td><%=session.getId()%></td></tr>
			<tr><th align = "left"> session 最後被請求的時間 </th>
				<td><%=session.getLastAccessedTime()%></td></tr>
            <tr><th align = "left"> session 預設結束得時間 </th>
				<td><%=session.getMaxInactiveInterval()%></td></tr>	</body>
	        <tr><th align = "left"> 是否為新建的 session  </th>
				<td><%=session.isNew()%></td></tr>
		</table>
		
	</body>
	
</html>
