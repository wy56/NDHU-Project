package DatabaseLib;
import java.sql.*;

public class DBworkBean
{
	private String DBname;
	private String SQLcmd;
	
	public void setDBname (String DBname)
	{
		this.DBname = DBname;
	}
	
	public void setSQLcmd(String SQLcmd)
	{
		this.SQLcmd = SQLcmd;
	}
	
	public String getResult()
	{
		String JDriver = "net.ucanaccess.jdbc.UcanaccessDriver";
		String connectDB="jdbc:ucanaccess://C:\\Program Files\\Apache Software Foundation\\Tomcat 8.0\\webapps\\example\\2015.11.06\\" + DBname + ".accdb";
		StringBuffer sb = new StringBuffer();
		
		try
		{
			Class.forName(JDriver);
			Connection con = DriverManager.getConnection(connectDB);
			
			Statement stmt = con.createStatement();
			
			if(stmt.execute(SQLcmd))
			{
				ResultSet rs = stmt.getResultSet();
				ResultSetMetaData md = rs.getMetaData();
				int colCount = md.getColumnCount();
				sb.append("<table cellspacing=10><tr>");
				for(int i=1; i<=colCount; i++)
					sb.append("<th>" + md.getColumnLabel(i));
				while(rs.next())
				{
					sb.append("<tr>");
					for(int i=1; i<=colCount; i++)
					{
						sb.append("<td>");
						Object obj = rs.getObject(i);
						if(obj!=null)
							sb.append(obj.toString());
						else 
							sb.append("&nbsp;");
					}
				}
				sb.append("</table>\n");
			}
			else
				sb.append("<b>Modifying works successfully</b>");
			
			stmt.close();
			con.close();
		}
		catch (Exception e){sb.append(e.getMessage());}
		return sb.toString();
	}
}