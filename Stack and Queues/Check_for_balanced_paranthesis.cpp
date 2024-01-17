/* Leetcode  Submission    (20. Valid Parentheses) */

/* Problem Statement: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.
An input string is valid if:
1) Open brackets must be closed by the same type of brackets.
1) Open brackets must be closed in the correct order.
1) Every close bracket has a corresponding open bracket of the same type. */


/* Solution: Using Stack*/
// Time Complexity: O(N)
// Space Complexity: O(N) 


// class Solution {
// public:
//     bool isValid(string s) {
//         int n = s.size();
//         stack<char> st;
//         for(int i = 0; i < n; i++){
//             if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
//                 st.push(s[i]);
//             }
//             else if(st.empty()){
//                 return false;
//             }
//             else{
//                 if((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')){
//                     st.pop();
//                 }
//                 else{
//                     return false;
//                 }
//             }
//         }

//         if(!st.empty()){
//             return false;
//         }

//         return true;
//     }
// };

