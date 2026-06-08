#include <iostream>
#include <vector>
using namespace std;

int res = 0;
int n;
int flag = 0;

void DP(vector<int> &v)
{

    if (flag == 1)
    {
        res += v[n - 2];
        n = n - 2;
        flag = 0;
    }
    else
    {
        // 같은 것도 고려해야됨 ~~~ 3 30 30 10
        //  cout << "현재 v:" << n << ":" << v[n] + v[n - 1] << ", " << v[n] + v[n - 2] << '\n';
        if (v[n] + v[n - 1] > v[n] + v[n - 2])
        {
            res += v[n - 1];
            flag++;
            n--;
        }
        else
        {
            res += v[n - 2];
            n = n - 2;
            flag = 0;
        }
    }

    if (n - 1 >= 0)
        DP(v);
    else
    {
        return;
    }
}

int main()
{

    cin >> n; // 계단 개수
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i]; // 계단 data
    }
    if (n == 1)
    {
        cout << v[1];
        return 0;
    }
    res = v[n];
    DP(v);
    cout << res;
}