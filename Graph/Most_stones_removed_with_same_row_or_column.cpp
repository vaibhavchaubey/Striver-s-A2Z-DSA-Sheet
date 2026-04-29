/* Leetcode Submission    (947. Most Stones Removed with Same Row or Column) */

/* Problem Statement: On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed. */




/* Solution: Using Disjoint Set Union (DSU) 
Whenever Graph is building dynamically or dynamic connections are happening, we can think of using Disjoint Set Union (DSU) or Union-Find data structure. Here we are connecting cells/nodes dynamically to form a graph. Hence, we can think of using DSU */


// Time Complexity:O(N * α(maxRow + maxCol))   ~   O(N)
// Space Complexity: O(α(maxRow + maxCol))        // DisjointSet (parent[] and size[])


// class DisjointSet{
//     vector<int> parent, size;
// public:
//     DisjointSet(int n){
//         parent.resize(n + 1);
//         size.resize(n + 1);

//         for(int i = 0; i <= n; i++){
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUParent(int node){
//         if(node == parent[node]){
//             return node;
//         }

//         return parent[node] = findUParent(parent[node]);
//     }

//     void unionBySize(int u, int v){
//         int parent_u = findUParent(u);
//         int parent_v = findUParent(v);

//         if(parent_u == parent_v){
//             return;
//         }
//         else if(size[parent_u] < size[parent_v]){
//             parent[parent_u] = parent_v;
//             size[parent_v] += size[parent_u];
//         }
//         else{
//             parent[parent_v] = parent_u;
//             size[parent_u] += size[parent_v];
//         }
//     }

//     bool isConnected(int u, int v){
//         return findUParent(u) == findUParent(v);
//     }
// };
// class Solution {
// public:
//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();

//         int maxRow = 0, maxCol = 0;

//         for(auto &it : stones){
//             maxRow = max(maxRow, it[0]);
//             maxCol = max(maxCol, it[1]);
//         }

//         DisjointSet ds(maxRow + maxCol + 1);

//         unordered_set<int> nodes;
//         for(auto &it : stones){
//             int nodeRow = it[0];
//             int nodeCol = it[1] + maxRow + 1;

//             ds.unionBySize(nodeRow, nodeCol);
//             nodes.insert(nodeRow);
//             nodes.insert(nodeCol);
//         }

//         int components = 0;
//         for(auto node : nodes){
//             if(ds.findUParent(node) == node){
//                 components++;
//             }
//         }

//         return (n - components);
//     }
// };