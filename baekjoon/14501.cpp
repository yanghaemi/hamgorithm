#include <iostream>
#include <vector>
using namespace std;

int great = 0;

int main()
{
    int n = 0; //(1<=N<=15)

    cin >> n;

    vector<int> T(n + 1); // 상담을 완료하는데 걸리는 기간
    vector<int> P(n + 1); // 상담을 했을 때 받을 수 있는 금액

    for (int i = 1; i <= n; i++)
    {
        cin >> T[i] >> P[i]; //(1<=T<=5, 1<=P<=1,000)
    }
    for (int i = 1; i < n; i++)
    {
        int total = 0;
        for (int j = i; j <= n;)
        {
            if (T[j] + j > n + 1) // 회의 끝났는데 n+a가 되면,
                break;

            total += P[j];
            j += T[j];
        }
        if (great < total)
        {
            great = total;
        }
    }

    cout << great;
}