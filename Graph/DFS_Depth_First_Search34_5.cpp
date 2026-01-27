/* 
DFS stands for Depth First Search is a edge based technique. It uses the Stack data structure, performs two stages, 
first visited vertices are pushed into stack and second if there is no vertices then visited vertices are popped. 
Ex- 
 

        A
       / \
      B   C
     /   / \
    D   E   F

Output is: 
A, B, D, C, E, F 
*/

/* 
INPUT
7 7
1 2
1 3
2 4
2 5
2 6
2 7
7 3

Adjacency of above graph is given by: 
1->2 3
2->1 4 5 6 7
3->1 7
4->2
5->2
6->2
7->2 3 

OUTPUT
For Pre-order = 1 2 4 5 6 7 3         //In GFG it is used

For Post-order = 4 5 6 3 7 2 1
*/

/* TC will be O(N+E) and SC will be O(N+E) + O(N) + O(N)
N time is taken for visiting N nodes, and E is for traveling through adjacent nodes overall. 
Space for adj list, vis array and auxiliary space */

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], bool vis[]){
    //preorder
    vis[node] = 1;
    cout<<node<<" ";

    //inorder
    vector<int> :: iterator it;
    for(it = adj[node].begin(); it != adj[node].end(); it++){
        if(!vis[*it]){
            dfs(*it,adj,vis);
        }
    }

    //postorder
   // cout<<node<<" ";

}
int main()
{ 
    int n,m;                                //no. of nodes    no. of edges
    cin>>n>>m;

    bool vis[n+1];
    vector<int> adj[n+1];

    for (int i = 0; i < n+1; i++)                      //Time Complexity: O(N + E) ~ O(N)
    {                                                 //Space Complexity: O(N + E) + O(N) + O(N) ~ O(N)
        vis[i] = 0;
    }
    
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,adj,vis);                        //If nodes start from 0 then we do  dfs(0,adj,vis)
    
    
    return 0;
}



/* If our graph has multiple components then always run a for loop which runs a dfs algorithm for every node */

/* Here Graph has 2 components */

/*         1 - 2 - 4         3 - 5
.              |   | 
.              7 - 6
.
*/

// #include <bits/stdc++.h>
// using namespace std;

// void dfs(int node, vector<int> adj[], bool vis[])
// {
//     // preorder
//     vis[node] = 1;
//     cout << node << " ";

//     // inorder
//     vector<int>::iterator it;
//     for (it = adj[node].begin(); it != adj[node].end(); it++)
//     {
//         if (!vis[*it])
//         {
//             dfs(*it, adj, vis);
//         }
//     }

//     // postorder
//     // cout<<node<<" ";
// }
// int main()
// {
//     int n, m; // no. of nodes    no. of edges
//     cin >> n >> m;

//     bool vis[n + 1];
//     vector<int> adj[n + 1];

//     for (int i = 0; i < n + 1; i++) // Time Complexity: O(N + E) ~ O(N)
//     {                               // Space Complexity: O(N + E) + O(N) + O(N) ~ O(N)
//         vis[i] = 0;
//     }

//     int x, y;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }

//     for (int i = 1; i <= n; i++)                  // If 0 is included in the nodes then we loop from  (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//         {
//             dfs(i, adj, vis);
//         }
//     }

//     return 0;
// }




/* GFG Submission       (DFS of Graph)    */


/* Problem Statement: Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list. */


/* Solution: */
// Time Complexity: O(N + E)
// Space Complexity: O(N) + O(N)


// class Solution {
//   public:
//     void dfsHelper(int node, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& ans){
//         vis[node] = true;
//         ans.push_back(node);
        
//         // traverse all its neighbours
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 dfsHelper(it, vis, adj, ans);
//             }
//         }
//     }
//     vector<int> dfs(vector<vector<int>>& adj) {
//         int n = adj.size();
//         vector<int> ans;
//         vector<bool> vis(n+1, false);
        
//         dfsHelper(0, vis, adj, ans);
        
//         return ans;   
//     }
// };