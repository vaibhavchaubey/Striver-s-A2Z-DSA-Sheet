/* GFG  Submission    (Find the number of islands) */

/* Problem Statement: Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions. */



/* Solution 1: Using DFS */
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)       // vis[]


// class Solution {
//   public:
//     bool isSafe(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 'L' && !vis[r][c]);
//     }
//     void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis){
//         vis[row][col] = true;

//         // All 8 possible directions (vertical, horizontal, diagonal)
//         vector<int> dirRow = {-1, -1, -1, 0, 0, 1, 1, 1};
//         vector<int> dirCol = {-1, 0, 1, -1, 1, -1, 0, 1};

//         for(int i = 0; i < 8; i++){
//             int r = row + dirRow[i];
//             int c = col + dirCol[i];

//             if(isSafe(r, c, grid, vis)){
//                 dfs(r, c, grid, vis);
//             }
//         }
//     }

//     int countIslands(vector<vector<char>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         int islands = 0;

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 // Start a new DFS when an unvisited land cell is found
//                if(grid[i][j] == 'L' && !vis[i][j]){
//                    islands++;
//                    dfs(i, j, grid, vis);
//                }
//             }
//         }

//         return islands;
//     }
// };



/* Solution 2: Using BFS */
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)       // vis[], queue


// class Solution {
//   public:
//     bool isSafe(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 'L' && !vis[r][c]);
//     }
//     void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis){
//         // All 8 possible directions (vertical, horizontal, diagonal)
//         vector<int> dirRow = {-1, -1, -1, 0, 0, 1, 1, 1};
//         vector<int> dirCol = {-1, 0, 1, -1, 1, -1, 0, 1};

//         queue<pair<int, int>> q;
//         q.push({row, col});
//         vis[row][col] = true;

//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();

//             for(int i = 0; i < 8; i++){
//                 int r = it.first + dirRow[i];
//                 int c = it.second + dirCol[i];

//                 if(isSafe(r, c, grid, vis)){
//                     vis[r][c] = true;
//                     q.push({r, c});
//                 }
//             }
//         }
//     }
//     int countIslands(vector<vector<char>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         int islands = 0;

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 // Start a new DFS when an unvisited land cell is found
//                if(grid[i][j] == 'L' && !vis[i][j]){
//                    islands++;
//                    bfs(i, j, grid, vis);
//                }
//             }
//         }

//         return islands;
//     }
// };