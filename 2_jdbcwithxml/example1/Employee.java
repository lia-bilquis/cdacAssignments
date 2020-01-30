package springBasics;

public class Employee {
	private int empno;
	private int dptid;
	private int salary;

	/**
	 * 
	 */
	public Employee() {
	}

	/**
	 * Employee
	 * 
	 * @param empno
	 * @param dptid
	 * @param salary
	 */
	public Employee(int empno, int dptid, int salary) {
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
	 * @param empno
	 *            the empno to set
	 */
	public void setEmpno(int empno) {
		this.empno = empno;
	}

	/**
	 * @return the dptid
	 */
	public int getDptid() {
		return dptid;
	}

	/**
	 * @param dptid
	 *            the dptid to set
	 */
	public void setDptid(int dptid) {
		this.dptid = dptid;
	}

	/**
	 * @return the salary
	 */
	public int getSalary() {
		return salary;
	}

	/**
	 * @param salary
	 *            the salary to set
	 */
	public void setSalary(int salary) {
		this.salary = salary;
	}

	/**
	 * 
	 */
	public String toString() {
		return "Employee [empno=" + empno + ", dptid=" + dptid + ", salary="
				+ salary + "]";
	}

}
