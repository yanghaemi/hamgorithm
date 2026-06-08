#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; // 집의 수

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end()); // 정렬

    int mididx = (n - 1) / 2; // 중간값

    cout << v[mididx];
}