<%@page contentType="text/html"%>
<%@page pageEncoding="utf-8"%>
<%@page import="javax.xml.parsers.*"%>
<%@page import="org.w3c.dom.*"%>

<%@page import="javax.xml.transform.*"%>
<%@page import="javax.xml.transform.stream.*"%>
<%@page import="javax.xml.transform.dom.*"%>
<%@page import="java.io.*"%>

<html>
	<head><title>建立 XML</title></head>
	<body>
	<%
		DocumentBuilderFactory theDocumentBuilderFactory=
				DocumentBuilderFactory.newInstance();
		DocumentBuilder theDocumentBuilder =
				theDocumentBuilderFactory.newDocumentBuilder();
		DOMImplementation theDOMImplementation = 
	theDocumentBuilder.getDOMImplementation();
	
		Document theDocument= theDOMImplementation.createDocument(null,"customers",null);
		Element theElement = theDocument.getDocumentElement();
		//建立節點
		Element theElementcustomer = theDocument.createElementNS(null,"customer");
		Element theElementcustomerid =theDocument.createElementNS(null,"customerid");
		Element theElementcustomername =theDocument.createElementNS(null,"customername");
		Element theElementtel = theDocument.createElementNS(null,"tel");
		Element theElementemail =theDocument.createElementNS(null,"email");
		
		Node theNodeCustomerid =theDocument.createTextNode("9001");
		Node theNodeCustomername = theDocument.createTextNode("鄭中基");
		Node theNodetel = theDocument.createTextNode("02-87878888");
		Node theNodeemail= theDocument.createTextNode("michael@gmail.com");
		
		theElementcustomerid.appendChild(theNodeCustomerid);
		theElementcustomername.appendChild(theNodeCustomername);
		theElementtel.appendChild(theNodeemail);
		theElementemail.appendChild(theNodeemail);
		
		theElementcustomer.appendChild(theElementcustomerid);
		theElementcustomer.appendChild(theElementcustomername);
		theElementcustomer.appendChild(theElementtel);
		theElementcustomer.appendChild(theElementemail);
		
		theElement.appendChild(theElementcustomer);
		
	   TransformerFactory tff= TransformerFactory.newInstance();
	   Transformer theTransformer=tff.newTransformer();
	    theTransformer.setOutputProperty(OutputKeys.ENCODING,"Big5");
		
	   DOMSource theDOMSource = new DOMSource(theDocument);
	   File theFile = new File(request.getRealPath("/"+"2015.11.20//xmlFile//customers.xml"));
	   theFile.createNewFile();
	   StreamResult theStreamResult = new StreamResult(theFile);
	   theTransformer.transform(theDOMSource,theStreamResult);
	   
	   out.println("XML檔案建立完成   !!");
	%>
	</body>
</html>