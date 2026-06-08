#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int num = 0;
    string str;
    vector<int> alphabet(26, -1);

    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (alphabet[str[i] - 97] == -1)
        {
            alphabet[int(str[i] - 97)] = num++;
        }
        else
            num++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }
}