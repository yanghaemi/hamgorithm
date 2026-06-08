#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> mung(n + 1);
    int i, j, k = 0;

    for (int l = 0; l < m; l++)
    {
        cin >> i >> j >> k;
        for (int p = i; p <= j; p++)
            mung.at(i++) = k;
    }
    for (int ll = 1; ll <= n; ll++)
        cout << mung.at(ll) << " ";
}