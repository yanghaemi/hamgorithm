#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int longnum = n / 4;

    for (int i = 0; i < longnum; i++)
    {
        cout << "long ";
    }
    cout << "int";
}