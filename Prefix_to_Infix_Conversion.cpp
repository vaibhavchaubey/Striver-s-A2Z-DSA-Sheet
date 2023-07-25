/* Codestudio  Submission    (Prefix to Infix) */

/* Problem Statement: You are given a string denoting a valid Prefix expression containing '+,'-','*','/' and lowercase letters. 
Convert the given Prefix expression into an Infix expression. */



/* Solution: 
Approach: The idea is to iterate over the expression from right to left and store the operands in a stack. 
Here, we are using a stack of strings for storing the operands. Whenever we encounter an operator, pop the 
top two operands from the stack and convert the expression to its infix form and then push back to the stack. */

// Time Complexity: O(N)
// Space Complexity: O(N) 


// string prefixToInfixConversion(string &s){
// 	stack<string> st;
// 	for(int i = s.size()-1; i >= 0; i--){
// 		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
// 			string op1 = st.top();
// 			st.pop();
// 			string op2 = st.top();
// 			st.pop();

// 			string temp = '(' + op1 + s[i] + op2 + ')';
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
// 	}

// 	return st.top();
// }
