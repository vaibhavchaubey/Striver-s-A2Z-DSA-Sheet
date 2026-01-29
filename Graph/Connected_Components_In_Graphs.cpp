/* What is a Connected Component
A connected component is a subgraph in which any two vertices
are connected to each other by paths, and which is connected to
no additional vertices in the supergraph. */



/* Q. Find the no of connected components in a graph. */       //Here we only find no. of components
/* 
There are 2 methods for finding number of components in Graph:-
1) Using DFS
2) Using BFS
*/


//Method-1     Using DFS
/* 
INPUT
10 7
1 3
3 4
4 6
6 8
2 9
5 7
7 10

OUTPUT
Number of components: 3
*/



// #include<bits/stdc++.h>
// using namespace std;
// void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
//     vis[node] = 1;
//     for(auto it : adj[node]){
//         if(!vis[it]){
//             dfs(it,adj,vis);
//         }
//     }
// }
// int main()
// {
//     int n,m;
//     cin>>n>>m;

//     vector<vector<int>> adj(n+1);
//     vector<int> vis(n+1,0);
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int cnt = 0;
//     for (int i = 1; i <= n; i++)              //If 0 is included in the nodes then we loop from  (int i = 0; i < n; i++)
//     {
//         if(!vis[i]){                        
//             cnt++;
//             dfs(i,adj,vis);            
//         }
//     }

//     cout<<"Number of components: "<<cnt<<endl;


//     return 0;
// }






//Method-2     Using BFS
/* 
INPUT
10 7
1 3
3 4
4 6
6 8
2 9
5 7
7 10

OUTPUT
Number of components: 3
*/


// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cin>>n>>m;

//     vector<vector<int>> adj(n+1);
//     vector<int> vis(n+1,0);
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int cnt = 0;
//     for (int i = 1; i <= n; i++)            //If 0 is included in the nodes then we loop from  (int i = 0; i < n; i++)
//     {
//         if(!vis[i]){                        
//             cnt++;
//             queue<int> q;
//             q.push(i);
//             vis[i] = 1;

//             while (!q.empty())
//             {
//                 int node = q.front();
//                 q.pop();
//                 for(auto it : adj[node]){
//                     if(!vis[it]){
//                         vis[it] = 1;
//                         q.push(it);
//                     }
//                 }
//             }
//         }
//     }

//     cout<<"Number of components: "<<cnt<<endl;
    

//     return 0;
// }



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* QUESTION ON ABOVE PROBLEM */
/* 
Question
There are N friends numbered from 0 to N-1. You have to choose 2
person such that they are not related to each other.
You are given information in the form of M pairs (X,Y) i.e there is an
link between friend X and Y.
Find out the number of ways in which 2 persons from different
groups can be chosen. 

OR

Given an undirected graph with n nodes and m edges, find the number of ways to choose 
a pair of nodes such that the two nodes belong to different connected components.


Idea
1) Find the components and their sizes.
2) At i'th component, choose one person from it
and other person from the rest of the groups.
*/

//Method-1     Using DFS
/* 
INPUT
5 3                     0 - 1       2 - 3                       
0 1                     |
2 3                     4 
0 4

OUTPUT
Number of ways: 6
*/


/* Solution: Using DFS */
// Time Complexity: O(N + M)
// Space Complexity: O(N + M) + O(N)       // adj[], vis[]


// #include<bits/stdc++.h>
// using namespace std;

// // It counts how many nodes are connected to this node (including itself)
// int dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
//     int ans = 1;
//     vis[node] = 1;
//     for(auto it : adj[node]){
//         if(!vis[it]){
//             ans += dfs(it,adj,vis);
//         }
//     }
//     return ans;
// }
// int main()
// {
//     int n,m;
//     cin>>n>>m;

//     vector<vector<int>> adj(n+1);
//     vector<int> vis(n+1,0);
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     vector<int> components;
//     for (int i = 0; i < n; i++)         //(Here 0 is included so) so we loop from  (int i = 0; i < n; i++)
//     {
//         int cnt = 0;
//         if(!vis[i]){                        
//             cnt = dfs(i,adj,vis); 
//             components.push_back(cnt);           
//         }
//     }

//     long long ans = 0;
//     for(auto i : components){
//         ans += i*(n-i);
//     }

//     // Divide by 2 at the end because every pair gets counted twice.
//     cout<<"Number of ways: "<<(ans/2)<<endl;


//     return 0;
// }





