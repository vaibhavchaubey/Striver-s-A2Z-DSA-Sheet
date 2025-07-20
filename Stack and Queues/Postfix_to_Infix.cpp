/* Codestudio  Submission    (Postfix to Infix) */

/* Problem Statement: You are given a mathematical expression in postfix notation.
The expression consists of alphabets(both lowercase and uppercase) and operators. Convert this expression to infix notation. */

/* Solution:
Approach:
In postfix expression, the operands are followed by the operator. So if we encounter an operator,
we’ll consider the latest two operands and evaluate them. */

// Time Complexity: O(N)
// Space Complexity: O(N)

// string postToInfix(string postfix) {
//     stack<string> st;
// 	for(int i = 0; i < postfix.size(); i++){
// 		if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
// 			string op2 = st.top();
// 			st.pop();
// 			string op1 = st.top();
// 			st.pop();

// 			string temp = '(' + op1 + postfix[i] + op2 + ')';
// 			st.push(temp);

// 		}
// 		else{
// 			// string str = "";
// 			// str += postfix[i];
// 			// st.push(str);

// 			/* OR */

// 			/* The string(1, postfix[i]) function creates a new string of length 1,
// 			with the character postfix[i] as its only character. */
// 			st.push(string(1, postfix[i]));
// 		}
// 	}

// 	return st.top();
// }