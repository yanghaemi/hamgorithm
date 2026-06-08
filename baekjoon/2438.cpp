#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int nn = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            if (nn != n + 1)
            {
                cout << "*";
            }
            else
                break;
        }
        nn++;
        cout << "\n";
    }
}