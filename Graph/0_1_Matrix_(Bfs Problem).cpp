/* GFG  Submission    (Distance of nearest cell having 1) */

/* Problem Statement: Given a binary grid[][], where each cell contains either 0 or 1, find the distance of the nearest 1 for every cell in the grid.
The distance between two cells (i1, j1)  and (i2, j2) is calculated as |i1 - i2| + |j1 - j2|. 
You need to return a matrix of the same size, where each cell (i, j) contains the minimum distance from grid[i][j] to the nearest cell having value 1.

Note: It is guaranteed that there is at least one cell with value 1 in the grid. */



/* Solution: Using BFS */
// Time Complexity: O(N * M) + O(N * M * 4) ~ O(N x M) 
/* the BFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. */

// Space Complexity: O(N * M) + O(N * M) + O(N * M) ~ O(N * M)               // vis[], dist[], queue space takes up N x M locations at max


// class Solution {
//   public:
//     bool isSafe(int r, int c, vector<vector<bool>>& vis){
//         int n = vis.size(), m = vis[0].size();
        
//         return (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]);
//     }
//     vector<vector<int>> nearest(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
        
//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         vector<vector<int>> dist(n, vector<int>(m, 0));
        
//         queue<pair<pair<int, int>, int>> q;       // row, col, steps
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(grid[i][j] == 1){
//                     // if the cell has 1, then the distance is 0
//                     q.push({{i, j}, 0});
//                     vis[i][j] = true;
//                 }
//             }
//         }
        
//         vector<int> dirRow = {-1, 1, 0, 0};
//         vector<int> dirCol = {0, 0, -1, 1};
        
//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();
//             int row = it.first.first;
//             int col = it.first.second;
//             int steps = it.second;
            
//             dist[row][col] = steps;
//             for(int i = 0; i < 4; i++){
//                 int r = row + dirRow[i];
//                 int c = col + dirCol[i];
                
//                 if(isSafe(r, c, vis)){
//                     vis[r][c] = true;
//                     q.push({{r, c}, steps + 1});
//                 }
//             }
//         }
        
//         return dist;
//     }
// };






/* Leetocde  Submission    (542. 01 Matrix) */

/* Problem Statement: Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1. */



/* Solution: Using BFS */
// Time Complexity: O(N * M) + O(N * M * 4) ~ O(N x M) 
/* the BFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. */

// Space Complexity: O(N * M) + O(N * M) + O(N * M) ~ O(N * M)               // vis[], dist[], queue space takes up N x M locations at max


// class Solution {
// public:
//     bool isSafe(int r, int c, vector<vector<bool>>& vis){
//         int n = vis.size(), m = vis[0].size();
        
//         return (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]);
//     }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n = mat.size(), m = mat[0].size();
        
//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         vector<vector<int>> dist(n, vector<int>(m, 0));
        
//         queue<pair<pair<int, int>, int>> q;       // row, col, steps
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(mat[i][j] == 0){
//                     // if the cell has 0, then the distance is 0
//                     q.push({{i, j}, 0});
//                     vis[i][j] = true;
//                 }
//             }
//         }
        
//         vector<int> dirRow = {-1, 1, 0, 0};
//         vector<int> dirCol = {0, 0, -1, 1};
        
//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();
//             int row = it.first.first;
//             int col = it.first.second;
//             int steps = it.second;
            
//             dist[row][col] = steps;
//             for(int i = 0; i < 4; i++){
//                 int r = row + dirRow[i];
//                 int c = col + dirCol[i];
                
//                 if(isSafe(r, c, vis)){
//                     vis[r][c] = true;
//                     q.push({{r, c}, steps + 1});
//                 }
//             }
//         }
        
//         return dist;
//     }
// };