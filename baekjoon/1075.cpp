#include <iostream>
using namespace std;

int main()
{
    int n, f;

    cin >> n >> f;

    int div = n % 100;

    int dlatl = n - div;

    int x = dlatl % f;

    if (x == 0)
    {
        cout << "00";
        return 0;
    }

    int dlatl2 = (f - x) % 100;

    if (dlatl2 >= 0 && dlatl2 <= 9)
    {
        cout << "0" << dlatl2;
        return 0;
    }
    else
    {
        cout << dlatl2;
        return 0;
    }
}