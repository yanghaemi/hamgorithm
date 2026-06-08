package 암호문3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int tc=1;tc<=10;tc++) {
			int N = Integer.parseInt(br.readLine());
			List<Integer> list = new ArrayList<>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++) {
				list.add(Integer.parseInt(st.nextToken()));
			}
			int M = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<M;i++) {
				String key = st.nextToken();
				if(key.equals("I")) {
					int idx = Integer.parseInt(st.nextToken());
					int num = Integer.parseInt(st.nextToken());
					for(int j=0;j<num;j++) {
						list.add(idx++, Integer.parseInt(st.nextToken()));
					}
				}else if(key.equals("A")) {
					int num = Integer.parseInt(st.nextToken());
					for(int j=0;j<num;j++) {
						list.add(Integer.parseInt(st.nextToken()));
					}
				}else if(key.equals("D")) {
					int idx = Integer.parseInt(st.nextToken());
					int num = Integer.parseInt(st.nextToken());
					for(int j=0;j<num;j++) {
						list.remove(idx);
					}
				}
			}
			
			System.out.print("#"+tc+" ");
			for(int i=0;i<10;i++) {
				System.out.print(list.get(i)+" ");
			}
			System.out.println();
		}
	}
}
