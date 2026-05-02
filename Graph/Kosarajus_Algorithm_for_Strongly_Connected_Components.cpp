/* GFG Submission    (Count Strongly Connected) */

/* Problem Statement: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph. */




/* Solution: Using Kosaraju's Algorithm
The idea behind KosaRaju’s algorithm is to do a DFS in a controlled fashion such that we won’t be able to go from one SCC to other. One DFS call would visit all the nodes in an SCC only. 
We sort nodes by finishing time so that when we process nodes in reverse order on the transposed graph, we always start DFS from the “leader” of an SCC. This guarantees that each DFS traversal visits exactly one strongly connected component without crossing into others */


// Time Complexity: O(N + E)                       
/* since each node and edge is visited at most twice (once in the original graph, once in the transposed graph) */

// Space Complexity: O(N + E) + O(N) + O(N)                  // adj[], vis[], stack 



// class Solution {
//     void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st){
//         vis[node] = true;
        
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 dfs(it, adj, vis, st);
//             }
//         }
        
//         // push the node to stack who's dfs call is completed
//         st.push(node);
//     }
//     void revDfs(int node, vector<int> transpose[], vector<bool> &vis){
//         vis[node] = true;
        
//         for(auto it : transpose[node]){
//             if(!vis[it]){
//                 revDfs(it, transpose, vis);
//             }
//         }
//     }
//   public:
//     int kosaraju(int V, vector<vector<int>> &edges) {
//         vector<int> adj[V];
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
            
//             adj[u].push_back(v);
//         }
        
//         // Step 1: Sort all nodes according to their TopoSort (in increasing order of finishing time)
//         // O(N + E)  
//         stack<int> st;
//         vector<bool> vis(V, false);
//         for(int i = 0; i < V; i++){
//             if(!vis[i]){
//                 dfs(i, adj, vis, st);
//             }
//         }
        
//         // Step 2: Transpose the graph (reverse all edges)
//         // O(N + E)  
//         vector<int> transpose[V];
//         for(int i = 0; i < V; i++){
//             vis[i] = false;
//             for(auto it : adj[i]){
//                 transpose[it].push_back(i);
//             }
//         }
        
//         // Step 3: DFS according to finishing time
//         // O(N + E)  
//         int count = 0;
//         while(!st.empty()){
//             int node = st.top();
//             st.pop();
//             if(!vis[node]){
//                 revDfs(node, transpose, vis);
//                 count++;
//             }
//         }
        
//         return count;
//     }
// };




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






/* Strongly Connected Components (SCC)
A strongly connected component is the portion of a directed graph in which there is a path from each vertex to another vertex. 
It is applicable only on a directed graph.

Strongly Connected Components is a component in which if we start from any node we can reach every other node in that component*/



/* 
Explanation: The idea behind SCC is that if we start from any node in a component, we must be able to reach all other nodes 
in that component. Note that by components here, we mean that we group certain nodes in the graph that meet the condition 
for every node in that component. The marked components in the following graph are from an SCC.


Solution: Using Kosaraju's Algorithm
The idea behind KosaRaju’s algorithm is to do a DFS in a controlled fashion such that we won’t be able to go from one SCC to other. One DFS call would visit all the nodes in an SCC only. 
We sort nodes by finishing time so that when we process nodes in reverse order on the transposed graph, we always start DFS from the “leader” of an SCC. This guarantees that each DFS traversal visits exactly one strongly connected component without crossing into others 


Approach :

1) Sort all the nodes according to their topo sort(loosely based topo sort as we may have cycles here)
2) Transpose the graph i.e reverse all the edges of the graph
3) Use the topo sort or the increasing order of finishing time to find the strongly connected components using DFS.
 */


/* 
INPUT
5 5
1 2
2 3
2 4
3 1
4 5

OUTPUT
SCC: 1 3 2 
SCC: 4
SCC: 5
*/


/* TC will be O(N + E) + DFS + TopoSort ~= O(N+E)  and  SC will be O(N+E) + O(N) + O(N)
N time is taken for visiting N nodes, and E is for traveling through adjacent nodes overall
Space for transpose list, vis array and stack */


// #include<bits/stdc++.h>
// using namespace std;
// void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st){
//     vis[node] = true;
    
//     for(auto it : adj[node]){
//         if(!vis[it]){
//             dfs(it, adj, vis, st);
//         }
//     }
    
//     // push the node to stack who's dfs call is completed
//     st.push(node);
// }

// void revDfs(int node, vector<int> transpose[], vector<bool> &vis){
//     vis[node] = true;
//     for(auto it : transpose[node]){
//         if(!vis[it]){
//             revDfs(it, transpose, vis);
//         }
//     }
// }

// void revDfsSCC(int node, vector<int> transpose[], vector<bool> &vis, vector<int> &component){
//     vis[node] = true;
//     component.push_back(node);

//     for(auto it : transpose[node]){
//         if(!vis[it]){
//             revDfsSCC(it, transpose, vis, component);
//         }
//     }
// }

// int kosaraju(int V, vector<vector<int>> &edges) {
//     vector<int> adj[V];
//     for(auto it : edges){
//         int u = it[0];
//         int v = it[1];
        
//         adj[u].push_back(v);
//     }
    
//     // Step 1: Sort all nodes according to their TopoSort (in increasing order of finishing time)
//     stack<int> st;
//     vector<bool> vis(V, false);
//     for(int i = 0; i < V; i++){
//         if(!vis[i]){
//             dfs(i, adj, vis, st);
//         }
//     }
    
//     // Step 2: Transpose the graph (reverse all edges)
//     vector<int> transpose[V];
//     for(int i = 0; i < V; i++){
//         vis[i] = false;
//         for(auto it : adj[i]){
//             transpose[it].push_back(i);
//         }
//     }
    
//     // Step 3: DFS according to finishing time
//     int count = 0;
//     while(!st.empty()){
//         int node = st.top();
//         st.pop();
//         if(!vis[node]){
//             revDfs(node, transpose, vis);
//             count++;
//         }
//     }
    
//     return count;
// }
// vector<vector<int>> kosarajuPrintSCC(int V, vector<vector<int>> &edges) {
//     vector<int> adj[V];
//     for(auto it : edges){
//         int u = it[0];
//         int v = it[1];
        
//         adj[u].push_back(v);
//     }
    
//     // Step 1: Sort all nodes according to their TopoSort (in increasing order of finishing time)
//     stack<int> st;
//     vector<bool> vis(V, false);
//     for(int i = 0; i < V; i++){
//         if(!vis[i]){
//             dfs(i, adj, vis, st);
//         }
//     }
    
//     // Step 2: Transpose the graph (reverse all edges)
//     vector<int> transpose[V];
//     for(int i = 0; i < V; i++){
//         vis[i] = false;
//         for(auto it : adj[i]){
//             transpose[it].push_back(i);
//         }
//     }
    
//     // Step 3: DFS according to finishing time
//     vector<vector<int>> ans;
//     while(!st.empty()){
//         int node = st.top();
//         st.pop();
//         if(!vis[node]){
//             vector<int> component;
//             revDfsSCC(node, transpose, vis, component);
//             ans.push_back(component);
//         }
//     }
    
//     return ans;
// }
// int main()
// {
//     int n = 8;

//     vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 4}, {6, 7}};
    
//     int count = kosaraju(n, edges);
//     cout<<"Number of strongly connected components: "<<count<<endl;

//     vector<vector<int>> scc = kosarajuPrintSCC(n, edges);
//     cout<<"Strongly Connected Components are: "<<endl;
//     for(int i = 0; i < scc.size(); i++){
//         for(int j = 0; j < scc[i].size(); j++){
//             cout<<scc[i][j]<<" ";
//         }
//         cout<<endl;
//     }


// /*  
//     Number of strongly connected components: 4
//     Strongly Connected Components are: 
//     0 2 1 
//     3 
//     4 6 5 
//     7  
// */





//     return 0;
// }



