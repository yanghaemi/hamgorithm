#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int t;

    cin >> t;

    int an, bn, nn;

    vector<int> a, b, n;

    for (int i = 0; i < t; i++)
    {
        cin >> an >> bn;

        a.push_back(an);
        b.push_back(bn);
    }

    for (int i = 0; i < t; i++)
    {
        nn = 1;
        for (int j = 0; j < b[i]; j++)
        {
            nn = (nn * a[i]) % 10;
        }
        n.push_back(nn);
    }

    for (int i = 0; i < t; i++)
    {
        if (n[i] != 0)
        {
            cout << n[i] << '\n';
        }
        else
            cout << "10" << '\n';
    }
}