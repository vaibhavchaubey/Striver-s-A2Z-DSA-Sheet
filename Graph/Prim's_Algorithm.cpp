/* GFG Submission    (Minimum Spanning Tree) */

/* Problem Statement: Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is provided as a list of edges, where each edge is represented as [u, v, w], indicating an edge between vertex u and vertex v with edge weight w. */





/* Prim's Algorithm is a greedy algorithm that is used to find the minimum spanning tree from a graph. 
Prim's algorithm finds the subset of edges that includes every vertex of the graph such that the sum of 
the weights of the edges can be minimized.

Better for dense graphs

Prim's algorithm starts with the single node and explores all the adjacent nodes with all the connecting 
edges at every step. The edges with the minimal weights causing no cycles in the graph got selected. */

/* The steps to implement the prim's algorithm are given as follows -

1) First, we have to initialize an MST with the randomly chosen vertex.
2) Now, we have to find all the edges that connect the tree in the above step with the new vertices. 
From the edges found, select the minimum edge and add it to the tree.
3) Repeat step 2 until the minimum spanning tree is formed.


The applications of prim's algorithm are -

1) Prim's algorithm can be used in network designing.
2) It can be used to make network cycles.
3) It can also be used to lay down electrical wiring cables. */





/* Solution: Using Prim's Algorithm 
The intuition of this algorithm is the greedy technique used for every node. If we carefully observe, for every node, we are greedily selecting its unvisited adjacent node with the minimum edge weight(as the priority queue here is a min-heap and the topmost element is the node with the minimum edge weight). Doing so for every node, we can get the sum of all the edge weights of the minimum spanning tree and the spanning tree itself(if we wish to) as well. */


// Time Complexity: O(E * logE) + O(E * logE)  ~  O(E * logE)
/* where E = no. of given edges. The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take logE time. This will result in the first O(E*logE) time complexity. Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, we need a logE time complexity. So this will result in the second O(E*logE).  */

// Space Complexity: O(E) + O(V)             // priority_queue, vis[]
/* where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most. */




// class Solution {
//   public:
//     int spanningTree(int V, vector<vector<int>>& edges) {
//         vector<pair<int, int>> adj[V];
        
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
            
//             adj[u].push_back({v, wt});
//             adj[v].push_back({u, wt});
//         }
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;          // {wt, node}
//         // Start with vertex 0
//         pq.push({0, 0});
        
//         vector<bool> vis(V, false);
        
//         int sum = 0;
//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
            
//             int wt = it.first;
//             int node = it.second;
            
//             if(!vis[node]){
//                 vis[node] = true;
//                 sum += wt;
                
//                 for(auto it : adj[node]){
//                     int v = it.first;
//                     int w = it.second;
                    
//                     if(!vis[v]){
//                         pq.push({w, v});
//                     }
//                 }
//             }
//         }
        
//         return sum;
//     }
// };










/* If we need to print the MST then we also need to store the parent of each vertex in PQ */


// class Solution {
//   public:
//     int spanningTree(int V, vector<vector<int>>& edges) {
//         vector<pair<int, int>> adj[V];
        
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
            
//             adj[u].push_back({v, wt});
//             adj[v].push_back({u, wt});
//         }
        
//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;          // {wt, node, parent}
//         pq.push({0, {0, -1}});
        
//         vector<bool> vis(V, false);
//         vector<pair<int, int>> mst;
        
//         int sum = 0;
//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
            
//             int wt = it.first;
//             int node = it.second.first;
//             int parent = it.second.second;
            
//             if(!vis[node]){
//                 vis[node] = true;
//                 sum += wt;
//                 if(parent != -1){
//                     mst.push_back({node, parent});
//                 }
                
//                 for(auto it : adj[node]){
//                     int v = it.first;
//                     int w = it.second;
                    
//                     if(!vis[v]){
//                         pq.push({w, {v, node}});
//                     }
//                 }
                
//             }
            
//         }
        
//         for(auto it : mst){
//             cout<<it.first<<"-"<<it.second<<endl;
//         }
        
//         return sum;
//     }
// };