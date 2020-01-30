package java_basics;

import java.sql.SQLException;
import java.util.ArrayList;

public class Basics01 {
	public static void main(String[] args) {
		System.out.println("Hello World");
		try {
			Emp_jdbc empJdbc = new Emp_jdbc();
			empJdbc.init("cdacacts", "root", "root");
			Employee emp = empJdbc.getEmployeeByEmpno(1);
			boolean flag = LoginAuth.checkAuth("admin", "admin123");
			ArrayList<Employee> empBySalary = empJdbc.getEmployeeBySalary(10);

			StringBuilder empSalByString = new StringBuilder();
			for (Employee empRow : empBySalary) {
				empSalByString.append("\n");
				empSalByString.append(empRow);
			}

			System.out.println(emp + " " + flag + " " + empSalByString.toString());
		} catch (ClassNotFoundException e) {
			System.out.println("Something went wrong:" + e.getMessage());
		} catch (SQLException e) {
			System.out.println("Something went wrong:" + e.getMessage());
		}

	}
}
