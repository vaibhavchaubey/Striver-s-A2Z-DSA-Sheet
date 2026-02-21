/* Leetcode  Submission    (802. Find Eventual Safe States) */

/* Problem Statement: There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order. */



/* Solution: Using DFS 
// We start a DFS call for each node. If the DFS completes without detecting a cycle, the node is safe. If a cycle is detected, the node is unsafe.

If a node is part of a cycle or leads to a cycle via an outgoing path, then that node cannot be considered safe. In simpler terms, a node is safe if it does not contribute to or connect into a cycle. */


// Time Complexity: O(N + E) + O(N) 
/* Where N = Nodes, E is for total edges. In the case of connected components of a graph, it will take another O(N) time. */

// Space Complexity: O(N) + O(N) + O(N)                  // vis[], pathVis[], recursion stack    


// class Solution {
// public: 
//     bool dfs(int node, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& pathVis){
//         vis[node] = true;
//         pathVis[node] = true;
        
//         for(auto it : graph[node]){
//             if(!vis[it]){
//                 if(dfs(it, graph, vis, pathVis)){
//                     return true;
//                 }
//             }
//             // Any adjacent node if visited and also part of current path then the graph has cycle
//             else if(pathVis[it]){
//                 return true;
//             }
//         }
        
//         // Backtracking step: Mark the current node as not part of the current path
//         pathVis[node] = false;
//         return false;
//     }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> ans;

//         vector<bool> vis(n, false);
//         vector<bool> pathVis(n, false);
//         for(int i = 0; i < n; i++){
//             if(!vis[i]){
//                 dfs(i, graph, vis, pathVis);
//             }
//         }

//         for(int i = 0; i < n; i++){
//             // It means that this node is not part of any cycle and also does not lead to any cycle, so it is a safe node
//             if(pathVis[i] == false){
//                 ans.push_back(i);
//             }
//         }
        
//         return ans;
//     }
// };