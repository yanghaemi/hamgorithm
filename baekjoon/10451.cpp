#include <iostream>
#include <vector>
using namespace std;

void Graph(int num) // num : 순열 크기
{
    int cnt = 0;

    vector<int> v(num + 1);
    vector<int> visit(num + 1, 0); // 방문 했나 확인하는 벡터
    for (int i = 1; i <= num; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= num; i++)
    {
        // for문으로 순서대로 그래프 순서대로 따라가기
        if (visit[i] == 0) // visit 안 한 것만 보기
        {
            int j = v[i];
            visit[i] = 1;
            while (1)
            {
                visit[j] = 1;
                if (j == i) // 돌다가 같은 거 나오면 순열 사이클이다
                {
                    cnt++;
                    break;
                }
                j = v[j]; // 같은 거 안 나오면 계속 그래프 들어가기 진행
            }
        }
    }
    cout << cnt << "\n";
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;

        Graph(num);
    }
}