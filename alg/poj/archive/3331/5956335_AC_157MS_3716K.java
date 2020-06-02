import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args)throws Exception {
		Scanner cin=new Scanner(System.in);
		PrintStream cout=new PrintStream(System.out);
		int t=cin.nextInt();int j;
		for(j=1;j<=t;j++){
			int n=cin.nextInt();
			int d=cin.nextInt();
			char c=(char)(d+48);
			int i;
			BigInteger sum=new BigInteger("1");
			for(i=1;i<=n;i++){
				sum=sum.multiply(BigInteger.valueOf(i));
				
			}
			String str=sum.toString();
			int len=str.length();
			int ans=0;
			for(i=0;i<len;i++){
				if(str.charAt(i)==c)
					ans++;				
			}
			cout.println(ans);
		}
	}

}
