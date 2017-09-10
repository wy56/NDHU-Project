<%@page contentType="text/html;charset=big5"%>
<html>
<head><title>EX97 Transaction Work</title>
</head>
<body>
<p align="left">
<font size="5"><b>Sub Page of EX97 Transaction Work</b></font>
</p>
<jsp:useBean id="TRwork97" scope="session" class="DatabaseLib.TRwork97Bean"/>

<%
  request.setCharacterEncoding("big5");
  String outNumberStr=request.getParameter("outNumber");
  String inNumberStr=request.getParameter("inNumber");
  String amountStr=request.getParameter("amount");
  
  String sql1=" UPDATE Deposit " + " SET tran_out= " + outNumberStr + " , " 
								 + " tran_in= " + inNumberStr + " , "
								 + " tran_amount= " + amountStr + " WHERE account_number=000 " + " ; ";		
  String sql2=" UPDATE Deposit " + " SET tran_amount=DLookup('tran_amount','Deposit', " + " 'account_number=000') " 
								 + " WHERE account_number=(SELECT tran_out " + " From Deposit " +"WHERE account_number=000) " ;
  String sql3=" UPDATE Deposit " + " SET tran_amount=DLookup('tran_amount','Deposit', " + " 'account_number=000') " 
								 + " WHERE account_number=(SELECT tran_in " + " From Deposit " + " WHERE account_number=000) " ;
  String sql4=" UPDATE Deposit " + " SET balance= balance-tran_amount " 
					             + " WHERE account_number=(SELECT tran_out " + " From Deposit " + " WHERE account_number=000) " ;
  String sql5=" UPDATE Deposit " + "SET balance= balance+tran_amount " 
                                 + " WHERE account_number=(SELECT tran_in " + " From Deposit " + " WHERE account_number=000) " ;
								 
  TRwork97.setSQLcmd(sql1,sql2,sql3,sql4,sql5);
  out.print(TRwork97.getResult());  
%>

</body>
</html>