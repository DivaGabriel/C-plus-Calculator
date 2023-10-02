#include <stack>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string input;
    stack<int> x;
    int i, n1, n2, total;
    cin >> input;
    bool IsNum, IsSub;
    for (i = 0; i < input.size(); i++)
    {
        if (input[i] == '+')
        {
            IsNum = false;
            IsSub = false;
            continue;
        }
        if (input[i] == '-')
        {
            IsNum = false;
            IsSub = true;
            continue;
        }
        if (input[i] >= '0' && input[i] <= '9')
        {
            if (!IsNum)
                n1 = input[i] - '0';
            else
                n1 = n1 * 10 + input[i] - '0';
            if (!(input[i + 1] >= '0' && input[i + 1] <= '9'))
            {
                if (IsSub)
                    x.push((-n1));
                else
                    x.push(n1);
            }
            IsNum = true;
            continue;
        }
        if (input[i] == '^')
        {
            i++;
            n1 = x.top();
            x.pop();
            x.push(n1 ^ input[i]);
            IsNum = false;
        } //不接受負次方
    }
    return 0;
}
//+-*/ ^!
//-5! 無效
//-5^5 有效
// 5^5 有效
// 5^-5 無效
//-5^-5 無效
// 5^5! 有效?
//-5^5! 有效?