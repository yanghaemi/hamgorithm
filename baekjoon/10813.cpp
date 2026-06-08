#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, temp, num1, num2;

    cin >> n >> m;
    vector<int> v(n);

    for (int i = 1; i <= n; i++)
    {
        v[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> num1 >> num2;
        temp = v[num1];
        v[num1] = v[num2];
        v[num2] = temp;
    }

    for (int i = 1; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << v[n];
}