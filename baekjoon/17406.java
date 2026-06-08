//package 배열돌리기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 순열 + 구현
public class Main {

    static int min = Integer.MAX_VALUE;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int arr[][] = new int[N + 2][M + 2];


        for (int n = 1; n <= N; n++) {
            st = new StringTokenizer(br.readLine());

            for (int m = 1; m <= M; m++) {
                arr[n][m] = Integer.parseInt(st.nextToken());
            }
        }

        int r[] = new int[K];
        int c[] = new int[K];
        int s[] = new int[K];

        for (int k = 0; k < K; k++) {

            st = new StringTokenizer(br.readLine());

            r[k] = Integer.parseInt(st.nextToken());
            c[k] = Integer.parseInt(st.nextToken());
            s[k] = Integer.parseInt(st.nextToken());
        }

        permutation(arr, r, c, s, 0, K);

        System.out.println(min);
    }

    public static int setMin(int min, int[][] arr, int N, int M){
        for (int n = 1; n <= N; n++) {
            int sum = 0;
            for (int m = 1; m <= M; m++) {
                sum += arr[n][m];
            }
            min = Math.min(min, sum);
        }
        
        return min;
    }

    public static void permutation(int arr[][],int[] r, int[] c, int[] s, int depth, int K){

        if(depth == K){
            solution(arr, r, c, s, arr.length-2, arr[0].length-2, K);
            return;
        }

        for(int i= depth; i< K; i++){
            swap(r, c, s, depth, i);
            permutation(arr, r, c, s, depth+1, K);
            swap(r, c, s, depth, i);
        }
    }

    static void solution(int[][] arr, int[] r, int[] c, int[]s, int N, int M, int K){
        for(int idx=0;idx<K;idx++){

            int arr2[][] = new int[N + 2][M + 2];
            for (int n = 1; n <= N; n++) {
                for (int m = 1; m <= M; m++) {
                    arr2[n][m] = arr[n][m];
                }
            }

            int y1 = r[idx] - s[idx];
            int x1 = c[idx] - s[idx];
            int y2 = r[idx] + s[idx];
            int x2 = c[idx] + s[idx];

            for (int i = 0; i < s[idx]; i++) {


                for (int j = x1; j < x2; j++) {
                    arr2[y1][j + 1] = arr[y1][j];
                }
                for (int j = y1; j < y2; j++) {
                    arr2[j + 1][x2] = arr[j][x2];
                }
                for (int j = x2; j > x1; j--) {
                    arr2[y2][j - 1] = arr[y2][j];
                }
                for (int j = y2; j > y1; j--) {
                    arr2[j - 1][x1] = arr[j][x1];

                }
                x1++;
                y1++;
                x2--;
                y2--;
            }

            arr = arr2.clone();
        }
        min = setMin(min, arr, N, M);

    }

    static void swap(int[] r, int[] c,int[] s,  int depth, int i){
        int temp1 = r[depth];
        r[depth] = r[i];
        r[i]= temp1;

        int temp2 = c[depth];
        c[depth] = c[i];
        c[i]= temp2;

        int temp3 = s[depth];
        s[depth] = s[i];
        s[i]= temp3;
    }
    
}
