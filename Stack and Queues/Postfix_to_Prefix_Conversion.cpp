/* Codestudio  Submission    (PostFix To Prefix) */

/* Problem Statement: You are given a string denoting a valid Postfix expression containing '+','-','*','/' and lowercase letters. 
Convert the given Postfix expression into a Prefix expression. */



/* Solution 1: 
Approach: postfix to prefix = postfix to infix => infix to prefix    */

// Time Complexity: O(N) + O(N) 
// Space Complexity: O(N) + O(N)


/* CODE */



/* Solution 2: 
Approach: Here, to convert from postfix to prefix, we can simply use stack data structure. We will be following two conditions as follow:
1) If we encounter an operand, then we will push it into the stack
20 If we encounter an operator, then we can pop 2 elements from the stack, create a new string in prefix format and push it back to the stack
This process should repeat till the end of prefix expression. */

// Time Complexity: O(N) 
// Space Complexity: O(N)


// #include<bits/stdc++.h>
// string postfixToPrefix(string &s){
//     stack<string> st;
    
//     for(int i = 0; i < s.size(); i++){
//         if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
// 			string op2 = st.top();
// 			st.pop();
// 			string op1 = st.top();
// 			st.pop();

// 			string temp = s[i] + op1 + op2;
// 			st.push(temp);				
// 		}
// 		else{
// 			// string str = "";
// 			// str += s[i];
// 			// st.push(str);

// 			/* OR */

// 			/* The string(1, s[i]) function creates a new string of length 1, 
// 			with the character s[i] as its only character. */
// 			st.push(string(1, s[i]));
// 		}
//     }

//     return st.top();
// }