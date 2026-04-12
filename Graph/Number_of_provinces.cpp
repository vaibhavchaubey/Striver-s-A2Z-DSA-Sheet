/* Leetcode  Submission    (547. Number of Provinces) */

/* Problem Statement: There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces. */



/* Solution 1: */
// Time Complexity: O(N^2)
// Space Complexity: O(N) + O(N)       // vis[], recursion


// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis) {
//         vis[node] = true;
//         for (int i = 0; i < isConnected.size(); i++) {
//             if (isConnected[node][i] && !vis[i]) {
//                 dfs(i, isConnected, vis);
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         int numberOfComponents = 0;
//         vector<bool> vis(n);

//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 numberOfComponents++;
//                 dfs(i, isConnected, vis);
//             }
//         }

//         return numberOfComponents;
//     }
// };




/* Solution 2: Converting adj matrix to adj list */
// Time Complexity: O(N^2) + O(N + E)
// Space Complexity: O(N) + O(N)       // vis[], recursion


// class Solution {
// public:
//     void dfs(int node, vector<int> adj[], vector<bool>& vis) {
//         vis[node] = true;
//         for (auto it : adj[node]) {
//             if (!vis[it]) {
//                 dfs(it, adj, vis);
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         int numberOfComponents = 0;
//         vector<int> adj[n];
//         vector<bool> vis(n, false);

//         // Convert matrix to list
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(isConnected[i][j] == 1 && i != j){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 numberOfComponents++;
//                 dfs(i, adj, vis);
//             }
//         }

//         return numberOfComponents;
//     }
// };



/* Solution 3: Using Disjoint Set*/
// Time Complexity: O(N^2 * α(n)) ~ O(N^2)
// Space Complexity: O(N)             // DisjointSet


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
// };

// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         int numberOfComponents = 0;

//         DisjointSet* ds = new DisjointSet(n);

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(isConnected[i][j] == 1 && i != j){
//                     ds->unionBySize(i, j);
//                 }
//             }
//         }

//         for(int i = 0; i < n; i++){
//             if(ds->findUParent(i) == i){
//                 numberOfComponents++;
//             }
//         }

//         return numberOfComponents;
//     }
// };