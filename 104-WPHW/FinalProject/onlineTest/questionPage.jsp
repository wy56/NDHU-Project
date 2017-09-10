<!--testPage.html-->
<%@page contentType = "text/html; charset=utf-8"%>
<%@page import="java.sql.*"%>
<%@page import="java.io.*"%>
<HTML lang ="en">
	<HEAD>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<!-- 最新編譯和最佳化的 CSS -->
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.1/css/bootstrap.min.css">
		<!-- 選擇性佈景主題 -->
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.1/css/bootstrap-theme.min.css">
		<!-- 最新編譯和最佳化的 JavaScript -->
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.1/js/bootstrap.min.js"></script>
	
		<TITLE>Welcome to testPage</TITLE>
	</HEAD>
<BODY>
<br><br>
<%

	Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
	Connection con = DriverManager.getConnection("jdbc:ucanaccess://D:\\Programs\\Java\\Apache Software Foundation\\Tomcat 7.0\\webapps\\ROOT\\yale918.github.io\\finalProject\\onlineTest\\onlineTest.accdb");
	Statement stmt = con.createStatement();
	StringBuffer sb = new StringBuffer();
	request.setCharacterEncoding("utf-8");
	int no = (int)(Math.random()*5+1) ;
	String description ="";
	String sql = "select * from questionTable where number = "+no+" ;" ;
	//String sql = "select * from questionTable where number = 3" ;

	if (stmt.execute(sql)){
		ResultSet rs = stmt.getResultSet();
		//ResultSetMetaData md = rs.getMetaData();
		//int colCount = md.getColumnCount();

		/*取出題目*/
		if (rs.next()){
			description = rs.getString("description");
		}
		
	}
	else
		sb.append("錯了唷!");
	
	
	//out.print("<div style=\'border:0px #ccc solid;font-family:微軟正黑體;width:420px;align:center\'  > " + "第" + no + "題: " +description+"</div>");
	
	//大框
	out.print("<div style=\'margin:0 auto;width:405;border-style: solid;border-width:3px;\'>");
	//上框
	out.print("<div  style=\'margin:0 auto;width:400px;height:50px;text-align:center;background-color:#FF8800;\' ><span style=\'font-size:30px;\'> " + "第" + no + "題</span></div>");
	//下框
	out.print("<div align = \'center\' style=\'margin:0 auto;width:400px;height:250px;background-color:#FFFFFF;\'>");
	//字
	out.print("<div style=\'margin-top:20px;text-align:center;width:350px;height:200px;background-color:‪#FF3333;\' ><span style=\'font-size:25px;\'>"+description+"</span></div>");
	out.print("</div>");
	out.print("</div>");
	
	
	
	//進度：調整div置中
	
	
	
	stmt.close();
	con.close();
%>
<br><br>
<div align = "center">
<form action="questionPage.jsp" method ="post">
<input type = "radio" name="choice" value= "A">A
<input type = "radio" name="choice" value= "B">B
<input type = "radio" name="choice" value= "C">C
<input type = "radio" name="choice" value= "D">D
<br>
<input type = "submit" value = "選擇">
</form>
</div>
</BODY>
</HTML>