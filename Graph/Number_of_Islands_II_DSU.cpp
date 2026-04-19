/* GFG Submission    (Number Of Islands) */

/* Problem Statement: You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.

Your Task:
You don't need to read or print anything. Your task is to complete the function numOfIslands() which takes an integer n denoting no. of rows in the matrix, an integer m denoting the number of columns in the matrix and a 2D array of size k denoting  the number of operators.

Expected Time Complexity: O(m * n)
Expected Auxiliary Space: O(m * n) */




/* Solution: Using Disjoint Set Union (DSU) 
Whenever Graph is building dynamically or dynamic connections are happening, we can think of using Disjoint Set Union (DSU) or Union-Find data structure. Here we are connecting cells/nodes dynamically to form a graph. Hence, we can think of using DSU */


// Time Complexity: O(K * α(N * M))   ~  O(K)     
/* where K = no. of operators and N = no. of rows and M = no. of columns in the grid. */

// Space Complexity: O(N * M) + O(N * M)   ~  O(N * M)         // grid[], DisjointSet (parent[] and size[])


// class DisjointSet{
//     vector<int> parent, size;
//     public:
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
//   private:
//     bool isSafe(int r, int c, vector<vector<int>>& grid){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m);
//     }
//   public:
//     vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
//         vector<vector<int>> grid(n, vector<int>(m, 0));
//         vector<int> ans;
        
//         DisjointSet* ds = new DisjointSet(n * m);
        
//         // All 4 possible directions (vertical, horizontal)
//         vector<int> dirRow = {-1, 1, 0, 0};
//         vector<int> dirCol = {0, 0, -1, 1};
        
//         int cnt = 0;
        
//         for(auto op : operators){                   // O(K)
//             int row = op[0];
//             int col = op[1];
            
//             // Skip if the cell is already land
//             if(grid[row][col] == 1){
//                 ans.push_back(cnt);
//                 continue;
//             }
            
//             // Mark cell as land
//             grid[row][col] = 1;
//             cnt++;
            
//             for(int i = 0; i < 4; i++){
//                 int r = row + dirRow[i];
//                 int c = col + dirCol[i];
                
//                 if(isSafe(r, c, grid)){
//                     if(grid[r][c] == 1){
//                         int u = (row * m) + col;        // nodeNo 
//                         int v = (r * m) + c;            // adjNodeNo 
//                         if(!ds->isConnected(u, v)){     // O(α(N * M))
//                             cnt--;
//                             ds->unionBySize(u, v);      // O(α(N * M))
//                         }
//                     }
//                 }
                
                
//             }
            
//             ans.push_back(cnt);
//         }
        
//         return ans;
//     }
// };
