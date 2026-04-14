/* LeetCode Submission    (721. Accounts Merge) */

/* Problem Statement: Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order. */




/* Solution: Using Disjoint Set Union (DSU) 
Whenever Graph is building dynamically or dynamic connections are happening, we can think of using Disjoint Set Union (DSU) or Union-Find data structure. Here we are merging emails and building a graph. Hence, we can think of using DSU */

// Time Complexity: O(E * α(n)) + O(E * α(n)) + O(E * logE)   ~    O(E * logE)
/* where N = no. of indices or nodes and E = no. of emails. */

// Space Complexity: O(E) + O(E) + O(N)    ~   O(N + E)          // mapMailNode, mergedMail, DisjointSet (parent[] and size[])


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
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         int n = accounts.size();
//         DisjointSet* ds = new DisjointSet(n);
        
//         // Maps email to their component index
//         unordered_map<string, int> mapMailNode;          // {email -> node(idx)}

//         // Step 1: Union accounts having common emails      O(E * α(n))
//         for(int i = 0; i < n; i++){
//             for(int j = 1; j < accounts[i].size(); j++){
//                 string email = accounts[i][j];

//                 // If we have seen this email before then union this group with the previous group of the email
//                 if(mapMailNode.count(email)){
//                     ds->unionBySize(i, mapMailNode[email]);
//                 }
//                 // If this is the first time seeing this email then assign component group as the account index
//                 else{
//                     mapMailNode[email] = i;
//                 }
//             }
//         }

//         // Step 2: Group emails under ultimate parent               O(E * α(n))
//         // Store list of emails corresponding to the ultimate parent
//         unordered_map<int, vector<string>> mergedMail;          // {node -> emails}
//         for(auto it : mapMailNode){
//             auto [email, idx] = it;
//             int node = ds->findUParent(idx);

//             mergedMail[node].push_back(email);
//         }

//         // Step 3: Prepare final merged result              O(E * logE)
//         // Sort the emails and add the account name
//         vector<vector<string>> ans;
//         for(auto it : mergedMail){
//             auto [idx, emails] = it;
//             // sort the emails
//             sort(emails.begin(), emails.end());

//             vector<string> account = {accounts[idx][0]};
//             // insert(position, start_iterator, end_iterator);
//             account.insert(account.end(), emails.begin(), emails.end());

//             ans.push_back(account);
//         }

//         return ans;        
//     }
// };