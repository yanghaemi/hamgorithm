#include <iostream>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    int a[10000], b[10000];
    for (int i = 0; i < t; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout << a[i] + b[i] << "\n";
    }
    return 0;
}