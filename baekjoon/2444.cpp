#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nn = n;
    int nnn = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nn - 1; j++)
        {
            cout << ' ';
        }
        nn--;
        for (int j = 1; j < nnn * 2; j++)
        {
            cout << "*";
        }
        cout << '\n';
        nnn++;
    }
    nn = 1;
    nnn = n - 1;
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < nn; j++)
        {
            cout << ' ';
        }
        nn++;
        for (int j = 1; j < nnn * 2; j++)
        {
            cout << "*";
        }
        cout << '\n';
        nnn--;
    }
}