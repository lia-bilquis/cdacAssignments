package basics;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class helloworld {
	public static void main(String[] args) {
		ClassPathXmlApplicationContext cpath = new ClassPathXmlApplicationContext(
				"carrot.xml");
		AddressBook addrbook = (AddressBook) cpath.getBean(AddressBook.class);
		addrbook.f1();
		cpath.close();
	}
}
