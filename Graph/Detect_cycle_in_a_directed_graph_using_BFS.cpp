/* GFG  Submission    (Directed Graph Cycle) */

/* Problem Statement: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

Note: The graph can have multiple component. */



/* Solution: Using BFS 
If a graph has a cycle then its Topological sort is not possible
If no. of nodes is equal to n then there is Topological sort and hence cycle is not present
If we are not able to produce Topological sort of size n (no. of nodes) then cycle is present */


// Time Complexity: O(N + E) 
// Space Complexity: O(N) + O(N)                  // indegree[], queue     


// class Solution {
//   public:
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         vector<int> indegree(V, 0);
//         vector<int> adj[V];
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             adj[u].push_back(v);
//             indegree[v]++;
//         }
        
//         queue<int> q;
//         for(int i = 0; i < V; i++){
//             if(indegree[i] == 0){
//                 q.push(i);
//             }
//         }
        
//         int cnt = 0;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             cnt++;
            
//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it] == 0){
//                     q.push(it);
//                 }
//             }
//         }
        
//         // If count of nodes in topological sort is equal to number of nodes in graph then there is no cycle as topological sort is possible for DAG (Directed Acyclic Graph)
//         if(cnt == V){
//             return false;
//         }
        
//         // If count of nodes in topological sort is not equal to number of nodes in graph then there is cycle as topological sort is not possible for cyclic graph
//         return true;
//     }
// };

