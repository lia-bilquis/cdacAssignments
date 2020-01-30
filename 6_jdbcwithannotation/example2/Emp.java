package jdbcannotation;

public class Emp {

	private int empno;
	private int salary;
	private int deptid;
	public int getEmpno() {
		return empno;
	}
	@Override
	public String toString() {
		return "Employee details: [empno=" + empno + ", salary=" + salary + ", deptid=" + deptid + "]";
	}
	public void setEmpno(int empno) {
		this.empno = empno;
	}
	public int getSalary() {
		return salary;
	}
	public void setSalary(int salary) {
		this.salary = salary;
	}
	public int getDeptid() {
		return deptid;
	}
	public void setDeptid(int deptid) {
		this.deptid = deptid;
	}
	
}
