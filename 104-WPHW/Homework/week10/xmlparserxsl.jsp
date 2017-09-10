<%@ page contentType="text/html" %>
<%@ page pageEncoding="utf-8" %> 
<%@ page import="javax.xml.pasers.*" %>
<%@ page import="org.w3c.dom.*" %>

<%@ page import="javax.xml.transform.*" %>
<%@ page import="javax.xml.transform.stream.*" %>
<%@ page import="javax.xml.transform.dom.*" %>

<%@ page import="java.io.*" %>

<html>
	<head><title>格式化 XML-套用 XSL 樣式表</title></head>
	<body>
	<%
		File theXMLFile = new File(request.getRealPath("/"+"2015.11.20//xmlFile//customers.xml"));
		StreamSource theXMStreamSourcee = new StreamSource(theXMLFile);
		File theXSLFile = new File(request.getRealPath("/"+"2015.11.20//xmlFile//customers.xsl"));
		StreamSource theXSLStreamSource = new StreamSource(theXSLFile);
		
		TransformerFactory tff = TransformerFactory.newInstance();
		Transformer theTransformer = tff.newTransformer(theXSLStreamSource);
		StreamResult theStreamResult = new StreamResult(out);
		
		theTransformer.transform(theXMStreamSourcee, theStreamResult);
	%>
	</body>
</html>