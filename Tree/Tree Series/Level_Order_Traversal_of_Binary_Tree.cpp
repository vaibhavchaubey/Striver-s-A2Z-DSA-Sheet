//Level Order Traversal

/* 
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
*/

// Time Complexity: O(N)
// Space Complexity: O(N) 

#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void printLevelOrder(Node* root){
    if (root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout<<node->data<<" ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //Level Order Traversal
    printLevelOrder(root);


    return 0;
}


/* Leetcode Submission    (102. Binary Tree Level Order Traversal)  */

/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(N) 


// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root == NULL){
//             return ans;
//         }

//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int len = q.size();
//             vector<int> level;
//             for(int i = 0; i < len; i++){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 level.push_back(node->val);

//                 if(node->left != NULL) q.push(node->left);
//                 if(node->right != NULL) q.push(node->right);
//             }
//             ans.push_back(level);
//         }

//         return ans;
//     }
// };

/* OR */

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         vector<int> level;
//         if(root == NULL){
//             return ans;
//         }

//         queue<TreeNode*> q;
//         q.push(root);
//         q.push(NULL);
//         while(!q.empty()){
//             TreeNode* node = q.front();
//             q.pop();
//             if(node){
//                 level.push_back(node->val);
//                 if(node->left != NULL){
//                     q.push(node->left);
//                 }
//                 if(node->right != NULL){
//                     q.push(node->right);
//                 }
//             }
//             else if(!q.empty()){
//                 q.push(NULL);
//                 ans.push_back(level);
//                 level.clear();
//             }
//         }
//         ans.push_back(level);    // This is done because in last step else if do not execute

//         return ans;
//     }
// };