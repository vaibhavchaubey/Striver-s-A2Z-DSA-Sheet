/* Leetcode  Submission    (207. Course Schedule) */

/* Problem Statement: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false. */



/* Solution: Using BFS 
Where we see problem where something is before something that is where we should think of Topological Sort.
If Topological Sort is possible then there is no cycle and we can finish all courses 
If Topological Sort is not possible then there is cycle and we cannot finish all courses */

// Time Complexity: O(N + E) 
// Space Complexity: O(N) + O(N)                  // indegree[], queue     


// class Solution {
// public:
//     bool hasNoCycle(int V, vector<vector<int>> &edges) {
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
        
//         int cnt = 0;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             cnt++;
            
//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it] == 0){
//                     q.push(it);
//                 }
//             }
//         }
        
//         // If count of nodes in topological sort is equal to number of nodes in graph then there is no cycle as topological sort is possible for DAG (Directed Acyclic Graph)
//         if(cnt == V){
//             return true;
//         }
        
//         // If count of nodes in topological sort is not equal to number of nodes in graph then there is cycle as topological sort is not possible for cyclic graph
//         return false;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         // If Topological Sort is possible then there is no cycle and we can finish all courses 
//         return hasNoCycle(numCourses, prerequisites);
//     }
// };
