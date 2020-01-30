package JdbcWithSpringExp1;

public class Book 
{
	private String bk_name;
	private int bk_id, bk_price;
	
	@Override
	public String toString() {
		return "Book [bk_name=" + bk_name + ", bk_id=" + bk_id + ", bk_price=" + bk_price + "]";
	}
	public String getBk_name() {
		return bk_name;
	}
	public void setBk_name(String bk_name) {
		this.bk_name = bk_name;
	}
	public int getBk_id() {
		return bk_id;
	}
	public void setBk_id(int bk_id) {
		this.bk_id = bk_id;
	}
	public int getBk_price() {
		return bk_price;
	}
	public void setBk_price(int bk_price) {
		this.bk_price = bk_price;
	}
	public Book(int bk_id, String bk_name, int bk_price) {
		this.bk_name = bk_name;
		this.bk_id = bk_id;
		this.bk_price = bk_price;
		System.out.println("ctor");
	}
	

}
