#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int count = 0;

    for (int i = 0; i < str.size(); i++)
    {
        count++;
        if (str[i + 1] == '=' || str[i + 1] == '-')
        {
            i++;
            cout << "case 1\n";
            continue;
        }
        else if (str[i] == 'd' || str[i + 1] == 'z' && str[i + 2] == '=')
        {
            i += 2;
            cout << "case 2\n";
            continue;
        }
        else if ((str[i] == 'n' || str[i] == 'l') && str[i + 1] == 'j')
        {
            i++;
            continue;
        }
        cout << "counting \n";
    }

    cout << count;
}
