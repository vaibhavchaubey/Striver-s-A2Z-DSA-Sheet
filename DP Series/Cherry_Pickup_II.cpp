/* Leetcode   Submission    (1463. Cherry Pickup II) */


/* Problem Statement: You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents 
the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid. */




/* Solution 1: */
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid){
//         if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){                      // base condition
//             return -1e9;
//         }
//         if(i == n-1){                                                 // base condition
//             if(j1 == j2){
//                 return grid[i][j1];
//             }
//             else{
//                 return grid[i][j1] + grid[i][j2];
//             }
//         }

//         // explore all paths of robot1 and robot2 simultaneously
//         int maxi = INT_MIN;
//         for(int dj1 = -1; dj1 <= 1; dj1++){
//             int ans = 0;
//             for(int dj2 = -1; dj2 <= 1; dj2++){
//                 if(j1 == j2){
//                     ans = grid[i][j1];
//                 }
//                 else{
//                     ans = grid[i][j1] + grid[i][j2];
//                 }
//                 ans += helper(i + 1, j1 + dj1, j2 + dj2, n, m, grid);
//                 maxi = max(maxi, ans);
//             }
//         }
//         return maxi;
//     }
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         return helper(0,0,m-1,n,m,grid);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*M*M) * 9
// Space Complexity: O(N) (Recursion)   +   O(N*M*M)  (Array)


// class Solution {
// public:
//     int helper(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
//         if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){        // base condition
//             return -1e9;
//         }
//         if(i == n-1){                                   // base condition
//             if(j1 == j2){
//                 return grid[i][j1];
//             }
//             else{
//                 return grid[i][j1] + grid[i][j2];
//             }
//         }
//         if(dp[i][j1][j2] != -1){
//             return dp[i][j1][j2];
//         }

//         // explore all paths of robot1 and robot2 simultaneously
//         int maxi = INT_MIN;
//         for(int dj1 = -1; dj1 <= 1; dj1++){
//             for(int dj2 = -1; dj2 <= 1; dj2++){
//                 int ans = 0;
//                 if(j1 == j2){
//                     ans = grid[i][j1];
//                 }
//                 else{
//                     ans = grid[i][j1] + grid[i][j2];
//                 }
//                 ans += helper(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
//                 maxi = max(maxi, ans);
//             }
//         }
//         return dp[i][j1][j2] = maxi;
//     }
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

//         return helper(0,0,m-1,n,m,grid,dp);
//     }
// };


/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*M*M) * 9
// Space Complexity: O(N*M*M)  (Array) 


// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

//         for(int j1 = 0; j1 < m; j1++){                      // base condition
//             for(int j2 = 0; j2 < m; j2++){
//                 if(j1 == j2){
//                     dp[n-1][j1][j2] = grid[n-1][j1];
//                 }
//                 else{
//                     dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
//                 }
//             }
//         }

//         for(int i = n-2; i >= 0; i--){
//             for(int j1 = 0; j1 < m; j1++){
//                 for(int j2 = 0; j2 < m; j2++){
//                     int maxi = INT_MIN;
//                     //Inner nested loops to try out 9 options
//                     for(int dj1 = -1; dj1 <= 1; dj1++){
//                         for(int dj2 = -1; dj2 <= 1; dj2++){
//                             int ans = 0;
//                             if(j1 == j2){
//                                 ans = grid[i][j1];
//                             }
//                             else{
//                                 ans = grid[i][j1] + grid[i][j2];
//                             }

//                             if(j1 + dj1 < 0 || j1 + dj1 >= m || j2 + dj2 < 0 || j2 + dj2 >= m){
//                                 ans += -1e9;
//                             }
//                             else{
//                                 ans += dp[i + 1][j1 + dj1][j2 + dj2];
//                             }
//                             maxi = max(maxi,ans);
//                         }
//                     }
//                     dp[i][j1][j2] = maxi;
//                 }
//             }
//         }

//         return dp[0][0][m-1];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*M*M)*9
// Space Complexity: O(M*M)


// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> front(m, vector<int>(m, 0));

//         for(int j1 = 0; j1 < m; j1++){                      // base condition
//             for(int j2 = 0; j2 < m; j2++){
//                 if(j1 == j2){
//                     front[j1][j2] = grid[n-1][j1];
//                 }
//                 else{
//                     front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
//                 }
//             }
//         }

//         for(int i = n-2; i >= 0; i--){
//             vector<vector<int>> cur(m, vector<int>(m, 0));
//             for(int j1 = 0; j1 < m; j1++){
//                 for(int j2 = 0; j2 < m; j2++){
//                     int maxi = INT_MIN;
//                     //Inner nested loops to try out 9 options
//                     for(int dj1 = -1; dj1 <= 1; dj1++){
//                         for(int dj2 = -1; dj2 <= 1; dj2++){
//                             int ans = 0;
//                             if(j1 == j2){
//                                 ans = grid[i][j1];
//                             }
//                             else{
//                                 ans = grid[i][j1] + grid[i][j2];
//                             }

//                             if(j1 + dj1 < 0 || j1 + dj1 >= m || j2 + dj2 < 0 || j2 + dj2 >= m){
//                                 ans += -1e9;
//                             }
//                             else{
//                                 ans += front[j1 + dj1][j2 + dj2];
//                             }
//                             maxi = max(maxi,ans);
//                         }
//                     }
//                     cur[j1][j2] = maxi;
//                 }
//             }
//             front = cur;
//         }

//         return front[0][m-1];
//     }
// };



