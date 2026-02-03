/* Leetcode  Submission    (994. Rotting Oranges) */

/* Problem Statement: You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1. */



/* Solution: Using BFS */
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)               // In the worst case, all the oranges might be rotten and will be stored in the queue simultaneously. The maximum size of the queue can be equal to the total number of oranges in the grid, i.e., n × n. 


// class Solution {
// public:
//     bool isSafe(int r, int c, vector<vector<int>>& grid){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1);
//     }
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         int total = 0, days = 0, count = 0;

//         queue<pair<int, int>> rotten;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(grid[i][j] != 0){
//                     total++;
//                 }
//                 if(grid[i][j] == 2){
//                     rotten.push({i, j});
//                 }
//             }
//         } 

//         vector<int> dirRow = {-1, 1, 0, 0};
//         vector<int> dirCol = {0, 0, -1, 1};

//         while(!rotten.empty()){
//             int k = rotten.size();
//             count += k;
//             while(k--){
//                 auto it = rotten.front();
//                 rotten.pop();

//                 for(int i = 0; i < 4; i++){
//                     int r = it.first + dirRow[i]; 
//                     int c = it.second + dirCol[i];

//                     if(isSafe(r, c, grid)){
//                         grid[r][c] = 2;
//                         rotten.push({r, c});
//                     }
//                 }
//             }
//             if(!rotten.empty()){
//                 days++;
//             }
//         }

//         return total == count ? days : -1;
//     }
// };

