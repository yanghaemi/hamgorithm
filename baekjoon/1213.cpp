#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    string str;
    cin >> str;

    map<char, int> m;
    vector<char> v;

    for (int i = 0; i < str.length(); i++)
    {
        if (m.find(str[i]) != m.end())
            m[str[i]]++;
        else
            m.insert({str[i], 1});
    } // O(n)

    int odd = 0, even = 0;
    char oddidx = 0;

    for (auto iter : m)
    {
        if (iter.second % 2 - 1 == 0)
        {
            oddidx = iter.first;
            odd++;
        }
        if (odd > 1)
        {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        for (int i = 0; i < iter->second / 2; i++)
        {
            cout << iter->first;
            v.push_back(iter->first);
        }
    }
    if (odd == 1)
        cout << oddidx;
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i];
}