/* Leetcode  Submission    (240. Search a 2D Matrix II) */

/* Problem Statement: Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom. */


/* Solution: */
// Time Complexity: O(M + N)
// Space Complexity: O(1) 


// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         int r = 0, c = n-1;
//         while(r < m && c >= 0){
//             if(matrix[r][c] == target){
//                 return true;
//             }
//             else if(matrix[r][c] > target){
//                 c--;
//             }
//             else{
//                 r++;
//             }
//         }

//         return false;
//     }
// };

