import java.math.*;
import java.util.*;
import java.io.*;

public class Main
{
public static void main(String [] args)throws Exception
{
        Scanner cin=new Scanner(new FileInputStream("in.txt"));
        PrintStream cout=new PrintStream(System.out);
        while(cin.hasNext())
        {
                String num=cin.next();
                BigInteger a1=new BigInteger(num);
                Integer temp=new Integer(num.length()+1);
                BigInteger a2=new BigInteger(temp.toString());
                String num1=a1.multiply(a2).toString();
                if(num1.length()==num.length())
                {
                        int i;
                        for(i=0;i<num1.length()&&num1.charAt(i)=='9';i++);
                        if(i==num.length())
                        {
                                cout.print(num);
                                cout.println(" is cyclic");
                        }
                        else
                        {
                                cout.print(num);
                                cout.println(" is not cyclic");
                        }
                }
                else
                {
                        cout.print(num);
                        cout.println(" is not cyclic");
                }

        }
}
}
