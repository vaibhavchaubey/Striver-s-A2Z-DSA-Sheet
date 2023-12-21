/* We are giving Infix Expression and Prefix Expression is coming Output
Input => Infix Expression
Output => Prefix Expression */

/*
x+y*z/w+u     - Input
++x/*yzwu     - Ans
*/

/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(N)


#include <bits/stdc++.h>
using namespace std;

bool isOperator(char ch)
{
    return (!isdigit(ch) && !isalpha(ch));
}
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string str)
{
    str = '(' + str + ')';
    stack<char> st;
    string res;

    for (int i = 0; i < str.size(); i++)
    {
        // if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
        // {
        //     res += str[i];
        // }

        /* OR */

        if (isdigit(str[i]) || isalpha(str[i]))
        {
            res += str[i];
        }
        else if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();                   // Remove '(' from the stack
            }
        }
        else
        {
            if (isOperator(st.top()))
            {
                if (str[i] == '^')
                {
                    while (!st.empty() && prec(st.top()) >= prec(str[i]))
                    {
                        res += st.top();
                        st.pop();
                    }
                }
                else
                {
                    while (!st.empty() && prec(st.top()) > prec(str[i]))
                    {
                        res += st.top();
                        st.pop();
                    }
                }
                // Push current Operator on stack
                st.push(str[i]);
            }
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

string infixToPrefix(string str)
{
    // Reverse infix
    reverse(str.begin(), str.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }

    string ans = infixToPostfix(str);
    // Reverse postfix
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "x+y*z/w+u";

    cout << infixToPrefix(s) << endl;                      //     ++x/*yzwu

    return 0;
}