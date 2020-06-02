import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {
	public static void main(String[] args) {
		Map<String,Integer> map=new HashMap<String,Integer>();
		Map<String,Integer> used=new HashMap<String,Integer>();
		Scanner cin=new Scanner(System.in);
		int t,i,j,n,cases=0;
		t=cin.nextInt();
		while(t!=0){
			cases++;
			t--;
			n=cin.nextInt();
			map.clear();
			used.clear();
			String temp=cin.nextLine();
			String[] ddl=new String[n];
			for(i=0;i<n;i++){
				ddl[i]=cin.nextLine();
			}
			int[] err=new int[n];
			for(i=0;i<n;i++){
				err[i]=0;
			}
			for(i=0;i<n-1;){
				String[] ss=new String[0];
				if(ddl[i].contains("=")){
					ss=Pattern.compile("\\s*=\\s*").split(ddl[i]);
				}else{
					ss=Pattern.compile("\\s+").split(ddl[i]);
				}
				j=0;
				if(ss[0].equals("")){
					j=1;
				}
				if(ss[j].equalsIgnoreCase("dcl")){
					Integer tempi=used.get(ss[j+1]);
					if(tempi==null){
						used.put(ss[j+1], 0);
						map.put(ss[j+1], 0);
					}else if(tempi.equals(0)){
						err[i+1]=1;
					}else{
						used.put(ss[j+1], 0);
						map.put(ss[j+1], 0);
					}
					i++;
				}
				else if(ss[j].equalsIgnoreCase("inc")){
					Integer tempi=used.get(ss[j+1]);
					if(tempi==null){
						err[i+1]=2;
					}else if(tempi.equals(0)){
						used.put(ss[j+1], 1);
						map.put(ss[j+1],new Integer( map.get(ss[j+1]).intValue()+1));
					}else{
						map.put(ss[j+1],new Integer( map.get(ss[j+1]).intValue()+1));
					}
					i++;
				}
				else if(ss[j].equalsIgnoreCase("goto")){
					Integer tempi=used.get(ss[j+1]);
					if(tempi==null){
						err[i+1]=2;
						i++;
					}else if(tempi.equals(0)){
						used.put(ss[j+1], 1);
						int tempg=map.get(ss[j+1]).intValue();
						if(tempg>0){
							i=new Integer(ss[j+2]).intValue()-1;
						}else{
							i++;
						}
					}else{
						int tempg=map.get(ss[j+1]).intValue();
						if(tempg>0){
							i=new Integer(ss[j+2]).intValue()-1;
						}else{
							i++;
						}
					}
				}
				else{
					ss[j]=ss[j].trim();
					Integer tempi=used.get(ss[j]);
					if(tempi==null){
						err[i+1]=2;
					}else if(tempi.equals(0)){
						used.put(ss[j], 1);
						map.put(ss[j], new Integer(ss[j+1]));
					}else{
						map.put(ss[j], new Integer(ss[j+1]));
					}
					i++;
				}
			}
			System.out.println(cases);
			for(i=1;i<n;i++){
				if(err[i]!=0){
					System.out.println(i+" "+err[i]);
				}
			}
		}

	}

}
