#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    string str[10];

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> str[i];
    }
    for (int i = 0; i < t; i++)
        cout << str[i].front() << str[i].back() << "\n";
}