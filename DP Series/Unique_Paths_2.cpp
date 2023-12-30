/* Problem Statement: You are given an m x n integer array grid. There is a robot initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes 
cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109. */


/* Leetcode   Submission    (62. Unique Paths) */


/* Solution 1: */
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int countPaths(int i, int j, vector<vector<int>>& obstacleGrid){
//         if(i < 0 || j < 0){
//             return 0;
//         }
//         if(obstacleGrid[i][j] == 1){
//             return 0;
//         }
//         if(i == 0 && j == 0){
//             return 1;
//         }
//         int up = countPaths(i-1,j,obstacleGrid);
//         int left = countPaths(i,j-1,obstacleGrid);

//         return up + left; 
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();

//         return countPaths(m-1,n-1,obstacleGrid);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(M*N)
// Space Complexity: O((N-1)+(M-1)) (Recursion)   +   O(M*N)  (Array)


// class Solution {
// public:
//     int countPaths(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
//         if(i < 0 || j < 0){
//             return 0;
//         }
//         if(obstacleGrid[i][j] == 1){
//             return 0;
//         }
//         if(i == 0 && j == 0){
//             return 1;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int up = countPaths(i-1,j,obstacleGrid,dp);
//         int left = countPaths(i,j-1,obstacleGrid,dp);

//         return dp[i][j] = up + left; 
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,-1));

//         return countPaths(m-1,n-1,obstacleGrid,dp);
//     }
// };


/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)  (Array) 


// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,0));

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(obstacleGrid[i][j] == 1){
//                     dp[i][j] = 0;
//                 }
//                 else if( i == 0 && j == 0){
//                     dp[i][j] = 1;
//                 }
//                 else{
//                     int up = 0;
//                     int left = 0;
//                     if(i > 0){
//                         up = dp[i-1][j];
//                     }
//                     if(j > 0){
//                         left = dp[i][j-1];
//                     }
//                     dp[i][j] = up + left;
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
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<int> prev(n,0);

//         for(int i = 0; i < m; i++){
//             vector<int> cur(n,0);
//             for(int j = 0; j < n; j++){
//                 if(obstacleGrid[i][j] == 1){
//                     cur[j] = 0;
//                 }
//                 else if( i == 0 && j == 0){
//                     cur[j] = 1;
//                 }
//                 else{
//                     int up = 0;
//                     int left = 0;
//                     if(i > 0){
//                         up = prev[j];
//                     }
//                     if(j > 0){
//                         left = cur[j-1];
//                     }
//                     cur[j] = up + left;
//                 }
//             }
//             prev = cur;
//         }

//         return prev[n-1];
//     }
// };



