#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v.at(i);
    }

    int find;
    cin >> find;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (v.at(i) == find)
            num++;
    }

    cout << num;
}