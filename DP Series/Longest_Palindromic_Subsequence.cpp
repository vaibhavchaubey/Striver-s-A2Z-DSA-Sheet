/* Leetcode   Submission    (516. Longest Palindromic Subsequence) */


/* Problem Statement: Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no 
elements without changing the order of the remaining elements. */



/* Solution 1: */
// Time Complexity: O(2^N x  2^M) 
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     // make sure you pass the string by reference because everytime if you create a new string it might give you TLE
//     int helper(int ind1, int ind2, string& text1, string& text2){
//         if(ind1 < 0 || ind2 < 0){                        // base condition
//             return 0;
//         }
          
//         if(text1[ind1] == text2[ind2]){
//             return 1 + helper(ind1-1, ind2-1, text1, text2);
//         }

//         return 0 + max(helper(ind1-1, ind2, text1, text2),  helper(ind1, ind2-1, text1, text2));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length(), m = text2.length();
        
//         return helper(n-1,m-1,text1,text2);
//     }
//     int longestPalindromeSubseq(string s) {
//         string t = s;
//         reverse(t.begin(), t.end());

//         return longestCommonSubsequence(s, t);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*M) 
// Space Complexity: O(N+M) (Recursion)   +   O(N*M)  (Array)


// class Solution {
// public:
//     // make sure you pass the string by reference because everytime if you create a new string it might give you TLE
//     int helper(int ind1, int ind2, string& text1, string& text2, vector<vector<int>>& dp){
//         if(ind1 < 0 || ind2 < 0){                       // base condition
//             return 0;
//         }
//         if(dp[ind1][ind2] != -1){
//             return dp[ind1][ind2];
//         }
          
//         if(text1[ind1] == text2[ind2]){
//             return dp[ind1][ind2] = 1 + helper(ind1-1, ind2-1, text1, text2, dp);
//         }
//         else{
//             return dp[ind1][ind2] = 0 + max(helper(ind1-1, ind2, text1, text2, dp),  helper(ind1, ind2-1, text1, text2, dp));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length(), m = text2.length();
//         vector<vector<int>> dp(n, vector<int>(m, -1));

//         return helper(n-1,m-1,text1,text2,dp);
//     }
//     int longestPalindromeSubseq(string s) {
//         string t = s;
//         reverse(t.begin(), t.end());

//         return longestCommonSubsequence(s, t);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)  (Array) 


// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length(), m = text2.length();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//         for(int i = 0; i <= m; i++){            // base condition
//             dp[0][i] = 0;                       // ind1 = -1
//         }
//         for(int i = 0; i <= n; i++){            
//             dp[i][0] = 0;                       // ind2 = -1
//         }

//         for(int ind1 = 1; ind1 <= n; ind1++){
//             for(int ind2 = 1; ind2 <= m; ind2++){
//                 if(text1[ind1-1] == text2[ind2-1]){
//                     dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
//                 }
//                 else{
//                     dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
//                 }
//             }
//         }

//         return dp[n][m];                // dp[n-1][m-1]     (Shifting of indexes)
//     }
//     int longestPalindromeSubseq(string s) {
//         string t = s;
//         reverse(t.begin(), t.end());

//         return longestCommonSubsequence(s, t);
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*M) 
// Space Complexity: O(M)


// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length(), m = text2.length();
//         vector<int> prev(m+1, 0);
//         // Base Case is covered as we have initialized the prev and cur to 0

//         for(int ind1 = 1; ind1 <= n; ind1++){
//             vector<int> cur(m+1, 0);
//             for(int ind2 = 1; ind2 <= m; ind2++){
//                 if(text1[ind1-1] == text2[ind2-1]){
//                     cur[ind2] = 1 + prev[ind2-1];
//                 }
//                 else{
//                     cur[ind2] = 0 + max(prev[ind2], cur[ind2-1]);
//                 }
//             }
//             prev = cur;
//         }

//         return prev[m];                // prev[m-1]     (Shifting of indexes)
//     }
//     int longestPalindromeSubseq(string s) {
//         string t = s;
//         reverse(t.begin(), t.end());

//         return longestCommonSubsequence(s, t);
//     }
// };