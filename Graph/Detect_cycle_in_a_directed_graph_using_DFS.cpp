/* GFG  Submission    (Directed Graph Cycle) */

/* Problem Statement: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

Note: The graph can have multiple component. */



/* Solution: Using DFS 
Any adjacent node if visited and also part of current path then the graph has cycle. We can use recursion to perform DFS and keep track of the nodes in the current path using a separate boolean vector (pathVis). If we encounter an adjacent node that is already visited and is also part of the current path, then we have found a cycle in the graph. After exploring all adjacent nodes, we backtrack by marking the current node as not part of the current path (pathVis[node] = false). */

/* Whenever a recursion call for a function is over we take that value from pathVis 
because that dfs is over we make it unvisited again. 
When we have :-
vis[node] = true    pathVis[node] = true    then cycle is present */


// Time Complexity: O(N + E) + O(N) 
/* Where N = Nodes, E is for total edges. In the case of connected components of a graph, it will take another O(N) time. */

// Space Complexity: O(N) + O(N) + O(N)                  // vis[], pathVis[], recursion stack,      


// class Solution {
//   public:
//     bool dfs(int node, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis){
//         vis[node] = true;
//         pathVis[node] = true;
        
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 if(dfs(it, adj, vis, pathVis)){
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
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         vector<int> adj[V];
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             // since it's a directed graph, we only add edge from u to v
//             adj[u].push_back(v);
//         }
        
//         vector<bool> vis(V, false);
//         vector<bool> pathVis(V, false);
//         for(int i = 0; i < V; i++){
//             if(!vis[i] && dfs(i, adj, vis, pathVis)){
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };