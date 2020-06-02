package J1001;
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		PrintStream cout=new PrintStream(System.out);
		while(cin.hasNextBigDecimal()){
			BigDecimal a=cin.nextBigDecimal();
			int k=cin.nextInt();
			BigDecimal b=a.pow(k);
			cout.println(b.toPlainString());
		}
	}

}
