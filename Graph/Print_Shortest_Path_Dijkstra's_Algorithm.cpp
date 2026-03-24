/* GFG  Submission    (Shortest Path in an Undirected Graph) */

/* Problem Statement: You are given a weighted undirected graph with n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between vertex 1 and vertex n. Each edge is given as {a, b, w}, denoting an edge between vertices a and b with weight w.

If a path exists, return a list of integers where the first element is the total weight of the shortest path, and the remaining elements are the nodes along that path (from 1 to n). If no path exists, return a list containing only {-1}.

Note: The driver code will internally verify your returned list.

If both the path and its total weight are valid, only the total weight will be displayed as output.
If your list contains only -1, the output will be -1.
If the returned list is invalid, the output will be -2. */




/* Solution: Using Dijkstra's Algorithm with Priority Queue  

// Time Complexity: O((N + E) * log N)  =>  O(N * logN + E * logN)  =>  O(E * logN)    (since usually E >> N)
/* N time is taken for visiting N nodes, and E is for traveling through adjacent nodes overall and log N for priority_queue */

// Space Complexity: O(N) + O(N) + O(N) + O(N + E)                // priority_queue, dist[], parent[], adj[]



// class Solution {
//   public:
//     vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
//         int src = 1, dest = n;
//         vector<pair<int, int>> adj[n+1];      // u, v, wt
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
            
//             adj[u].push_back({v, wt});
//             adj[v].push_back({u, wt});
//         }
        
//         // Always stores shortest distance at the top (min_heap)
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;       // dist, node   
//         vector<int> dist(n+1, INT_MAX);
        
//         vector<int> parent(n+1);
//         for(int i = 1; i <= n; i++) {
//             parent[i] = i;
//         }
        
//         dist[src] = 0;
//         pq.push({0, src});            // dist, node 
        
//         while(!pq.empty()){
//             int dis = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();
            
//             // If the distance is greater than the already found shortest distance, skip processing this node as it won't lead to a shorter path to any of its neighbors. This is an optimization to avoid unnecessary processing of nodes that have already been found with a shorter path.
//             if(dis > dist[node]){
//                 continue;
//             }
            
//             for(auto it : adj[node]){
//                 int v = it.first;
//                 int wt = it.second;
                
//                 if(dist[node] + wt < dist[v]){
//                     dist[v] = dist[node] + wt;
//                     pq.push({dist[v], v});
//                     parent[v] = node;
//                 }
//             }
//         }
        
//         // If no path exists, return a list containing only {-1}
//         if(dist[dest] == INT_MAX){
//             return {-1};
//         }
        
//         vector<int> ans;
//         int node = dest;
//         ans.push_back(node);
//         while(parent[node] != node){
//             ans.push_back(node);
//             node = parent[node];
//         }
//         ans.push_back(src);
        
//         // Reverse the path to get the correct order from source to destination
//         reverse(ans.begin(), ans.end());
//         // Insert the shortest distance at the beginning 
//         ans.insert(ans.begin(), dist[n]);
        
//         return ans;
//     }
// };