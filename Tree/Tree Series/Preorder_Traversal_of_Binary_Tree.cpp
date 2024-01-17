/* 
              1
            /   \
           2     3
          / \   / \
         4   5 6   7

Preorder (root,left,right)    Ex:- 1 2 4 5 3 6 7
*/

// Time Complexity: O(N)
// Space Complexity: O(N)     Recursion

#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(struct Node* root){
    if (root == NULL)
    {
        return;
    }    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"Preorder Traversal: ";
    preorder(root);
    


    return 0;
}


/* Leetcode Submission     (144. Binary Tree Preorder Traversal) */

/* Solution: Recursion */
// Time Complexity: O(N)
// Space Complexity: O(N)           // (recursion stack)


// class Solution {
// public:
//     void preorder(TreeNode* root, vector<int>& nodes){
//         if(root == NULL){
//             return;
//         }

//         // Preorder => root, left, right
//         nodes.push_back(root->val);
//         preorder(root->left, nodes);
//         preorder(root->right, nodes);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         preorder(root, nodes);

//         return nodes;
//     }
// };