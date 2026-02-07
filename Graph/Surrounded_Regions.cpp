/* Leetocde  Submission    (130. Surrounded Regions) */

/* Problem Statement: You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything. */



/* Solution: Using DFS 
If there is a 'O' at the boundary, then we can say that this 'O' and all its connected 'O's are not surrounded by 'X'. So we will start DFS from all unvisited boundary 'O' and mark all those 'O' as visited. Finally, we will flip all unvisited 'O' to 'X' because all those 'O' will be surrounded by 'X'. 
*/

// Time Complexity: O(N) + O(M) + O(N * M * 4)  ~  O(N x M) 
// Space Complexity: O(N * M) + O(N * M)             // vis[], recursion stack 


// class Solution {
// public:
//     bool isSafe(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& vis){
//         int n = board.size(), m = board[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && !vis[r][c]);
//     }
//     void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& vis){
//         vis[row][col] = true;

//         // All 4 possible directions (vertical, horizontal)
//         vector<int> dirRow = {-1, 1, 0, 0};
//         vector<int> dirCol = {0, 0, -1, 1};

//         for(int i = 0; i < 4; i++){
//             int r = row + dirRow[i];
//             int c = col + dirCol[i];

//             if(isSafe(r, c, board, vis)){
//                 dfs(r, c, board, vis);
//             }
//         }
//     }
//     void solve(vector<vector<char>>& board) {
//         int n = board.size(), m = board[0].size();

//         vector<vector<bool>> vis(n, vector<bool>(m, false));

//         // traverse first and last row
//         for(int j = 0; j < m; j++){
//             // start DFS from unvisited boundary 'O' (top row)
//             if(!vis[0][j] && board[0][j] == 'O'){
//                 dfs(0, j, board, vis);
//             }
//             // start DFS from unvisited boundary 'O' (bottom row)
//             if(!vis[n-1][j] && board[n-1][j] == 'O'){
//                 dfs(n-1, j, board, vis);
//             }
//         }

//         // traverse first and last column
//         for(int i = 0; i < n; i++){
//             // start DFS from unvisited boundary 'O' (left col)
//             if(!vis[i][0] && board[i][0] == 'O'){
//                 dfs(i, 0, board, vis);
//             }
//             // start DFS from unvisited boundary 'O' (right col)
//             if(!vis[i][m-1] && board[i][m-1] == 'O'){
//                 dfs(i, m-1, board, vis);
//             }
//         }

//         // flip all unvisited 'O' to 'X'  (because all those 'O' will be surrounded by 'X')
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(!vis[i][j] && board[i][j] == 'O'){
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };







/* GFG  Submission    (Replace O's with X's) */

/* Problem Statement: You are given a grid[][] of size n*m, where every element is either 'O' or 'X'. You have to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it. */




/* Solution: Using DFS */
// Time Complexity: O(N) + O(M) + O(N * M * 4)  ~  O(N x M) 
// Space Complexity: O(N * M) + O(N * M)             // vis[], recursion stack 


// class Solution {
//   public:
//     bool isSafe(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 'O' && !vis[r][c]);
//     }
//     void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis){
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
//     void fill(vector<vector<char>>& grid) {
//         int n = grid.size(), m = grid[0].size();

//         vector<vector<bool>> vis(n, vector<bool>(m, false));

//         // traverse first and last row
//         for(int j = 0; j < m; j++){
//             // start DFS from unvisited boundary 'O' (top row)
//             if(!vis[0][j] && grid[0][j] == 'O'){
//                 dfs(0, j, grid, vis);
//             }
//             // start DFS from unvisited boundary 'O' (bottom row)
//             if(!vis[n-1][j] && grid[n-1][j] == 'O'){
//                 dfs(n-1, j, grid, vis);
//             }
//         }

//         // traverse first and last column
//         for(int i = 0; i < n; i++){
//             // start DFS from unvisited boundary 'O' (left col)
//             if(!vis[i][0] && grid[i][0] == 'O'){
//                 dfs(i, 0, grid, vis);
//             }
//             // start DFS from unvisited boundary 'O' (right col)
//             if(!vis[i][m-1] && grid[i][m-1] == 'O'){
//                 dfs(i, m-1, grid, vis);
//             }
//         }

//         // flip all unvisited 'O' to 'X'  (because all those 'O' will be surrounded by 'X')
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(!vis[i][j] && grid[i][j] == 'O'){
//                     grid[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };