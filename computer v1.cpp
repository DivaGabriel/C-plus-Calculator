#include <stack>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
//接受 +-/* !^
//-5! 無效
//-5^5 有效
// 5^5 有效
// 5^-5 無效
//-5^-5 無效
// 5^5! 有效
//-5^5! 有效
int main()
{
    string input;
    stack<int> x;
    int i, n1, n2, n3, total = 0;
    cin >> input;
    bool IsNum = false, IsSub = false, IsMulDiv = false;
    for (i = 0; i < input.size(); i++)
    {
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
            IsMulDiv = false;
            continue;
        }
        if (input[i] == '+')
        {
            IsNum = false;
            IsSub = false;
            IsMulDiv = false;
            continue;
        }
        if (input[i] == '-')
        {
            IsNum = false;
            IsSub = true;
            IsMulDiv = false;
            continue;
        }
        if (input[i] == '^')
        {
            n1 = x.top();
            x.pop();
            i++;
            if (input[i] == '-')
                return 0; // 5^-5 無效
            int tmp = input[i] - '0';
            n2 = n1;
            for (int j = 0; j < tmp - 1; j++)
                n1 *= n2;
            if (tmp == 0)
                x.push(1);
            else
                x.push(n1);
            IsNum = false;
            IsMulDiv = false;
        }
        if (input[i] == '!')
        {
            n1 = x.top();
            x.pop();
            if (n1 < 0)
                return 0;
            if (n1 == 0)
                n1 = 1;
            int tmp = n1;
            for (int j = 1; j < tmp; j++)
                n1 *= j;
            x.push(n1);
            IsNum = false;
            IsMulDiv = false;
            i++;
        }
        if (input[i] == '/')
        {
            n1 = x.top();
            x.pop();
            i++;
            IsNum = false;
            IsSub = false;
            while ((input[i] >= '0' && input[i] <= '9') || (input[i] == '-' && IsMulDiv == false))
            {
                if (input[i] == '-')
                {
                    IsSub = true;
                    i++;
                    continue;
                }
                if (!IsNum)
                    n2 = input[i] - '0';
                else
                    n2 = n2 * 10 + input[i] - '0';
                IsNum = true;
                IsMulDiv = true;
                i++;
            }
            if (input[i] == '^')
            {
                i++;
                if (input[i] == '-')
                    return 0; // 5^-5 無效
                int tmp = input[i] - '0';
                n3 = n2;
                for (int j = 0; j < tmp - 1; j++)
                    n2 *= n3;
                i++;
            }
            if (input[i] == '!')
            {
                if (n2 < 0)
                    return 0;
                if (n2 == 0)
                    n2 = 1;
                int tmp = n2;
                for (int j = 1; j < tmp; j++)
                    n2 *= j;
                IsNum = false;
                i++;
            }
            if (IsSub)
                x.push(-(n1 / n2));
            else
                x.push(n1 / n2);
            i--;
            IsNum = false;
            IsSub = false;
            IsMulDiv = true;
            continue;
        }
        if (input[i] == '*')
        {
            i++;
            n1 = x.top();
            x.pop();
            IsNum = false;
            while ((input[i] >= '0' && input[i] <= '9') || (input[i] == '-' && IsMulDiv == false))
            {
                if (input[i] == '-')
                {
                    IsSub = true;
                    i++;
                    continue;
                }
                if (!IsNum)
                    n2 = input[i] - '0';
                else
                {
                    n2 = n2 * 10 + input[i] - '0';
                }
                IsNum = true;
                IsMulDiv = true;
                i++;
            }
            if (input[i] == '^')
            {
                i++;
                if (input[i] == '-')
                    return 0; // 5^-5 無效
                int tmp = input[i] - '0';
                n3 = n2;
                for (int j = 0; j < tmp - 1; j++)
                    n2 *= n3;
                if (tmp == 0)
                    n2 = 1;
                i++;
            }
            if (input[i] == '!')
            {
                if (n2 < 0)
                    return 0;
                if (n2 == 0)
                    n2 = 1;
                int tmp = n2;
                for (int j = 1; j < tmp; j++)
                    n2 *= j;
                IsNum = false;
                i++;
            }
            if (IsSub)
                x.push(-(n1 * n2));
            else
                x.push(n1 * n2);
            i--;
            IsNum = false;
            IsSub = false;
            IsMulDiv = true;
            continue;
        }
        if (input[i] == '=')
        {
            while (x.size() != 0)
            {
                total += x.top();
                x.pop();
            }
        }
    }
    cout << total;
    return 0;
}
