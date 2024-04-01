/* Leetcode  Submission    (22. Generate Parentheses) */

/* Problem Statement: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. */


/* Solution: Recursion */
// Time Complexity: O(2 ^ 2*N)
// Space Complexity: O(2*N)          // recursion stack


// class Solution {
// public:
//     void helper(int open, int close, int n, string s, vector<string>& ans){
//         if(s.size() == n*2){
//             ans.push_back(s);
//             return;
//         }

//         // For adding ( : If number of opening brackets (open) is less than the 
//         // given length(n) i.e if open < n, then we can add (, else not.
//         if(open < n){
//             helper(open+1, close, n, s + '(', ans);
//         }

//         // For adding ) : If number of close brackets (close) is less than the 
//         // opening brackets (open), i.e. if close < open, we can add ), else not
//         if(close < open){
//             helper(open, close+1, n, s + ')', ans);
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         int open = 0, close = 0;
//         helper(open, close, n, "", ans);

//         return ans;
//     }
// };