/* Leetcode  Submission    (1277. Count Square Submatrices with All Ones) */


/* Problem Statement: Given a m * n matrix of ones and zeros, return how many square submatrices have all ones. */



/* A square matrix is a matrix with equal numbers of rows and columns. */


/* Solution:  */
// Time Complexity: O(N*M), where N = total no. of rows and M = total no. of columns
// Space Complexity: O(N*M), where N = total no. of rows and M = total no. of columns


// class Solution {
// public:
//     int countSquares(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, 0));
//         // for the first row and first column, we will just copy the values of the matrix as it is to the dp array. 
//         for(int j = 0; j < m; j++){         // for 1st row
//             dp[0][j] = matrix[0][j];
//         }
//         for(int i = 0; i < n; i++){        // for 1st column
//             dp[i][0] = matrix[i][0];
//         }

//         for(int i = 1; i < n; i++){
//             for(int j = 1; j < m; j++){
//                 if(matrix[i][j] == 0){
//                     dp[i][j] = 0;
//                 }
//                 else{           // matrix[i][j] == 1
//                     dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
//                 }
//             }
//         }

//         int sum = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 sum += dp[i][j];
//             }
//         }

//         return sum;
//     }
// };