package J1131;
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner cin=new Scanner(System.in);
		PrintStream cout=new PrintStream(System.out);
		while(cin.hasNextBigDecimal()){	
			BigDecimal num=cin.nextBigDecimal();
			String num1=num.toString();
			//cout.println(num.toString().charAt(1));
			BigDecimal res=new BigDecimal(0);
			int n=num1.length();
			double a=1;
			for(int i=2;i<n;i++){
				a/=8;
				double c=(double)(num1.charAt(i)-48);
				BigDecimal d=BigDecimal.valueOf(a).multiply(BigDecimal.valueOf(c));
				res=res.add(d);
			}
			String num2=res.toString();
			int i;
			for(i=num2.length()-1;i>=0&&num2.charAt(i)=='0';i--);
			num2=num2.substring(0,i+1);
			cout.println(num1+" [8] = "+num2+" [10]");
		}
	}
}