#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> res;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int x1, y1, x2, y2;
        double r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if (d == 0 && r1 == r2)
            res.push_back(-1);
        else if (d > r1 + r2 || d < abs(r1 - r2))
            res.push_back(0);
        else if (d == r1 + r2 || d == abs(r1 - r2))
            res.push_back(1);
        else if (d < r1 + r2)
            res.push_back(2);
    }
    for (int i = 0; i < t; i++)
        cout << res[i] << '\n';
}