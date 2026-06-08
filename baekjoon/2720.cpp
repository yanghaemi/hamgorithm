#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int main()
{
    int t;
    cin >> t;

    vector<int> v(t), q(t), d(t), n(t), p(t);

    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < t; i++)
    {
        q[i] = v[i] / 25;
        v[i] %= 25;
        d[i] = v[i] / 10;
        v[i] %= 10;
        n[i] = v[i] / 5;
        v[i] %= 5;
        p[i] = v[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout << q[i] << " " << d[i] << " " << n[i] << " " << p[i] << '\n';
    }
}