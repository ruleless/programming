import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		PrintStream cout=new PrintStream(System.out);
		while(cin.hasNextBigDecimal()){
			BigDecimal a=cin.nextBigDecimal();
			int k=cin.nextInt();
			BigDecimal b=a.pow(k);
			String c=b.toPlainString();
			if(c.charAt(1)=='.'&&c.charAt(0)=='0')
				c=c.substring(1, c.length()-1);
			else{
				int i;
				for(i=c.length()-1;i>=0&&c.charAt(i)=='0';i--);
				c=c.substring(0,i+1);
			}
			cout.println(c);
		}
	}

}
