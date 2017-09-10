<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>

<html>
	<head><title>取得系統資訊</title></head>
	<body>
		<b>通訊協定                   </b><%=request.getProtocol()%><br>
		<b>客戶端位址                 </b><%=request.getRemoteAddr()%><br>
		<b>客戶端主機名稱             </b><%=request.getRemoteHost()%><br>
		<b>請求的方式                 </b><%=request.getScheme()%><br>
		<b>伺服端主機名稱             </b><%=request.getServerName()%><br>
		<b>伺服器主機 Port 號碼       </b><%=request.getServerPort()%><br>
		<b>虛擬目錄的真實路徑         </b><%=request.getRealPath("")%><br>
		<b>傳送資料的方式              </b><%=request.getMethod()%><br>
		<b>網址列後的字串資料          </b><%=request.getQueryString()%><br>
		<b>URI 字串                     </b><%=request.getRequestURI()%><br>
		<b>程式的相對路徑與檔名        </b><%=request.getServletPath()%><br>
	</body>
	
</html>
