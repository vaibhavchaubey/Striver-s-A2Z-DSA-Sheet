/* We are giving Infix Expression and Prefix Expression is coming Output
Input => Infix Expression
Output => Prefix Expression */

/*
(a-b/c)*(a/k-l)    - Input
*-a/bc-/akl       - Ans
*/

/* STEPS TO CONVERT INFIX TO PREFIX EXPRESSION
1) Reverse the infix expression

2) Replace ( with ) and vice versa

3) Get the postfix expression of the modified expression

4) Reverse the postfix expression
*/

/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;
int prec(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string s)
{
    stack<char> st;
    string ans;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        // if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        // {
        //     ans += s[i];
        // }

        /* OR */

        // if (isdigit(s[i]) || isalpha(s[i]))
        // {
        //     // Operand, add to output
        //     ans += s[i];
        // }

        /* OR */

        if (isalnum(s[i]))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infixToPrefix(string infix)
{
    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    string ans = infixToPostfix(infix);
    // Reverse postfix
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPrefix(s) << endl;
    return 0;
}