/* GFG  Submission    (Dijkstra Algorithm) */

/* Problem Statement: Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
It is guaranteed that all the shortest distance will fit in a 32-bit integer. */



/* Given a graph and a source vertex in the graph, find the shortest paths from the source to all vertices in the given graph. */


/* 
This algorithm is used to find the shortest path in Google Maps, in network routing protocols, in social networking applications, 
and also in many places.
For a given graph G Dijkstra’s algorithm is helpful to find the shortest path between a source node to a destination node.
For example, if we draw a graph in which nodes represent the cities and weighted edges represent the driving distances 
between pairs of cities connected by a direct road, then Dijkstra’s algorithm when applied gives the shortest route 
between one city and all other cities. 


Dijkstra's Algorithm Applications :-
1) To find the shortest path
2) In social networking applications
3) In a telephone network
4) To find the locations in the map 


Disadvantage of Dijkstra’s Algorithm :-
1) It follows the blind search, so wastes a lot of time to give the desired output.
2) It Negative edges value cannot be handled by it.
3) We need to keep track of vertices that have been visited.
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* IMPORTANT
QUES => WHY WE USE PRIORITY_QUEUE HERE
ANS => we can use Queue also to get the shortest path but also we have to update the shortest path values in array multiple times.  
But if we use PriorityQueue it will minimize of updation of the minimum path value in array. 
Thats why we are using priorityQueue here.

Dijkstras because of priority queue we save the time and avoid extra operations and thus its better.

Ques => why should we use priorty queue rather than queue, I implemented with queue also and got the same result
Ans => It will end up taking a lot more time, as you will not get the shorter distance at first instance, will have to do a lot of rounds.

Ex :-
1 2 10
2 3 15 
1 4 1
4 5 1 
3 6 10
5 6 1 

In this queue, you will necessary travel some nodes, you reach the node 6 twice, which will be avoided in case of PQ, 
so in larger cases, this becomes more costlier.


The fact is that even without a Priority Queue, the algorithm will work absolutely fine, Priority Queue is just an 
optimizing technique here, as it always returns the minimum distance, hence we would have already figured the minimum
distance of a node with least comparisons, greatly reducing the time complexity. Otherwise, if we were to use a normal Queue, 
we might find the shorter distance to a node in later checks. 
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* NOTE: In place of priorityqueue we can also use set (set<pair<int,itn>>) as in set we can get a 
deletion option => s.erase({dist[it.first],it.first});
if elemnts are 
1,4
5,5
2,2
4,3
7,5
0,1

Then by using set we can delete 7,5

We can use priorityquueue or set that's not make any difference
*/

/* 
INPUT
5 6
1 2 2
1 4 1
2 5 5
2 3 4
3 4 3
3 5 1
1

OUTPUT
The distance from source 1 are :
0 2 4 1 5 
*/



/* Solution: Using Dijkstra's Algorithm with Priority Queue  

/* Note that the above code uses Binary Heap for Priority Queue implementation. Time complexity can be reduced to 
O(E + VLogV) using Fibonacci Heap. The reason is, that Fibonacci Heap takes O(1) time for decrease-key operation 
while Binary Heap takes O(Logn) time. */


// Time Complexity: O((N + E) * log N)  =>  O(N * logN + E * logN)  =>  O(E * logN)    (since usually E >> N)
/* N time is taken for visiting N nodes, and E is for traveling through adjacent nodes overall and log N for priority_queue */

// Space Complexity: O(N) + O(N) + O(N + E)                // priority_queue, dist[], adj[]



// class Solution {
//   public:
//     vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
//         vector<pair<int, int>> adj[V];      // u, v, wt
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
            
//             adj[u].push_back({v, wt});
//             adj[v].push_back({u, wt});
//         }
        
//         // Always stores shortest distance at the top (min_heap)
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;       // dist, node   
//         vector<int> dist(V, INT_MAX);
        
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
//                 }
//             }
//         }
        
//         return dist;
//     }
// };