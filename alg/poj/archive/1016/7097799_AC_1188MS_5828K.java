//package NumbersThatCount;

import java.util.HashMap;
import java.util.Scanner;
import java.io.*;

/**
 * 1016
 * @author Administrator
 *
 */
public class Main {
	public boolean check(String number,String newNumber){
		if(number.equals(newNumber))
			return true;
		return false;
		
	}

	public static String turnNext(String number){
		Integer count = 0;
		StringBuffer newNumber = new StringBuffer();
		HashMap<String,String> map = new HashMap<String,String>();
		for (int i = 0; i < number.length(); i++) {
			a:if(i == 0){
				for (int j = 0; j < number.length(); j++) {
					if (number.charAt(j) == (number.charAt(i))) {
						count++;
					}
				}
				map.put(String.valueOf(number.charAt(i)), count.toString());
				count = 0;
			}else{
				if (map.containsKey(String.valueOf(number.charAt(i)))){
						break a;
				}
				for (int j = 0; j < number.length(); j++) {
					if (number.charAt(j) == (number.charAt(i))) {
						count++;
					}
				}
				map.put(String.valueOf(number.charAt(i)), count.toString());
				count = 0;
			}
		}
		int i = 0;
		while(i<10){
			if(map.containsKey(String.valueOf(i))){
				newNumber.append(map.get(String.valueOf(i)));
				newNumber.append(String.valueOf(i));
			}
			i++;
		}
		return newNumber.toString();
	}
	public void justice(String number){
		String[] numbers = new String[20];
		numbers[1] = number;
		String oldnumber = number;
		number = turnNext(number);
		int count = 1;
		if(check(oldnumber,number)){
			System.out.println(oldnumber + " is self-inventorying ");
		}else{
			while(!check(number,turnNext(number))&&!check(oldnumber,number)&&isExist(numbers, number) == -1){
				count ++;
				numbers[count] = number;
				number = turnNext(number);
				if(count > 15){
					System.out.println(oldnumber + " can not be classified after 15 iterations ");
					return ;
				}
			}
			if(check(number,turnNext(number))){
				System.out.println(oldnumber + " is self-inventorying after " + count + " steps ");
			}else if(isExist(numbers, number)!= -1){
				System.out.println(oldnumber + " enters an inventory loop of length " + isExist(numbers, 

number));
			}
		}
	}
	/**
	 * 判断在前面是不是存在该数字
	 * @param numbers
	 * @param number
	 * @return
	 */
	public int isExist(String[] numbers,String number){
		int k = 1;
		while(numbers[k] != null){
			k++;
		}
		for(int i = 1;numbers[i]!=null;i++){
			if(numbers[i].equals(number)){
				return k-i;
			}
		}
		return -1;
	}
	public static void main(String args[])throws Exception{
		Scanner input = new Scanner(System.in/*new FileInputStream("in.txt")*/);
		String number = input.next();	
		while(!number.equals("-1")){
			new Main().justice(number);	
			number = input.next();	
		}
		
	}
}
