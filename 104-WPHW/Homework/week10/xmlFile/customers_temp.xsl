<?xml version="1.0" encoding="Big5" ?> 
<xsl:stylesheet 
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
    version="1.0"  >    
<xsl:template match="customers">

<html>
<head>
<title>套用XSL樣式</title>
</head>
<body>

  <table border="1" width="100%">
  <tr>
    <th>編號</th>
    <th>姓名</th>
    <th>電話</th>
    <th>電子郵件</th>
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
