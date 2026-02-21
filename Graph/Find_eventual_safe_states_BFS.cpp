/* Leetcode  Submission    (802. Find Eventual Safe States) */

/* Problem Statement: There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order. */



/* Solution: Using BFS 
We can also solve this problem using BFS by reversing the graph and then performing a topological sort. We start by building a reverse graph where all edges are reversed. Then, we calculate the indegree of each node in the reverse graph. We enqueue all nodes with an indegree of zero (terminal nodes) and perform a BFS. For each node dequeued, we reduce the indegree of its adjacent nodes in the reverse graph. If any adjacent node's indegree becomes zero, we enqueue it as well. The nodes that are processed in this manner are the safe nodes, as they lead to terminal nodes without forming cycles.

The node which we get by performing topological sort will be the safe nodes as these nodes will not be part of any cycle or lead to any cycle. */


// Time Complexity: O(N + E) + O(N logN)  
// Space Complexity: O(N) + O(N) + O(N)                  // indegree[], queue, adj[]


// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> ans;
//         vector<int> adj[n];             // Reverse adjacency list
//         vector<int> indegree(n, 0);

//         // Build the reverse graph and calculate indegrees
//         for(int i = 0; i < n; i++){
//             for(auto it : graph[i]){
//                 adj[it].push_back(i);       // Reverse the direction of edges
//                 indegree[i]++;
//             }
//         }

//         queue<int> q;
//         for(int i = 0; i < n; i++){
//             if(indegree[i] == 0){
//                 q.push(i);
//             }
//         }

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             ans.push_back(node);            // This node is safe

//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it] == 0){
//                     q.push(it);
//                 }
//             }
//         }

//         sort(ans.begin(), ans.end());

//         return ans;
//     }
// };