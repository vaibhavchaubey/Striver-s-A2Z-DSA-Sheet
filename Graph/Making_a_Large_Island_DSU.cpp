/* Leetcode Submission    (827. Making A Large Island) */

/* Problem Statement: You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s. */




/* Solution: Using Disjoint Set Union (DSU) 
Whenever Graph is building dynamically or dynamic connections are happening, we can think of using Disjoint Set Union (DSU) or Union-Find data structure. Here we are connecting cells/nodes dynamically to form a graph. Hence, we can think of using DSU */


// Time Complexity:O(N^2 * α(N^2))   ~   O(N^2)
// Space Complexity: O(N * N)        // DisjointSet (parent[] and size[])


// class DisjointSet{
//     public:
//     vector<int> parent, size;
//     DisjointSet(int n){
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for(int i = 0; i <= n; i++){
//             parent[i] = i;                          // Initially, each node is its own parent (representative of its own set)
//             size[i] = 1;                           // Size is initialized to 1 for all nodes (each node is a set of size 1)
//         }
//     }

//     int findUParent(int node){
//         if(node == parent[node]){
//             return node;
//         }

//         return parent[node] = findUParent(parent[node]);            // Path Compression
//     }

//     void unionBySize(int u, int v){
//         int parent_u = findUParent(u); 
//         int parent_v = findUParent(v);

//         if(parent_u == parent_v){
//             return;
//         }

//         if(size[parent_u] < size[parent_v]){
//             parent[parent_u] = parent_v;
//             size[parent_v] += size[parent_u];
//         }
//         else{                                                    // size[parent_v] < size[parent_u]
//             parent[parent_v] = parent_u;
//             size[parent_u] += size[parent_v];
//         }
//     }
    
//     bool isConnected(int u, int v){
//         return findUParent(u) == findUParent(v);
//     }
// };
// class Solution {
// private:
//     // All 4 possible directions (vertical, horizontal)
//     vector<int> dirRow = {-1, 1, 0, 0};
//     vector<int> dirCol = {0, 0, -1, 1};

//     bool isSafe(int r, int c, vector<vector<int>>& grid){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m);
//     }

//     // Function to add initial islands to the disjoint set data structure
//     void addInitialIslands(vector<vector<int>> &grid, DisjointSet &ds, int n) {
//         for(int row = 0; row < n; row++){
//             for(int col = 0; col < n; col++){

//                 // If the cell is not land, skip
//                 if (grid[row][col] == 0){
//                     continue;
//                 }

//                 for(int i = 0; i < 4; i++){
//                     int r = row + dirRow[i];
//                     int c = col + dirCol[i];
                    
//                     if(isSafe(r, c, grid)){
//                         if(grid[r][c] == 1){
//                             int u = (row * n) + col;        // nodeNo 
//                             int v = (r * n) + c;            // adjNodeNo 
//                             ds.unionBySize(u, v);      // O(α(N * N))
//                         }
//                     }
//                 }
                
//             }
//         }
//     }
// public:
//     int largestIsland(vector<vector<int>>& grid) {      
//         int n = grid.size();  
//         DisjointSet ds(n * n);
        
//         // Function call to add initial islands in the disjoint set
//         addInitialIslands(grid, ds, n);

//         int ans = 0;
//         for(int row = 0; row < n; row++){
//             for(int col = 0; col < n; col++){
//                 // If the cell is a land cell, skip
//                 if (grid[row][col] == 1){
//                     continue;
//                 }

//                 // Set to store the ultimate parents of neighboring islands (To avoid counting the same island multiple times if it is connected to the current cell from multiple sides)
//                 set<int> components;

//                 for(int i = 0; i < 4; i++){
//                     int r = row + dirRow[i];
//                     int c = col + dirCol[i];
                    
//                     if(isSafe(r, c, grid)){
//                         if(grid[r][c] == 1){
//                             int v = (r * n) + c;            // adjNodeNo 
//                             int parent_v =  ds.findUParent(v);
//                             components.insert(parent_v);
//                         }
//                     }
//                 }

//                 int size = 0;

//                 // Iterate on all the neighborinh ultimate parents
//                 for(auto it : components){
//                     size += ds.size[it];
//                 }

//                 // Store the maximum size of island
//                 ans = max(ans, size + 1);
//             }
//         }

//         // Edge case (when there is no 0 in the grid, i.e., the whole grid is one big island)
//         for (int cellNo = 0; cellNo < n * n; cellNo++) {
//             int parent_cell = ds.findUParent(cellNo);
//             ans = max(ans, ds.size[parent_cell]);
//         }
        
//         return ans;
//     }
// };

