/* Leetcode   Submission    (115. Distinct Subsequences) */


/* Problem Statement: Given two strings s and t, return the number of distinct subsequences of s which equals t. */



/* Solution 1: */
// Time Complexity: O(2^N x  2^M)  (Exponential)
// Space Complexity: O(N+M) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int ind1, int ind2, string& s,string& t){
//         if(ind2 < 0){                                    // base condition
//             return 1;
//         }
//         if(ind1 < 0){                                    // base condition
//             return 0;
//         }
        
//         if(s[ind1] == t[ind2]){
//             int taken = helper(ind1-1,ind2-1,s,t);
//             int notTaken = helper(ind1-1,ind2,s,t); 

//             return taken + notTaken;
//         }
//         else{
//             return helper(ind1-1,ind2,s,t); 
//         }
//     }
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();

//         return helper(n-1,m-1,s,t);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*M) 
// Space Complexity: O(N+M) (Recursion)   +   O(N*M)  (Array)


// class Solution {
// public:
//     int helper(int ind1, int ind2, string& s,string& t, vector<vector<int>>& dp){
//         if(ind2 < 0){                                    // base condition
//             return 1;
//         }
//         if(ind1 < 0){                                    // base condition
//             return 0;
//         }

//         if(dp[ind1][ind2] != -1){
//             return dp[ind1][ind2];
//         }

//         if(s[ind1] == t[ind2]){
//             int taken = helper(ind1-1,ind2-1,s,t,dp);
//             int notTaken = helper(ind1-1,ind2,s,t,dp); 

//             return dp[ind1][ind2] = taken + notTaken;
//         }
//         else{
//             return dp[ind1][ind2] = helper(ind1-1,ind2,s,t,dp); 
//         }
//     }
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));

//         return helper(n-1,m-1,s,t,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)  (Array) 


// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         static int MOD = (int)1e9 + 7;            // To avoid Integer Overflow on some cases
//         int n = s.size();
//         int m = t.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//         for(int i = 0; i <= n; i++){               // base condition
//             dp[i][0] = 1;                         // ind2 = -1
//         }
//         for(int i = 1; i <= m; i++){             // base condition
//             dp[0][i] = 0;                       // ind1 = -1
//         }

//         for(int ind1 = 1; ind1 <= n; ind1++){
//             for(int ind2 = 1; ind2 <= m; ind2++){
//                if(s[ind1-1] == t[ind2-1]){
//                    int taken = dp[ind1-1][ind2-1];
//                    int notTaken = dp[ind1-1][ind2];

//                    dp[ind1][ind2] = (taken + notTaken) % MOD;
//                 }
//                 else{
//                     dp[ind1][ind2] = dp[ind1-1][ind2]; 
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


/* Two Row Optimization */

// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         static int MOD = (int)1e9 + 7;            // To avoid Integer Overflow on some cases
//         int n = s.size();
//         int m = t.size();
//         vector<int> prev(m+1, 0), cur(m+1, 0);

//         prev[0] = cur[0] = 1;              // base condition     // ind2 = -1                 
        
//         for(int ind1 = 1; ind1 <= n; ind1++){
//             for(int ind2 = 1; ind2 <= m; ind2++){
//                if(s[ind1-1] == t[ind2-1]){
//                    int taken = prev[ind2-1];
//                    int notTaken = prev[ind2];

//                    cur[ind2] = (taken + notTaken) % MOD;
//                 }
//                 else{
//                     cur[ind2] = prev[ind2]; 
//                 } 
//             }
//             prev = cur;
//         }

//         return prev[m];
//     }
// };



/* One Row Optimization */

// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         static int MOD = (int)1e9 + 7;            // To avoid Integer Overflow on some cases
//         int n = s.size();
//         int m = t.size();
//         vector<int> prev(m+1, 0);

//         prev[0] = 1;                             // base condition     // ind2 = -1                 

//         for(int ind1 = 1; ind1 <= n; ind1++){
//             for(int ind2 = m; ind2 >= 1; ind2--){
//                if(s[ind1-1] == t[ind2-1]){
//                    int taken = prev[ind2-1];
//                    int notTaken = prev[ind2];

//                    prev[ind2] = (taken + notTaken) % MOD;
//                 }
//                 else{
//                     prev[ind2] = prev[ind2]; 
//                 } 
//             }
//         }

//         return prev[m];
//     }
// };