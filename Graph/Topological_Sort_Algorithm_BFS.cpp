/* 
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
such that for every directed edge u v, vertex u comes before v in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a DAG.

Topological Sort
A Topological Ordering is an ordering of the nodes in a directed graph where for each 
directed edge from node A to node B, node A appears before node B in the ordering.

Note: Topological ordering are NOT unique. 


Not Every Graph has a Topological Sort!

Directed Cyclic Graph cannot have a Topological Sort.
Only Directed Acyclic Graph (DAG) have a valid Topological Sort.

Indegree
The number of inward directed edges on vertex in a directed
graph.

Indegree of A :-

.               A                          A                          B
.              / \                       / | \                       / \
.             B   C                     B  C  D                     A   C
.           Indegree = 2               Indegree = 3                Indegree = 0


Algorithm
While(All the nodes are not visited)
  Nodes with zero indegree can be added to the output
  array.
  All the nodes which are adjacent to terminal nodes, gets
  their indegree subtracted.
*/


/* 
There are 2 methods for finding Topological Sort :-
1) Using BFS (also known as Kahn's Algorithm)
2) Using DFS
*/



// Method-2   Using BFS  
/* 
INPUT
6 6
5 2
5 0
4 0
4 1
2 3
3 1

OUTPUT
5 4 2 3 1 0     

OR

4 5 2 0 3 1  (This is also correct as Topological ordering are NOT unique)
*/



/* GFG  Submission    (Topological Sort) */


/* Problem Statement: Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false. */



/* Solution: Using BFS (Kahn's Algorithm) 
Step 1: Calculate the indegree of each vertex in the graph and push all vertices with indegree 0 into a queue.
Step 2: Take the front element of the queue and add it to the topological order. For each of its adjacent vertices, reduce their indegree by 1. If any adjacent vertex's indegree becomes 0, push it into the queue.
Step 3: Repeat step 2 until the queue is empty.
*/

// Time Complexity: O(N + E) 
// Space Complexity: O(N) + O(N)                  // indegree[], queue    


// class Solution {
//   public:
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         vector<int> indegree(V, 0);
//         vector<int> adj[V];
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             adj[u].push_back(v);
//             indegree[v]++;
//         }
        
//         queue<int> q;
//         for(int i = 0; i < V; i++){
//             if(indegree[i] == 0){
//                 q.push(i);
//             }
//         }
        
//         vector<int> ans;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             ans.push_back(node);
            
//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it] == 0){
//                     q.push(it);
//                 }
//             }
//         }
        
//         return ans;
//     }
// };



/////////////////////////////////////////////////////////////////////////////////////////////////



// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n,m;
//     cin>>n>>m;

//     vector<vector<int>> adj(n);
//     vector<int> indeg(n);

//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         // u --> v
//         adj[u].push_back(v);
//         indeg[v]++;
//     }

//     queue<int> q;
//     for (int i = 0; i < n; i++)
//     {
//         if(indeg[i] == 0){
//             q.push(i);
//         }
//     }

//     while (!q.empty())
//     {
//         int x = q.front();
//         q.pop();
//         cout<<x<<" ";
//         // x --> v
//         for(auto it : adj[x]){
//             indeg[it]--;
//             if(indeg[it] == 0){
//                 q.push(it);
//             }
//         }
//     }   

    

//     return 0;
// }