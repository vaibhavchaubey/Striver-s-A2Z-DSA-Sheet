/* Leetcode  Submission    (54. Spiral Matrix) */

/* Problem Statement: Given an m x n matrix, return all elements of the matrix in spiral order. */


/* Solution: */
// Time Complexity: O(M * N)
// Space Complexity: O(1)


// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int R = matrix.size();
//         int C = matrix[0].size();
//         vector<int> ans;
        
//         int row_start = 0, row_end = R-1, column_start = 0, column_end = C-1;
//         while(row_start <= row_end && column_start <= column_end){  
//             // for row_start
//             for(int col = column_start; col <= column_end; col++){
//                 ans.push_back(matrix[row_start][col]);
//             }
//             row_start++;
            
//             // for column_end
//             for(int row = row_start; row <= row_end; row++){
//                 ans.push_back(matrix[row][column_end]);
//             }
//             column_end--;
            
//             // for row_end
//             if(row_start <= row_end){
//                 for(int col = column_end; col >= column_start; col--){
//                 ans.push_back(matrix[row_end][col]);
//                 }
//                 row_end--;
//             }
            
//             // for column_start
//             if(column_start <= column_end){
//                 for(int row = row_end; row >= row_start; row--){
//                 ans.push_back(matrix[row][column_start]);
//                 }
//                 column_start++;
//             }
//         }

//         return ans;
//     }
// };

