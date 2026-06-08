#include <iostream>
using namespace std;
#define endl "\n"

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    cout << n1 * (n2 % 10) << endl;
    cout << n1 * ((n2 % 100) / 10) << endl;
    cout << n1 * (n2 / 100) << endl;
    cout << n1 * n2;
}