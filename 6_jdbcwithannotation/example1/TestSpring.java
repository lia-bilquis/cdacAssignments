/**
 * 
 */
package dao_annotation;

import java.util.List;
import java.util.MissingResourceException;
import java.util.ResourceBundle;

import org.apache.commons.dbcp.BasicDataSource;
import org.apache.log4j.Logger;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.jdbc.core.JdbcTemplate;

/**
 * @author dac55
 * 
 */
@ComponentScan("dao_annotation")
public class TestSpring {
	private static final Logger log = Logger.getLogger(TestSpring.class);

	@Bean
	public JdbcTemplate createTemplateInstance() {
		BasicDataSource bds = new BasicDataSource();
		ResourceBundle rs = ResourceBundle.getBundle("dbconfig");
		try {
			bds.setUsername(rs.getString("username"));
			bds.setUrl(rs.getString("url"));
			bds.setPassword(rs.getString("password"));// password
			bds.setDriverClassName(rs.getString("driverClassName"));
		} catch (MissingResourceException e) {
			log.fatal(e, e);
			System.out.println("Connection failed!");
		}
		JdbcTemplate jd = new JdbcTemplate(bds);
		System.out.println("JDBC Template created");
		return jd;
	}

	/**
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		AnnotationConfigApplicationContext anno = new AnnotationConfigApplicationContext(TestSpring.class);
		DAO_Employee daoEmp = anno.getBean(DAO_Employee.class);
		boolean status = daoEmp.registerEmployee(new Employee(45, 50, 6000));
		if (status) {
			System.out.println("Insert successful!");
		} else {
			System.out.println("Insert failed!");
		}
		List<Employee> emplist = daoEmp.getEmployeeBySalaryGt(20);
		StringBuilder Sbuilder = new StringBuilder();
		for (Employee empRow : emplist) {
			Sbuilder.append("\n");
			Sbuilder.append(empRow);
		}
		System.out.println(Sbuilder.toString());
		anno.close();
	}

}