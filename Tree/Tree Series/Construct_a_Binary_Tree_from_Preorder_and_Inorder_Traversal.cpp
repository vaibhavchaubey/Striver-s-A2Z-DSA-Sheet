/* Leetcode Submission      (105. Construct Binary Tree from Preorder and Inorder Traversal) */

/* Problem Statement: Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
and inorder is the inorder traversal of the same tree, construct and return the binary tree. */



/* Solution 1: Using a function for pos (Which take O(N)) */
// Time Complexity: O(N^2) 
// Space Complexity: O(N) 


// class Solution {
// public:
//     int idx = 0;
//     int search(vector<int>& inorder, int start, int end, int curr){
//         for(int i = start; i <= end; i++){
//             if(inorder[i] == curr){
//                 return i;
//             }
//         }
//         return -1;
//     }
//     TreeNode* constructBT(vector<int>& preorder, vector<int>& inorder, int start, int end){
//         if(start > end){
//             return NULL;
//         }
//         int curr = preorder[idx];
//         idx++;
//         TreeNode* node = new TreeNode(curr);
//         if(start == end){
//             return node;
//         }
//         int pos = search(inorder, start, end, curr);
//         node->left = constructBT(preorder, inorder, start, pos-1);
//         node->right = constructBT(preorder, inorder, pos+1, end);
        
//         return node;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        TreeNode* root = constructBT(preorder, inorder, 0, preorder.size()-1);
        
//         return root;
//     }
// };



/* Solution 2: Using map to store the inorder indexes */
// Time Complexity: O(N) 
// Space Complexity: O(N) 


// class Solution {
// public:
//     int idx = 0;
//     TreeNode* constructBT(vector<int>& preorder, int start, int end, unordered_map<int, int>& mp){ 
//         if(start > end){
//             return NULL;
//         }
//         int curr = preorder[idx];
//         idx++;
//         TreeNode* node = new TreeNode(curr);
//         if(start == end){
//             return node;
//         }
//         int pos = mp[curr];
//         node->left = constructBT(preorder, start, pos-1, mp);
//         node->right = constructBT(preorder, pos+1, end, mp);
        
//         return node;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int start = 0, end = inorder.size()-1;
//         unordered_map<int, int> mp;
//         for(int i = start; i <= end; i++){
//             mp[inorder[i]] = i;
//         }
        
//        TreeNode* root = constructBT(preorder, start, end, mp);
        
//         return root;
//     }
// };





/* 
              1
            /   \
           2     3
          /     / 
         4     5   
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
Node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;        //Here we are using static as when recursion is called idx become 0 again (to avoid this we use static)
    if (start > end)
    {
        return NULL;
    }
    
    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos-1);
    node->right = buildTree(preorder, inorder, pos+1, end);

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
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    
    //build tree
    Node* root = buildTree(preorder,inorder,0,4);
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
// int idx = 0;
// Node* buildTree(int preorder[], int start, int end, unordered_map<int,int>& mp){
//     if (start > end)
//     {
//         return NULL;
//     }
    
//     int curr = preorder[idx];
//     idx++;
//     Node* node = new Node(curr);
//     if (start == end)
//     {
//         return node;
//     }
    
//     int pos = mp[curr];
//     node->left = buildTree(preorder, start, pos-1,mp);
//     node->right = buildTree(preorder, pos+1, end,mp);

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
//     int preorder[] = {1,2,4,3,5};
//     int inorder[] = {4,2,1,5,3};
    
//     unordered_map<int,int> mp;
//     for (int i = 0; i <= 4; i++)
//     {
//         mp[inorder[i]] = i;
//     }
    
//     //build tree
//     Node* root = buildTree(preorder,0,4,mp);
//     inorderPrint(root);



//     return 0;
// }



