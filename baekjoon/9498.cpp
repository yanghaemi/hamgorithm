#include <iostream>
using namespace std;

int main()
{
    int s = 0;
    cin >> s;
    if (90 <= s && s <= 100)
        cout << "A";
    else if (80 <= s && s < 90)
        cout << "B";
    else if (70 <= s && s < 80)
        cout << "C";
    else if (60 <= s && s < 70)
        cout << "D";
    else
        cout << "F";
    return 0;
}