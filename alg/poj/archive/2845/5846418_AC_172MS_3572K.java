import java.math.*;
import java.io.*;
import java.util.*;

public class Main
{
        public static void main(String [] args)throws Exception
        {
                Scanner cin=new Scanner(System.in);
                PrintStream cout=new PrintStream(System.out);
                int t=cin.nextInt();
                for(int i=1;i<=t;i++)
                {
                        BigInteger a=cin.nextBigInteger(2);
                        BigInteger b=cin.nextBigInteger(2);
                        String str=a.add(b).toString(2);
                        cout.print(i+" ");
                        cout.println(str);

                }
                cout.close();
        }
}
