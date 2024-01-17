/* Minimum time taken to BURN the Binary Tree from a Node/Leaf   */



/* GFG Submission        (Burning Tree)    */

/* Problem Statement: Given a binary tree and a node data called target. Find the minimum time required to burn the complete 
binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. 
That is its left child, right child, and parent.
Note: The tree contains unique values. */


//                 bfsToMapParent
//Time Complexity: O(N) + O(N) => O(N)
//                         findMaxDistance        
//Space Complexity: O(N)


// class Solution {
//   public:       
//     int findMaxDistance(map<Node*, Node*>& mp, Node* target){
//         queue<Node*> q;
//         q.push(target);
//         map<Node*, int> vis;
//         vis[target] = 1;
//         int max = 0;
//         while(!q.empty()){
//             int size = q.size();
//             int fl = 0;
//             for(int i = 0; i < size; i++){
//                 Node* node = q.front();
//                 q.pop();
                
//                 if(node->left && !vis[node->left]){
//                     fl = 1;
//                     vis[node->left] = 1;
//                     q.push(node->left);
//                 }
//                 if(node->right && !vis[node->right]){
//                     fl = 1;
//                     vis[node->right] = 1;
//                     q.push(node->right);
//                 }
//                 if(mp[node] && !vis[mp[node]]){
//                     fl = 1;
//                     vis[mp[node]] = 1;
//                     q.push(mp[node]);
//                 }
//             }
//             if(fl){
//                 max++;
//             }
//         }
        
//         return max;
//     }
//     Node* bfsToMapParent(Node* root, map<Node*, Node*>& mp, int target){
//         queue<Node*> q;
//         q.push(root);
//         Node* res;
//         while(!q.empty()){
//             Node* node = q.front();
//             q.pop();
//             if(node->data == target){
//                 res = node;
//             }
            
//             if(node->left){
//                 mp[node->left] = node;
//                 q.push(node->left);
//             }
//             if(node->right){
//                 mp[node->right] = node;
//                 q.push(node->right);
//             }
//         }
        
//         return res;
        
//     }
//     int minTime(Node* root, int target) 
//     {
//         map<Node*, Node*> mp;       // child, parent
//         Node* res = bfsToMapParent(root, mp, target);
//         int max = findMaxDistance(mp, res);
        
//         return max;
//     }
// };




/* Interviewbit Submission        (Burn a Tree)    */

/* Problem Statement: Given a binary tree denoted by root node A and a leaf node B from this tree.
It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.
You need to find the minimum time required to burn the complete binary tree. */


//                 bfsToMapParent
//Time Complexity: O(N) + O(N) => O(N)
//                         findMaxDistance        
//Space Complexity: O(N)


// int findMaxDistance(map<TreeNode*,TreeNode*> &m, TreeNode* target){
//     queue<TreeNode*> q;
//     q.push(target);
//     map<TreeNode*,int> vis;
//     vis[target] = 1;
//     int max = 0;
//     while(!q.empty()){
//         int size = q.size();
//         int fl = 0;
//         for(int i = 0; i < size; i++){
//             TreeNode* node = q.front();
//             q.pop();
//             if(node->left && !vis[node->left]){
//                 fl = 1;
//                 vis[node->left] = 1;
//                 q.push(node->left);
//             }
//             if(node->right && !vis[node->right]){
//                 fl = 1;
//                 vis[node->right] = 1;
//                 q.push(node->right);
//             }
//             if(m[node] && !vis[m[node]]){
//                 fl = 1;
//                 vis[m[node]] = 1;
//                 q.push(m[node]);
//             }
//         }
//         if(fl){
//             max++;
//         }
//     }
//     return max;
// }
// TreeNode* bfsToMapParent(TreeNode* root, map<TreeNode*,TreeNode*> &m, int B){
//     queue<TreeNode*> q;
//     q.push(root);
//     TreeNode* res;
//     while(!q.empty()){
//         TreeNode* node = q.front();
//         if(node->val == B){
//             res = node;
//         }
//         q.pop();
//         if(node->left){
//             m[node->left] = node;
//             q.push(node->left);
//         }
//         if(node->right){
//             m[node->right] = node;
//             q.push(node->right);
//         }
//     }
//     return res;
// }
// int Solution::solve(TreeNode* A, int B) {
//     map<TreeNode*,TreeNode*> m;
//     TreeNode* target = bfsToMapParent(A,m,B);
//     int max = findMaxDistance(m,target);

//     return max;
// }




#include<iostream>
#include<map>
#include<queue>                                                        //bfsToMapParent
using namespace std;                                //Time Complexity: O(N) + O(N) => O(N)
struct Node                                                                  //findMaxDistance        
{
    int data;                                      //Space Complexity: O(N)
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int findMaxDistance(map<Node*,Node*> &m, Node* target){
    queue<Node*> q;
    q.push(target);
    map<Node*,int> vis;
    vis[target] = 1;
    int max = 0;
    while(!q.empty()){
        int size = q.size();
        int fl = 0;
        for(int i = 0; i < size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]){
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if(m[node] && !vis[m[node]]){
                fl = 1;
                vis[m[node]] = 1;
                q.push(m[node]);
            }
        }
        if(fl){
            max++;
        }
    }
    return max;
}
Node* bfsToMapParent(Node* root, map<Node*,Node*> &m, int start){
    queue<Node*> q;
    q.push(root);
    Node* res;
    while(!q.empty()){
        Node* node = q.front();
        if(node->data == start){
            res = node;
        }
        q.pop();
        if(node->left){
            m[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            m[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int timeToBurnTree(Node* root, int start) {
    map<Node*,Node*> m;
    Node* target = bfsToMapParent(root,m,start);
    int max = findMaxDistance(m,target);

    return max;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

/* 
.               1
.              / \
.             2   3             ans = 3
.            /   / \
.           4   5   6
.            \
.             7
. */


    cout<<timeToBurnTree(root,2)<<endl;


    return 0;
}


