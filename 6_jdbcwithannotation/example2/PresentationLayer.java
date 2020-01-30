package jdbcannotation;

import java.util.ResourceBundle;
import java.util.Scanner;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import empjdbc.EmpJdbc;

@Component
public class PresentationLayer {

	private ServiceLayer ser;

	@Autowired
	public void setSer(ServiceLayer ser) {
		this.ser = ser;
	}
	public static void empMenu() {
		System.out.println("______________________________");
		System.out.println("Choose any one option");
		System.out.println("1. Update");
		System.out.println("2. Delete");
		System.out.println("______________________________");
		System.out.print("Enter your choice: ");
	}
	private void userMenu() {
		System.out.println("______________________________");
		System.out.println("Choose any one option");
		System.out.println("1. Enter Emp No");
		System.out.println("2. Enter Salary");
		System.out.println("3. Log Out");
		System.out.println("______________________________");
		System.out.print("Enter your choice: ");
	}
	
	private  void userOperation() {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int empno;
		int salary;
		while (true) {
			userMenu();
			int ch = sc.nextInt();
			switch (ch) {
			case 1:
				empno = sc.nextInt();
				ser.findEmp(empno);
				break;
			case 2:
				salary = sc.nextInt();
				ser.salarySearch(salary);
				break;
			case 3:
				System.out.println("Log Out Successfully!!!");
				mainMenu();
				return;
			default:
				System.out.println("Invalid Choice!!!");

			}
		}

	}
	private boolean checkCredentials() {
		// TODO Auto-generated method stub

		ResourceBundle rb = ResourceBundle.getBundle("y");
		String userid = rb.getString("userid");
		String password = rb.getString("password");
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter User ID: ");
		String uid = sc.next();
		System.out.print("Enter Password: ");
		String pass = sc.next();

		if (userid.equals(uid) && password.equals(pass))
			return true;
		else
			return false;
	}
	
	public void mainMenu() {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		EmpJdbc.menu();
		int ch = sc.nextInt();
		switch (ch) {
		case 1:
			if (checkCredentials()) {
				System.out.println("Welcome");
				userOperation();
			} else {
				System.out.println("Invalid Login Credential!!!");
			}
			break;
		case 2:
			return;
		default:
			System.out.println("Invalid Choice!!!");
		}

	}
	
}
