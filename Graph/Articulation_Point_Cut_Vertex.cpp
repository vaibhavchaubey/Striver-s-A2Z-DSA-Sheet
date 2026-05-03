/* GFG Submission    (Articulation Point - I) */

/* Problem Statement: Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1. */




/* Solution: Using Tarjan's Algorithm
Tarjan's Algorithm is used to find all the articulation points in a graph. An articulation point is a vertex whose removal increases the number of connected components in the graph. */

// Time Complexity: O(N + 2E)                       
// Space Complexity: O(N) + O(N) + O(N) + O(N)                // tin[], low[], vis[], isArticulation[]


// class Solution {
//     void dfs(int node, int parent, vector<bool> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation){
//         // when we visite node first time, tin and low of the node are equal to the time
//         vis[node] = true;
//         tin[node] = low[node] = timer++;
//         int child = 0;
        
//         for(auto it : adj[node]){
//             if(it == parent){ 
//                 continue;             // to avoid backtracking
//             }
            
//             // if node is not visited, call the dfs function
//             if(!vis[it]){
//                 dfs(it, node, vis, tin, low, timer, adj, isArticulation);
//                 // when we return, low of the node is equal to the minimum of low of its child and low of itself
//                 low[node] = min(low[node], low[it]);
                
//                 // when we get low of child is greater than or equal to tin of the node
//                 // it means there is only path to cover child that's why node will be our articulation point
//                 if(low[it] >= tin[node] && parent != -1){
//                     isArticulation[node] = 1;
//                 }
//                 child++;
//             }
//             // if node is already visited and tin of the child is less than the low of itself
//             // we assign tin of the child to the low of the node
//             else{
//                 low[node] = min(low[node], tin[it]);
//             }
//         }
        
//         // If root node has more than one child
//         if(parent == -1 && child > 1){
//             isArticulation[node] = 1;
//         }
//     }
//   public:
//     vector<int> articulationPoints(int V, vector<int> adj[]) {
//        // tin - time of insertion at the node
//         // low - lowest time of insertion at the node
//         // vis - mark visited node 
//         vector<int> tin(V, -1);
//         vector<int> low(V, -1);
//         vector<bool> vis(V, 0);
//         vector<int> isArticulation(V, 0);
//         int timer = 0;
        
//         dfs(0, -1, vis, tin, low, timer, adj, isArticulation);
        
//         vector<int> ans;
//         for(int i = 0; i < V; i++){
//             if(isArticulation[i] == 1){
//                 ans.push_back(i);
//             }
//         }
        
//         if(ans.size() == 0){
//             return {-1};
//         }
        
//         return ans;
        
//     }
// };





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







/* Articulation Point :-
Those nodes are called Articulation Point in a graph on whose removable the graph is broken into 2 or more number of components */


/*                          Tarjans Algorithm                                    */

/* 
Here Nodes Start with 1 so we take size as N+1
INPUT
12 14
1 2
1 4
2 3
3 4
4 5
5 6
6 7
6 9
7 8
9 8
8 10
10 11
10 12
11 12

OUTPUT
8 10
5 6
4 5
*/

/* 
INPUT
4 4
0 1
1 2
2 0 
1 3

OUTPUT
1 3
*/

/* TC will be O(N + E) and SC will be O(N+E) + O(N) + O(N)
N time is taken for visiting N nodes, and E is for traveling through adjacent nodes overall
Space for adj list, tin array and low array */


// #include<bits/stdc++.h>
// using namespace std;
// void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int timer,vector<int> adj[], vector<int> &isArticulation){
//     vis[node] = 1;
//     tin[node] = low[node] = timer++;
//     int child = 0;
//     for(auto it : adj[node]){
//         if(it == parent){
//             continue;
//         }
//         if(!vis[it]){
//             dfs(it,node,vis,tin,low,timer,adj,isArticulation);
//             low[node] = min(low[node],low[it]);
//             if(low[it] >= tin[node] && parent != -1){
//                 isArticulation[node] = 1;
//             }
//             child++;
//         }
//         else{
//             low[node] = min(low[node],tin[it]);
//         }
//     }
//     if(parent == -1 && child > 1){
//         isArticulation[node] = 1;
//     }
// }
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<int> adj[n+1];
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     vector<int> tin(n+1,-1);
//     vector<int> low(n+1,-1); 
//     vector<int> vis(n+1,0);
//     vector<int> isArticulation(n+1,0);
//     int timer = 0;
//     for (int i = 1; i <= n; i++)       // If 0 is included in the nodes then we loop from  (int i = 0; i < n; i++)
//     {
//         if(!vis[i]){
//             dfs(i,-1,vis,tin,low,timer,adj,isArticulation);
//         }
//     }

//     for (int i = 1; i <= n; i++)       // If 0 is included in the nodes then we loop from  (int i = 0; i < n; i++)
//     {
//         if(isArticulation[i] == 1){
//             cout<<i<<endl;
//         }
//     }



    
//     return 0;
// }