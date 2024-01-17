/* GFG Submission     (Boundary Traversal of binary tree) */


/* QUESTION
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. 
The boundary includes left boundary, leaves, and right boundary in order without duplicate nodes. 
(The values of the nodes may still be duplicates.)
*/

/* Algorithm :-
1. Print the left boundary in top-down manner. 
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts: 
…..2.1 Print all leaf nodes of left sub-tree from left to right. 
…..2.2 Print all leaf nodes of right subtree from left to right. 
3. Print the right boundary in bottom-up manner.
*/


// Time Complexity: O(N).
// Reason: The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)
// Space Complexity: O(N)
// Reason: Space is needed for the recursion stack while adding leaves. In the worst case (skewed tree), space complexity can be O(N).



// class Solution
// {
// public:
//     void printLeaves(Node *root, vector<int>& ans){ 
//         if (root == NULL){
//             return;
//         }
//         printLeaves(root->left,ans);
//         // Print it if it is a leaf node
//         if ((root->left == NULL) && (root->right == NULL)){ 
//             ans.push_back(root->data);
//         }
//         printLeaves(root->right,ans);
//     }
//     void printBoundaryLeft(Node *root, vector<int>& ans){
//         if (root == NULL){
//             return;
//         }
//         if (root->left){
//             // to ensure top down order, print the node
//             // before calling itself for left subtree
//             ans.push_back(root->data);
//             printBoundaryLeft(root->left,ans);
//         }
//         else if (root->right){
//             ans.push_back(root->data);
//             printBoundaryLeft(root->right,ans);
//         }
//     }
//     void printBoundaryRight(Node *root, vector<int>& ans){
//         if (root == NULL){
//             return;
//         }
//         // to ensure bottom up order, first call for right
//         // subtree, then print this node
//         if (root->right){
//             printBoundaryRight(root->right,ans);
//             ans.push_back(root->data);
//         }
//         else if (root->left){
//             printBoundaryRight(root->left,ans);
//             ans.push_back(root->data);
//         }
//     }
//     vector<int> boundary(Node *root)
//     {
//         vector<int> ans;
//         if (root == NULL){
//             return ans;
//         }
//         ans.push_back(root->data);

//         // Print the left boundary in top-down manner
//         printBoundaryLeft(root->left,ans);

//         // Print all leaf nodes
//         printLeaves(root->left,ans);
//         printLeaves(root->right,ans);

//         // Print the right boundary in bottom-up manner
//         printBoundaryRight(root->right,ans);
        
//         return ans;
//     }
// };



#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void printLeaves(Node* root){                         //Time Complexity: O(N) where N is the number of nodes in binary tree.
    if (root == NULL)
    {
        return;
    }
    printLeaves(root->left);
    // Print it if it is a leaf node
    if ((root->left == NULL) && (root->right == NULL))     //   OR    if (!(root->left) && !(root->right))
    {
        cout<<root->data<<" ";
    }
    printLeaves(root->right);
}
void printBoundaryLeft(Node* root){
    if (root == NULL)
    {
        return;
    }
    if (root->left)
    {
        // to ensure top down order, print the node
        // before calling itself for left subtree
        cout<<root->data<<" ";
        printBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        cout<<root->data<<" ";
        printBoundaryLeft(root->right);
    }
}
void printBoundaryRight(Node* root){
    if (root == NULL)
    {
        return;
    }
    // to ensure bottom up order, first call for right
    // subtree, then print this node
    if (root->right)
    {
        printBoundaryRight(root->right);
        cout<<root->data<<" ";
    }
    else if (root->left)
    {
        printBoundaryRight(root->left);
        cout<<root->data<<" ";
    }
}
void printBoundary(Node* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    
    // Print the left boundary in top-down manner
    printBoundaryLeft(root->left);

    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);

    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);   
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);



/*
.                1
.              /   \
.             2     7
.            /       \
.           3         8                 1 2 3 4 5 6 10 11 9 8 7 
.           \        /
.            4      9
.           / \    / \
.          5   6  10 11
.
  */

    printBoundary(root);



    return 0;
}