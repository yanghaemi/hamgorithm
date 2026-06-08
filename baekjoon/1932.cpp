#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int maxSum = 0;
int move_x[2] = {0, 1};
int move_y[2] = {1, 1}; // 아래나 대각선 오른쪽아래로 이동

void solution(vector<vector<int>> v, int n, int px, int py, int sum)
{
    int x = px;
    int y = py;
    int presum = sum;

    for (int j = 0; j < 2; j++)
    {
        sum = presum;
        int xx = x + move_x[j];
        int yy = y + move_y[j];
        if (v[yy][xx] != -1)
        {
            if (yy == n - 1)
            {
                int presum = sum;
                sum += v[yy][xx];
                maxSum = max(sum, maxSum);
                // cout << v[yy][xx] << "| x : " << xx << ", y : " << yy << ", sum : " << sum << ", maxSum: " << maxSum << "\n--------------\n";
                continue;
            }
            else
            {
                sum += v[yy][xx];
                // cout << v[yy][xx] << "| x : " << xx << ", y : " << yy << ", sum : " << sum << '\n';

                solution(v, n, xx, yy, sum);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> v[i][j];
        }
    }

    solution(v, n, 0, 0, v[0][0]);
    cout << maxSum;
}