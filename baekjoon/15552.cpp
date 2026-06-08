#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    vector<int> A(T);
    vector<int> B(T);
    for (int i = 0; i < T; i++)
    {
        cin >> A.at(i) >> B.at(i);
    }
    for (int i = 0; i < T; i++)
    {
        cout << A.at(i) + B.at(i) << endl;
    }
}