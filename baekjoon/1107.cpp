#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int Min(int a, int b) { return a > b ? b : a; } // 작은 거 반환하는 함수

int button[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int min_num = 999999;
int n;

void BF(string s)
{
    for (int i = 0; i < 10; i++)
    {
        if (button[i])
        {
            string str_num = s + to_string(i);                                 // s 뒤에 정상 버튼 붙여주기
            min_num = Min(min_num, abs(n - stoi(str_num)) + str_num.length()); // str_num.length()는 버튼 횟수,
                                                                               // n-stoi(str_num)은 +/-버튼 횟수

            if (str_num.length() < 6) // 0<n<500,000이니까 최대 버튼을 6번 누를 거니까
                BF(str_num);
        }
    }
}

int main()
{

    cin >> n; // 번호 입력

    int m = 0;
    cin >> m; // 고장난 버튼 개수

    min_num = Min(min_num, abs(100 - n)); // min_num에 100와 n 차의 절댓값 넣기
    int k;                                // 고장난 버튼을 저장할 임시 변수
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        button[k] = 0; // 고장난 거면 0으로 초기화
    }

    if (m < 10) // 고장난 버튼이 하나라도 있으면
        BF("");

    cout << min_num;
}