package basics;

public class AddressBook {
	private LL x;

	public AddressBook() {
		System.out.println("Address book Object is created!!");
	}

	public void setX(LL x) {
		this.x = x;
	}

	public void f1(){
		x.Add(1);
	}
}
