package 이진수표현;

import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc=1; tc<=T; tc++) {
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			boolean flag = true;
			
			for(int i=0;i<N;i++) {
				if((M & (1<<i))==0) {
					flag = false;
					break;
				}
			}
			
			System.out.println("#"+tc+" "+((flag)?"ON":"OFF"));
		}
	}
}
