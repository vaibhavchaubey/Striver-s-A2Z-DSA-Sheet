/* GFG  Submission    (Undirected Graph Cycle) */

/* Problem Statement: Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component. */



/* Solution: Using BFS 
Any adjacent node other that parent node if visited then the graph has cycle. We can use a queue to perform BFS and keep track of the parent node for each visited node. If we encounter an adjacent node that is already visited and is not the parent of the current node, then we have found a cycle in the graph. */


// Time Complexity: O(N + 2E) + O(N) 
/* Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time. */

// Space Complexity: O(N) + O(N) ~ O(N)       // queue, vis[]       


// class Solution {
//   public:
//     bool bfs(int src, vector<int> adj[], vector<bool> &vis){
//         queue<pair<int, int>> q;        // node, parent
//         q.push({src, -1});
//         vis[src] = true;
        
//         while(!q.empty()){
//             auto [node, parent] = q.front();
//             q.pop();
            
//             for(auto it : adj[node]){
//                 if(!vis[it]){
//                     vis[it] = true;
//                     q.push({it, node});
//                 }
//                 // Any adjacent node other that parent node if visited then the graph has cycle
//                 else if(it != parent){
//                     return true;
//                 }
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
//             if(!vis[i] && bfs(i, adj, vis)){
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };