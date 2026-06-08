#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> num(t);
    vector<string> str(t);
    for (int i = 0; i < t; i++)
    {
        cin >> num[i] >> str[i];
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < str[i].length(); j++)
            for (int k = 0; k < num[i]; k++)
                cout << str[i][j];
        cout << '\n';
    }
}