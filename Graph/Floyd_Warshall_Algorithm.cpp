/* GFG Submission    (Floyd Warshall) */

/* Problem Statement: You are given a weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
The graph may contain negative edge weights, but it does not contain any negative weight cycles.

Your task is to find the shortest distance between every pair of nodes i and j in the graph.

Note: Modify the distances for every pair in place. */




/* Floyd-Warshall Algorithm is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph. 
This algorithm works for both the directed and undirected weighted graphs. But, it does not work for the graphs with negative cycles 
(where the sum of the edges in a cycle is negative). 

How to detect negative cycle using Floyd Warshall Algorithm?
If the distance of any vertex from itself becomes negative, then there is a negative cycle in the graph.

dist[i][i] < 0  → Negative Cycle exists in the graph. */



/* Floyd Warshall Algorithm 
We initialize the solution matrix same as the input graph matrix as a first step. 
Then we update the solution matrix by considering all vertices as an intermediate vertex. 
The idea is to one by one pick all vertices and updates all shortest paths which include 
the picked vertex as an intermediate vertex in the shortest path. When we pick vertex 
number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} 
as intermediate vertices. For every pair (i, j) of the source and destination vertices respectively, 
there are two possible cases. 
1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is. 
2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j] */




/* Solution: Using Floyd-Warshall Algorithm */
// Time Complexity: O(N^3)   
// Space Complexity: O(N^2)                // dist[]



// class Solution {
//   public:
//     void floydWarshall(vector<vector<int>> &dist) {
//         int n = dist.size();
        
//         for(int k = 0; k < n; k++){
//             // Pick all vertices as source one by one
//             for(int i = 0; i < n; i++){
//                 // Pick all vertices as destination for the above picked source
//                 for(int j = 0; j < n; j++){ 
//                     // shortest path from i to j 
//                     if(dist[i][k] != 1e8 && dist[k][j] != 1e8){
//                         dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                     }
//                 }
//             }
//         }
//     }
// };




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* 
INPUT
0 3 INF 6 
5 0 2 INF
3 INF 0 1
2 INF INF 0

OUTPUT
0 3 5 6 
5 0 2 3
3 6 0 1
2 5 7 0
*/


/* TC will be O(N^3)  and  SC will be O(N^2)
As there are 3 loops so N^3 
Space for dist 2d array */


// #include<bits/stdc++.h>
// using namespace std;
// const int INF = 1e9;
// int main()
// {
//     vector<vector<int>> adjm = {{0,3,INF,7},
//                                 {8,0,2,INF},  
//                                 {5,INF,0,1},  
//                                 {2,INF,INF,0} 
//                               };


//     int n = adjm.size();
//     vector<vector<int>> dist = adjm;
//     for (int k = 0; k < n; k++){             //For every vertex
//         for (int i = 0; i < n; i++){
//             for (int j = 0; j < n; j++){
//                 if(dist[i][k] + dist[k][j] < dist[i][j]){
//                     dist[i][j] = dist[i][k] + dist[k][j];
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             if(dist[i][j] == INF){
//                 cout<<"INF ";
//             }
//             else{
//                 cout<<dist[i][j]<<" ";
//             }
//         }
//         cout<<endl;
//     }
    
    

//     return 0;
// }