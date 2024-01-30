/* Leetcode  Submission    (678. Valid Parenthesis String) */

/* Problem Statement: Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "". 
*/


/* Solution: 1 */
// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     bool hasStarBefore(int ind, vector<int>& star){
//         for(int i = ind; i >= 0; i--){
//             if(star[i] == 1){
//                 star[i] = 0;
//                 return true;
//             }
//         }

//         return false;
//     }
//     bool hasStarAfter(int ind, vector<int>& star){
//         int n = star.size();
//         for(int i = ind; i < n; i++){
//             if(star[i] == 1){
//                 star[i] = 0;
//                 return true;
//             }
//         }

//         return false;
//     }
//     bool checkValidString(string s) {
//         int n = s.size();

//         vector<int> star(n);
//         stack<int> st;     // index
//         for(int i = 0; i < n; i++){
//             if(s[i] == '*'){
//                 star[i] = 1;
//             }
//             else if(s[i] == '('){
//                 st.push(i);
//             }
//             else{           // s[i] = ')'
//                 if(!st.empty()){
//                     st.pop();
//                 }
//                 else{
//                     if(!hasStarBefore(i-1, star)){
//                         return false;
//                     }
//                 }
//             }
//         }

//         while(!st.empty()){
//             int i = st.top();
//             st.pop();
//             if(!hasStarAfter(i + 1, star)){
//                 return false;
//             }
//         }

//         return true;
//     }
// };



/* Solution: 2 */
// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     bool checkValidString(string s) {
//         int n = s.size();
//         stack<int> validPar;
//         stack<int> asterisk;

//         for(int i = 0; i < n; i++){
//             if(s[i] == '('){
//                 validPar.push(i);
//             }
//             else if(s[i] == '*'){
//                 asterisk.push(i);
//             }
//             else{                       // s[i] = ')'
//                 if(!validPar.empty()){
//                     validPar.pop();
//                 }
//                 // here the '*' should come before ')' so that we can treat '*' as '('
//                 else if(!asterisk.empty()){
//                     asterisk.pop();
//                 }
//                 else{
//                     return false;
//                 }
//             }
//         }

//         // here the '*' should come after '(' so that we can treat '*' as ')'
//         while(!validPar.empty() && !asterisk.empty()){
//             if(validPar.top() > asterisk.top()){
//                 return false;
//             }
//             validPar.pop();
//             asterisk.pop();
//         }

//         return validPar.empty();
//     }
// };