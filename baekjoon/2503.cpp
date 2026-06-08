#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n = 0;     // 민혁이의 질문 횟수
    string answer; // 답 변수 생성
    string flag;   // 임시로 답 저장할 flag 생성
    cin >> n;      // 개수 입력 받기

    vector<string> v(n);   // 민혁이의 숫자를 담은 벡터, 자릿수로 볼 거라서 string 벡터
    vector<int> strike(n); // 스트라이크 숫자 int 벡터
    vector<int> ball(n);   // 볼 숫자 int 벡터

    cin >> v[0] >> strike[0] >> ball[0]; // 첫 번째 영수 힌트 입력
    for (int i = 1; i < n - 1; i++)
    {
        cin >> v[i] >> strike[i] >> ball[i]; // 답 입력 받기
        if (strike[i] <= 3 && strike[i] > 0)
        { // 스트라이크가 1 이상이면
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                    if (answer[k] == v[i][j])
                    {
                        flag[j] = v[i][j];
                        continue; // 이거 있어야되나? break랑 헷갈
                    }
            }
        }
        else
        {
        }
        if (ball[i] <= 3 && ball[i] > 0)
        {
            // 볼이 1 이상이면
        }
        else
        {
        }
    }

    cout << answer; // 답 출력
}