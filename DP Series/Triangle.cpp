/* Problem Statement: We are given a Triangular matrix. We need to find the minimum path sum from the first row to the last row.
At every cell we can move in only two directions: either to the bottom cell (↓) or to the bottom-right cell(↘) */


/* Leetcode   Submission    (120. Triangle) */


/* Solution 1: */
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int i, int j, vector<vector<int>>& triangle, int n){
//         if(i == n-1){                            // base condition
//             return triangle[i][j];              // we reach last row
//         }
//         int down = triangle[i][j] + helper(i+1,j,triangle,n);
//         int diagonal = triangle[i][j] + helper(i+1,j+1,triangle,n);

//         return min(down, diagonal);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
        
//         return helper(0,0,triangle,n);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N)
// Space Complexity: O(N) (Recursion)   +   O(N*N)  (Array)


// class Solution {
// public:
//     int helper(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
//         if(i == n-1){                            // base condition
//             return triangle[i][j];              // we reach last row
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int down = triangle[i][j] + helper(i+1,j,triangle,n,dp);
//         int diagonal = triangle[i][j] + helper(i+1,j+1,triangle,n,dp);

//         return dp[i][j] = min(down, diagonal);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         return helper(0,0,triangle,n,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N)
// Space Complexity: O(N*N)  (Array) 


// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         for(int j = 0; j < n; j++){             // base condition
//             dp[n-1][j] = triangle[n-1][j]; 
//         }

//         for(int i = n-2; i >= 0; i--){
//             for(int j = i; j >= 0; j--){
//                 int down = triangle[i][j] + dp[i+1][j];
//                 int diagonal = triangle[i][j] + dp[i+1][j+1];

//                 dp[i][j] = min(down, diagonal);
//             }
//         }

//         return dp[0][0];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*N)
// Space Complexity: O(N)


// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<int> front(n, 0);

//         for(int j = 0; j < n; j++){             // base condition
//             front[j] = triangle[n-1][j]; 
//         }

//         for(int i = n-2; i >= 0; i--){
//             vector<int> cur(n, 0);
//             for(int j = i; j >= 0; j--){
//                 int down = triangle[i][j] + front[j];
//                 int diagonal = triangle[i][j] + front[j+1];

//                 cur[j] = min(down, diagonal);
//             }
//             front = cur;
//         }

//         return front[0];
//     }
// };