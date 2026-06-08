#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// �̺�Ž�� O(log N)
int cnt = 0; // ���� ���� ī��Ʈ

int BS(vector<int> v, int k, int n, int sidx, int lidx)
{
    int mididx = (sidx + lidx) / 2;
    int num = v[mididx];
    int res = 0;
    cnt = 0;
    int i = 0;
    for (i = 0; i < k; i++)
    {
        cnt += v[i] / num;
    }
    if (cnt < n)
    {
    }
    else if (cnt >= n)
    {
    }
}

int fromn1ton2(vector<int> v, int k, int n1, int n2)
{
    int mid = (n1 + n2) / 2;
    cnt = 0;

    if (n1 == n2)
    {
        return n1;
    }

    for (int i = 0; i < k; i++)
    {
        cnt += v[i] / mid;
    }
    if (cnt < k)
    {
        fromn1ton2(v, k, n1, mid);
    }
    else if (cnt >= k)
    {
        fromn1ton2(v, k, mid, n2);
    }

    return 0;
}

int main()
{
    int k; // �̹� ������ �ִ� ������ ����
    int n; // �ʿ��� ������ ����
    cin >> k >> n;

    vector<int> v(k); // ���� ����

    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end()); // �������� ����

    cout << BS(v, k, n, 0, v.size() - 1);
}