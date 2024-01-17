/* 
              1
            /   \
           2     3
          / \   / \
         4   5 6   7

Postorder (left,right,root)   Ex:- 4 5 2 6 7 3 1
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
void postorder(struct Node* root){
    if (root == NULL)
    {
        return;
    }    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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

    cout<<endl<<"Postorder Traversal: ";
    postorder(root);


    return 0;
}


/* Leetcode Submission     (145. Binary Tree Postorder Traversal) */

/* Solution: Recursion */
// Time Complexity: O(N)
// Space Complexity: O(N)           // (recursion stack)


// class Solution {
// public:
//     void postorder(TreeNode* root, vector<int>& nodes){
//         if(root == NULL){
//             return;
//         }

//         // Postorder => left, right, root
//         postorder(root->left, nodes);
//         postorder(root->right, nodes);
//         nodes.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         postorder(root, nodes);

//         return nodes;
//     }
// };