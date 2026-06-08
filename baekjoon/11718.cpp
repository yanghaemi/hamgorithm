#include <iostream>
#include <string>
using namespace std;

int main()
{
    char ch[101];

    while (true)
    {
        cin.getline(ch, 101);

        if (cin.eof())
            return 0;
        cout << ch << "\n";
    }
}