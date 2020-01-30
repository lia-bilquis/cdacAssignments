package JdbcWithSpringExp1;

import org.springframework.jdbc.core.JdbcTemplate;

public class DAO_Book 
{
	private JdbcTemplate jdbc_obj;

	public void setJdbc_obj(JdbcTemplate jdbc_obj) {
		
		this.jdbc_obj = jdbc_obj;
		System.out.println("wiring");
	}
	
	public boolean insertBook(Book obj)
	{
		String query_obj = "insert into Book(bk_id, bk_name, bk_price) values(?,?,?)";
		
		Object[] parameters = {obj.getBk_id(),obj.getBk_name(),obj.getBk_price()};
		int row_modified = jdbc_obj.update(query_obj,parameters);
		
		return row_modified > 0;
		
	}

	

}
