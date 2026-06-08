#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> num(n);

    for (int i = 0; i < n; i++)
        cin >> num[i];

    if (n == 1)
    {
        cout << num[0] * num[0];
        return 0;
    }

    int max = -999, min = 999;

    for (int i = 0; i < n; i++)
    {
        if (num[i] > max)
            max = num[i];
        if (num[i] < min)
            min = num[i];
    }

    cout << min * max;
}