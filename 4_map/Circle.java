package map_ass;

public class Circle {
	public float radius,res1;

	public float getRadius() {
		return radius;
	}
	
	

	public Circle(float radius) {
		
		this.radius = radius;
	}



	


	


	@Override
	public String toString() {
		return "Circle [radius=" + radius + ", res1=" + res1 + "]";
	}



	public void setRadius(float radius) {
		this.radius = radius;
	}
	public float getPerimiter() {
		return (float) (2*3.14*radius);
		
	}

}
