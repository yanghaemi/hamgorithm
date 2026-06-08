#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int move_x[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int move_y[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int ly, lx; // last_y, fist_x
int fy, fx; // first_y, first_x
int result;

int m; // 체스판 한 변의 길이

int BFS(vector<vector<int>> &v, queue<pair<int, int>> &q1, queue<pair<int, int>> &q2)
{
    int y = q1.front().first;
    int x = q1.front().second; // 큐에서 꺼내기
    q1.pop();
    for (int i = 0; i < 8; i++)
    {
        int flag_y = 0, flag_x = 0; // 임시 좌표
        flag_y = y + move_y[i];
        flag_x = x + move_x[i];

        if (flag_y < m && flag_y >= 0 && flag_x < m && flag_x >= 0 && v[flag_y][flag_x] != 1) // 방문 안 한 곳
        {

            if (v[flag_y][flag_x] == 3) // 이동 성공
            {
                return ++result;
            }
            else
            {
                q2.push(make_pair(flag_y, flag_x)); // 큐에 넣기
                v[flag_y][flag_x] = 1;              // 방문 표시
            }
        }
    }

    if (q1.empty() && !q2.empty())
    {
        // for (int j = 0; j < m; j++)
        // {
        //     for (int k = 0; k < m; k++)
        //     {
        //         cout << v[j][k] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << "----------\n";
        result++;    // 큐가 바뀐다는 건 이동을 한 번 했다는 것!
        q1.swap(q2); // 스왑해줌
        BFS(v, q1, q2);
    }
    else
    {
        BFS(v, q1, q2);
    }
    return result; // 추가했더니 됨;;;
}

int solution()
{

    queue<pair<int, int>> q1; // 좌표 넣을 큐
    queue<pair<int, int>> q2; // 다음 좌표 넣을 큐

    result = 0; // 결과 초기화

    cin >> m;

    vector<vector<int>> v(m, vector<int>(m, 0));

    cin >> fy >> fx;
    cin >> ly >> lx;

    v[fy][fx] = 2; // 처음 장소 방문 처리
    v[ly][lx] = 3; // 3: 가야 하는 곳

    if (fy == ly && fx == lx)
        return 0;

    q1.push(make_pair(fy, fx)); // 시작

    BFS(v, q1, q2);
    return result;
}

int main()
{
    int n; // 테스트 케이스 횟수
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << solution() << '\n';
    }

    return 0;
}