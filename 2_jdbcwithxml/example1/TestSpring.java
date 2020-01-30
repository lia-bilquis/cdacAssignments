/**
 * 
 */
package springBasics;

import java.util.List;

import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * @author dac55
 * 
 */
public class TestSpring {

	/**
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		ClassPathXmlApplicationContext cpath = new ClassPathXmlApplicationContext(
				"springbasic.xml");
		DAO_Employee daoEmp = (DAO_Employee) cpath.getBean(DAO_Employee.class);
		boolean status = daoEmp.registerEmployee(new Employee(3, 3, 400));
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
		cpath.close();
	}

}