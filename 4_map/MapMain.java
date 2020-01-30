package map_ass;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;


public class MapMain {
	
	int l,b,opt;
	float r;
	static int option=0;
	String str;
	
	
	public static int menu1() {
		System.out.println("Menu2:"+"\n"+"1.Rectangle"+"\n"+"2.Circle");
		Scanner sc=new Scanner (System.in);
		option=sc.nextInt();
		return option;
	}
	
	
	public void add(HashMap<String,Object> hashmap) {
		
		System.out.println("Enter String");
	    Scanner sc=new Scanner(System.in);
    	str = sc.next();
    	opt = MapMain.menu1();
    	
    	if(1==opt) {
    		
    		
    		System.out.println("Enter length");
    		l=sc.nextInt();
   		    System.out.println("Enter Breadth");
    		b=sc.nextInt();
    		Rectangle rect=new Rectangle(l,b);
    		hashmap.put(str,rect);
    		System.out.println("Added Successfully");
    	}
    	else if(2==opt)
    	{
    		System.out.println("Enter Radius");
    		r=sc.nextFloat();
    		Circle cir=new Circle(r);
    		hashmap.put(str,cir);
    		System.out.println("Added Successfully");

    	}
    	else {
    		System.out.println("Wrong Option");
    		
    	}
	
		
	}
	
	public void viewMap(HashMap<String, Object> hashmap) {
		System.out.println("Enter Key");
		Scanner sc1=new Scanner(System.in);
		String key=sc1.nextLine();
        Object b = hashmap.get(key);
        
        if(b instanceof Rectangle)
        {
        	System.out.println("Area of Rectangle: "+((Rectangle)b).getArea());
        }
        else {
        	System.out.println("Perimeter of Circle: "+((Circle)b).getPerimiter());
        }
       
	}

	public void countObject(HashMap<String, Object> hashmap) {
	
		int reccount=0,circount=0;
		 for(Entry<String, Object> m :hashmap.entrySet())
			{
				if(m.getValue() instanceof Rectangle)
				{
					reccount++;
				}
				else
				{
					circount++;
				}
			}
		System.out.println("Rectangle Objects is "+reccount+"\nCircle Objects is "+circount +"\n");
			
	}

	
	public static void main(String [] args) {
		int choice=0;
		MapMain mm=new MapMain();
		HashMap<String,Object>hashmap=new HashMap<>();
		do {
		System.out.println("Menu:"+"\n"+"1.Add to Map"+"\n"+"2.View Map"+"\n"+
		"3.View How Many Object create"+"\n"+"4.Exit");
		
		System.out.println("Enter your Choice:");
		Scanner sc=new Scanner(System.in);
		choice=sc.nextInt();
		if(choice ==1) {
			mm.add(hashmap);	
			System.out.println(hashmap);
		}
		else if(choice ==2){
			mm.viewMap(hashmap);
		
		}
		else if(choice ==3) {
			mm.countObject(hashmap);
		}
		else if(choice ==4) {
			System.out.println("Exit");
		}
		
		
		
		}while(choice!=4);
		
	}

	

}
