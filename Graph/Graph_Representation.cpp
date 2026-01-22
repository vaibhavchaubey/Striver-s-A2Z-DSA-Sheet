/* The following two are the most commonly used representations of a graph. 
1. Adjacency Matrix 
2. Adjacency List 
*/


/*
Adjacency Matrix: 
Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. 
Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j. 
Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent weighted graphs. 
If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w. 

Pros: Representation is easier to implement and follow. Removing an edge takes O(1) time. Queries like whether there 
is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done O(1).
Cons: Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges), it consumes the same space.
Adding a vertex is O(V^2) time. 
*/

/* If there is 1-based indexing and no. of nodes n = 5 then we create n+1 size 2D vector */

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

OUTPUT
Adjacency matrix of above graph is gien by:
0 1 1 0 0 0 0
1 0 0 1 1 1 1
1 0 0 0 0 0 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 1 1 0 0 0 0
*/


// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;                //no. of nodes    no. of edges
//     cin>>n>>m;

//     vector<vector<int>> adjm(n+1,vector<int>(n+1,0));                     //Space Complexity: O(N^2)

//     for (int i = 0; i < m; i++)
//     {
//         int x,y;
//         cin>>x>>y;

//         adjm[x][y] = 1;
//         adjm[y][x] = 1;
//     }
    
//     cout<<"Adjacency matrix of above graph is gien by: "<<endl;

//     for (int i = 1; i < n+1; i++)                //If 0 is included in the nodes then we loop from  (int i = 0; i < n; i++)
//     {
//         for (int j = 1; j < n+1; j++)           //If 0 is included in the nodes then we loop from  (int j = 0; j < n; j++)
//         {
//             cout<<adjm[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     if(adjm[3][7] == 1){
//         cout<<"There is a edge between 3 and 7"<<endl;
//     }
//     else{
//         cout<<"No edge"<<endl;
//     }



//     return 0;
// }





/* Adjacency List: 
An array of lists is used. The size of the array is equal to the number of vertices. 
Let the array be an array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. 
This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs.  */

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

OTPUT
Adjacency of above graph is given by: 
1->2 3
2->1 4 5 6 7
3->1 7
4->2
5->2
6->2
7->2 3 
*/

/* If there is 1-based indexing and no. of nodes n = 5 then we create n+1 size vector of array */

/* IMP NOTE :-

In case of Undirected Graph we do

For Adjacency List 
adj[x].push_back(y);
adj[y].push_back(x);


In case of Directed Graph we do

For Adjacency List 
adj[x].push_back(y);  

In case of Weighted Graph

    int n,m;
    cin>>n>>m;
                                                                 
    vector<pair<int,int> adj[n+1];                          
    for (int i = 0; i < m; i++)                              
    {
        int x,y,wt;
        cin>>x>>y>>wt;

        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
                                                                 
    vector<int> adj[n+1];                                       //Space Complexity: O(N + 2E)
    for (int i = 0; i < m; i++)                                // E - no. of edges
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"Adjacency of above graph is given by: "<<endl;

    for (int i = 1; i < n+1; i++)         //If 0 is included in the nodes then we loop from  (int i = 0; i < n; i++)
    {
        cout<<i<<"->";
        for(auto x : adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
      



    return 0;
}