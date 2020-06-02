import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		for(int i=0;i<n;i++){
			BigDecimal a=cin.nextBigDecimal();
			BigDecimal b=cin.nextBigDecimal();
			System.out.println(a.add(b));
		}
	}
}
