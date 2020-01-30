package annotationExp;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Component;

@Component
@ComponentScan("annotationExp")
public class PenClass 
{
	private RiffileClass obj;
	
	@Autowired
	public void setObj(RiffileClass obj) {
		System.out.println("asking for wiring to spring");
		this.obj = obj;
		System.out.println("wiring is done"+ (obj==null));
	}

	
	public PenClass() {
		System.out.println("ctor of pen class i.e. object is created by spring using annotation");
		// TODO Auto-generated constructor stub
	}
	
	@Bean
	public RiffileClass freak()
	{
		System.out.println("we are creating object");
		RiffileClass obj1 =new RiffileClass();
		return obj1;
		
		
	}
	
}
