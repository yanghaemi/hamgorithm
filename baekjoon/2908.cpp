#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string n1, n2;
    cin >> n1 >> n2;

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    if (n1 > n2)
        cout << n1;
    else
        cout << n2;
}