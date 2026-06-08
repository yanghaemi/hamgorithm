#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    int min = 1000000;
    int max = -1000000;

    for (int i = 0; i < n; i++)
    {
        cin >> v.at(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (v.at(i) < min)
            min = v.at(i);
        if (v.at(i) > max)
            max = v.at(i);
    }
    cout << min << " " << max;
}