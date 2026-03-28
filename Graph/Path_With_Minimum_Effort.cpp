/* Leetcode Submission    (1631. Path With Minimum Effort) */

/* Problem Statement: You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell. */



/* Solution: Using Dijkstra's Algorithm with Priority Queue  

// Time Complexity: O(N * M * 4 * log(N * M))  =>  O(N * M * log(N * M))    (since we are visiting each cell at most once and for each cell we are checking its 4 neighbors and log(N * M) for priority_queue)
/* Time complexity of Dijkstra's algorithm is O(E log V) here, E = n * m * 4, V = n * m  */

// Space Complexity: O(N * M) + O(N * M)             // priority_queue, dist[]



// class Solution {
// public:
//     bool isSafe(int r, int c, vector<vector<int>>& heights){
//         int n = heights.size(), m = heights[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m);
//     }
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int n = heights.size(), m = heights[0].size();

//         vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
//         dist[0][0] = 0;

//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;    // {diff, {row, col}}
//         pq.push({0, {0, 0}});

//         vector<int> dirRow = {-1, 0, 1, 0};
//         vector<int> dirCol = {0, 1, 0, -1};

//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();

//             int diff = it.first;
//             int row = it.second.first;
//             int col = it.second.second;

//             // If we have reached the destination, we can return the effort immediately because we are using a priority queue and the first time we reach the destination, it will be with the minimum effort.
//             if(row == n - 1 && col == m - 1){
//                 return dist[n-1][m-1];
//             }

//             for(int i = 0; i < 4; i++){
//                 int r = row + dirRow[i];
//                 int c = col + dirCol[i];

//                 if(isSafe(r, c, heights)){
//                     // Calculate new effort as max of current effort and height difference
//                     int newEffort = max(abs(heights[row][col] - heights[r][c]), diff);
//                     if(newEffort < dist[r][c]){
//                         dist[r][c] = newEffort;
//                         pq.push({dist[r][c], {r, c}});
//                     }
//                 }
//             }
//         }
        
//         // unreachable
//         return 0;
//     }
// };



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* GFG Submission    (Path With Minimum Effort) */

/* Problem Statement: You are given a 2D array mat[][], of size n*m. Your task is to find the minimum possible path cost from the top-left cell (0, 0) to the bottom-right cell (n-1, m-1) by moving up, down, left, or right between adjacent cells.

Note: The cost of a path is defined as the maximum absolute difference between the values of any two consecutive cells along that path. */



/* Solution: Using Dijkstra's Algorithm with Priority Queue  

// Time Complexity: O(N * M * 4 * log(N * M))  =>  O(N * M * log(N * M))    (since we are visiting each cell at most once and for each cell we are checking its 4 neighbors and log(N * M) for priority_queue)
/* Time complexity of Dijkstra's algorithm is O(E log V) here, E = n * m * 4, V = n * m  */

// Space Complexity: O(N * M) + O(N * M)             // priority_queue, dist[]



// class Solution {
//   public:
//     bool isSafe(int r, int c, vector<vector<int>>& mat){
//         int n = mat.size(), m = mat[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m);
//     }
//     int minCostPath(vector<vector<int>>& mat) {
//         int n = mat.size(), m = mat[0].size();

//         vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
//         dist[0][0] = 0;

//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;    // {diff, {row, col}}
//         pq.push({0, {0, 0}});

//         vector<int> dirRow = {-1, 0, 1, 0};
//         vector<int> dirCol = {0, 1, 0, -1};

//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();

//             int diff = it.first;
//             int row = it.second.first;
//             int col = it.second.second;

//             // If we have reached the destination, we can return the effort immediately because we are using a priority queue and the first time we reach the destination, it will be with the minimum effort.
//             if(row == n - 1 && col == m - 1){
//                 return dist[n-1][m-1];
//             }

//             for(int i = 0; i < 4; i++){
//                 int r = row + dirRow[i];
//                 int c = col + dirCol[i];

//                 if(isSafe(r, c, mat)){
//                     // Calculate new effort as max of current effort and height difference
//                     int newEffort = max(abs(mat[row][col] - mat[r][c]), diff);
//                     if(newEffort < dist[r][c]){
//                         dist[r][c] = newEffort;
//                         pq.push({dist[r][c], {r, c}});
//                     }
//                 }
//             }
//         }
        
//         // unreachable
//         return 0;
//     }
// };
