#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;
    long int n_sum = 0; // n까지 더한 값

    vector<vector<int>> v(n, vector<int>(n, 0));

    for (int i = 1; i <= n; i++)
    {
        n_sum += i;
    }
    cout << n_sum;

    vector<int> v(n_sum, 0);
    int idx = 0;

    {
        for (int i = 0; i < n; i++)
        {
            v[idx] = i + 1;
            idx += i + 1;
        }
        idx -= n;
        int preidx = idx;
        idx++;
        for (int i = n + 1; idx <= n_sum; i++)
        {
            v[idx++] = i;
        }
        for (int i = preidx - 1; i > 1; i--)
        {
        }
    }
    cout << '\n';
    for (int i = 0; i < n_sum; i++)
    {
        cout << v[i] << ", ";
    }
}