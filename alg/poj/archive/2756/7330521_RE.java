import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		for(int i=0;i<n;i++){
			BigInteger a=cin.nextBigInteger();
			BigInteger b=cin.nextBigInteger();
			System.out.println(a.add(b));
		}
	}
}
