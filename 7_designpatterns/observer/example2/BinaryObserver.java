package Observer;

/*public class BinaryObserver {

}*/

public class BinaryObserver extends Observer{

	   private Subject subject;

	public BinaryObserver(Subject subject){
	      this.subject = subject;
	      this.subject.attach(this);
	   }

	   @Override
	   public void update() {
	      System.out.println( "Binary String: " + Integer.toBinaryString( subject.getState() ) ); 
	   }
	}

 class OctalObserver extends Observer{

	   private Object subject;

	public OctalObserver(Subject subject){
	      this.subject = subject;
	      ((Subject) this.subject).attach(this);
	   }

	   @Override
	   public void update() {
	     System.out.println( "Octal String: " + Integer.toOctalString( (((Subject) subject).getState() ) )); 
	   }
	}
