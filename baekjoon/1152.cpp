#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int num = 1;
    if (str[0] == ' ')
        num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            num++;
    }
    if (str[str.length() - 1] == ' ')
        num--;
    cout << num;
}