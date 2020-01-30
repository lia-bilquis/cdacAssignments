package map_ass;

public class Rectangle {
	

public int length,breadth,res2;



public Rectangle(int length, int breadth) {
	
	this.length = length;
	this.breadth = breadth;
}


@Override
public String toString() {
	return "Rectangle [length=" + length + ", breadth=" + breadth + ", res2=" + res2 + "]";
}


@Override
public boolean equals(Object obj) {
	// TODO Auto-generated method stub

	return true;
}


@Override
public int hashCode() {
	// TODO Auto-generated method stub
	return super.hashCode();
}


public int getLength() {
	return length;
}

public void setLength(int length) {
	this.length = length;
}

public int getBreadth() {
	return breadth;
}

public void setBreadth(int breadth) {
	this.breadth = breadth;
}

public int getArea() {
	return length*breadth;
}

}
