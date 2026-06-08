#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> res(100001);
vector<int> mp[100001];
bool check[100001];

void BFS()
{
    check[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < mp[parent].size(); i++)
        {
            int child = mp[parent][i];
            if (!check[child])
            {
                res[child] = parent;
                check[child] = true;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int a, b = 0;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    BFS();
    for (int i = 2; i <= n; i++)
    {
        cout << res[i] << '\n';
    }
}