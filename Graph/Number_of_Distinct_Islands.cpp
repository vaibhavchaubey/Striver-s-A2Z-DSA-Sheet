/* GFG  Submission    (Number of Distinct Islands) */

/* Problem Statement: Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected). */



/* Solution 1: Using DFS
Substract the base coordinates of the island from all the coordinates of the island to get the relative position of all the cells in the island. Store this relative position in a set to get distinct islands. At the end, the size of the set will give us the number of distinct islands. */

// Time Complexity: O(n * m log(n * m)) + O(n * m * 4)              // O(n * m log(n * m)) is for inserting the shape of the island in the set and O(n * m * 4) is for traversing all the cells of the grid and all 4 directions for each cell.
// Space Complexity: O(n * m) + O(n * m) + O(n * m)                 // vis[], recursion stack, set



// class Solution {
//   public:
//     bool isSafe(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c]);
//     }
//     void dfs(int row, int col, int baseRow, int baseCol, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int, int>>& shape){
//         vis[row][col] = true;
//         // Store relative position
//         shape.push_back({row - baseRow, col - baseCol});
        
//         // All 4 possible directions (vertical, horizontal)
//         vector<int> dirRow = {-1, 0, 1, 0};
//         vector<int> dirCol = {0, 1, 0, -1};
        
//         for(int i = 0; i < 4; i++){
//             int r = row + dirRow[i];
//             int c = col + dirCol[i];
            
//             if(isSafe(r, c, grid, vis)){
//                 dfs(r, c, baseRow, baseCol, grid, vis, shape);
//             }
//         }
//     }
//     int countDistinctIslands(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         vector<vector<bool>> vis(n, vector<bool>(m, false));
        
//         set<vector<pair<int, int>>> st;
        
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 // Start a new DFS when an unvisited land cell is found
//                 if(grid[i][j] == 1 && !vis[i][j]){
//                     int baseRow = i;
//                     int baseCol = j;
//                     vector<pair<int, int>> shape;
//                     dfs(i, j, baseRow, baseCol, grid, vis, shape);
//                     st.insert(shape);
//                 }
//             }
//         }
        
//         return st.size();
//     }
// };




/* Solution 2: Using BFS 
Substract the base coordinates of the island from all the coordinates of the island to get the relative position of all the cells in the island. Store this relative position in a set to get distinct islands. At the end, the size of the set will give us the number of distinct islands. */

// Time Complexity: O(n * m log(n * m)) + O(n * m * 4)              // O(n * m log(n * m)) is for inserting the shape of the island in the set and O(n * m * 4) is for traversing all the cells of the grid and all 4 directions for each cell.
// Space Complexity: O(n * m) + O(n * m) + O(n * m)                 // vis[], queue, set


// class Solution {
//   public:
//     bool isSafe(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c]);
//     }
//     void bfs(int row, int col, int baseRow, int baseCol, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int, int>>& shape){
//         // All 4 possible directions (vertical, horizontal)
//         vector<int> dirRow = {-1, 0, 1, 0};
//         vector<int> dirCol = {0, 1, 0, -1};
        
//         queue<pair<int, int>> q;
//         q.push({row, col});
//         vis[row][col] = true;
//         // Store relative position
//         shape.push_back({row - baseRow, col - baseCol});
        
//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();
            
//             for(int i = 0; i < 4; i++){
//             int r = it.first + dirRow[i];
//             int c = it.second + dirCol[i];
            
//                 if(isSafe(r, c, grid, vis)){
//                     vis[r][c] = true;
//                     q.push({r, c});
//                     shape.push_back({r - baseRow, c - baseCol});
//                 }
//             }
//         }
//     }
//     int countDistinctIslands(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         vector<vector<bool>> vis(n, vector<bool>(m, false));
        
//         set<vector<pair<int, int>>> st;
        
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 // Start a new DFS when an unvisited land cell is found
//                 if(grid[i][j] == 1 && !vis[i][j]){
//                     int baseRow = i;
//                     int baseCol = j;
//                     vector<pair<int, int>> shape;
//                     bfs(i, j, baseRow, baseCol, grid, vis, shape);
//                     st.insert(shape);
//                 }
//             }
//         }
        
//         return st.size();
//     }
// };
