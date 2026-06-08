#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v(9);

    for (int i = 0; i < 9; i++)
    {
        cin >> v.at(i);
    }
    int idx = 0;
    int max = -1;
    for (int i = 0; i < 9; i++)
    {
        if (max < v.at(i))
        {
            max = v.at(i);
            idx = i;
        }
    }
    cout << max << '\n'
         << idx + 1;
}