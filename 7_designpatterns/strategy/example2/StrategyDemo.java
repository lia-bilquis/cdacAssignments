package Stratergy;

public class StrategyDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		      Context context = new Context(new AddOperation());		
		      System.out.println("10 + 5 = " + context.executeStrategy(10, 5));

		      context = new Context(new SubstractOperation());		
		      System.out.println("10 - 5 = " + context.executeStrategy(10, 5));

		    /*  context = new Context(new OperationMultiply());		
		      System.out.println("10 * 5 = " + context.executeStrategy(10, 5));*/
		   }

	}


