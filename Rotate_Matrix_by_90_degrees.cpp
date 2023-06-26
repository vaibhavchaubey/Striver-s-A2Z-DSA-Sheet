/* Leetcode  Submission    (48. Rotate Image) */

/* Problem Statement: You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation. */



/* Solution 1: Brute force */
/* Approach: Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last 
column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so. */
// Time Complexity: O(N*N) 
// Space Complexity: O(N*N)


// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dummyMatrix = matrix;

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 matrix[j][n-1-i] = dummyMatrix[i][j];
//             }
//         }
//     }
// };



/* Solution 2: Optimized approach */
// Time Complexity: O(N*N) + O(N*N)
// Space Complexity: O(1)


// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
        
//         // Transpose the matrix
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }

//         // Reversing each row of the matrix
//         for(int i = 0; i < n; i++){
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
//     }
// };