/* Leetcode  Submission    (162. Find Peak Element) */

/* Here Peak Element means  =>  arr[i][j] > arr[i-1][j]   arr[i][j] > arr[i+1][j]   arr[i][j] > arr[i][j-1]   arr[i][j] > arr[i][j+1] */

/* Problem Statement: A peak element in a 2D grid is an element that is strictly greater than all of its adjacent 
neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return 
the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time. */


/* Solution 1: Brute Force   */
// Time Complexity: O(M * N)
// Space Complexity: O(1)


// class Solution {
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 // top
//                 bool cond1 = (i == 0 || mat[i][j] > mat[i-1][j]);
//                 // down
//                 bool cond2 = (i == m-1 || mat[i][j] > mat[i+1][j]);
//                 // left
//                 bool cond3 = (j == 0 || mat[i][j] > mat[i][j-1]);
//                 // right
//                 bool cond4 = (j == n-1 || mat[i][j] > mat[i][j+1]);

//                 if(cond1 && cond2 && cond3 && cond4){
//                     return {i, j};
//                 }

//             }
//         }

//         return {-1, -1};
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N * logM)
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxRowElementPosition(vector<int>& arr, int n){
//         int maxIdx = 0;
//         for(int i = 0; i < n; i++){
//             if(arr[i] > arr[maxIdx]){
//                 maxIdx = i;
//             }
//         }

//         return maxIdx;
//     }
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();
//         int startRow = 0, endRow = m-1;
//         while(startRow <= endRow){
//             int middleRow = startRow + (endRow - startRow) / 2;

//             // will get max element position for that row
//             int rowMax = maxRowElementPosition(mat[middleRow], n);

//             if((middleRow == 0 || mat[middleRow][rowMax] > mat[middleRow - 1][rowMax]) && (middleRow == m-1 || mat[middleRow][rowMax] > mat[middleRow + 1][rowMax])){
//                 return {middleRow, rowMax};
//             }

//             // if max is lesser than next rows same column element, will move startRow to nextRow
//             else if(middleRow < m-1 && mat[middleRow][rowMax] < mat[middleRow + 1][rowMax]){
//                 startRow = middleRow + 1; 
//             }
//             // otherwise move the endRow to current row - 1
//             else{
//                 endRow = middleRow - 1;
//             }
//         }

//         return {-1, -1};
//     }
// };
