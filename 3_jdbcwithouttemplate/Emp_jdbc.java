package basics;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import springBasics.Employee;

public class Emp_jdbc {
	private Connection con;

	/**
	 * 
	 * @param dbname
	 *            Database
	 * @param username
	 *            username
	 * @param password
	 *            password
	 * @throws ClassNotFoundException
	 * @throws SQLException
	 */
	public boolean init(String dbname, String username, String password) {
		boolean status = false;
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost:3306/"
					+ dbname, username, password);
			status = true;
		} catch (ClassNotFoundException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		} catch (SQLException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		}

		return status;
	}

	/**
	 * Insert Employee
	 * 
	 * @param sc
	 * @throws SQLException
	 */
	public boolean insertEmployee(Employee emp) {
		boolean status = false;
		try {
			PreparedStatement ps = this.con
					.prepareStatement("insert into emp(empno,dptid,salary) values(?,?,?)");
			ps.setInt(1, emp.getEmpno());
			ps.setInt(2, emp.getDptid());
			ps.setInt(3, emp.getSalary());
			ps.execute();
		} catch (SQLException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		}
		return status;
	}

	/**
	 * Update employee
	 * 
	 * @param sc
	 * @throws SQLException
	 */
	public int updateEmployee(Employee emp) {
		int rows = 0;
		try {
			PreparedStatement ps = this.con
					.prepareStatement("update emp set dptid = ?,salary = ? where empno = ?");
			ps.setInt(1, emp.getEmpno());
			ps.setInt(2, emp.getDptid());
			ps.setInt(3, emp.getSalary());
			rows = ps.executeUpdate();
		} catch (SQLException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		}
		return rows;
	}

	/**
	 * Get All Employee in the department
	 * 
	 * @param sc
	 * @throws SQLException
	 */
	public ArrayList<Employee> getEmployeesInDept(int deptid) {
		ArrayList<Employee> empList = new ArrayList<Employee>();
		try {
			PreparedStatement ps = this.con
					.prepareStatement("select empno,dptid,salary from emp where dptid = ?");
			ps.setInt(1, deptid);
			ResultSet rs = ps.executeQuery();

			while (rs.next()) {
				empList.add(new Employee(rs.getInt("empno"),
						rs.getInt("dptid"), rs.getInt("salary")));
			}
		} catch (SQLException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		}
		return empList;
	}

	/**
	 * Delete employee
	 * 
	 * @param sc
	 * @throws SQLException
	 */
	public boolean deleteEmployee(int empno) {
		boolean status = false;
		try {
			PreparedStatement ps = this.con
					.prepareStatement("delete from emp where empno = ?");
			ps.setInt(1, empno);
			ps.execute();
		} catch (SQLException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		}
		return status;
	}

	/**
	 * Get All Employee in the department
	 * 
	 * @param sc
	 * @throws SQLException
	 */
	public Employee getEmployeeByEmpno(int empno) {
		Employee emp = null;
		try {
			PreparedStatement ps = this.con
					.prepareStatement("select empno,dptid,salary from emp where empno = ?");
			ps.setInt(1, empno);
			ResultSet rs = ps.executeQuery();
			while (rs.next()) {
				emp = new Employee(rs.getInt("empno"), rs.getInt("dptid"),
						rs.getInt("salary"));
			}
		} catch (SQLException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		}
		return emp;
	}

	/**
	 * Get All Employee by Salary
	 * 
	 * @param sc
	 * @throws SQLException
	 */
	public ArrayList<Employee> getEmployeeBySalary(int salary)
			{
		ArrayList<Employee> empList = new ArrayList<Employee>();
		try {
			PreparedStatement ps = this.con
					.prepareStatement("select empno,dptid,salary from emp where salary > ?");
			ps.setInt(1, salary);
			ResultSet rs = ps.executeQuery();
			
			while (rs.next()) {
				empList.add(new Employee(rs.getInt("empno"), rs.getInt("dptid"), rs
						.getInt("salary")));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return empList;
	}

}
