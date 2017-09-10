<?xml version="1.0" encoding="Big5" ?> 

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"  >
<xsl:template match="customers">

<html>
<head>
<title>套用XSL樣式</title>
</head>
<body>

  <table border="1" width="100%">
  <tr>
    <td>編號</td>
    <td>姓名</td>
    <td>電話</td>
    <td>電子郵件</td>
  </tr>
  <xsl:apply-templates  />
  </table>

</body>
</html>

</xsl:template>

<xsl:template match="customer">
<tr>
    <xsl:apply-templates  />
</tr>
</xsl:template >

<xsl:template match="customerid">
<td>
    <xsl:apply-templates  />
</td>
</xsl:template >

<xsl:template match="customername">
<td>
    <xsl:apply-templates  />
</td>
</xsl:template >

<xsl:template match="tel">
<td>
    <xsl:apply-templates  />
</td>
</xsl:template >

<xsl:template match="email">
<td>
    <xsl:apply-templates  />
</td>
</xsl:template >


</xsl:stylesheet>