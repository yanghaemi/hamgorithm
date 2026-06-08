#include <iostream>
using namespace std;
int main()
{
    double a, b = 1;
    cin >> a >> b;
    if (a > 0 && b < 10)
    {
        cout << fixed;
        cout.precision(9); 
        cout << a / b;
    }

    return 0;
}
