#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, num = 0;
    cin >> n;

    set<int> a;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a.insert(num);
    }
    cin >> m;
    vector<int> b(m);

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    set<int>::iterator iter;
    for (int i = 0; i < m; i++)
    {

        iter = a.find(b[i]);

        if (iter != a.end())
        {
            cout << "1" << '\n';
        }
        else
            cout << "0" << '\n';
    }
}
