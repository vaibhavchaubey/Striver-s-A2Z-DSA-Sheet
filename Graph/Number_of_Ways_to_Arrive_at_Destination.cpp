/* Leetcode Submission    (1976. Number of Ways to Arrive at Destination) */

/* Problem Statement: You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7. */



/* Solution: Using Dijkstra's Algorithm with Priority Queue

// Time Complexity: O((N + E) * log N)  =>  O(N * logN + E * logN)  =>  O(E * logN)    (since usually E >> N)
/* N time is taken for visiting N nodes, and E is for traveling through adjacent nodes overall and log N for priority_queue */

// Space Complexity: O(N) + O(N) + O(N) + O(N + E)                // priority_queue, dist[], pathCount[], adj[]



// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         const int MOD = 1e9 + 7;

//         vector<pair<int, int>> adj[n];      // u, v, wt
//         for(auto it : roads){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
            
//             adj[u].push_back({v, wt});
//             adj[v].push_back({u, wt});
//         }
        
//         // Always stores shortest distance at the top (min_heap)
//         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;       // {dist, node}   
//         pq.push({0, 0});            

//         // Store shortest time to each node
//         vector<long long> dist(n, LLONG_MAX);
//         dist[0] = 0;            // Distance to source is 0

//         // Number of ways to reach each node in shortest time
//         vector<int> pathCount(n, 0);
//         pathCount[0] = 1;      // 1 way to reach node 0
        
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
                
//                 // Found a new shortest path → Update shortest time and reset path count
//                 if(dist[node] + wt < dist[v]){
//                     dist[v] = dist[node] + wt;
//                     pathCount[v] = pathCount[node];
//                     pq.push({dist[v], v});
//                 }
//                 // Found another way with the same shortest time → Add to path count
//                 else if(dist[node] + wt == dist[v]){
//                     pathCount[v] = (pathCount[v] + pathCount[node]) % MOD;
//                 }
//             }
//         }
        
//         return pathCount[n - 1]; 
//     }
// };





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/* GFG Submission    (Number of Ways to Arrive at Destination) */

/* Problem Statement: You are given an undirected weighted graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where edges[i] = [ui, vi, timei] means that there is an undirected edge between nodes ui and vi that takes timei minutes to reach.
Your task is to return in how many ways you can travel from node 0 to node V - 1 in the shortest amount of time. */



/* Solution: Using Dijkstra's Algorithm with Priority Queue

// Time Complexity: O((N + E) * log N)  =>  O(N * logN + E * logN)  =>  O(E * logN)    (since usually E >> N)
/* N time is taken for visiting N nodes, and E is for traveling through adjacent nodes overall and log N for priority_queue */

// Space Complexity: O(N) + O(N) + O(N) + O(N + E)                // priority_queue, dist[], pathCount[], adj[]



// class Solution {
//   public:
//     int countPaths(int V, vector<vector<int>>& edges) {
//         const int MOD = 1e9 + 7;

//         vector<pair<int, int>> adj[V];      // u, v, wt
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
            
//             adj[u].push_back({v, wt});
//             adj[v].push_back({u, wt});
//         }
        
//         // Always stores shortest distance at the top (min_heap)
//         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;       // {dist, node}   
//         pq.push({0, 0});            

//         // Store shortest time to each node
//         vector<long long> dist(V, LLONG_MAX);
//         dist[0] = 0;            // Distance to source is 0

//         // Number of ways to reach each node in shortest time
//         vector<int> pathCount(V, 0);
//         pathCount[0] = 1;      // 1 way to reach node 0
        
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
                
//                 // Found a new shortest path → Update shortest time and reset path count
//                 if(dist[node] + wt < dist[v]){
//                     dist[v] = dist[node] + wt;
//                     pathCount[v] = pathCount[node];
//                     pq.push({dist[v], v});
//                 }
//                 // Found another way with the same shortest time → Add to path count
//                 else if(dist[node] + wt == dist[v]){
//                     pathCount[v] = (pathCount[v] + pathCount[node]) % MOD;
//                 }
//             }
//         }
        
//         return pathCount[V - 1]; 
//     }
// };