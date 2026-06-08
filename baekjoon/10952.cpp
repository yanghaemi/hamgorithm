#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int main()
{
    vector<int> a, b;

    int num = 0;
    while (cin >> num && num != 0)
    {
        a.push_back(num);
        cin >> num;
        b.push_back(num);
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a.at(i) + b.at(i) << "\n";
    }
}