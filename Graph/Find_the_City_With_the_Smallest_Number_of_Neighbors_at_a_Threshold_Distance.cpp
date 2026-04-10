/* LeetCode Submission    (1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance) */

/* Problem Statement: There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path. */




/* Solution: Using Floyd-Warshall Algorithm 
Can also be solved using Dijkstra's Algorithm and Bellman-Ford Algorithm */

// Time Complexity: O(N^3)   
// Space Complexity: O(N^2)                // dist[]



// class Solution {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];

//             dist[u][v] = wt;            // Set the distance from city1 to city2
//             dist[v][u] = wt;            // Set the distance from city2 to city1
//         }

//         // Set the diagonal to 0, as the distance from a city to itself is 0
//         for (int i = 0; i < n; i++){
//             dist[i][i] = 0;
//         } 

//         for(int k = 0; k < n; k++){
//             // Pick all vertices as source one by one
//             for(int i = 0; i < n; i++){
//                 // Pick all vertices as destination for the above picked source
//                 for(int j = 0; j < n; j++){ 
//                     // shortest path from i to j 
//                     if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
//                         dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                     }
//                 }
//             }
//         }

//         // Initialize variables to track the city with the least reachable cities
//         int cntCity = n;
//         int cityNo = -1;

//         // Check each city and count the number of cities within the threshold distance
//         for (int city = 0; city < n; city++) {
//             int cnt = 0;
//             for (int adjCity = 0; adjCity < n; adjCity++) {
//                 // If the distance to the adjacent city is within the threshold, increment count
//                 if (dist[city][adjCity] <= distanceThreshold){
//                     cnt++;
//                 }
//             }

//             // Update the city with the least number of reachable cities
//             if (cnt <= cntCity) {
//                 cntCity = cnt;
//                 cityNo = city;
//             }
//         }

//         return cityNo;
//     }
// };







/* GFG Submission    (City With the Smallest Number of Neighbors at a Threshold Distance) */

/* Problem Statement: There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, our answer will be the city with the greatest label.

Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path. */




/* Solution: Using Floyd-Warshall Algorithm 
Can also be solved using Dijkstra's Algorithm and Bellman-Ford Algorithm */

// Time Complexity: O(N^3)   
// Space Complexity: O(N^2)                // dist[]



// class Solution {
//   public:
//     int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];

//             dist[u][v] = wt;            // Set the distance from city1 to city2
//             dist[v][u] = wt;            // Set the distance from city2 to city1
//         }

//         // Set the diagonal to 0, as the distance from a city to itself is 0
//         for (int i = 0; i < n; i++){
//             dist[i][i] = 0;
//         } 

//         for(int k = 0; k < n; k++){
//             // Pick all vertices as source one by one
//             for(int i = 0; i < n; i++){
//                 // Pick all vertices as destination for the above picked source
//                 for(int j = 0; j < n; j++){ 
//                     // shortest path from i to j 
//                     if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
//                         dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                     }
//                 }
//             }
//         }

//         // Initialize variables to track the city with the least reachable cities
//         int cntCity = n;
//         int cityNo = -1;

//         // Check each city and count the number of cities within the threshold distance
//         for (int city = 0; city < n; city++) {
//             int cnt = 0;
//             for (int adjCity = 0; adjCity < n; adjCity++) {
//                 // If the distance to the adjacent city is within the threshold, increment count
//                 if (dist[city][adjCity] <= distanceThreshold){
//                     cnt++;
//                 }
//             }

//             // Update the city with the least number of reachable cities
//             if (cnt <= cntCity) {
//                 cntCity = cnt;
//                 cityNo = city;
//             }
//         }

//         return cityNo;
        
//     }
// };