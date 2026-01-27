/* 
BFS stands for Breadth First Search is a vertex based technique for finding a shortest path in graph. 
It uses a Queue data structure which follows first in first out.
In BFS, one vertex is selected at a time when it is visited and marked then its adjacent are visited 
and stored in the queue. It is slower than DFS. 

Ex- 
.        A
.       / \
.      B   C
.     /   / \
.    D   E   F

Output is: 
A, B, C, D, E, F 
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
1
2
3
4
5
6
7 
*/

/* TC will be O(N+E) and SC will be O(N+E) + O(N) + O(N)
N time is taken for visiting N nodes, and E is for traveling through adjacent nodes overall. 
Space for adj list, vis array and queue */

#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int n,m;                            //no. of nodes    no. of edges
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

    queue<int> q;                    //In GFG it is there
    q.push(1);                      //If nodes start from 0 then we do  q.push(0)
    vis[1] = true;                 //If nodes start from 0 then we do   vis[0] = true

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<endl;

        // vector<int> :: iterator it;
        // for (it = adj[node].begin(); it != adj[node].end(); it++)
        // {
        //     if(!vis[*it]){
        //         vis[*it] = 1;
        //         q.push(*it);
        //     }
        // }

        for (auto it : adj[node])
        {
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }


    }
    
    
    return 0;
}



/* If our graph has multiple components then always run a for loop which runs a bfs algorithm for every node */

/* Here Graph has 2 components */

/*         1 - 2           4 - 6
.              | \  
.              |   3
.              |   |
.              7 - 5
.
*/

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 2;
// bool vis[N];
// vector<int> adj[N];
// int main()
// {
//     for (int i = 0; i < N; i++)
//     {
//         vis[i] = 0;
//     }

//     int n, m;
//     cin >> n >> m;

//     int x, y;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }

//     for (int i = 1; i <= n; i++)            //If 0 is included in the nodes then we loop from  (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//         {
//             queue<int> q;
//             q.push(i);                    
//             vis[i] = true;              

//             while (!q.empty())
//             {
//                 int node = q.front();
//                 q.pop();
//                 cout << node << endl;

//                 vector<int>::iterator it;
//                 for (it = adj[node].begin(); it != adj[node].end(); it++)
//                 {
//                     if (!vis[*it])
//                     {
//                         vis[*it] = 1;
//                         q.push(*it);
//                     }
//                 }
//             }
//         }
//     }



//     return 0;
// }



/* GFG Submission       (BFS of graph)    */


/* Problem Statement: Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list. */


/* Solution: */
// Time Complexity: O(N + E)
// Space Complexity: O(N) + O(N)


// class Solution {
//   public:
//     vector<int> bfs(vector<vector<int>> &adj) {
//         int n = adj.size();
//         vector<int> ans;
//         vector<bool> vis(n+1, false);
//         queue<int> q;
        
//         q.push(0);
//         vis[0] = true;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             ans.push_back(node);
            
//             // vector<int> :: iterator it;
//             // for(it = adj[node].begin(); it != adj[node].end(); it++){
//             //     if(!vis[*it]){
//             //         vis[*it] = true;
//             //         q.push(*it);
//             //     }
//             // }
            
//             for(auto it : adj[node]){
//                 if(!vis[it]){
//                     vis[it] = true;
//                     q.push(it);
//                 }
//             }
//         }
        
//         return ans;
//     }
// };