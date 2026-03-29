/* Leetcode Submission    (787. Cheapest Flights Within K Stops) */

/* Problem Statement: There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1. */



/* Solution: Using Dijkstra's Algorithm with Queue 

We are not strictly asked to find the absolute shortest path ignoring stops — we have a stops constraint.
Using Dijkstra’s algorithm with a priority queue always picks the currently cheapest distance to process next. But here, a cheaper path may exceed the allowed stops, so you can’t always commit to the first smallest distance.

BFS guarantees:
The first time we reach a node with a certain number of stops ≤ k, it’s the minimum cost for that stop count.
Using a queue level by level (stop by stop) allows us to respect the stop limit automatically. */


// Time Complexity: O(E)             
/* As for Dijkstra's algorithm, the time complexity is O(E log V) where E is the number of edges and V is the number of vertices. However, in this implementation, we are using a queue instead of a priority queue (so we can omit this log V), which means that we are not always processing the vertex with the smallest distance first. Therefore, in the worst case, we may end up processing all edges without any optimization, leading to a time complexity of O(E). */

// Space Complexity: O(N) + O(N) + O(N + E)                // queue, dist[], adj[]



// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<pair<int, int>> adj[n];
//         for(auto it : flights){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];

//             adj[u].push_back({v, wt});
//         }

//         queue<pair<int, pair<int, int>>> q;       // {stops, {node, dist}}  
//         q.push({0, {src, 0}});

//         vector<int> dist(n, INT_MAX);
//         dist[src] = 0;

//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();

//             int stops = it.first;
//             int node = it.second.first;
//             int cost = it.second.second;

//             // If the number of stops exceeds k, skip to the next iteration
//             if(stops > k){
//                 continue;
//             }

//             for(auto it : adj[node]){
//                 int v = it.first;
//                 int wt = it.second;

//                 // If the cost to reach the neighbor node v through the current node is less than the previously recorded cost and the number of stops is within the allowed limit, update the cost and push the neighbor node into the queue with an incremented stop count.
//                 if(cost + wt < dist[v] && stops <= k){
//                     dist[v] = cost + wt;
//                     q.push({stops + 1, {v, dist[v]}});

//                 }
//             }
//         }

//         // If destination node is unreachable, return -1
//         if(dist[dst] == INT_MAX){
//             return -1;
//         }

//         return dist[dst];
//     }
// };





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* GFG Submission    (Cheapest Flights Within K Stops) */

/* Problem Statement: There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Note: The price from city A to B may be different From the price from city B to A. */



/* Solution: Using Dijkstra's Algorithm with Queue  

// Time Complexity: O(E)             
/* As for Dijkstra's algorithm, the time complexity is O(E log V) where E is the number of edges and V is the number of vertices. However, in this implementation, we are using a queue instead of a priority queue (so we can omit this log V), which means that we are not always processing the vertex with the smallest distance first. Therefore, in the worst case, we may end up processing all edges without any optimization, leading to a time complexity of O(E). */

// Space Complexity: O(N) + O(N) + O(N + E)                // queue, dist[], adj[]



// class Solution {
//   public:
//     int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         vector<pair<int, int>> adj[n];
//         for(auto it : flights){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];

//             adj[u].push_back({v, wt});
//         }

//         queue<pair<int, pair<int, int>>> q;       // {stops, {node, dist}}  
//         q.push({0, {src, 0}});

//         vector<int> dist(n, INT_MAX);
//         dist[src] = 0;

//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();

//             int stops = it.first;
//             int node = it.second.first;
//             int cost = it.second.second;

//             // If the number of stops exceeds k, skip to the next iteration
//             if(stops > K){
//                 continue;
//             }

//             for(auto it : adj[node]){
//                 int v = it.first;
//                 int wt = it.second;
                
//                 // If the cost to reach the neighbor node v through the current node is less than the previously recorded cost and the number of stops is within the allowed limit, update the cost and push the neighbor node into the queue with an incremented stop count.
//                 if(cost + wt < dist[v] && stops <= K){
//                     dist[v] = cost + wt;
//                     q.push({stops + 1, {v, dist[v]}});

//                 }
//             }
//         }

//         // If destination node is unreachable, return -1
//         if(dist[dst] == INT_MAX){
//             return -1;
//         }

//         return dist[dst];
        
//     }
// };