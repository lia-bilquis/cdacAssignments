package JdbcWithSpringExp1;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestMainExp1
{
	public static void main(String[] args) {
		ClassPathXmlApplicationContext c =new ClassPathXmlApplicationContext("carrot.xml");
		
		  DAO_Book y =c.getBean(DAO_Book.class); // getting the object
		
		Book x =new Book(006,"bk6",498); //assume this was created based on the
		 
		
		  
		  boolean z1 = y.insertBook(x); // fdism wwiby 
		  
		if (z1)
			System.out.println("insert successful");
		else
			System.out.println("update failed");
	
	}

}
