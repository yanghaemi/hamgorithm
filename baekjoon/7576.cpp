#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, day = 0, flag = 0;
queue<pair<int, int>> q;
queue<pair<int, int>> next_q;

void BFS(vector<vector<int>> &v)
{
    int move_x[4] = {-1, 0, 1, 0};
    int move_y[4] = {0, -1, 0, 1};
    int y = q.front().first, x = q.front().second;

    int xx = 0, yy = 0;

    for (int i = 0; i < 4; i++)
    {

        xx = x + move_x[i], yy = y + move_y[i];
        if (xx >= 0 && xx < m && yy >= 0 && yy < n)
        {
            if (v[yy][xx] == 0)
            {
                next_q.push(make_pair(yy, xx));
                v[yy][xx] = 1;
            }
            else
                continue;
        }
        else
        {
            continue;
        }
    }

    q.pop();
}

int main()
{
    cin >> m >> n;
    int num;

    vector<vector<int>> v(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            v[i][j] = num;

            if (num == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }
    while (!q.empty())
        BFS(v);

    while (!next_q.empty())
    {
        swap(q, next_q);

        while (!q.empty())
        {

            BFS(v);
        }
        day++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                cout << "-1";
                return 0;
            }
        }
    }

    cout << day;
    return 0;
}