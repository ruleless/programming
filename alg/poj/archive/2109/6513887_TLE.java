import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner cin=new Scanner(System.in);
		BigInteger p;
		while(cin.hasNext()){
			int n=cin.nextInt();
			p=cin.nextBigInteger();
			BigInteger t=new BigInteger("1");
			for(;!t.pow(n).equals(p);t=t.add(new BigInteger("1")));
			System.out.println(t);	
		}
	}

}
