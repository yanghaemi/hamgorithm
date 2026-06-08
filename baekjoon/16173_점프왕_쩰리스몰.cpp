#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int flag = 0;
int x_move[2] = {1, 0}; // ➡️⬇️
int y_move[2] = {0, 1};

// void BFS(int n, vector<vector<int>> &v, int py, int px)
// {

//     for (int i = 0; i < 2; i++)
//     {
//         int cx = px + (x_move[i] * v[py][px]);
//         int cy = py + (y_move[i] * v[py][px]);

//         if (cx >= 0 && cx < n && cy >= 0 && cy < n)
//         {
//             if (v[cy][cx] == -1)
//             {
//                 flag = 1;
//                 return;
//             }

//             BFS(n, v, cy, cx);
//         }
//     }

//     return;
// }

int main()
{
    int n; // 게임 구역의 크기
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n)); // 게임판의 구역(맵)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    stack<pair<int, int>> s;
    s.push(make_pair(0, 0)); // 첫 번째 좌표 스택에 넣어주기

    while (!s.empty())
    {
        int y = s.top().first;
        int x = s.top().second;
        s.pop();

        int d = v[y][x];

        for (int i = 0; i < 2; i++)
        {
            int cx = x + (x_move[i] * d);
            int cy = y + (y_move[i] * d);

            if (cx >= 0 && cx < n && cy >= 0 && cy < n)
            {
                if (v[cy][cx] == -1)
                {
                    cout << "HaruHaru";
                    return 0;
                }
                else if (v[cy][cx] == 0)
                {
                    continue;
                }
                else
                {
                    s.push(make_pair(cy, cx));
                }
            }
        }
    }

    cout << "Hing";

    return 0;
}