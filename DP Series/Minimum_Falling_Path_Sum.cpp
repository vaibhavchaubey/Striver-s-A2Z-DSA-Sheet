/* Problem Statement: We are given an ‘N*N’ matrix. We need to find the maximum path sum from 
any cell of the first row to any cell of the last row.
At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙). */


/* For Maximum Falling Path Sum we use max in place of min and return -1e9 in place of 1e9 */


/* Leetcode   Submission    (931. Minimum Falling Path Sum) */


/* Solution 1: */
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int i, int j, int m, vector<vector<int>>& matrix){
//         if(j < 0 || j >= m){                // base condition
//             return 1e9;
//         }
//         if(i == 0){                        // base condition
//             return matrix[0][j];
//         }
//         int up = matrix[i][j] + helper(i-1,j,m,matrix);
//         int leftDiagonal = matrix[i][j] + helper(i-1,j-1,m,matrix);
//         int rightDiagonal = matrix[i][j] + helper(i-1,j+1,m,matrix);

//         return min(up, min(leftDiagonal, rightDiagonal));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         int mini = INT_MAX;
//         for(int j = 0; j < m; j++){
//             int ans = helper(n-1,j,m,matrix);
//             mini = min(mini, ans);
//         }

//         return mini;
//     }



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N)
// Space Complexity: O(N) (Recursion)   +   O(N*N)  (Array)


// class Solution {
// public:
//     int helper(int i, int j, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         if(j < 0 || j >= m){                // base condition
//             return 1e9;
//         }
//         if(i == 0){                        // base condition
//             return matrix[0][j];
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int up = matrix[i][j] + helper(i-1,j,m,matrix,dp);
//         int leftDiagonal = matrix[i][j] + helper(i-1,j-1,m,matrix,dp);
//         int rightDiagonal = matrix[i][j] + helper(i-1,j+1,m,matrix,dp);

//         return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));

//         int mini = INT_MAX;
//         for(int j = 0; j < m; j++){
//             int ans = helper(n-1,j,m,matrix,dp);
//             mini = min(mini, ans);
//         }

//         return mini;
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N)
// Space Complexity: O(N*N)  (Array) 


// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, 0));

//         // Initializing first row - base condition
//         for(int j = 0; j < m; j++){            
//             dp[0][j] = matrix[0][j];
//         }

//         for(int i = 1; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 int up = matrix[i][j] + dp[i-1][j];
//                 int leftDiagonal = matrix[i][j];
//                 int rightDiagonal = matrix[i][j];

//                 if(j > 0){
//                     leftDiagonal += dp[i-1][j-1];
//                 }
//                 else{
//                     leftDiagonal += 1e9;
//                 }
//                 if(j+1 < m){
//                     rightDiagonal += dp[i-1][j+1];
//                 }
//                 else{
//                     rightDiagonal += 1e9;
//                 }

//                 dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
//             }
//         }

//         int mini = INT_MAX;
//         for(int j = 0; j < m; j++){
//             mini = min(mini, dp[n-1][j]);
//         }

//         return mini;
//     }
// };


/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*N)
// Space Complexity: O(N)


// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<int> prev(m, 0);

//         // Initializing first row - base condition
//         for(int j = 0; j < m; j++){            
//             prev[j] = matrix[0][j];
//         }

//         for(int i = 1; i < n; i++){
//             vector<int> cur(m, 0);
//             for(int j = 0; j < m; j++){
//                 int up = matrix[i][j] + prev[j];
//                 int leftDiagonal = matrix[i][j];
//                 int rightDiagonal = matrix[i][j];

//                 if(j > 0){
//                     leftDiagonal += prev[j-1];
//                 }
//                 else{
//                     leftDiagonal += 1e9;
//                 }
//                 if(j+1 < m){
//                     rightDiagonal += prev[j+1];
//                 }
//                 else{
//                     rightDiagonal += 1e9;
//                 }

//                 cur[j] = min(up, min(leftDiagonal, rightDiagonal));
//             }
//             prev = cur;
//         }

//         int mini = INT_MAX;
//         for(int j = 0; j < m; j++){
//             mini = min(mini, prev[j]);
//         }

//         return mini;
//     }
// };



/* For Maximum Falling Path Sum we use max in place of min and return -1e9 in place of 1e9 */


/* CodeStudio   Submission    (931. Maximum Path Sum in the matrix) */


// #include <bits/stdc++.h> 

// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<int> prev(m, 0);
    
//     for(int j = 0; j < m; j++){
//         prev[j] = matrix[0][j];
//     }
    
//     for(int i = 1; i < n; i++){
//         vector<int> cur(m, 0);
//         for(int j = 0; j < m; j++){
//             int up = matrix[i][j] + prev[j];
//             int leftDiagonal = matrix[i][j];
//             int rightDiagonal = matrix[i][j];
            
//             if(j > 0){
//                 leftDiagonal += prev[j-1];
//             }
//             else{
//                 leftDiagonal += -1e9;
//             }
//             if(j+1 < m){
//                 rightDiagonal += prev[j+1];
//             }
//             else{
//                 rightDiagonal += -1e9;
//             }
            
//             cur[j] = max(up, max(leftDiagonal, rightDiagonal));
//         }
//         prev = cur;
//     }
    
//     int maxi = INT_MIN;
//     for(int j = 0; j < m; j++){
//         maxi = max(maxi, prev[j]);
//     }
    
//     return maxi;
// }