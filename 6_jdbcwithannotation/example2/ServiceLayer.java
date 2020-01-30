package jdbcannotation;

import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;
import java.util.Scanner;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcOperations;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;
@Component
public class ServiceLayer {

	private DAOLayer dao;
	private JdbcTemplate jt;
	
	@Autowired
	public void setDao(DAOLayer dao) {
		this.dao = dao;
		 jt=this.dao.getJt();
	}
	public void findEmp(int empno) {
		// TODO Auto-generated method stub
		Emp emp = null;
		String qry="select empno,salary,deptid from emp where empno=?";
		BeanPropertyRowMapper<Emp> bp=new BeanPropertyRowMapper<Emp>(Emp.class);
		Object params[]= {empno};
		
		try {
			emp=jt.queryForObject(qry, bp, params);
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			System.out.println("");
		}
		Scanner sc = new Scanner(System.in);
		if(emp!=null)
		{
			System.out.println(emp);
			PresentationLayer.empMenu();
			int ch = sc.nextInt();
			switch(ch)
			{
			case 1:
				updateEmp(emp.getEmpno());
				break;
			case 2:
				deleteEmp(emp.getEmpno());
				break;
			default:
				System.out.println("Invalid Choice!!!");
			}
		}
		else
		{
			System.out.println("Employee Not Found!!!");
			insertEmp(empno);
		}
				
			
	}
	private  void deleteEmp(int empno) {
		// TODO Auto-generated method stub
		String qry="delete from emp where empno=?";
		Object params[]= {empno};
		int row=0;
		try {
			row=jt.update(qry,params);
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}
		if(row>0)
		{
			System.out.println("Record Deleted Successfully!!!");
		}
		else
		{
			System.out.println("some error occured try after sometime");
		}
	}
	private  void updateEmp(int empno) {
		// TODO Auto-generated method stub
		Emp emp=new Emp();
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Salary: ");
		emp.setSalary(sc.nextInt());
		System.out.print("Enter Department ID: ");
		emp.setDeptid(sc.nextInt());
		emp.setEmpno(empno);
		String qry = "update emp set salary=?,deptid=? where empno=?";
		Object params[]= {emp.getSalary(),emp.getDeptid(),emp.getEmpno()};
		int row=0;
		try {
			row=jt.update(qry, params);
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}
		if(row>0)
		{
			System.out.println("Record Updated Successfully!!!");
		}
		else
		{
			System.out.println("some error occured try after sometime");
		}
	}
	private  void insertEmp(int empno) {
		// TODO Auto-generated method stub
		Emp emp=new Emp();
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Salary:");
		emp.setSalary(sc.nextInt());
		System.out.print("Enter Department ID:");
		emp.setDeptid(sc.nextInt());
		emp.setEmpno(empno);
		String qry = "insert into emp(empno,salary,deptid) values(?,?,?)";
		Object params[]= {emp.getEmpno(),emp.getSalary(),emp.getDeptid()};
		int row=0;
		try {
			 row=jt.update(qry,params);
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}
		if(row>0)
		{
			System.out.println("Record inserted Successfully!!!");
		}
		else
		{
			System.out.println("some error occured try after sometime");
		}
	}
	public  void salarySearch(int salary) {
		// TODO Auto-generated method stub
		List<Emp> list=new ArrayList<Emp>();
		String qry="select empno,salary,deptid from emp where salary>?";
		BeanPropertyRowMapper<Emp> bp=new BeanPropertyRowMapper<Emp>(Emp.class);
		Object params[]= {salary};
		try {
			list=jt.query(qry,params, bp);
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}
		
		if(list.size()!=0)
		{
			StringBuilder sb=new StringBuilder();
			for(Emp emp:list)
			{
				sb.append("\n");
				sb.append(emp);
			}
			System.out.println(sb);
		}
		else
		{
			System.out.println("No Employee having salary below "+salary);
		}
	}
}
