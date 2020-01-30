package jdbcannotation;

import org.apache.commons.dbcp.BasicDataSource;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.jdbc.core.JdbcTemplate;

@ComponentScan("jdbcannotation")
public class TestJdbcAnnotation {

	@Bean
	public JdbcTemplate createObj()
	{
		BasicDataSource b=new BasicDataSource();
		b.setUrl("jdbc:mysql://localhost:3306/employee");
		b.setUsername("root");
		b.setPassword("cdacacts");
		b.setDriverClassName("com.mysql.cj.jdbc.Driver");
		JdbcTemplate jtemp=new JdbcTemplate(b);
		return jtemp;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		AnnotationConfigApplicationContext ac=new AnnotationConfigApplicationContext(TestJdbcAnnotation.class);
		
		PresentationLayer plLayer=ac.getBean(PresentationLayer.class);
		plLayer.mainMenu();
		
	}

}
