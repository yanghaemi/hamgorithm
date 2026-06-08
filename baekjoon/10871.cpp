#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x = 0;
    cin >> n >> x;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (v.at(i) < x)
            cout << v.at(i) << " ";
    }
}