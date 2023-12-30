/* Problem Statement: Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time. */


/* Leetcode   Submission    (64. Minimum Path Sum) */


/* Solution 1: */
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int i, int j, vector<vector<int>>& grid){
//         if(i == 0 && j == 0){
//             return grid[0][0];
//         }
//         if(i < 0 || j < 0){
//             return 1e9;
//         }
//         int up = grid[i][j] + helper(i-1,j,grid);
//         int left = grid[i][j] + helper(i,j-1,grid);

//         return min(up, left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         return helper(m-1,n-1,grid);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(M*N)
// Space Complexity: O((N-1)+(M-1)) (Recursion)   +   O(M*N)  (Array)


// class Solution {
// public:
//     int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
//         if(i == 0 && j == 0){
//             return grid[0][0];
//         }
//         if(i < 0 || j < 0){
//             return 1e9;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int up = grid[i][j] + helper(i-1,j,grid,dp);
//         int left = grid[i][j] + helper(i,j-1,grid,dp);

//         return dp[i][j] = min(up, left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,-1));

//         return helper(m-1,n-1,grid,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)  (Array) 


// class Soluclass Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,0));

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(i == 0 && j == 0){
//                     dp[i][j] = grid[0][0];
//                 }
//                 else{
//                     int up = grid[i][j];
//                     int left = grid[i][j];
//                     if(i > 0){
//                         up += dp[i-1][j];
//                     }
//                     else{
//                         up += 1e9;
//                     }
//                     if(j > 0){
//                         left += dp[i][j-1];
//                     }
//                     else{
//                         left += 1e9;
//                     }
//                     dp[i][j] = min(up, left);
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(M*N)
// Space Complexity: O(N)


// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<int> prev(n, 0);

//         for(int i = 0; i < m; i++){
//             vector<int> cur(n, 0);
//             for(int j = 0; j < n; j++){
//                 if(i == 0 && j == 0){
//                     cur[j] = grid[0][0];
//                 }
//                 else{
//                     int up = grid[i][j];
//                     int left = grid[i][j];
//                     if(i > 0){
//                         up += prev[j];
//                     }
//                     else{
//                         up += 1e9;
//                     }
//                     if(j > 0){
//                         left += cur[j-1];
//                     }
//                     else{
//                         left += 1e9;
//                     }
//                     cur[j] = min(up, left);
//                 }
//             }
//             prev = cur;
//         }
//         return prev[n-1];
//     }
// };



