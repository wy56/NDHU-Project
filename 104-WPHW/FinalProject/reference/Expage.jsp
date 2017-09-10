<!-- Expage.jsp-->

<%@ page contentType="text/html;charset=utf-8" %>
<HTML>
<HEAD>
<TITLE>Front Page of ExamPage</TITLE>
</HEAD>
<FRAMESET ROWS = "20%, 70%, 10%">
	<FRAME NAME= "TopEx" SRC= "TopEx.jsp">
	<FRAMESET COLS="20%,*">
		<FRAME NAME= "MidEx_1" SRC="MidEx_1.jsp">
		<FRAME NAME= "MidEx_2" SRC="MidEx_2.jsp">
	</FRAMESET>
	<FRAME NAME= "Bottom" SRC="BottomEx.jsp">
</FRAMESET>
</HTML>


