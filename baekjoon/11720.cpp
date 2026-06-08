#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;

    cin >> str;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        res += str[i] - '0';
    }

    cout << res;
}