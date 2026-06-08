#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, flag = 1;

    cin >> n;

    vector<string> filename(n);

    for (int i = 0; i < n; i++)
    {
        cin >> filename[i];
    }

    vector<char> output;

    for (int j = 0; j < filename[0].length(); j++)
    {
        flag = 1;
        for (int i = 0; i < n - 1; i++)
        {

            if (filename[i][j] != filename[i + 1][j])
                flag = 0;
        }
        if (flag == 1)
            output.push_back(filename[0][j]);
        else
            output.push_back('?');
    }

    for (int j = 0; j < filename[0].length(); j++)
        cout << output[j];
}