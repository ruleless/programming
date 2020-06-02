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
		BigInteger a=cin.nextBigInteger();
		BigInteger b=cin.nextBigInteger();
		cout.println(a.multiply(b).toString());

	}

}
