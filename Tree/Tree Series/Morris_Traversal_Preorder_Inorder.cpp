/* Morris Traversal :- 
Morris (InOrder) traversal is a tree traversal algorithm that does not employ the use of recursion or a stack. 
In this traversal, links are created as successors and nodes are printed using these links. 
Finally, the changes are reverted back to restore the original tree. */

/* QUESTION
Using Morris Traversal, we can traverse the tree without using stack and recursion. 
The idea of Morris Traversal is based on Threaded Binary Tree. 
In this traversal, we first create links to Inorder successor and print the data using these links, 
and finally revert the changes to restore original tree. 
*/

/* Threaded binary tree :-
A binary tree is threaded by making all right child pointers that would normally be null point 
to the inorder successor of the node (if it exists), and all left child pointers that would normally 
be null point to the inorder predecessor of the node.  
*/


/* Leetcode Submission  (94. Binary Tree Inorder Traversal)  */


/* Solution: Using Morris Traversal */
// Time Complexity: O(N) 
// Space Complexity: O(1) 


// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> inorder;
//         if(root == NULL){
//             return inorder;
//         }

//         TreeNode* cur = root;
//         while(cur != NULL){
//             if(cur->left == NULL){
//                 inorder.push_back(cur->val);
//                 cur = cur->right;
//             }
//             else{
//                 TreeNode* prev = cur->left;
//                 while(prev->right && prev->right != cur){
//                     prev = prev->right;
//                 }

//                 if(prev->right == NULL){
//                     prev->right = cur;
//                     cur = cur->left;
//                 }
//                 else{
//                     prev->right = NULL;
//                     inorder.push_back(cur->val);
//                     cur = cur->right;
//                 }
//             }
//         }

//         return inorder;
//     }
// };




/* Leetcode Submission  (144. Binary Tree Preorder Traversal)  */


/* Solution: Using Morris Traversal */
// Time Complexity: O(N) 
// Space Complexity: O(1) 


// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> preorder;
//         if(root == NULL){
//             return preorder;
//         }
        
//         TreeNode* cur = root;
//         while(cur != NULL){
//             if(cur->left == NULL){
//                 preorder.push_back(cur->val);
//                 cur = cur->right;
//             }
//             else{
//                 TreeNode* prev = cur->left;
//                 while(prev->right && prev->right != cur){
//                     prev = prev->right;
//                 }

//                 if(prev->right == NULL){
//                     prev->right = cur;
//                     preorder.push_back(cur->val);
//                     cur = cur->left;
//                 }
//                 else{
//                     prev->right = NULL;
//                     cur = cur->right;
//                 }
//             }
//         }

//         return preorder;
//     }
// };




/* NOTE:- In normal inorder traversal space complexity is O(N) but in morris traversal it it O(1) */

//Inorder 

#include<iostream>
#include<vector>                                                         
using namespace std;                                                 //Time Complexity: O(N)
struct Node                                                         //Space Complexity: O(1)
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

vector<int> morrisTraversal(Node* root){
    vector<int> inorder;
    Node* cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            Node* prev = cur->left;
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }
            
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

/* 
.                1
.               / \
.              2   3            ans = 4 2 5 6 1 3 
.             / \ 
.            4   5
.                 \
.                  6
.
*/

    vector<int> v = morrisTraversal(root);
    for(auto i : v){
        cout<<i<<" ";
    }   


    return 0;
}


/* NOTE:- In normal inorder traversal space complexity is O(N) but in morris traversal it it O(1) */

//Preorder

// #include<iostream>
// #include<vector>                                                         
// using namespace std;                                                 //Time Complexity: O(N)
// struct Node                                                         //Space Complexity: O(1)
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

// vector<int> morrisTraversal(Node* root){
//     vector<int> preorder;
//     Node* cur = root;
//     while(cur != NULL){
//         if(cur->left == NULL){
//             preorder.push_back(cur->data);
//             cur = cur->right;
//         }
//         else{
//             Node* prev = cur->left;
//             while (prev->right && prev->right != cur)
//             {
//                 prev = prev->right;
//             }
            
//             if(prev->right == NULL){
//                 prev->right = cur;
//                 preorder.push_back(cur->data);
//                 cur = cur->left;
//             }
//             else{
//                 prev->right = NULL;
//                 cur = cur->right;
//             }
//         }
//     }
//     return preorder;
// }

// int main()
// {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->left->right->right = new Node(6);

// /* 
// .                1
// .               / \
// .              2   3            ans = 1 2 4 5 6 3 
// .             / \ 
// .            4   5
// .                 \
// .                  6
// .
// */

//     vector<int> v = morrisTraversal(root);
//     for(auto i : v){
//         cout<<i<<" ";
//     }


//     return 0;
// }
