#include<iostream>
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
void flatten(Node* root){
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}
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
    Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    /*  Binary Tree

              4
            /   \                    
           9     5
          / \   / 
         1   3 6   
    */

    flatten(root);
    inorder(root);
    


    return 0;
}


/* Leetcode Submission  (114. Flatten Binary Tree to Linked List)  */


/* Solution 1: Using Recursion */
// Time Complexity: O(N) 
// Space Complexity: O(N) 


// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(root == NULL || root->left == NULL && root->right == NULL){
//             return;
//         }
//         if(root->left){
//             flatten(root->left);
            
//             TreeNode* temp = root->right;
//             root->right = root->left;
//             root->left = NULL;
            
//             TreeNode* t = root->right;
//             while(t->right != NULL){
//                 t = t->right;
//             }
//             t->right = temp;
//         }
//         flatten(root->right);
//     }
// };



/* Solution 2: Using Recursion */
// Time Complexity: O(N) 
// Space Complexity: O(N) 


// class Solution {
// public:
//     TreeNode* prev = NULL;
//     void flatten(TreeNode* root) {
//         if(root == NULL){
//             return;
//         }
//         flatten(root->right);
//         flatten(root->left);

//         root->right = prev;
//         root->left = NULL;
//         prev = root;
//     }
// };



/* Solution 3: Using Stack */
// Time Complexity: O(N) 
// Space Complexity: O(N)


// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(root == NULL){
//             return;
//         }
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             TreeNode* cur = st.top();
//             st.pop();

//             if(cur->right){
//                 st.push(cur->right);
//             }
//             if(cur->left){
//                 st.push(cur->left);
//             }
//             if(!st.empty()){
//                 cur->right = st.top();
//             }
//             cur->left = NULL;
//         }
//     }
// };



/* Solution 4: Using Intuition behind Morris Traversal */
// Time Complexity: O(N) 
// Space Complexity: O(1) 


// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(root == NULL){
//             return;
//         }
//         TreeNode* cur = root;
//         while(cur != NULL){
//             if(cur->left){
//                 TreeNode* pre = cur->left;
//                 while(pre->right != NULL){
//                     pre = pre->right;
//                 }
//                 pre->right = cur->right;
//                 cur->right = cur->left;
//                 cur->left = NULL;
//             }
//             cur = cur->right;
//         }
//     }
// };