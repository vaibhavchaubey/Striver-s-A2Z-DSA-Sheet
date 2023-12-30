/* Problem Statement: There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any 
point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109. */


/* Leetcode   Submission    (62. Unique Paths) */


/* Solution 1: */
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int countPaths(int i, int j){
//         if(i == 0 && j == 0){
//             return 1;
//         }
//         if(i < 0 || j < 0){
//             return 0;
//         }
//         int up = countPaths(i-1,j);
//         int left = countPaths(i,j-1);

//         return up + left; 
//     }
//     int uniquePaths(int m, int n) {
//         return countPaths(m-1,n-1);
//     }
// };


/* Other Way */

// class Solution {
// public:
//     int countPaths(int i, int j, int m, int n){
//         if(i == m-1 && j == n-1){
//             return 1;
//         }
//         if(i >= m || j >= n){
//             return 0;
//         }
//         int down = countPaths(i+1,j,m,n);
//         int right = countPaths(i,j+1,m,n);

//         return down + right;
//     }
//     int uniquePaths(int m, int n) {
//         return countPaths(0,0,m,n);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(M*N)
// Space Complexity: O((N-1)+(M-1)) (Recursion)   +   O(M*N)  (Array)


// class Solution {
// public:
//     int countPaths(int i, int j, vector<vector<int>>& dp){
//         if(i == 0 && j == 0){
//             return 1;
//         }
//         if(i < 0 || j < 0){
//             return 0;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int up = countPaths(i-1,j,dp);
//         int left = countPaths(i,j-1,dp);

//         return dp[i][j] = up + left; 
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n,-1));
//         return countPaths(m-1,n-1,dp);
//     }
// };


/* Other Way */

// class Solution {
// public:
//     int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp){
//         if(i == m-1 && j == n-1){
//             return 1;
//         }
//         if(i >= m || j >= n){
//             return 0;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int down = countPaths(i+1,j,m,n,dp);
//         int right = countPaths(i,j+1,m,n,dp);

//         return dp[i][j] = down + right;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n,-1));
//         return countPaths(0,0,m,n,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)  (Array) 


// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n,0));

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(i == 0 && j == 0){
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
//     int uniquePaths(int m, int n) {
//         vector<int> prev(n,0);

//         for(int i = 0; i < m; i++){
//             vector<int> cur(n, 0);
//             for(int j = 0; j < n; j++){
//                 if(i == 0 && j == 0){
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



/* Solution 5: */
/* Combinatorial Solution */
// Time Complexity: O(M-1) or O(N-1)
// Space Complexity: O(1)


// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         int N = m + n - 2;          // number of directions or total steps
//         int r = min(m-1, n-1);
//         double res = 1;

//         for(int i = 1; i <= r; i++){
//             res = res * (N - r + i) / i;       // Calculation NCr
//         }
//         return (int) res;
//     }
// };


