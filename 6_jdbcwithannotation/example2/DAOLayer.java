package jdbcannotation;

import org.apache.commons.dbcp.BasicDataSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

@Component
public class DAOLayer {
	private JdbcTemplate jt;

	@Autowired
	public void setJt(JdbcTemplate jt) {
		this.jt = jt;
	}

	public JdbcTemplate getJt() {
		return jt;
	}
	
}
