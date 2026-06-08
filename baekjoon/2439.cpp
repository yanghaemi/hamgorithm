#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nn = 1;
    int nnn = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nnn - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < nn; j++)
        {
            if (n + 1 != nn)
                cout << "*";
            else
                break;
        }
        nn++;
        nnn--;
        cout << '\n';
    }
}