/* Leetcode  Submission    (240. Search a 2D Matrix II) */

/* Problem Statement: Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom. */


/* Solution 1: Brute Force */
// Time Complexity: O(M * N)
// Space Complexity: O(1) 


// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(matrix[i][j] == target){
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };



/* Solution 2: Better Approach (Applying binary search on each row)*/
// Time Complexity: O(M logN)
// Space Complexity: O(1) 


// class Solution {
// public:
//     bool binarySearch(vector<int>& nums, int target){
//         int n = nums.size();
//         int low = 0, high = n - 1;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(nums[mid] == target){
//                 return true;
//             }
//             else if(nums[mid] < target){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }

//         return false;
//     }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         for(int i = 0; i < m; i++){
//             if(binarySearch(matrix[i], target)){
//                 return true;
//             }
//         }

//         return false;
//     }
// };


/* OR */


// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         for(int i = 0; i < m; i++){
//             // using inbuilt binary_search
//             if(binary_search(matrix[i].begin(), matrix[i].end(), target)){
//                 return true;
//             }
//         }

//         return false;
//     }
// };



/* Solution 3: Optimal Approach */
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

