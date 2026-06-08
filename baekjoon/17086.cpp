#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;

int n;
int m;

int move_x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int move_y[8] = {0, 1, 0, -1, 1, -1, 1, -1};
queue<pair<int, int>> s;
int safe = 0;     // 안전거리
int big_safe = 0; // 안전거리 최댓값

void BFS(vector<vector<int>> &v, vector<vector<int>> &visit, int px, int py)
{
    s.push(make_pair(px, py));
    visit[py][px] = 1;

    while (!s.empty())
    {
        int xx = s.front().first;
        int yy = s.front().second;
        s.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = xx + move_x[i];
            int y = yy + move_y[i];

            if (x >= 0 && x < m && y >= 0 && y < n && visit[y][x] == 0)
            {

                if (v[y][x] == 1)
                {

                    safe = pow(pow(px - x, 2) + pow(py - y, 2), 0.5) - 1;

                    while (!s.empty())
                        s.pop();
                    return;
                }
                visit[y][x] = 1;
                s.push(make_pair(x, y));
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));        // n*m 벡터
    vector<vector<int>> visit(n, vector<int>(m, 0)); // 방문 여부 벡터

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                vector<vector<int>>::iterator iter;
                for (iter = visit.begin(); iter != visit.end(); iter++)
                {
                    fill(iter->begin(), iter->end(), 0);
                }
                BFS(v, visit, j, i); // 각 시점에 대해 BFS 실행

                big_safe = max(big_safe, safe);
            }
        }
    }

    cout << "big_safe : " << big_safe;
    return 0;
}