#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string dump;
    vector<int> colornum(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> dump;
        switch (dump[0])
        {
        case 'b':
            if (dump[2] == 'a')
                colornum[i] = 0;
            else if (dump[1] == 'r')
                colornum[i] = 1;
            else
                colornum[i] = 6;
            break;
        case 'r':
            colornum[i] = 2;
            break;
        case 'o':
            colornum[i] = 3;
            break;
        case 'y':
            colornum[i] = 4;
            break;
        case 'g':
            if (dump[3] == 'e')
                colornum[i] = 5;
            else
                colornum[i] = 8;
            break;
        case 'v':
            colornum[i] = 7;
            break;
        case 'w':
            colornum[i] = 9;
            break;
        default:
            break;
        }
    }
    int flag = 0;
    if (colornum[0] == 0 && colornum[1] == 0)
        flag = 1;

    cout << (colornum[0] * 10 + colornum[1]);
    for (int i = 0; flag == 0 && i < colornum[2]; i++)
        cout << "0";
}