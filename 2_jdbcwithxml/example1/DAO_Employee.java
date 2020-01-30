package springBasics;

import java.util.ArrayList;
import java.util.List;

import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

public class DAO_Employee {
	private JdbcTemplate jdbcTemp;

	public DAO_Employee() {
	}

	/**
	 * @param jdbcTemp
	 *            the jdbcTemp to set
	 */
	public void setJdbcTemp(JdbcTemplate jdbcTemp) {
		this.jdbcTemp = jdbcTemp;
	}

	/**
	 * Register Employee
	 * 
	 * @param emp
	 * @return boolean
	 */
	public boolean registerEmployee(Employee emp) {
		Object[] params = { emp.getEmpno(), emp.getDptid(), emp.getSalary() };
		int rowsaffected = jdbcTemp.update(
				"insert into emp(empno,dptid,salary) values (?,?,?)", params);
		return rowsaffected > 0;

	}

	/**
	 * Update Employee
	 * 
	 * @param emp
	 * @return boolean
	 */
	public boolean updateEmployee(Employee emp) {
		Object[] params = { emp.getDptid(), emp.getSalary(), emp.getEmpno() };
		int rowsaffected = jdbcTemp.update(
				"UPDATE emp SET dptid = ?,salary = ? WHERE empno = ?", params);
		return rowsaffected > 0;

	}

	/**
	 * Get Employee by Empno
	 * 
	 * @param emp
	 * @return boolean
	 */
	public Employee getEmployeeById(int empno) {
		Employee emp = null;
		BeanPropertyRowMapper<Employee> rowMapper = new BeanPropertyRowMapper<Employee>(
				Employee.class);
		Object params[] = { empno };
		try {
			emp = jdbcTemp.queryForObject(
					"SELECT empno,dptid,salary FROM emp WHERE empno = ?",
					params, rowMapper);
		} catch (DataAccessException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		}
		return emp;

	}

	/**
	 * Get Employee by deptId
	 * 
	 * @param emp
	 * @return boolean
	 */
	public List<Employee> getEmployeeByDeptId(int deptid) {
		List<Employee> empList = new ArrayList<Employee>();
		BeanPropertyRowMapper<Employee> rowMapper = new BeanPropertyRowMapper<Employee>(
				Employee.class);
		Object params[] = { deptid };
		try {
			empList = jdbcTemp.query(
					"SELECT empno,dptid,salary FROM emp WHERE dptid = ?",
					params, rowMapper);
		} catch (DataAccessException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		}
		return empList;
	}
	

	/**
	 * Get Employees with salary with salary greater than supplied salaries
	 * 
	 * @param emp
	 * @return boolean
	 */
	public List<Employee> getEmployeeBySalaryGt(int salary) {
		List<Employee> empList = new ArrayList<Employee>();
		BeanPropertyRowMapper<Employee> rowMapper = new BeanPropertyRowMapper<Employee>(
				Employee.class);
		Object params[] = { salary };
		try {
			empList = jdbcTemp.query(
					"SELECT empno,dptid,salary FROM emp WHERE salary > ?",
					params, rowMapper);
		} catch (DataAccessException e) {
			System.out.println("Oops something went wrong! message:"
					+ e.getMessage());
		}
		return empList;
	}
}
