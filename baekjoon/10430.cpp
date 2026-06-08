#include <iostream>
using namespace std;
#define endl "\n"

int main()
{
    int a, b, c = 0;
    cin >> a >> b >> c;
    cout << (a + b) % c << endl;
    cout << ((a % c) + (b % c)) % c << endl;
    cout << (a * b) % c << endl;
    cout << ((a % c) * (b % c)) % c << endl;
}