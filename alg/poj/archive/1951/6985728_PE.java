import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		String str=cin.nextLine();
		str=str.trim();
		str=str.replaceAll("[A|E|I|O|U]","");
		str=str.replaceAll("\\s+", " ");
		int[] hash=new int[30];
		int i;
		for(i=0;i<26;i++){
			hash[i]=0;
		}
		int len=str.length();
		StringBuffer buf=new StringBuffer();
		for(i=0;i<len;i++){
			if(str.charAt(i)>='A'&&str.charAt(i)<='Z'){
				if(hash[str.charAt(i)-'A']==0){
					buf.append(str.charAt(i));
				}
				hash[str.charAt(i)-'A']++;
			}else{
				buf.append(str.charAt(i));
			}
		}
		String res=buf.toString().trim();
		res=res.replaceAll("\\s+", " ");
		res=res.trim();
		System.out.println(res);
	}

}
