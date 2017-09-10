<?xml version="1.0" encoding="Big5" ?> 
<xsl:stylesheet 
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
    version="1.0"  >    
<xsl:template match="customers">

<html>
<head>
<title>�M��XSL�˦�</title>
</head>
<body>

  <table border="1" width="100%">
  <tr>
    <th>�s��</th>
    <th>�m�W</th>
    <th>�q��</th>
    <th>�q�l�l��</th>
  </tr>  
  
  <xsl:call-template name="funcustomer">
    <xsl:with-param name="customerelement" select="customer"  />
  </xsl:call-template>
  </table>

</body>
</html>

</xsl:template>

<xsl:template name="funcustomer">
    <xsl:param name="customerelement"/> 
    <xsl:for-each select="$customerelement"  >
    <tr>
        <td><xsl:value-of select="customerid" />    </td>
        <td><xsl:value-of select="customername" />     </td>
        <td><xsl:value-of select="tel" />     </td>    
        <td><xsl:value-of select="email" />     </td>    
    </tr>
    </xsl:for-each>
</xsl:template>



</xsl:stylesheet>
