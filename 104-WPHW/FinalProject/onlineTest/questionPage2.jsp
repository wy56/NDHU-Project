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

<%

	Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
	Connection con = DriverManager.getConnection("jdbc:ucanaccess://C:\\Myprograms\\Java\\Tomcat7\\webapps\\ROOT\\yale918.github.io\\finalProject\\onlineTest\\onlineTest.accdb");
	Statement stmt = con.createStatement();
	StringBuffer sb = new StringBuffer();
	request.setCharacterEncoding("utf-8");
	int no = (int)(Math.random()*5+1) ;
	String description ="";
	//String sql = "select * from questionTable where no = 1 ;" ;
	String sql = "select * from questionTable ;" ;
	//out.print("hi");
	if (stmt.execute(sql)){
		ResultSet rs = stmt.getResultSet();
		//ResultSetMetaData md = rs.getMetaData();
		//int colCount = md.getColumnCount();
		
		/*取出題目*/
		if (rs.next()){  
			description = rs.getString("description");  
			//out.print(description);
		}
	}
	else
		sb.append("錯了唷!");
	
	
	out.print("第" + no + "題: " +description);
	
	
	
	
	
	
	
	
	
	
	
	
	stmt.close();
	con.close();
%>
</BODY>
</HTML>