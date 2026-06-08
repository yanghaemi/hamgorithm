#include <iostream>
#include <vector>
using namespace std;

vector<int> stack;
vector<int> res;
int top = -1;

void push(int n)
{
    stack.push_back(n);
    // cout << "top : " << top << '\n';
    ++top;
    return;
}

void pop()
{
    if (top == -1)
    {
        res.push_back(-1);
        return;
    }
    else
    {
        res.push_back(stack[top--]);
        stack.pop_back();
        return;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> str(n);
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        if (str[i] == "push")
        {
            cin >> temp;
            push(temp);
        }
        else if (str[i] == "top")
            if (top != -1)
            {
                res.push_back(stack[top]);
            }
            else
                res.push_back(-1);
        else if (str[i] == "size")
            res.push_back(top + 1);
        else if (str[i] == "empty")
        {
            if (top == -1)
                res.push_back(1);
            else
                res.push_back(0);
        }
        else if (str[i] == "pop")
            pop();
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';
}