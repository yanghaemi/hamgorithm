#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n; // 상근이가 가지고 있는 숫자 카드

    vector<int> v(n);
    vector<int> answer(20000001, 0);
    // -10000000 부터 10000000 길래 걍 20000000만큼 메모리 생성

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        answer[v[i] + 10000000]++;
        // 음수는 0~9,999,999 까지, 양수는 10,000,001~20,000,000
        // 해당 인덱스의 값을 1 올려줘서 개수가 오름을 표현했다.
    }

    int m;
    cin >> m;
    vector<int> v2(m);

    for (int i = 0; i < m; i++)
    {
        cin >> v2[i]; // 상근이가 몇 개 가지고 있는 숫자 카드인지
    }

    for (int i = 0; i < m; i++)
    {
        cout << answer[v2[i] + 10000000] << " ";
    }
}