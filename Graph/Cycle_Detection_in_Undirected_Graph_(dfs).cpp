/* GFG  Submission    (Undirected Graph Cycle) */

/* Problem Statement: Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component. */



/* Solution: Using DFS */
// Time Complexity: O(N + 2E) + O(N) 
/* Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time. */

// Space Complexity: O(N) + O(N) ~ O(N)                   // recursion stack, vis[]      


// class Solution {
//   public:
//     bool dfs(int node, int parent, vector<int> adj[], vector<bool> &vis){
//         vis[node] = true;
        
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 if(dfs(it, node, adj, vis)){
//                     return true;
//                 }
//             }                
//             // Any adjacent node other that parent node if visited then the graph has cycle
//             else if(it != parent){
//                 return true;
//             }
//         }
        
//         return false;
//     }
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         vector<int> adj[V];
//         // Converting to adj list
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
//         vector<bool> vis(V, false);
//         for(int i = 0; i < V; i++){
//             if(!vis[i] && dfs(i, -1, adj, vis)){
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };