#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N = 0, cnt = 1, blind_cnt = 1;
char C = ' ';

int x = 0, y = 0;

int BFS(vector<vector<int>> &visit, vector<vector<char>> v, int x, int y, int cnt)
{

    int move_x[4] = {1, 0, -1, 0};
    int move_y[4] = {0, 1, 0, -1};

    visit[y][x] = 1; //(x,y) 방문

    for (int i = 0; i < 4; i++) // 4방향 탐색
    {
        int ax = x + move_x[i], ay = y + move_y[i];

        if (ax >= 0 && ay >= 0 && ax < N && ay < N)
        {
            if (v[ay][ax] == C && visit[ay][ax] == 0)
            {
                BFS(visit, v, ax, ay, cnt);
            }
        }
        else
            continue;
    }

    return cnt;
}

int main()
{
    cin >> N;
    if (N == 0)
        cout << "0 0";

    vector<vector<char>> v(N, vector<char>(N, 0));
    vector<vector<char>> blind_v(N, vector<char>(N, 0));
    vector<vector<int>> visit(N, vector<int>(N, 0));
    vector<vector<int>> blind_visit(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'G')
                blind_v[i][j] = 'R';
            else
                blind_v[i][j] = v[i][j];
        }
    }
    C = v[0][0];
    BFS(visit, v, 0, 0, cnt);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j] == 0)
            {
                ++cnt;
                C = v[i][j];
                BFS(visit, v, j, i, cnt);
            }
        }
    }
    C = blind_v[0][0];
    BFS(blind_visit, blind_v, 0, 0, blind_cnt);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (blind_visit[i][j] == 0)
            {
                ++blind_cnt;
                C = blind_v[i][j];
                BFS(blind_visit, blind_v, j, i, blind_cnt);
            }
        }
    }
    cout << cnt << " " << blind_cnt;
}