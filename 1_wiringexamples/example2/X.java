package basics;

public class X {
	
	private Y y;

	public void setY(Y y) {
		this.y = y;
	}

	/**
	 * X Constructor machaan 3:D
	 */
	public X() {
		System.out.println("X object created!!");
	}

	public void fun(){
		System.out.println("x::fun() "+y.dofun());
	}
}
