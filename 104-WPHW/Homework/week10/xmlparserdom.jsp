<%@page contentType="text/html"%>
<%@page pageEncoding="Big5"%>
<%@page import="javax.xml.parsers.*"%>
<%@page import="org.w3c.dom.*"%>

<html>
	<head><title>��R XML </title></head>
	<body>
	<%
	
		DocumentBuilderFactory theDocumentBuilderFactory=
				DocumentBuilderFactory.newInstance();
		DocumentBuilder theDocumentBuilder =
				theDocumentBuilderFactory.newDocumentBuilder();
				Document theDocument =
		theDocumentBuilder.parse(request.getRealPath("/"+"2015.11.20//xmlFile//customers.xml"));
		
				Element theParentElement = theDocument.getDocumentElement();
				NodeList theNodeList =theParentElement.getElementsByTagName("customer");
				
				for(int i=0;i<theNodeList.getLength();i++){
					Element theChildElement = (Element)theNodeList.item(i);
					NodeList theChildNodeList   =null;
					String outString="";
					//
					theChildNodeList=theChildElement.getElementsByTagName("customerid");
					outString = (theChildNodeList.item(0)).getFirstChild().getNodeValue();
					out.println("�s�� :"+outString+"<br>") ;
					//
					theChildNodeList=theChildElement.getElementsByTagName("customername");
					outString = (theChildNodeList.item(0)).getFirstChild().getNodeValue();
					out.println("�m�W :"+outString+"<br>") ;
					//
					theChildNodeList=theChildElement.getElementsByTagName("tel");
					outString = (theChildNodeList.item(0)).getFirstChild().getNodeValue();
					out.println("�q�� :"+outString+"<br>") ;
					//
					theChildNodeList=theChildElement.getElementsByTagName("email");
					outString = (theChildNodeList.item   (0)).getFirstChild().getNodeValue();
					out.println("�q�l�l�� :"+outString+"<br>") ;
					out.println("========================================<br>");
				}
	%>
	</body>
</html>
