import java.util.*;
import java.math.*;
public class Main {
	public static int n;
	public static BigInteger one=BigInteger.ONE;
	public static BigInteger zero=BigInteger.ZERO;
	public static BigInteger ten=BigInteger.TEN;
	public static BigInteger negone=one.negate();
	public static BigInteger bfs(BigInteger a,int len){
		if(len>100)return negone;
		if(a.mod(BigInteger.valueOf(n))==zero)
			return a;
		BigInteger b=bfs(a.multiply(ten),len+1);
		if(b.compareTo(negone)!=0)return b;
		b=bfs(a.multiply(ten).add(one),len+1);
		if(b.compareTo(negone)!=0)return b;
		return negone;
	}
	public static void main(String args[]){
		Scanner cin=new Scanner(System.in);
		BigInteger ans=one;
		while(true){
			n=cin.nextInt();
			if(n==0)break;
			//System.out.println(n);
			ans=bfs(one,1);
			System.out.println(ans.toString());
		}
	}
}
