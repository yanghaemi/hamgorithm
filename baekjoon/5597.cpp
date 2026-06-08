#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> n(30);
    int num;
    for (int i = 0; i < 28; i++)
    {
        cin >> num;
        n[num - 1] = 1;
    }
    for (int i = 0; i < 30; i++)
    {
        if (n[i] != 1)
            cout << i + 1 << '\n';
    }
}