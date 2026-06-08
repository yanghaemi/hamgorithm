#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;
vector<char> stack;
int top = -1;
int flag = 0;

void push(char c)
{
    stack.push_back(c);
    top++;

    return;
}

void pop()
{
    if (top == -1)
    {
        flag = 1;
        return;
    }
    else
    {
        stack.pop_back();
        top--;

        return;
    }
}

void ps_stack(string ps)
{
    for (int i = 0; i < ps.length(); i++)
    {
        if (ps[i] == '(')
        {
            push(ps[i]);
        }
        else if (ps[i] == ')')
        {
            // cout << "pop ";
            pop();
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    vector<string> ps(t);

    for (int i = 0; i < t; i++)
    {
        cin >> ps[i];
        ps_stack(ps[i]);

        if (flag == 1 || top != -1)
        {
            res.push_back("NO");
        }
        else
        {
            res.push_back("YES");
        }
        while (top != -1)
        {
            pop();
        }
        flag = 0;
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << '\n';
    }
}