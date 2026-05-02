/* Leetcode Submission    (1192. Critical Connections in a Network) */

/* Problem Statement: There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order. */




/* Solution: Using Tarjan's Algorithm
Tarjan's Algorithm is used to find all the bridges in a graph. A bridge is an edge whose removal increases the number of connected components in the graph. */

// Time Complexity: O(N + 2E)                       
// Space Complexity: O(N + 2E) + O(N) + O(N) + O(N)                // adj[], tin[], low[], vis[] 



// class Solution {
// public:    
//     void dfs(int node, int parent, vector<bool> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<vector<int>> &ans)
//     {
//         // when we visite node first time, tin and low of the node are equal to the time
//         vis[node] = true;
//         tin[node] = low[node] = timer++;
        
//         for(auto it : adj[node]){
//             if(it == parent){ 
//                 continue;             // to avoid backtracking
//             }
            
//             // if node is not visited, call the dfs function
//             if(!vis[it]){
//                 dfs(it, node, vis, tin, low, timer, adj, ans);
//                 // when we return, low of the node is equal to the minimum of low of its child and low of itself
//                 low[node] = min(low[node], low[it]);
                
//                 // when we get low of child is greater than tin of the node
//                 // it means there is only path to cover child that's why {node, it} will be our critical connections or bridge 
//                 if(low[it] > tin[node]){
//                     ans.push_back({node, it});
//                 }
//             }
//             // if node is already visited and tin of the child is less than the low of itself
//             // we assign tin of the child to the low of the node
//             else{
//                 low[node] = min(low[node], tin[it]);
//             }
//         }
//     }
//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
//         vector<int> adj[n];
//         for(auto it : connections){
//             int u = it[0];
//             int v = it[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
//         // tin - time of insertion at the node
//         // low - lowest time of insertion at the node
//         // vis - mark visited node 
//         vector<int> tin(n, -1);
//         vector<int> low(n, -1);
//         vector<bool> vis(n, 0);
//         vector<vector<int>> ans;
//         int timer = 0;
        
//         dfs(0, -1, vis, tin, low, timer, adj, ans);
        
//         return ans;
//     }
// };





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* Bridges in Graph :-
Those edges are called bridge in a graph on whose removable the graph is broken into 2 or more number of components */


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
// void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]){
//     vis[node] = 1;
//     tin[node] = low[node] = timer++;
//     for(auto it : adj[node]){
//         if(it == parent){
//             continue;
//         }
//         if(!vis[it]){
//             dfs(it,node,vis,tin,low,timer,adj);
//             low[node] = min(low[node], low[it]);
//             if(low[it] > tin[node]){
//                 cout<<node<<" "<<it<<endl;
//             }
//         }
//         else{
//             low[node] = min(low[node],tin[it]);
//         }
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
//     int timer = 0;
//     for (int i = 1; i <= n; i++)       // If 0 is included in the nodes then we loop from  (int i = 0; i < n; i++)
//     {
//         if(!vis[i]){
//             dfs(i,-1,vis,tin,low,timer,adj);
//         }
//     }



//     return 0;
// }



