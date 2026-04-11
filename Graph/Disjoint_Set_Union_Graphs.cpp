/* Disjoint Set Union */




/* Union by Size/nodeRank :-
final time complexity will be O(α(n))
.                               ↓
.                             inverse Ackermann function
.                - O(1)
*/



// #include<bits/stdc++.h>
// using namespace std;

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

// int main()
// {

//     DisjointSet* ds = new DisjointSet(7);

//     ds->unionByRank(1, 2);
//     ds->unionByRank(2, 3);
//     ds->unionByRank(4, 5);
//     if(ds->isConnected(3, 4)){
//         cout<<"3 and 4 are connected"<<endl;
//     }
//     else{
//         cout<<"3 and 4 are not connected"<<endl;
//     }
//     ds->unionByRank(6, 7);
//     ds->unionByRank(5, 6);
//     ds->unionByRank(3, 7);

//     if(ds->isConnected(3, 4)){
//         cout<<"3 and 4 are connected"<<endl;
//     }
//     else{
//         cout<<"3 and 4 are not connected"<<endl;
//     }



//     DisjointSet* ds1 = new DisjointSet(7);

//     ds1->unionBySize(1, 2);
//     ds1->unionBySize(2, 3);
//     ds1->unionBySize(4, 5);
//     if(ds1->isConnected(3, 4)){
//         cout<<"3 and 4 are connected"<<endl;
//     }
//     else{
//         cout<<"3 and 4 are not connected"<<endl;
//     }
//     ds1->unionBySize(6, 7);
//     ds1->unionBySize(5, 6);
//     ds1->unionBySize(3, 7);

//     if(ds1->isConnected(3, 4)){
//         cout<<"3 and 4 are connected"<<endl;
//     }
//     else{
//         cout<<"3 and 4 are not connected"<<endl;
//     }




//     return 0;
// }




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* GFG Submission    (Union-Find) */

/* Problem Statement: This problem is to implement disjoint set union. There will be 2 incomplete functions namely union and find. You have to complete these functions. 

Union: Join two subsets into a single set.
isConnected: Determine which subset a particular element is in. This can be used for determining if two elements are in same subset. 

Your Task:

You have to complete the function union_() which merges the node1 and node2. You will also have to complete the function isConnected() which will return whether the two nodes are connected.

Note: Both function will contain two arrays par[] and ranks1[] along with two nodes. Initially par[i] = i and rank1[i] = 1 

Expected Time Complexity: O(N + Q).
Expected Auxiliary Space: O(1). */




/* Solution: Using Union-Find */
// Time Complexity: O(α(N)) */
// Space Complexity: O(N) */



// class Solution {
//   public:
//     int findUParent(int node, int parent[]){
//         if(node == parent[node]){
//             return node;
//         }

//         return parent[node] = findUParent(parent[node], parent);
//     }
//     // Function to merge two nodes a and b.
//     void union_(int a, int b, int par[], int rank1[]) {
//         int parent_a = findUParent(a, par);
//         int parent_b = findUParent(b, par);

//         if(parent_a == parent_b){
//             return;
//         }

//         if(rank1[parent_a] < rank1[parent_b]){
//             par[parent_a] = parent_b;
//         }
//         else if(rank1[parent_b] < rank1[parent_a]){
//             par[parent_b] = parent_a;
//         }
//         else{
//             par[parent_b] = parent_a;
//             rank1[parent_a]++;
//         }

//     }

//     // Function to check whether 2 nodes are connected or not.
//     bool isConnected(int x, int y, int par[], int rank1[]) {
        
//         return findUParent(x, par) == findUParent(y, par);
//     }
// };







/* GFG Submission    (Disjoint set (Union-Find)) */

/* Problem Statement: You are given n elements numbered from 1 to n . Initially, each element is in its own group.

You need to process k queries. Each query is one of the following types:

UNION x z – Merge the groups of x and z by making the ultimate representative of x to the ultimate representative of z. After merging, the ultimate representative of z becomes the ultimate representative of the whole group.

FIND x – Output the ultimate representative of the group containing element x. The representative is the element that acts as the "leader" of the group.

Note: The ultimate representative of an element is the root of its group, i.e., the element whose parent is itself. Initially, every element is the leader of its own group. */




/* Solution: Using Union-Find */
// Time Complexity: O(α(N)) */
// Space Complexity: O(N) */



// int find(int par[], int x) {
//     if(x == par[x]){
//         return x;
//     }

//     return par[x] = find(par, par[x]);
// }

// void unionSet(int par[], int x, int z) {
//     par[find(par, x)] = find(par, z);
// }








////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/* 
DISJOINT SET UNION
(UNION FIND)

SETS
S= { 1,2,3,4 }
P= { 4,5,6,9 }

Which SET element 6 belongs to?
Set-P
P= { 4,5,6,9 }

Leading Element/Parent :- Element which can be regarded as the leader element for that set.
S = { 1,2,3,4 }
Leader = 2
Parent[1] = Parent[2] = Parent[3] = Parent[4] = 2 = used to identify the set.



//1) Naive Implementation         Time Complexity: O(N)

void make(int v)
{
    parent[v] = v;
}
int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        parent[b] = a;
    }
}



//2) Optimization    Path Compression       Time Complexity: O(logN)
This simple optimisation reduces the time complexity
from O(n) to O(log n)

void make(int v)
{
    parent[v] = v;
}
int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        parent[b] = a;
    }
}



In the naive implementation, Union (a,b) b gets attached to a
long chains can be formed,which leads to O(n) complexity.

//3) Union by Size/nodeRank :-
final time complexity will be O(α(n))
.                               ↓
.                             inverse Ackermann function
.                - O(1)


Union by Size :-
Solve the problem of long chains.

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

  


  
CONCLUSION
Disjoint Set Union
in O(1) time complexity
and O(n) space complexity


Applications
1- MST
2- Connected components in agraph
3- Cycle detection and many more
*/


/* 
TC: O(4α) ~ O(4) 
SC: O(N) 
*/


// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5+6;
// vector<int> parent(N);
// vector<int> Rank(N);
// void makeset(int node){
//     parent[node] = node;
//     Rank[node] = 0;
// }

// int findParent(int node){
//     if(node == parent[node]){
//         return node;
//     }
//     return parent[node] = findParent(parent[node]);              //7 -> 6 -> 4 -> 3  then it will do   7 -> 3
// } 
// void union_sets(int u, int v){
//     u = findParent(u);
//     v = findParent(v);

//     if(Rank[u] < Rank[v]){
//         parent[u] = v;           //took u and attached it to v
//     }
//     else if(Rank[v] < Rank[u]){
//         parent[v] = u;           //took v and attached it to u
//     }
//     else{
//         parent[v] = u;
//         Rank[u]++;                //when rank of two nodes are equal then we increase the rank of node to whom we attach
//     }
// }
// int main()
// {
//     for (int i = 0; i < N; i++)
//     {
//         makeset(i);
//     }

//     union_sets(0, 2);
//     union_sets(4, 2);
//     union_sets(3, 1);
//     if (findParent(4) == findParent(0))
//         cout << "Yes\n";
//     else
//         cout << "No\n";
//     if (findParent(1) == findParent(0))
//         cout << "Yes\n";
//     else
//         cout << "No\n";

       
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int parent[100000];
// int nodeRank[100000];
// #define n 100
// void makeset(){
//     for (int i = 0; i <= n; i++)
//     {
//         parent[i] = i;
//         nodeRank[i] = 0;
//     }
// }

// int findParent(int node){
//     if(node == parent[node]){
//         return node;
//     }
//     return parent[node] = findParent(parent[node]);      //7 -> 6 -> 4 -> 3  then it will do   7 -> 3
// }

// void Union(int u, int v){
//     u = findParent(u);
//     v = findParent(v);

//     if(nodeRank[u] < nodeRank[v]){
//         parent[u] = v;    //took u and attached it to v
//     }
//     else if(nodeRank[v] < nodeRank[u]){
//         parent[v] = u;    //took v and attached it to u
//     }
//     else{
//         parent[v] = u;
//         nodeRank[u]++;
//     }
// }
// int main()
// {
//     makeset();

//     Union(0, 2);
//     Union(4, 2);
//     Union(3, 1);
//     if (findParent(4) == findParent(0))
//         cout << "Yes\n";
//     else
//         cout << "No\n";
//     if (findParent(1) == findParent(0))
//         cout << "Yes\n";
//     else
//         cout << "No\n";




//     // int m;
//     // cin>>m;
//     // while(m--){
//     //     int u,v;
//     //     Union(u,v);
//     // }



//     //if 2 and 3 belong to the same component or not
//     // if(findParent(2) != findParent(3)){
//     //     cout<<"Different Component"<<endl;
//     // }
//     // else{
//     //     cout<<"Same Component"<<endl;
//     // }


    
//     return 0;
// }