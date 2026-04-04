/* GFG Submission    (Bellman-Ford) */

/* Problem Statement: Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed. */



/* Bellman Ford algorithm helps us find the shortest path from a vertex to all other vertices of a weighted graph. 
It is similar to Dijkstra's algorithm but it can work with graphs in which edges can have negative weights.

The bellman ford algorithm does not produce a correct answer if the sum of the edges of a cycle is negative (Negative Cycle).

A Negative Cycle is one in which the overall sum of the cycle becomes negative. 

-> Detect Negative Cycle
-> Find the shortest path from a vertex to all other vertices of a weighted graph. Works with negative weights as well. 
-> Only work for directed graph. For undirected graph, we can convert it into directed graph by replacing each undirected edge with two directed edges in opposite directions. */



/* Solution: Using Bellman-Ford Algorithm

// Time Complexity: O(N * E)   
/* N-1 time is taken for relaxation, and we are doing it on the no. of edges i.e. E time  */

// Space Complexity: O(N)                // dist[]



// class Solution {
//   public:
//     vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
//         vector<int> dist(V, 1e8);
//         dist[src] = 0;
        
//         // N-1 relaxations
//         for(int i = 0; i < V - 1; i++){
//             for(auto it : edges){
//                 int u = it[0];
//                 int v = it[1];
//                 int wt = it[2];
                
//                 if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
//                     dist[v] = dist[u] + wt;
//                 }
//             }
//         }
        
//         // Nth relaxation to check negative cycle
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
            
//             // If we can still relax any edge, then there is a negative cycle in the graph
//             if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
//                 return {-1};
//             }
//         } 
        
//         return dist;
//     }
// };
