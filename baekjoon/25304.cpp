#include <iostream>
using namespace std;
int main()
{
    int n, x = 0;
    int a[100], b[100];
    cin >> n >> x;
    int res = 0;

    for (int i = 0; i < x; i++)
    {
        cin >> a[i] >> b[i];
        res += a[i] * b[i];
    }

    if (n == res)
        cout << "Yes";
    else
        cout << "No";
}
