package annotations_basics.tests;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;

import annotations_basics.parts.Lens;
import annotations_basics.whole.Camera;

@ComponentScan("annotations_basics.whole")
public class TestCamera {
	@Bean
	public Lens createLens() {
		Lens lens = new Lens();
		System.out.println("New Lens created!!");
		return lens;
	}

	public static void main(String[] args) {
		AnnotationConfigApplicationContext anno = new AnnotationConfigApplicationContext(TestCamera.class);
		Camera cam = anno.getBean(Camera.class);
		cam.clickPic();
	}

}
