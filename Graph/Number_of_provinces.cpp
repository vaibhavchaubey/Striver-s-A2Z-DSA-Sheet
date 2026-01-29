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
// Time Complexity: O(N + E)
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