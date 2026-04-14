/* LeetCode Submission    (1319. Number of Operations to Make Network Connected) */

/* Problem Statement: There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1. */




/* Solution: Using Disjoint Set Union (DSU) 
When ever Graph is building dynamically or dynamic connections are happening, we can think of using Disjoint Set Union (DSU) or Union-Find data structure. */

// Time Complexity: O((N + E) * α(N))                  we visit every node and edge once to find number of components.
// Space Complexity: O(N)                             // DisjointSet (parent[] and size[])


// class DisjointSet{
//     vector<int> parent, size;
//     public:
//     DisjointSet(int n){
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for(int i = 0; i <= n; i++){
//             parent[i] = i;                          // Initially, each node is its own parent (representative of its own set)
//             size[i] = 1;                           // Size is initialized to 1 for all nodes (each node is a set of size 1)
//         }
//     }

//     int findUParent(int node){
//         if(node == parent[node]){
//             return node;
//         }

//         return parent[node] = findUParent(parent[node]);            // Path Compression
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
// };
// class Solution {
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         // To connect n computers, we need at least n-1 cables. If the number of cables is less than n-1, it's impossible to connect all computers.
//         if(connections.size() < n - 1){
//             return -1;
//         }

//         int numberOfComponents = 0;

//         DisjointSet* ds = new DisjointSet(n);

//         for(auto it : connections){
//             int u = it[0];
//             int v = it[1];
//             ds->unionBySize(u, v);
//         }

//         for(int i = 0; i < n; i++){
//             if(ds->findUParent(i) == i){
//                 numberOfComponents++;
//             }
//         }

//         return numberOfComponents - 1;
//     }
// };



/* OR  (In this approach we can also get the extra edges if asked in the question)  */



/* Solution: Using Disjoint Set Union (DSU) 
Whenever Graph is building dynamically or dynamic connections are happening, we can think of using Disjoint Set Union (DSU) or Union-Find data structure. */

// Time Complexity: O((N + E) * α(N))                  we visit every node and edge once to find number of components.
// Space Complexity: O(N)                             // DisjointSet (parent[] and size[])



// class DisjointSet{
//     vector<int> parent, size;
//     public:
//     DisjointSet(int n){
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for(int i = 0; i <= n; i++){
//             parent[i] = i;                          // Initially, each node is its own parent (representative of its own set)
//             size[i] = 1;                           // Size is initialized to 1 for all nodes (each node is a set of size 1)
//         }
//     }

//     int findUParent(int node){
//         if(node == parent[node]){
//             return node;
//         }

//         return parent[node] = findUParent(parent[node]);            // Path Compression
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
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {

//         int numberOfComponents = 0;

//         DisjointSet* ds = new DisjointSet(n);

//         int extraEdges = 0;
//         for(auto it : connections){
//             int u = it[0];
//             int v = it[1];

//             if(!ds->isConnected(u, v)){
//                 ds->unionBySize(u, v);
//             }
//             // If u and v are already connected, then this edge is an extra edge that can be used to connect other components.
//             // We can also print this extra edge if asked in the question.
//             else{
//                 extraEdges++;
//             }

//         }

//         for(int i = 0; i < n; i++){
//             if(ds->findUParent(i) == i){
//                 numberOfComponents++;
//             }
//         }
        
//         int ans = numberOfComponents - 1;

//         // To connect all components, we need at least (numberOfComponents - 1) edges. If the number of extra edges is greater than or equal to (numberOfComponents - 1), then we can connect all components.
//         if(extraEdges >= ans){
//             return ans;
//         }

//         return -1;
//     }
// };