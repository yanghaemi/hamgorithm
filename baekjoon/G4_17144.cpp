#include <iostream>
#include <vector>
using namespace std;

int main(){
    int R, C, T;
    cin >> R>>C>>T;

    vector<vector<int>> v(R+2, vector<int>(C+2,0));

    int machine_x = 1;
    int machine_y = 0;


    for(int r=1;r<=R;r++){
        for(int c =1 ;c<=C;c++){
            int tmp;
            cin >> tmp;
            if(machine_y == 0)  // x는 항상 1이므로 생략
            {
                if(tmp == -1){  // 공기청정기 위치 저장
                machine_y = r;
                v[r+1][c] = -1;
                
                }
            }
            v[r][c] = tmp;
        }
    }

    int dx[4] = {1, -1, 0, 0}; // 우, 좌, 하, 상
    int dy[4] = {0, 0, 1, -1};


    for(int t=0;t<T;t++){ // 미세먼지 움직임
        vector<vector<int>> v2(R+2, vector<int>(C+2,0));
        v2[machine_y][1] = -1;
        v2[machine_y+1][1] = -1;

        for(int r=1;r<=R;r++){
            for(int c =1 ;c<=C;c++){
                if(v[r][c] && (v[r][c] !=-1)){    // 미세먼지 있으면

                    int num = 0;
                    for(int dir=0; dir<4; dir++){
                        int nx = c+dx[dir];
                        int ny = r+dy[dir];

                        if(nx > 0 && nx <= C && ny >0 && ny <= R && v[ny][nx] != -1){
                            num ++; // 가능 방향 개수 세기
                        }
                    }

                    int tmp =v[r][c]/5; 
                    for(int dir=0; dir<4; dir++){
                        int nx = c+dx[dir];
                        int ny = r+dy[dir];

                        if(nx > 0 && nx <= C && ny >0 && ny <= R && v[ny][nx] != -1){
                            v2[ny][nx] += tmp;
                        }
                    }

                    v2[r][c] += v[r][c] - (tmp * num); 
                }
            }
        }

        // for(int r=1;r<=R;r++){
        //     for(int c =1 ;c<=C;c++){
        //         cout << v2[r][c] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout <<"-------hs\n";

        v=v2;


        // 공기청정기 작동
        v2[machine_y][2] = 0;
        v2[machine_y+1][2] = 0;

        for(int c=2;c<C;c++){ // 우측 이동
            v2[machine_y][c+1] = v[machine_y][c];
            v2[machine_y + 1][c+1] = v[machine_y+1][c];
        }
        for(int r=machine_y; r > 1; r--){    // 공기청정기 위쪽: 위로 이동
            v2[r-1][C] = v[r][C];
        }
        for(int r=(machine_y+1);r<R;r++){  // 공기청정기 아래쪽: 아래로 이동
            v2[r+1][C] = v[r][C];
        }
        for(int c=C;c > 1;c--){ // 좌측 이동
            v2[1][c-1] = v[1][c];
            v2[R][c-1] = v[R][c];
        }
        for(int r=1; v[r+1][1] != -1;r++){ // 공기청정기 위쪽: 아래로 이동
            v2[r+1][1] = v[r][1]; 
        }
        for(int r=R; v[r-1][1] != -1;r--){ // 공기청정기 아래쪽 : 위로 이동
            v2[r-1][1] = v[r][1];
        }

        v=v2;

        // for(int r=1;r<=R;r++){
        //     for(int c =1 ;c<=C;c++){
        //         cout << v[r][c] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout <<"-------\n";
    }

    int sum = 0;
    for(int r=1;r<=R;r++){
        for(int c =1 ;c<=C;c++){
            if(v[r][c] != -1){
                sum += v[r][c];
            }
        }
    }

    cout << sum <<'\n';
}
