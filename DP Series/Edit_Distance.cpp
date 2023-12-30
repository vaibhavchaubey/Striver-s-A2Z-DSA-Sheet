/* Leetcode   Submission    (72. Edit Distance) */


/* Problem Statement: Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character */



/* Solution 1: */
// Time Complexity: (Exponential)
// Space Complexity: O(N+M) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int i, int j, string& word1, string& word2){
//         if(i < 0){                         // base condition
//             return j+1;                   // insert the remaining characters
//         }
//         if(j < 0){                      // base condition
//             return i+1;                // delete the remaining characters
//         }

//         if(word1[i] == word2[j]){
//             return 0 + helper(i-1,j-1,word1,word2);
//         }
//         else{
//             // Minimum of three choices
//             int insert = helper(i,j-1,word1,word2);
//             int del = helper(i-1,j,word1,word2);
//             int replace = helper(i-1,j-1,word1,word2);

//             return 1 + min(insert, min(del, replace));
//         }
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();

//         return helper(n-1,m-1,word1,word2);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*M) 
// Space Complexity: O(N+M) (Recursion)   +   O(N*M)  (Array)


// class Solution {
// public:
//     int helper(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
//         if(i < 0){                         // base condition
//             return j+1;                   // insert the remaining characters
//         }
//         if(j < 0){                      // base condition
//             return i+1;                // delete the remaining characters
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         if(word1[i] == word2[j]){
//             return dp[i][j] = 0 + helper(i-1,j-1,word1,word2,dp);
//         }
//         else{
//             // Minimum of three choices
//             int insert = helper(i,j-1,word1,word2,dp);
//             int del = helper(i-1,j,word1,word2,dp);
//             int replace = helper(i-1,j-1,word1,word2,dp);

//             return dp[i][j] = 1 + min(insert, min(del, replace));
//         }
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));

//         return helper(n-1,m-1,word1,word2,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)  (Array) 


// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//         for(int j = 0; j <= m; j++){                 // base condition       
//             dp[0][j] = j;                           // ind1 = -1
//         }
//         for(int i = 0; i <= n; i++){                 // base condition       
//             dp[i][0] = i;                           // ind2 = -1
//         }

//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 if(word1[i-1] == word2[j-1]){
//                     dp[i][j] = 0 + dp[i-1][j-1];
//                 }
//                 else{
//                     // Minimum of three choices
//                     int insert = dp[i][j-1];
//                     int del = dp[i-1][j];
//                     int replace = dp[i-1][j-1];

//                     dp[i][j] = 1 + min(insert, min(del, replace));
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
//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();
//         vector<int> prev(m+1, 0), cur(m+1, 0);

//         for(int j = 0; j <= m; j++){                 // base condition       
//             prev[j] = j;                            // ind1 = -1
//         }


//         for(int i = 1; i <= n; i++){
//             cur[0] = i;                           // base condition       // ind2 = -1
//             for(int j = 1; j <= m; j++){
//                 if(word1[i-1] == word2[j-1]){
//                     cur[j] = 0 + prev[j-1];
//                 }
//                 else{
//                     // Minimum of three choices
//                     int insert = cur[j-1];
//                     int del = prev[j];
//                     int replace = prev[j-1];

//                     cur[j] = 1 + min(insert, min(del, replace));
//                 }
//             }
//             prev = cur;
//         }

//         return prev[m];
//     }
// };