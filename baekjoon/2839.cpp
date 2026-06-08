#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int bag_count = 0;
    while (n > 0)
    {
        if (n % 5 == 0)
        {
            bag_count += n / 5;
            n = 0;
        }
        else if (n >= 3)
        {
            n -= 3;
            bag_count++;
        }
        else
        {
            bag_count = -1; // 배달할 수 없는 경우
            break;
        }
    }

    cout << bag_count << endl;
    return 0;
}
