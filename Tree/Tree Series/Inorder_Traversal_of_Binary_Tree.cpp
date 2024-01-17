/* 
              1
            /   \
           2     3
          / \   / \
         4   5 6   7

Inorder (left,root,right)     Ex:- 4 2 5 1 6 3 7
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
void inorder(struct Node* root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);    
    cout<<root->data<<" ";
    inorder(root->right);
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

    cout<<endl<<"Inorder Traversal: ";
    inorder(root);


    return 0;
}


/* Leetcode Submission     (94. Binary Tree Inorder Traversal) */

/* Solution: Recursion */
// Time Complexity: O(N)
// Space Complexity: O(N)           // (recursion stack)


// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& nodes){
//         if(root == NULL){
//             return;
//         }

//         // Inorder => left, root, right
//         inorder(root->left, nodes);
//         nodes.push_back(root->val);
//         inorder(root->right, nodes);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         inorder(root, nodes);

//         return nodes;
//     }
// };