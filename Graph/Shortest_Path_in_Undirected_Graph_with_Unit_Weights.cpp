/* GFG  Submission    (Shortest Path in Undirected Graph) */

/* Problem Statement: You are given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents an undirected edge between vertices u and v.

Your task is to find the shortest path distance from a given source vertex src to all other vertices in the graph.
If a vertex is not reachable from the source, return -1 for that vertex.


Note: All edges have unit weight (1). */



/* Solution: Using BFS 
The idea is to use BFS because it explores nodes level by level, and in a graph with unit weight edges, each level represents exactly 1 unit of distance.

All edges have unit weight, so there is no need for Dijkstra's algorithm.
BFS explores level-wise, meaning the earliest time you reach a node is always the shortest path.
No backtracking or priority queue is required, making the solution efficient. */


// Time Complexity: O(N + E)  
// Space Complexity: O(N) + O(N) + O(N + E)                // queue, dist[], adj[]


// class Solution {
//   public:
//     vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
//         vector<int> adj[V];
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
//         vector<int> dist(V, INT_MAX);
//         // Set the source node distance to 0
//         dist[src] = 0;
        
//         queue<int> q;
//         q.push(src);
        
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
            
//             for(auto it : adj[node]){
//                 // If a shorter path to neighbor is found
//                 if(dist[node] + 1 < dist[it]){
//                     dist[it] = dist[node] + 1;
//                     q.push(it);
//                 }
//             }
//         }
        
//         for(int i = 0; i < V; i++){
//             if(dist[i] == INT_MAX){
//                 dist[i] = -1;
//             }
//         }
        
//         return dist;
//     }
// };
