#include <iostream>
#include <vector>
using namespace std;

int answer;

void DFS(vector<vector<char>> &v, vector<vector<int>> &visit, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j])
            {
                visit[i][j] = 1;
                if (v[i][j] == '-')
                {
                    int mj = j;
                    while (1)
                    {
                        mj++;
                        if (mj >= 0 && mj < m && v[i][mj] == '-')
                        {
                            visit[i][mj] = 1;
                        }
                        else
                        {
                            answer++;
                            break;
                        }
                    }
                }
                else if (v[i][j] == '|')
                {
                    int mi = i;
                    while (1)
                    {
                        mi++;
                        if (mi >= 0 && mi < n && v[mi][j] == '|')
                        {
                            visit[mi][j] = 1;
                        }
                        else
                        {
                            answer++;
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n; // 세로 크기
    int m; // 가로 크기

    cin >> n >> m;

    vector<vector<int>> visit(n, vector<int>(m, 0)); // 방문 여부 벡터
    vector<vector<char>> v(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    DFS(v, visit, n, m);
    cout << answer;
}