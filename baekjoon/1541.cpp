#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    bool isMinus = false;
    int res = 0;
    string num;

    cin >> str;

    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == '-' || str[i] == '+' || i == str.size())
        {
            if (isMinus)
            {
                res -= stoi(num);
                num = "";
            }
            else
            {
                res += stoi(num);
                num = "";
            }
        }
        else
        {
            num += str[i];
        }
        if (str[i] == '-')
            isMinus = true;
    }
    cout << res;
}
