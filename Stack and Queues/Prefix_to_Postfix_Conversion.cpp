/* Codestudio  Submission    (Convert Prefix to Postfix) */

/* Problem Statement: You are given a string 's' of size 'n', representing the prefix form of a valid mathematical expression. 
Your task is to find out its corresponding postfix expression. The expected time and space complexity is O(n) and O(n), 
where 'n' is the size of the string's. */



/* Solution 1: 
Approach: prefix to postfix = prefix to infix => infix to postfix    */

// Time Complexity: O(N) + O(N) 
// Space Complexity: O(N) + O(N)


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
// string prefixToInfix(string &s){
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

// string preToPost(string s) {
//     /* prefix to postfix = prefix to infix => infix to postfix */

//     string infix = prefixToInfix(s);
//     string postfix = infixToPostfix(infix);

//     return postfix;
// }




/* Solution 2: 
Approach: We can convert a prefix expression into a postfix expression using a stack. First, we will reverse the string and iterate 
through it. When we encounter an operand, we will push it into the stack. When meeting an operator ‘op’, we will pop two operands 
from the stack, ‘s1’ and ‘s2’. We will then push into the stack expression ‘s1’+’s2’+’op’, where + means concatenation. 
Ultimately, we will have our final expression as the only element in the stack. */

// Time Complexity: O(N) 
// Space Complexity: O(N)


// string preToPost(string s) {
//     stack<string> st;
    
//     for(int i = s.size()-1; i >= 0; i--){
//         if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
// 			string op1 = st.top();
// 			st.pop();
// 			string op2 = st.top();
// 			st.pop();

// 			string temp = op1 + op2 + s[i];
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


