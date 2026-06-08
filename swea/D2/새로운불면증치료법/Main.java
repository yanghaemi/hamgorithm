package 새로운불면증치료법;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++) {
			int originN = Integer.parseInt(br.readLine());

			int num = 1;
			Set<Character> s = new HashSet<>();

			while(true) {
				int multipleN = originN * num;
				String N = String.valueOf(multipleN);
				int n = N.length();	
				for(int i =0;i<n;i++) {
					s.add(N.charAt(i));
				}
				if(s.size() == 10) {
					System.out.println("#"+tc+" "+multipleN);
					break;
				}
				num++;
			}
			
		}
	}
}
