/* Leetcode  Submission    (74. Search a 2D Matrix) */

/* Problem Statement: You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity. */


/* Solution 1: */
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



/* Solution 2: Binary Search */
// Time Complexity: O(log(M * N))
// Space Complexity: O(1) 


// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         int lo = 0, hi = m*n-1;
//         while(lo <= hi){
//             int mid = lo + (hi - lo)/2;
//             // We can get the element at middle index using matrix[middle/col][middle%col]
//             int r = mid/n, c = mid%n;
//             if(matrix[r][c] == target){
//                 return true;
//             }
//             else if(matrix[r][c] < target){
//                 lo = mid + 1;
//             }
//             else{
//                 hi = mid - 1;
//             }
//         }
        
//         return false;
//     }
// };


