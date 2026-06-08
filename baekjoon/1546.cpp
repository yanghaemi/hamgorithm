#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = -99;

    vector<double> grade(n);
    for (int i = 0; i < n; i++)
        cin >> grade[i];

    for (int i = 0; i < n; i++)
        if (max < grade[i])
            max = grade[i];

    double res = 0;

    for (int i = 0; i < n; i++)
    {

        grade[i] = grade[i] / max * 100;
        res += grade[i];
    }
    res /= n;
    cout << res;
}