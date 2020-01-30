package annotationExp;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class TestAnnotationExp 
{
	public static void main(String[] args) {
		
		//class name where componentscan is used
		AnnotationConfigApplicationContext c = new AnnotationConfigApplicationContext(PenClass.class);
	}

}
