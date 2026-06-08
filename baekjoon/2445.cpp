#include <iostream>
using namespace std;
// 2445번 별 찍기 - 8

int main()
{
    int n;
    cin >> n;
    // n 입력

    int nn = 1;

    for (int i = 0; i < n && nn < n; i++, nn++) // 윗 부분
    {

        for (int j = 0; j < nn; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < 2 * (n - nn); j++)
        {
            cout << " ";
        }

        for (int j = 0; j < nn; j++)
        {
            cout << "*";
        }

        cout << '\n';
    }
    for (int j = 0; j < 2 * n; j++) // 가운데
    {
        cout << "*";
    }
    cout << '\n';
    n--; // 가운데 출력했으니까 n 한 칸 줄여줌

    for (; n > 0; n--) // 아랫 부분
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < 2 * (nn - n); j++)
        {
            cout << " ";
        }

        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }
}
