/* Leetcode  Submission    (210. Course Schedule II) */

/* Problem Statement: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array. */



/* Solution: Using BFS */
// Time Complexity: O(N + E) 
// Space Complexity: O(N) + O(N)                  // indegree[], queue     


// class Solution {
// public:
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         vector<int> indegree(V, 0);
//         vector<int> adj[V];

//         // pre_course -> course
//         for(auto it : edges){
//             int u = it[0];              // course   
//             int v = it[1];              // pre_course
//             adj[v].push_back(u);
//             indegree[u]++;
//         }
        
//         queue<int> q;
//         for(int i = 0; i < V; i++){
//             if(indegree[i] == 0){
//                 q.push(i);
//             }
//         }
        
//         vector<int> order;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             order.push_back(node);
            
//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it] == 0){
//                     q.push(it);
//                 }
//             }
//         }

//         // Return order if valid topological ordering, else empty
//         if(order.size() == V){
//             return order;
//         }
        
//         return {};
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         return topoSort(numCourses, prerequisites);
//     }
// };