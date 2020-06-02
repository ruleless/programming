//package J1405;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		BigInteger[] b=new BigInteger[n+1];
		b[1]=new BigInteger("2");
		for(int i=2;i<=n;i++){
			b[i]=new BigInteger("1");
			BigInteger temp=new BigInteger(b[i-1].toByteArray());
			b[i]=b[i-1].pow(2).subtract(temp).add(new BigInteger("1"));
		}
		for(int i=1;i<=n;i++){
			System.out.println(b[i].toString());
		}
	}

}
