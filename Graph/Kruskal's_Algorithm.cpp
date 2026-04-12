/* GFG Submission    (Minimum Spanning Tree - Kruskal's Algorithm) */

/* Problem Statement: Given a weighted, undirected, and connected graph with V vertices and E edges, the task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph using Kruskal's Algorithm. The graph is represented as an edge list edges[][], where edges[i] = [u, v, w] denotes an undirected edge between u and v with weight w. */





/* Kruskal's Algorithm is used to find the minimum spanning tree for a connected weighted graph. 
The main target of the algorithm is to find the subset of edges by using which we can traverse every 
vertex of the graph. It follows the greedy approach that finds an optimum solution at every stage instead 
of focusing on a global optimum. 

Better for sparse graphs */

/* The steps to implement Kruskal's algorithm are listed as follows -

1) First, sort all the edges from low weight to high.
2) Now, take the edge with the lowest weight and add it to the spanning tree. 
If the edge to be added creates a cycle, then reject the edge.
3) Continue to add the edges until we reach all vertices, and a minimum spanning tree is created.


The applications of Kruskal's algorithm are -

1) Kruskal's algorithm can be used to layout electrical wiring among cities.
2) It can be used to lay down LAN connections. */




/* Solution: Using Kruskal's Algorithm 
The intuition of this algorithm is the greedy technique used for every edge. If we carefully observe, for every edge, we are greedily adding it to the spanning tree if it does not create a cycle. Doing so for every edge, we can get the sum of all the edge weights of the minimum spanning tree and the spanning tree itself(if we wish to) as well. */


// Time Complexity: O(E log E) + O(E * 4 * α)  ~  O(E log E)
/* where E = no. of given edges. The first O(E log E) is for sorting the edges based on their weights. Now, we are doing union-find operations for at most E edges and each union or find operation takes O(α) time, where α is the Inverse Ackermann function which grows very slowly and is almost constant for all practical purposes. So this will result in O(E * 4 * α) time complexity.  */

// Space Complexity: O(E) + O(V)             // adj[], DisjointSet
/* where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the adjacency list and O(V) due to the Disjoint Set data structure. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most. */



// class DisjointSet{
//     vector<int> rank, parent, size;
//     public:
//     DisjointSet(int n){
//         rank.resize(n + 1);
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for(int i = 0; i <= n; i++){
//             parent[i] = i;                          // Initially, each node is its own parent (representative of its own set)
//             rank[i] = 0;                            // Rank is initialized to 0 for all nodes
//             size[i] = 1;                           // Size is initialized to 1 for all nodes (each node is a set of size 1)
//         }
//     }

//     int findUParent(int node){
//         if(node == parent[node]){
//             return node;
//         }

//         return parent[node] = findUParent(parent[node]);            // Path Compression
//     }

//     void unionByRank(int u, int v){
//         int parent_u = findUParent(u);
//         int parent_v = findUParent(v);

//         if(parent_u == parent_v){
//             return;
//         }

//         if(rank[parent_u] < rank[parent_v]){
//             parent[parent_u] = parent_v;                        // took parent of u and attached it to v
//         }
//         else if(rank[parent_v] < rank[parent_u]){
//             parent[parent_v] = parent_u;                       // took parent of v and attached it to u
//         }
//         else{
//             parent[parent_v] = parent_u;
//             rank[parent_u]++;                                    // when rank of two nodes are equal then we increase the rank of node to whom we attach
//         }
//     }

//     void unionBySize(int u, int v){
//         int parent_u = findUParent(u);
//         int parent_v = findUParent(v);

//         if(parent_u == parent_v){
//             return;
//         }

//         if(size[parent_u] < size[parent_v]){
//             parent[parent_u] = parent_v;
//             size[parent_v] += size[parent_u];
//         }
//         else{                                                    // size[parent_v] < size[parent_u]
//             parent[parent_v] = parent_u;
//             size[parent_u] += size[parent_v];
//         }
//     }

//     bool isConnected(int u, int v){
//         return findUParent(u) == findUParent(v);
//     }

// };
// class Solution {
//   public:
//     int kruskalsMST(int V, vector<vector<int>> &edges) {
//         vector<pair<int, pair<int, int>>> adj;               // {wt, u, v}
        
//         // O(N + E)
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
            
//             adj.push_back({wt, {u, v}});
//         }

//         // O(E log E)
//         sort(adj.begin(), adj.end());               // sort all edges w.r.t wt
        
//         DisjointSet* ds = new DisjointSet(V);
        
//         int sum = 0;

//         // O(E * 4 * α)
//         for(auto it : adj){
//             int wt = it.first;
//             int u = it.second.first;
//             int v = it.second.second;
            
//             if(!ds->isConnected(u, v)){
//                 sum += wt;
//                 ds->unionBySize(u, v);
//             }
            
//         }
        
//         return sum;
//     }
// };







/* If we need to print the MST */


/* 
INPUT
5 6
0 1 2
0 3 6
1 2 3
1 4 5
1 3 8
2 4 7

OUTPUT
Cost: 16
0 - 1
1 - 2
1 - 4
0 - 3
*/


/* 
Here Nodes Start with 1 so we take size as N+1
INPUT
6 9
1 4 1                 
1 2 2
2 3 3
2 4 3
1 5 4
3 4 5
2 6 7
3 6 8
4 5 9

OUTPUT
Cost: 17
1 - 4
1 - 2
2 - 3
1 - 5
2 - 6
*/

/* TC will be O(E logE)+O(E*4*α) ~= O(E logE) (or O(E log N)) and SC will be O(M) + O(N) + O(N)
E logE for sorting and E*4*α for findParent operation ‘E’ times
Space for edges, Parent array and Rank Array */



// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     int u;
//     int v;
//     int wt;
//     node(int first, int second, int third){
//         u = first;
//         v = second;
//         wt = third;
//     }
// };


// bool comp(node a, node b){
//     return a.wt < b.wt;
// }

// int findParent(int node, vector<int> &parent){
//     if(node == parent[node]){
//         return node;
//     }
//     return parent[node] = findParent(parent[node],parent);
// }

// void union_sets(int u, int v, vector<int> &parent, vector<int> &rank){
//     u = findParent(u,parent);
//     v = findParent(v,parent);

//     if(rank[u] < rank[v]){
//         parent[u] = v;
//     }
//     else if(rank[v] < rank[u]){
//         parent[v] = u;
//     }
//     else{
//         parent[v] = u;
//         rank[u]++;
//     }
// }

// int main()
// {
//     int N,m;
//     cin>>N>>m;
//     vector<node> edges;
//     for (int i = 0; i < m; i++)
//     {
//         int u,v,wt;
//         cin>>u>>v>>wt;
//         edges.push_back(node(u,v,wt));
//     }
//     sort(edges.begin(), edges.end(), comp);

//     vector<int> parent(N);                 //If Nodes Start with 1 then we take size as N+1
//     for (int i = 0; i < N; i++)
//     {
//         parent[i] = i;
//     }
//     vector<int> rank(N,0);               //If Nodes Start with 1 then we take size as N+1

//     int cost = 0;
//     vector<pair<int,int>> mst;
//     for(auto it : edges){
//         if(findParent(it.v,parent) != findParent(it.u,parent)){
//             cost += it.wt;
//             mst.push_back({it.u,it.v});
//             union_sets(it.u,it.v,parent,rank);
//         }
//     }
//     cout<<"Cost: "<<cost<<endl;
//     for(auto it : mst){
//         cout<<it.first<<" - "<<it.second<<endl;
//     }


    
//     return 0;
// }