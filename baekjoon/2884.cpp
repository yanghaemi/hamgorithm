#include <iostream>
using namespace std;
int main()
{
    int h, m = 0;
    cin >> h >> m;
    if ((m - 45) < 0)
    {
        if (h == 0)
        {
            h = 23;
        }
        else
        {
            h--;
        }
        m = 60 + (m - 45);
    }
    else
    {
        m = m - 45;
    }

    cout << h << " " << m;
}