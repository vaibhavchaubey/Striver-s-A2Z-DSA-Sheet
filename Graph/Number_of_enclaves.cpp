/* Leetocde  Submission    (1020. Number of Enclaves) */

/* Problem Statement: You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves. */



/* Solution 1: Using DFS 
If there is a '1' at the boundary, then we can say that this '1' and all its connected '1's are not enclaves. So we will start DFS from all unvisited boundary '1' and mark all those '1' as visited. Finally, we will count all unvisited '1' because all those '1' will be enclaves. 
*/

// Time Complexity: O(N) + O(M) + O(N * M * 4)  ~  O(N x M) 
// Space Complexity: O(N * M) + O(N * M)             // vis[], recursion stack 


// class Solution {
// public:
//     bool isSafe(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c]);
//     }
//     void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis){
//         vis[row][col] = true;

//         // All 4 possible directions (vertical, horizontal)
//         vector<int> dirRow = {-1, 1, 0, 0};
//         vector<int> dirCol = {0, 0, -1, 1};

//         for(int i = 0; i < 4; i++){
//             int r = row + dirRow[i];
//             int c = col + dirCol[i];

//             if(isSafe(r, c, grid, vis)){
//                 dfs(r, c, grid, vis);
//             }
//         }
//     }
//     int numEnclaves(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();

//         vector<vector<bool>> vis(n, vector<bool>(m, false));

//         // traverse first and last row
//         for(int j = 0; j < m; j++){
//             // start DFS from unvisited boundary 1 (top row)
//             if(!vis[0][j] && grid[0][j] == 1){
//                 dfs(0, j, grid, vis);
//             }
//             // start DFS from unvisited boundary 1 (bottom row)
//             if(!vis[n-1][j] && grid[n-1][j] == 1){
//                 dfs(n-1, j, grid, vis);
//             }
//         }

//         // traverse first and last column
//         for(int i = 0; i < n; i++){
//             // start DFS from unvisited boundary 1 (left col)
//             if(!vis[i][0] && grid[i][0] == 1){
//                 dfs(i, 0, grid, vis);
//             }
//             // start DFS from unvisited boundary 1 (right col)
//             if(!vis[i][m-1] && grid[i][m-1] == 1){
//                 dfs(i, m-1, grid, vis);
//             }
//         }

//         int count = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(!vis[i][j] && grid[i][j] == 1){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };




/* Solution 2: Using BFS 
If there is a '1' at the boundary, then we can say that this '1' and all its connected '1's are not enclaves. So we will start BFS from all unvisited boundary '1' and mark all those '1' as visited. Finally, we will count all unvisited '1' because all those '1' will be enclaves.
*/

// Time Complexity: O(N) + O(M) + O(N * M * 4)  ~  O(N x M) 
// Space Complexity: O(N * M) + O(N * M)             // vis[], queue


// class Solution {
// public:
//     bool isSafe(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c]);
//     }
//     int numEnclaves(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();

//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         queue<pair<int, int>> q;       // row, col

//         // traverse first and last row
//         for(int j = 0; j < m; j++){
//             // push unvisited boundary 1 (top row)
//             if(!vis[0][j] && grid[0][j] == 1){
//                 vis[0][j] = true;
//                 q.push({0, j});
//             }
//             // push unvisited boundary 1 (bottom row)
//             if(!vis[n-1][j] && grid[n-1][j] == 1){
//                 vis[n-1][j] = true;
//                 q.push({n-1, j});
//             }
//         }

//         // traverse first and last column
//         for(int i = 0; i < n; i++){
//             // push unvisited boundary 1 (left col)
//             if(!vis[i][0] && grid[i][0] == 1){
//                 vis[i][0] = true;
//                 q.push({i, 0});
//             }
//             // push unvisited boundary 1 (right col)
//             if(!vis[i][m-1] && grid[i][m-1] == 1){
//                 vis[i][m-1] = true;
//                 q.push({i, m-1});
//             }
//         }
        
//         // All 4 possible directions (vertical, horizontal)
//         vector<int> dirRow = {-1, 1, 0, 0};
//         vector<int> dirCol = {0, 0, -1, 1};
        
//         while(!q.empty()){
//             auto [row, col] = q.front();
//             q.pop();

//             for(int i = 0; i < 4; i++){
//                 int r = row + dirRow[i];
//                 int c = col + dirCol[i];
                
//                 if(isSafe(r, c, grid, vis)){
//                     vis[r][c] = true;
//                     q.push({r, c});
//                 }
//             }
//         }

//         int count = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(!vis[i][j] && grid[i][j] == 1){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };