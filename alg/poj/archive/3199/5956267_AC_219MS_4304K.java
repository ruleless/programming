import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args)throws Exception {
		Scanner cin=new Scanner(System.in);
		PrintStream cout=new PrintStream(System.out);
		BigInteger n;
		int d;
		n=cin.nextBigInteger();
		d=cin.nextInt();
		while(!(n.compareTo(new BigInteger("0"))==0&&d==0)){
			cout.println(n.pow(d));
			n=cin.nextBigInteger();
			d=cin.nextInt();
		}

	}

}
