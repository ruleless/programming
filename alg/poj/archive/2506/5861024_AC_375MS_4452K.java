import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
        private static String [] str;
        public static void main(String [] args)throws Exception
        {
                str=new String[257];
                Scanner cin=new Scanner(System.in);
                PrintStream cout=new PrintStream(System.out);
                f();
                while(cin.hasNextInt())
                {
                        int n=cin.nextInt();
                        cout.println(str[n]);
                }
        }
        public static void f()
        {
               str[0]=new String("1");
               str[1]=new String("1");
               for(int n=2;n<=250;n++)
               {
                       BigInteger a=new BigInteger(str[n-2]);
                       BigInteger b=new BigInteger(str[n-1]);
                       str[n]=a.multiply(new BigInteger("2")).add(b).toString();
               }
        }
}
