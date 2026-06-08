package 수열편집;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc =1; tc<=T; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int L = Integer.parseInt(st.nextToken());
			
			List<Integer> list = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++) {
				list.add(Integer.parseInt(st.nextToken()));
			}
			
			
			for(int i=0;i<M;i++) {
				st = new StringTokenizer(br.readLine());
				String key = st.nextToken();
				if(key.equals("I")) {
					int index = Integer.parseInt(st.nextToken());
					int item = Integer.parseInt(st.nextToken());
					list.add(index, item);
				}else if(key.equals("D")) {
					int index = Integer.parseInt(st.nextToken());
					list.remove(index);
				}else if(key.equals("C")) {
					int index = Integer.parseInt(st.nextToken());
					int item =Integer.parseInt(st.nextToken());
					list.set(index, item);
				}
			}
			
			System.out.println("#"+tc+" "+((list.size()>L)?list.get(L):-1));
		}
	}
}
