package java_basics;

public class Employee {

	private int empno;
	private int dptid;
	private int salary;

	/**
	 * 
	 */
	Employee() {
	}

	/**
	 * 
	 * @param empno
	 * @param dptid
	 * @param salary
	 */
	Employee(int empno, int dptid, int salary) {
		this.empno = empno;
		this.dptid = dptid;
		this.salary = salary;
	}

	/**
	 * @return the empno
	 */
	public int getEmpno() {
		return empno;
	}

	/**
	 * @return the dptid
	 */
	public int getDptid() {
		return dptid;
	}

	/**
	 * @return the salary
	 */
	public int getSalary() {
		return salary;
	}

	/**
	 * 
	 * @param empno
	 */
	public void setEmpno(int empno) {
		this.empno = empno;
	}

	/**
	 * 
	 * @param dptid
	 */
	public void setDptid(int dptid) {
		this.dptid = dptid;
	}

	/**
	 * 
	 * @param salary
	 */
	public void setSalary(int salary) {
		this.salary = salary;
	}

	@Override
	public String toString() {
		return "EmpNo:" + this.empno + ", DptId:" + this.dptid + ", Salary:" + this.salary;
	}
}
