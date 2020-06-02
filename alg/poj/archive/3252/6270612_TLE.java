import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static boolean is(String s){
		int n=s.length();
		int m=0;
		for(int i=0;i<n;i++){
			if(s.charAt(i)=='0')
				m++;
		}
		if(m>=n-m){
			return true;
		}
		else 
			return false;
	}
	public static void main(String[] args) throws Exception{
		Scanner cin=new Scanner(System.in);
		BigInteger a,b,num;
		int cnt=0;
		a=cin.nextBigInteger();
		b=cin.nextBigInteger();
		for(num=new BigInteger(a.toString());num.compareTo(b)!=1;num=num.add(new BigInteger("1"))){
			String s=num.toString(2);
			if(is(s)){
				cnt++;
				//System.out.println(cnt);
			}			
		}
		System.out.println(cnt);
	}

}
