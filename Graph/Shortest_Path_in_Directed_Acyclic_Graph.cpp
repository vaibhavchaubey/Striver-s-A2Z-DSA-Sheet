/* GFG  Submission    (Shortest path in Directed Acyclic Graph) */

/* Problem Statement: Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. */



/* Solution: Using DFS 
Intuition: As because to toposort we move sequentially from one node to another node and we are sure that we have already calculated the shortest path for the previous node before moving to the next node. Hence, we minimize the no. of steps (which is O(N + E)) better than other standard algorithms like Dijkstra's or Bellman-Ford which have time complexity of O((N + E) log N) and O(N * E) respectively.

Step 1: Perform a topological sort of the graph using DFS. This will give us an ordering of the vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Step 2:  Take the nodes out of stack & relax the edges. Initialize a distance array with infinity (or a very large number) for all vertices except the source vertex (0), which should be initialized to 0.
Step 3: Process the vertices in topological order. For each vertex, relax all its outgoing edges. If the distance to a vertex can be shortened by taking the edge from the current vertex, update the distance to that vertex.
Step 4: After processing all vertices, replace any distance that is still infinity with -1 to indicate that those vertices are unreachable from the source. */



// Time Complexity: O(N + E)  {for the topological sort} + O(N + E) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N + E) 

// Space Complexity: O(N) + O(N) + O(N) + O(N + 2E) ~ O(N + E)                 // stack, vis[], dist[], adj[]


// class Solution {
//   public:
//     void topoSort(int node, vector<pair<int, int>> adj[],  vector<bool> &vis, stack<int> &st){
//         vis[node] = true;
        
//         for(auto it : adj[node]){
//             int v = it.first; 
//             if(!vis[v]){
//                 topoSort(v, adj, vis, st);
//             }
//         }
        
//         // push the node to stack who's dfs call is completed
//         st.push(node);
//     }
//     vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
//         vector<pair<int, int>> adj[V];          // u, v, wt
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
//             adj[u].push_back({v, wt});
//         }
        
//         // Stack to store the topological order
//         stack<int> st;
//         vector<bool> vis(V, false);
//         for(int i = 0; i < V; i++){
//             if(!vis[i]){
//                 topoSort(i, adj, vis, st);
//             }
//         }
        
//         vector<int> dist(V, INT_MAX);
        
//         // Distance to the source node (0) is 0
//         dist[0] = 0;                    
//         while(!st.empty()){
//             int node = st.top();
//             st.pop();
            
//             // Relax all outgoing edges from the current node
//             if(dist[node] != INT_MAX){
//                 for(auto it : adj[node]){
//                     int v = it.first;
//                     int wt = it.second;
                    
//                     // Update distance if a shorter path is found
//                     if(dist[node] + wt < dist[v]){
//                         dist[v] = dist[node] + wt;
//                     }
//                 }
//             }
//         }
        
//         // Replace all unreachable nodes' distances with -1
//         for(int i = 0; i < V; i++){
//             if(dist[i] == INT_MAX){
//                 dist[i] = -1;
//             }
//         }
        
//         return dist;
//     }
// };