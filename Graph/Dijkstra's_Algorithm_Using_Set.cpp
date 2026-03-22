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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* 
Both implementations of Dijkstra's Algorithm run in O(E log V) time, but the priority queue uses lazy updates, while the set maintains only optimal entries via decrease-key simulation. 

Priority Queue version
    Faster in practice (less overhead)
    May store duplicate entries
Set version
    Cleaner logic (true decrease-key)
    Slightly slower due to tree operations


Priority Queue is faster
set → Red-Black Tree (slower constants)
priority_queue → Binary Heap (cache-friendly, faster)


“Why priority queue over set?”

“Both implementations of Dijkstra's Algorithm have O(E log N) complexity, but I prefer the priority queue approach because it is faster in practice due to heap-based implementation, simpler to code, and widely used in industry. The set-based approach simulates decrease-key but has higher constant factors.”


“C++ priority_queue doesn’t support decrease-key, so we use lazy updates and skip outdated entries.”

C++ priority_queue does NOT support updating an existing element
So what do we do? (Lazy Update)

Instead of updating, we insert again:
pq.push({5, A});   // new better distance

Now PQ contains:
{10, A}   ❌ old (wrong)
{5, A}    ✅ new (correct)
*/


/* Solution: Using Dijkstra's Algorithm with Set 

// Time Complexity: O((N + E) * log N)  =>  O(N * logN + E * logN)  =>  O(E * logN)    (since usually E >> N)
/* N time is taken for visiting N nodes, and E is for traveling through adjacent nodes overall and log N for priority_queue */

// Space Complexity: O(N) + O(N) + O(N + E)                // set, dist[], adj[]



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
        
//         // Always stores shortest distance at the top
//         set<pair<int, int>> st;       // dist, node   
//         vector<int> dist(V, INT_MAX);
        
//         dist[src] = 0;
//         st.insert({0, src});          // dist, node 
        
//         while(!st.empty()){
//             auto it = *(st.begin());
//             int dis = it.first;
//             int node = it.second;
//             st.erase(it);
            
//             for(auto it : adj[node]){
//                 int v = it.first;
//                 int wt = it.second;
                
//                 if(dist[node] + wt < dist[v]){
//                     // If the distance is already present in set then remove it
//                     if(dist[v] != INT_MAX){
//                         st.erase({dist[v], v});
//                     }
                    
//                     dist[v] = dist[node] + wt;
//                     st.insert({dist[v], v});
//                 }
//             }
//         }
        
//         return dist;
//     }
// };
