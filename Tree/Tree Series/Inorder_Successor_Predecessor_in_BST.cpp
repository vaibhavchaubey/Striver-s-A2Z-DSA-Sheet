/* In Binary Tree, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree. 
Inorder Successor is NULL for the last node in Inorder traversal. 

In Binary Search Tree, Inorder Successor of an input node can also be defined as the node with the smallest 
key greater than the key of the input node. So, it is sometimes important to find next node in sorted order. */



/* Inorder Successor */
// Time complexity: O(H) 
// Space complexity: O(1)


// class Solution {
// public:
//     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//         TreeNode* successor = NULL;
//         while (root != NULL) {
            
//             if (p->val >= root->val) {
//                 root = root->right;
//             } 
//             else {
//                 successor = root;
//                 root = root->left;
//             }
//         }
        
//         return successor;
//     }
// };



/* Inorder Predecessor */
// Time complexity: O(H) 
// Space complexity: O(1)


// class Solution {
// public:
//     TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
//         TreeNode* predecessor = NULL;
//         while (root != NULL) {
            
//             if (p->val <= root->val) {
//                 root = root->left;
//             } 
//             else {
//                 predecessor = root;
//                 root = root->right;
//             }
//         }

//         return predecessor;
//     }
// };



/* GFG Submission    (Predecessor and Successor) */

/* Problem Statement: There is BST given with the root node with the key part as an integer only. You need to find the 
in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.
Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater 
than the target is the successor.  */


/* Solution: */
// Time complexity: O(H) 
// Space complexity: O(1)


// class Solution
// {
//     public:
//     void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
//     {
//         Node* cur = root;
//         suc = NULL;
//         while(cur != NULL){
//             if(key >= cur->key){
//                 cur = cur->right;
//             }
//             else{
//                 suc = cur;
//                 cur = cur->left;
//             }
//         }
        
//         cur = root;
//         pre = NULL;
//         while(cur != NULL){
//             if(key <= cur->key){
//                 cur = cur->left;
//             }
//             else{
//                 pre = cur;
//                 cur = cur->right;
//             }
//         }
//     }
// };



/* Inorder Successor */

#include<iostream>                                              
using namespace std;                                          //Time Complexity: O(H)     where h is height   (we can also say O(LogN))
struct Node                                                  //Space Complexity: O(1)
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

Node* inorderSuccessor(Node* root, Node* p){
    Node* successor = NULL;
    while (root != NULL)
    {
        if(p->data >= root->data){
            root = root->right;
        }
        else{
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

/* 
.                 5
.               /   \
.              3     7            ans = 9
.             / \   / \
.            2   4 6   9
.           /         / \
.          1         8   10
.
*/

    Node* p = root->right->right->left;    // 8
    Node* succ = inorderSuccessor(root,p);

    if(succ != NULL){
        cout<<"Inorder Successor of "<<p->data<<" is "<<succ->data<<endl;
    }
    else{
        cout<<"Inorder Successor doesn't exist"<<endl;
    }


    return 0;
}



/* Predecessor Successor */

// #include<iostream>                                              
// using namespace std;                                          //Time Complexity: O(H)     where h is height   (we can also say O(LogN))
// struct Node                                                  //Space Complexity: O(1)
// {
//     int data;                                         
//     Node* left;
//     Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// Node* predecessorSuccessor(Node* root, Node* p){
//     Node* predecessor = NULL;
//     while (root != NULL)
//     {
//         if(p->data <= root->data){
//             root = root->left;
//         }
//         else{
//             predecessor = root;
//             root = root->right;
//         }
//     }
//     return predecessor;
// }

// int main()
// {
//     Node* root = new Node(5);
//     root->left = new Node(3);
//     root->left->left = new Node(2);
//     root->left->right = new Node(4);
//     root->left->left->left = new Node(1);
//     root->right = new Node(7);
//     root->right->left = new Node(6);
//     root->right->right = new Node(9);
//     root->right->right->left = new Node(8);
//     root->right->right->right = new Node(9);

// /* 
// .                 5
// .               /   \
// .              3     7            ans = 7
// .             / \   / \
// .            2   4 6   9
// .           /         / \
// .          1         8   10
// .
// */

    // Node* p = root->right->right->left;    // 8
    // Node* pre = predecessorSuccessor(root,p);

//     if(pre != NULL){
//         cout<<"Predecessor Successor of "<<p->data<<" is "<<pre->data<<endl;
//     }
//     else{
//         cout<<"Predecessor Successor doesn't exist"<<endl;
//     }


//     return 0;
// }












// Node* inorderSuccessor(Node* root, Node* p){
//     Node* successor = NULL;
//     while (root != NULL)
//     {
//         if(p->data >= root->data){
//             root = root->right;
//         }
//         else{
//             successor = root;
//             root = root->left;
//         }
//     }
//     return successor;
// }


// Node* predecessorSuccessor(Node* root, Node* p){
//     Node* predecessor = NULL;
//     while (root != NULL)
//     {
//         if(p->data <= root->data){
//             root = root->left;
//         }
//         else{
//             predecessor = root;
//             root = root->right;
//         }
//     }
//     return predecessor;
// }