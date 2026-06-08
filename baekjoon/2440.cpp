#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int nn = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            cout << "*";
        }
        cout << "\n";
        nn--;
    }
}