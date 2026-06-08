#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }

    vector<char> ch;

    int f = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (ch.empty())
            ch.push_back(str[i]);
        for (int j = 0; j < ch.size(); j++)
        {
            if (ch[j] == str[i])
            {
                f = 1;
                break;
            }
        }
        if (f != 1)
        {
            ch.push_back(str[i]);
        }
        f = 0;
    }

    vector<int> flag(ch.size());

    for (int i = 0; i < ch.size(); i++)
    {
        flag[i] = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (ch[i] == str[j])
            {
                flag[i]++;
            }
        }
    }

    int max = -999;
    int maxidx = 0;

    for (int i = 0; i < flag.size(); i++)
    {
        if (max < flag[i])
        {
            max = flag[i];
            maxidx = i;
            f = 0;
        }
        else if (max == flag[i])
        {
            f = 2;
        }
    }

    if (f == 2)
    {
        cout << "?";
    }
    else if (f == 0)
    {
        cout << ch[maxidx];
    }

    return 0;
}