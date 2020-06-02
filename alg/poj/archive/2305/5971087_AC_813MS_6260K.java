import java.math.*;
import java.util.*;
import java.io.*;

/**
 * @author Administrator
 *
 */
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		Scanner cin=new Scanner(System.in);
		PrintStream cout=new PrintStream(System.out);
		int base;
		base=cin.nextInt();
		while(base!=0){
			BigInteger a=cin.nextBigInteger(base);
			BigInteger b=cin.nextBigInteger(base);
			BigInteger c=a.mod(b);
			cout.println(c.toString(base));
			base=cin.nextInt();
		}
	}
}
