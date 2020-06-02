import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args)throws Exception {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		PrintStream cout=new PrintStream(System.out);
		while(cin.hasNext()){
			String a=cin.next();
			int i;
			int n=a.length();
			for(i=0;i<n&&a.charAt(i)==' ';i++);
			a.subSequence(i, n-1);
			int base1=cin.nextInt();
			BigInteger num=new BigInteger(a,base1);
			int base2=cin.nextInt();
			String s=num.toString(base2);
			s=s.toUpperCase();
			if(s.length()>7)
				cout.println("  ERROR");
			else
			{
				n=s.length();
				for(i=1;i<=7-n;i++){
					cout.print(" ");
				}
				cout.println(s);
			}
		}
	}
}
