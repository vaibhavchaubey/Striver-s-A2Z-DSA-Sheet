/* Leetcode  Submission    (73. Set Matrix Zeroes) */

/* Problem Statement: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.   
You must do it in place.  */



/* Solution 1: */
// Time Complexity: O(2 * M * N)  where M and N are the number of rows and columns respectively
// Space Complexity: O(M + N)


// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int R = matrix.size(), C = matrix[0].size();
//         vector<int> row(R,1);
//         vector<int> col(C,1);
        
//         for(int i = 0; i < R; i++){
//             for(int j = 0; j < C; j++){
//                 if(matrix[i][j] == 0){
//                     row[i] = 0;
//                     col[j] = 0;
//                 }
//             }
//         }
        
//         for(int i = 0; i < R; i++){
//             for(int j = 0; j < C; j++){
//                 if(row[i] == 0 || col[j] == 0){ 
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
        
//     }
// };



/* Solution 2: */
// Time Complexity: O(2 * M * N)  where M and N are the number of rows and columns respectively
// Space Complexity: O(1)


// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int col0 = 1, R = matrix.size(), C = matrix[0].size();
        
//         for(int i = 0; i < R; i++){
//             if(matrix[i][0] == 0){
//                 col0 = 0;
//             }
//             for(int j = 1; j < C; j++){
//                 if(matrix[i][j] == 0){
//                     matrix[i][0] = matrix[0][j] = 0;
//                 }
//             }
//         }
        
//         for(int i = R-1; i >= 0 ; i--){
//             for(int j = C-1; j >= 1; j--){
//                 if(matrix[i][0] == 0 || matrix[0][j] == 0){ 
//                     matrix[i][j] = 0;
//                 }
//             }
//             if(col0 == 0){
//                 matrix[i][0] = 0;
//             }
//         }
        
//     }
// };




/* GFG  Submission    (Make Zeroes) */

/* Problem Statement: Given a matrix of  size n x m. Your task is to make Zeroes, that means in whole matrix 
when you find a zero, convert its upper, lower, left, and right value to zero and make that element the sum 
of the upper, lower, left and right value. Do the following tasks according to the initial matrix.  */


/* Solution: */
// Time Complexity: O(M * N)  where M and N are the number of rows and columns respectively
// Space Complexity: O(M * N)


// class Solution {
// public:
//     void MakeZeros(vector<vector<int> >& matrix) {
//         int R = matrix.size();
//         int C = matrix[0].size();
        
//         vector<vector<int>> cloneMatrix = matrix;
//         for(int i = 0; i < R; i++){
//             for(int j = 0; j < C; j++){
//                 if(cloneMatrix[i][j] == 0){
//                     int sum = 0;
//                     if(i-1 >= 0){                   // upper
//                         sum += cloneMatrix[i-1][j];
//                         matrix[i-1][j] = 0;
//                     }
//                     if(i+1 < R){                   // lower
//                         sum += cloneMatrix[i+1][j];
//                         matrix[i+1][j] = 0;
//                     }
//                     if(j-1 >= 0){                    // left
//                         sum += cloneMatrix[i][j-1];
//                         matrix[i][j-1] = 0;
//                     }
//                     if(j+1 < C){                  // right
//                         sum += cloneMatrix[i][j+1];
//                         matrix[i][j+1] = 0;
//                     }
//                     matrix[i][j] = sum;
//                 }
//             }
//         }
//     }
// };