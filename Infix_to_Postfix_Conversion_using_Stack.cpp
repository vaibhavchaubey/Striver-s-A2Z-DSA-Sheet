/* Codestudio  Submission    (Infix To Postfix) */

/* Problem Statement: You are given a string 'exp' which is a valid infix expression. Convert the given infix expression 
to postfix expression. */



/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(N) 


// #include<bits/stdc++.h>
// int prec(char ch){
// 	if(ch == '^'){
// 		return 3;
// 	}
// 	else if(ch == '*' || ch == '/'){
// 		return 2;
// 	}
// 	else if(ch == '+' || ch == '-'){
// 		return 1;
// 	}
// 	else{
// 		return -1;
// 	}
// }
// string infixToPostfix(string exp){
// 	int n = exp.size();
// 	stack<char> st;
// 	string ans = "";
// 	for(int i = 0; i < n; i++){
// 		// if((exp[i] >= '0' && exp[i] <= '9') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')){
// 		// 	ans += exp[i];
// 		// }

// 		/* OR */

// 		if(isdigit(exp[i]) || isalpha(exp[i])){
// 			ans += exp[i];
// 		}
// 		else if(exp[i] == '('){
// 			st.push(exp[i]);
// 		}
// 		else if(exp[i] == ')'){
// 			while(!st.empty() && st.top() != '('){
// 				ans += st.top();
// 				st.pop();
// 			}
// 			if(!st.empty()){
// 				st.pop();
// 			}
// 		}
// 		else{
// 			while(!st.empty() && prec(st.top()) >= prec(exp[i])){
// 				ans += st.top();
// 				st.pop();
// 			}
// 			st.push(exp[i]);
// 		}
// 	}

// 	while(!st.empty()){
// 		ans += st.top();
// 		st.pop();
// 	}

// 	return ans;
// }



////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* We are giving Infix Expression and Postfix Expression is coming Output
Input => Infix Expression
Output => Postfix Expression */

/*
(a-b/c)*(a/k-l)    - Input
abc/-ak/l-*        - Ans
*/

/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(N) 


// #include <bits/stdc++.h>
// using namespace std;
// int prec(char c)
// {
//     if (c == '^')
//     {
//         return 3;
//     }
//     else if (c == '*' || c == '/')
//     {
//         return 2;
//     }
//     else if (c == '+' || c == '-')
//     {
//         return 1;
//     }
//     else
//     {
//         return -1;
//     }
// }
// string infixToPostfix(string s)
// {
//     stack<char> st;
//     string res;
//     for (int i = 0; i < s.length(); i++)
//     {
//         // if ((s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'))
//         // {
//         //     res += s[i];
//         // }

//         /* OR */

//         if (isdigit(s[i]) || isalpha(s[i]))
//         {
//             res += s[i];
//         }
//         else if (s[i] == '(')
//         {
//             st.push(s[i]);
//         }
//         else if (s[i] == ')')
//         {
//             while (!st.empty() && st.top() != '(')
//             {
//                 res += st.top();
//                 st.pop();
//             }
//             if (!st.empty())                    // It is done in order to remove '('
//             {
//                 st.pop();
//             }
//         }
//         else
//         {
//             while (!st.empty() && prec(st.top()) >= prec(s[i]))
//             {
//                 res += st.top();
//                 st.pop();
//             }
//             st.push(s[i]);
//         }
//     }
//     while (!st.empty())             // It is done to print remaining elements
//     {
//         res += st.top();
//         st.pop();
//     }
//     return res;
// }
// int main()
// {
//     cout << infixToPostfix("(a-b/c)*(a/k-l)") << endl;       // abc/-ak/l-*

//     return 0;
// }