/* GFG  Submission    (Shortest Distance in a Binary Maze) */

/* Problem Statement: Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1. */




/* Solution 1: Using BFS */
// Time Complexity: O(4 * N * M)
// Space Complexity: O(N * M) + O(N * M)                // dist[], queue


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
Since this is BFS (all weights = 1):
First time you reach a cell = shortest path guaranteed 

This is pure BFS (level order traversal)

Each level = 1 step
First time reaching destination = shortest path */

// Time Complexity: O(4 * N * M)
// Space Complexity: O(N * M) + O(N * M)                // vis[], queue



// User function Template for C++

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
