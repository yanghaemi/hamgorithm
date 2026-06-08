package 가랏RC카;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc=1;tc<=T;tc++) {
		
			int N = Integer.parseInt(br.readLine());
			int v = 0; // 속도
			int m = 0; // 거리
			
			for(int i=0;i<N;i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int command = Integer.parseInt(st.nextToken());
				if(command != 0) {
					int n = Integer.parseInt(st.nextToken());
					
					if(command == 1) {
						v+=n;
					}else if(command == 2) {
						if(v < n) { // 현재 속도보다 감속할 속도가 더 큰 경우 0m/s
							v = 0;
						}else {
							v-=n;
						}
					}
				}
				m += v;
			}
			
			System.out.println("#"+tc+" "+m);
		}
	}
}
