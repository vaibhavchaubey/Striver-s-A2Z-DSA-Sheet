/* Problem Statement: Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The efficient way is the one that involves the least number of multiplications.
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) 
where the ith matrix has the dimensions (arr[i-1] x arr[i]). */


/* GFG   Submission    (Matrix Chain Multiplication) */


/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: (Exponential)
// Space Complexity: O(N) (Recursion)


// class Solution{
// public:
//     int helper(int i, int j, int arr[]){
//         if(i == j){                              // base condition
//             return 0;
//         }
        
//         int mini = INT_MAX;
//         // partioning loop
//         for(int k = i; k < j; k++){
//             int steps = arr[i-1] * arr[k] * arr[j] + helper(i, k, arr) + helper(k+1, j, arr);
//             mini = min(mini, steps);
//         }
        
//         return mini;
//     }
//     int matrixMultiplication(int N, int arr[])
//     {
//         return helper(1, N-1, arr);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N*N) 
// Space Complexity: O(N) (Recursion)   +   O(N*N)  (Array)


// class Solution{
// public:
//     int helper(int i, int j, int arr[], vector<vector<int>>& dp){
//         if(i == j){                         // base condition
//             return 0;
//         }
        
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         int mini = INT_MAX;
//         for(int k = i; k < j; k++){
//             int steps = arr[i-1] * arr[k] * arr[j] + helper(i, k, arr, dp) + helper(k+1, j, arr, dp);
//             mini = min(mini, steps);
//         }
        
//         return dp[i][j] = mini;
//     }
//     int matrixMultiplication(int N, int arr[])
//     {
//         vector<vector<int>> dp(N, vector<int>(N, -1));
        
//         return helper(1, N-1, arr, dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N*N)
// Space Complexity: O(N*N)  (Array) 


// class Solution{
// public:
//     int matrixMultiplication(int N, int arr[])
//     {
//         vector<vector<int>> dp(N, vector<int>(N, 0));
        
//         for(int i = 1; i < N; i++){             // base condition
//             dp[i][i] = 0;
//         }
        
//         for(int i = N-1; i >= 1; i--){
//             for(int j = i+1; j < N; j++){
//                 int mini = INT_MAX;
//                 // partioning loop
//                 for(int k = i; k < j; k++){
//                     int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
//                     mini = min(mini, steps);
//                 }
                
//                 dp[i][j] = mini;
//             }
//         }
        
//         return dp[1][N-1];
//     }
// };