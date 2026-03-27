/* GFG Submission    (Shortest Distance in a Binary Maze) */

/* Problem Statement: Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1. */




/* Solution 1: Using BFS
If I detect destination while exploring neighbors, I can return early and avoid pushing others.
Because BFS guarantees:
The first time you reach a node → it is via the shortest path
So:

✔ You can stop immediately
✔ No need to explore further
✔ No need to push other neighbors */

// Time Complexity: O(4 * N * M)
// Space Complexity: O(N * M) + O(N * M)                // dist[][], queue



// class Solution {
//   public:
//     bool isSafe(int r, int c, vector<vector<int>>& grid){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1);
//     }
//     int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
//                      pair<int, int> destination) {
//         if(source == destination){
//             return 0;
//         }
        
//         int n = grid.size(), m = grid[0].size();
        
//         vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
//         dist[source.first][source.second] = 0;
        
//         queue<pair<int, int>> q;         // row, col
//         q.push(source);
        
//         // All 4 possible directions (vertical, horizontal)
//         vector<int> dirRow = {-1, 0, 1, 0};
//         vector<int> dirCol = {0, 1, 0, -1};
        
//         while(!q.empty()){
//             auto [row, col] = q.front();
//             q.pop();
            
//             for(int i = 0; i < 4; i++){
//                 int r = row + dirRow[i];
//                 int c = col + dirCol[i];
                
//                 if(isSafe(r, c, grid)){
//                     if(dist[row][col] + 1 < dist[r][c]){
//                         dist[r][c] = dist[row][col] + 1;
//                         if(destination.first == r && destination.second == c){
//                             return dist[r][c];
//                         }
                        
//                         q.push({r, c});
//                     }   
//                 }   
//             }
//         }
        
//         return -1;
//     }
// };




/* Solution 2: Using BFS 
If I detect destination while exploring neighbors, I can return early and avoid pushing others.
Because BFS guarantees:
The first time you reach a node → it is via the shortest path
So:

✔ You can stop immediately
✔ No need to explore further
✔ No need to push other neighbors */

// Time Complexity: O(4 * N * M)
// Space Complexity: O(N * M) + O(N * M)                // vis[][], queue



// class Solution {
//   public:
//     bool isSafe(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c]);
//     }
//     int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
//                      pair<int, int> destination) {
//         if(source == destination){
//             return 0;
//         }
        
//         int n = grid.size(), m = grid[0].size();
        
//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         vis[source.first][source.second] = true;
        
//         queue<pair<int, int>> q;         // row, col
//         q.push(source);
        
//         int steps = 0;
//         // All 4 possible directions (vertical, horizontal)
//         vector<int> dirRow = {-1, 0, 1, 0};
//         vector<int> dirCol = {0, 1, 0, -1};
        
//         while(!q.empty()){
//             int size = q.size();
//             steps++;
            
//             while(size--){
//                 auto [row, col] = q.front();
//                 q.pop();
                
//                 for(int i = 0; i < 4; i++){
//                     int r = row + dirRow[i];
//                     int c = col + dirCol[i];
                    
//                     if(isSafe(r, c, grid, vis)){
//                         if(destination.first == r && destination.second == c){
//                             return steps;
//                         }
                           
//                         vis[r][c] = true; 
//                         q.push({r, c});  
//                     }   
//                 }
//             }
//         }
        
//         return -1;
//     }
// };




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* Leetcode Submission    (1091. Shortest Path in Binary Matrix) */

/* Problem Statement: Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path. */




/* Solution: Using BFS
If I detect destination while exploring neighbors, I can return early and avoid pushing others.
Because BFS guarantees:
The first time you reach a node → it is via the shortest path
So:

✔ You can stop immediately
✔ No need to explore further
✔ No need to push other neighbors */

// Time Complexity: O(8 * N * M)
// Space Complexity: O(N * M) + O(N * M)                // vis[][], queue



// class Solution {
// public:
//     bool isSafe(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 0 && !vis[r][c]);
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         if(grid[0][0] == 1){
//             return -1;
//         }
//         // source = destination
//         if(n - 1 == 0 && m - 1 == 0){
//             return 1;
//         }
        
//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         vis[0][0] = true;
        
//         queue<pair<int, int>> q;         // row, col
//         q.push({0, 0});
        
//         // Starting cell itself counts as 1 step in the path, so we initialize steps to 1.
//         int steps = 1;
//         // All 8 possible directions (vertical, horizontal, diagonal)
//         vector<int> dirRow = {-1, -1, -1, 0, 0, 1, 1, 1};
//         vector<int> dirCol = {-1, 0, 1, -1, 1, -1, 0, 1};
        
//         while(!q.empty()){
//             int size = q.size();
//             steps++;
            
//             while(size--){
//                 auto [row, col] = q.front();
//                 q.pop();
                
//                 for(int i = 0; i < 8; i++){
//                     int r = row + dirRow[i];
//                     int c = col + dirCol[i];
                    
//                     if(isSafe(r, c, grid, vis)){
//                         if(n-1 == r && m-1 == c){
//                             return steps;
//                         }
                           
//                         vis[r][c] = true; 
//                         q.push({r, c});  
//                     }   
//                 }
//             }
//         }
        
//         return -1;
//     }
// };
