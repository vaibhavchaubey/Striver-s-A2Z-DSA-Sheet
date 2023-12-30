/* Problem Statement: Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial). */


/* Leetcode   Submission    (44. Wildcard Matching) */


/* Solution 1: */
// Time Complexity: (Exponential)
// Space Complexity: O(N+M) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     // If p is all-stars, we return true, else return false.
//     bool isAllStars(string& p, int i){
//         for(int j = 0; j <= i; j++){
//             if(p[j] != '*'){
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool helper(int i, int j, string& p, string& s){
//         // base condition
//         if( i < 0 && j < 0){                    // both p and s exhausted
//             return true;
//         }
//         if(i < 0 && j >= 0){                   // p is exhausted
//             return false;
//         }
//         // When s is exhausted(j<0) and p has not. It is if p is like this “*”,”****”,”***”, i.e: p contains only stars. Then we can replace every star with a sequence of length 0 and say that the string match.
//         if(i >= 0 && j < 0){                 // s is exhausted
//             return isAllStars(p, i);
//         }

//         if(p[i] == s[j] || p[i] == '?'){
//             return helper(i-1,j-1,p,s);
//         }
//         else if(p[i] == '*'){
//                     //replace ‘*’ with nothing                     
//             return (helper(i-1,j,p,s) || helper(i,j-1,p,s));
//         }                                // replace ‘*’ with a single character
//         else{
//             return false;
//         }
//     }
//     bool isMatch(string s, string p) {
//         int n = p.size();
//         int m = s.size();

//         return helper(n-1,m-1,p,s);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*M) 
// Space Complexity: O(N+M) (Recursion)   +   O(N*M)  (Array)


// class Solution {
// public:
//     // If p is all-stars, we return true, else return false.
//     bool isAllStars(string& p, int i){
//         for(int j = 0; j <= i; j++){
//             if(p[j] != '*'){
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool helper(int i, int j, string& p, string& s, vector<vector<int>>& dp){
//         // base condition
//         if( i < 0 && j < 0){                    // both p and s exhausted
//             return true;
//         }
//         if(i < 0 && j >= 0){                   // p is exhausted
//             return false;
//         }
//         // When s is exhausted(j<0) and p has not. It is if p is like this “*”,”****”,”***”, i.e: p contains only stars. Then we can replace every star with a sequence of length 0 and say that the string match.
//         if(i >= 0 && j < 0){                 // s is exhausted
//             return isAllStars(p, i);
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         if(p[i] == s[j] || p[i] == '?'){
//             return dp[i][j] = helper(i-1,j-1,p,s,dp);
//         }
//         else if(p[i] == '*'){
//                                //replace ‘*’ with nothing                     
//             return dp[i][j] = (helper(i-1,j,p,s,dp) || helper(i,j-1,p,s,dp));
//         }                                              // replace ‘*’ with a single character   
//         else{
//             return dp[i][j] = false;
//         }
//     }
//     bool isMatch(string s, string p) {
//         int n = p.size();
//         int m = s.size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));

//         return helper(n-1,m-1,p,s,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)  (Array) 


// class Solution {
// public:
//     // If p is all-stars, we return true, else return false.
//     bool isAllStars(string& p, int i){
//         for(int j = 1; j <= i; j++){
//             if(p[j-1] != '*'){
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool isMatch(string s, string p) {
//         int n = p.size();
//         int m = s.size();
//         vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

//         // base condition
//         dp[0][0] = true;                  // i < 0 && j < 0   // both p and s exhausted

//         for(int j = 1; j <= m; j++){       // i < 0 && j >= 0   // p is exhausted
//             dp[0][j] = false;
//         }    

//         for(int i = 1; i <= n; i++){
//             dp[i][0] = isAllStars(p, i);       // i >= 0 && j < 0    // s is exhausted
//         }  

//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 if(p[i-1] == s[j-1] || p[i-1] == '?'){
//                     dp[i][j] = dp[i-1][j-1];
//                 }
//                 else if(p[i-1] == '*'){
//                     dp[i][j] = dp[i-1][j] || dp[i][j-1];
//                 }
//                 else{
//                     dp[i][j] = false;
//                 }
//             }
//         }    

//         return dp[n][m];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*M) 
// Space Complexity: O(M)


// class Solution {
// public:
//     // If p is all-stars, we return true, else return false.
//     bool isAllStars(string& p, int i){
//         for(int j = 1; j <= i; j++){
//             if(p[j-1] != '*'){
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool isMatch(string s, string p) {
//         int n = p.size();
//         int m = s.size();
//         vector<bool> prev(m+1, false), cur(m+1, false);

//         // base condition
//         prev[0] = true;                    // i < 0 && j < 0   // both p and s exhausted

//         for(int j = 1; j <= m; j++){        // i < 0 && j >= 0   // p is exhausted
//             prev[j] = false;
//         }     

//         for(int i = 1; i <= n; i++){
//             cur[0] = isAllStars(p, i);        // i >= 0 && j < 0    // s is exhausted
//             for(int j = 1; j <= m; j++){
//                 if(p[i-1] == s[j-1] || p[i-1] == '?'){
//                     cur[j] = prev[j-1];
//                 }
//                 else if(p[i-1] == '*'){
//                     cur[j] = prev[j] || cur[j-1];
//                 }
//                 else{
//                     cur[j] = false;
//                 }
//             }
//             prev = cur;
//         }    

//         return prev[m];
//     }
// };