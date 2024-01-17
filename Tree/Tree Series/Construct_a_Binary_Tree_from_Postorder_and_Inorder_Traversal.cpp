/* Leetcode Submission (106. Construct Binary Tree from Inorder and Postorder Traversal) */

/* Problem Statement: Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
and postorder is the postorder traversal of the same tree, construct and return the binary tree. */



/* Solution 1: Using a function for pos (Which take O(N)) */
// Time Complexity: O(N^2) 
// Space Complexity: O(N) 


// class Solution {
// public:
//     int search(vector<int>& inorder, int start, int end, int curr){
//         for(int i = start; i <= end; i++){
//             if(inorder[i] == curr){
//                 return i;
//             }
//         }
//         return -1;
//     }
//     TreeNode* constructBT(vector<int>& postorder, vector<int>& inorder, int start, int end, int& idx){
//         if(start > end){
//             return NULL;
//         }
//         int curr = postorder[idx];
//         idx--;
//         TreeNode* node = new TreeNode(curr);
//         if(start == end){
//             return node;
//         }
//         int pos = search(inorder, start, end, curr);
//         node->right = constructBT(postorder, inorder, pos+1, end, idx);
//         node->left = constructBT(postorder, inorder, start, pos-1, idx);
        
//         return node;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n = inorder.size(), idx = n-1;
//        TreeNode* root = constructBT(postorder, inorder, 0, n-1, idx);
        
//         return root;
//     }
// };



/* Solution 2: Using map to store the inorder indexes */
// Time Complexity: O(N) 
// Space Complexity: O(N) 


// class Solution {
// public:
//     TreeNode* constructBT(vector<int>& preorder, int start, int end, unordered_map<int, int>& mp, int& idx){ 
//         if(start > end){
//             return NULL;
//         }
//         int curr = preorder[idx];
//         idx--;
//         TreeNode* node = new TreeNode(curr);
//         if(start == end){
//             return node;
//         }
//         int pos = mp[curr];
//         node->right = constructBT(preorder, pos+1, end, mp, idx);
//         node->left = constructBT(preorder, start, pos-1, mp, idx);
        
//         return node;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n = inorder.size(), idx = n-1;
//         int start = 0, end = n-1;
//         unordered_map<int, int> mp;
//         for(int i = start; i <= end; i++){
//             mp[inorder[i]] = i;
//         }
        
//        TreeNode* root = constructBT(postorder, start, end, mp, idx);
        
//         return root;
//     }
// };


/* OR */




/* 
              1
            /   \
           2     3
          /     / 
         4     6   
 */

/* Time Complexity: O(N^2)
The worst case occurs when the tree is left-skewed.
*/


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
int search(int inorder[], int start, int end, int curr){
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
Node* buildTree(int postorder[], int inorder[], int start, int end){
    static int idx = end;      //Here we are using static as when recursion is called idx become 0 again (to avoid this we use static)
    if (start > end)
    {
        return NULL;
    }
    
    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->right = buildTree(postorder, inorder, pos+1, end);
    node->left = buildTree(postorder, inorder, start, pos-1);

    return node;    
}
void inorderPrint(Node* root){
    if (root == NULL)
    {   
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);    
}
int main()
{
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    //build tree
    Node* root = buildTree(postorder,inorder,0,4);
    inorderPrint(root);



    return 0;
}


//OR

/* Time Complexity: O(N)
Hashmap returns the answer in constant time.

Space Complexity: O(N)
We are using an external hashmap of size ‘N’. */


// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// Node* buildTree(int postorder[], int start, int end, unordered_map<int,int>& mp, int& idx){
//     if (start > end)
//     {
//         return NULL;
//     }
    
//     int curr = postorder[idx];
//     idx--;
//     Node* node = new Node(curr);
//     if (start == end)
//     {
//         return node;
//     }
    
//     int pos = mp[curr];
//     node->right = buildTree(postorder, pos+1, end, mp, idx);
//     node->left = buildTree(postorder, start, pos-1, mp, idx);

//     return node;
// }
// void inorderPrint(Node* root){
//     if (root == NULL)
//     {
//         return;
//     }
//     inorderPrint(root->left);
//     cout<<root->data<<" ";
//     inorderPrint(root->right);    
// }
// int main()
// {
//     int postorder[] = {4,2,5,3,1};
//     int inorder[] = {4,2,1,5,3};
    
//     unordered_map<int,int> mp;
//     for (int i = 0; i <= 4; i++)
//     {
//         mp[inorder[i]] = i;
//     }
    
//     int idx = 4;
//     //build tree
//     Node* root = buildTree(postorder,0,4,mp,idx);
//     inorderPrint(root);



//     return 0;
// }


