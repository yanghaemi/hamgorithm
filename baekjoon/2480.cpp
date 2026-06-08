#include <iostream>
using namespace std;
#define endl '\n'

int main()
{
    int n[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        cin >> n[i];
    }
    if (n[0] == n[1] && n[1] == n[2])
    {
        cout << 10000 + n[0] * 1000;
        return 0;
    }
    else if (n[0] == n[1] || n[1] == n[2] || n[0] == n[2])
    {
        int a;
        if (n[0] == n[1] || n[0] == n[2])
            a = n[0];
        else
            a = n[1];
        cout << 1000 + a * 100;
        return 0;
    }
    else
    {
        int max = -9999;
        for (int i = 0; i < 3; i++)
        {
            if (max < n[i])
                max = n[i];
        }
        cout << max * 100;
        return 0;
    }
}