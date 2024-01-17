// Time complexity: O(N) where n is the number of nodes.
// Space complexity: O(N), auxiliary space.


/* Leetcode Submission    (236. Lowest Common Ancestor of a Binary Tree) */


/* Solution 1: (By Storing root to n1 and root to n2 paths) 
Follow the steps below to solve the problem:
1) Find a path from the root to n1 and store it in a vector or array. 
2) Find a path from the root to n2 and store it in another vector or array. 
3) Traverse both paths till the values in arrays are the same. Return the common element just before the mismatch. */

// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     bool getPath(TreeNode* root, TreeNode* key, vector<TreeNode*>& path){
//         if(root == NULL){
//             return false;
//         }

//         path.push_back(root);

//         if(root == key){
//             return true;
//         }

//         if(getPath(root->left, key, path) || getPath(root->right, key, path)){
//             return true;
//         }

//         path.pop_back();
//         return false;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL || root == p || root == q){
//             return root;
//         }

//         vector<TreeNode*> path1, path2;

//         if(!getPath(root, p, path1) || !getPath(root, q, path2)){
//             return root;
//         }

//         int i;
//         for(i = 0; i < path1.size() && i < path2.size(); i++){
//             if(path1[i] != path2[i]){
//                 break;
//             }
//         }

//         return path1[i-1];
//     }
// };



/* Solution 2: (Using Single Traversal)
The idea is to traverse the tree starting from the root. 
1) If any of the given keys (n1 and n2) matches with the root, then the root is LCA (assuming that both keys are present). 
2) If the root doesn’t match with any of the keys, we recur for the left and right subtree. 

The node which has one key present in its left subtree and the other key present in the right subtree is the LCA. 
If both keys lie in the left subtree, then the left subtree has LCA also, otherwise, LCA lies in the right subtree.  */

// Time Complexity: O(N)
// Space Complexity: O(H), where H is the height of the tree.


// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL || root == p || root == q){
//             return root;
//         }

//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);

//         if(left == NULL){
//             return right;
//         }
//         else if(right == NULL){
//             return left;
//         }
//         else{                    // Both left and right are not NULL we found our result
//             return root;
//         }
//     }
// };



#include<bits/stdc++.h>
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
bool getPath(Node* root, int key, vector<int>& path){
    if (root == NULL)
    {
        return false;
    }
    
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }
    
    if (getPath(root->left,key,path) || getPath(root->right,key,path))
    {
        return true;
    }

    path.pop_back();
    return false;
}
// Method 1 (By Storing root to n1 and root to n2 paths):
/* Following is a simple O(n) algorithm to find LCA of n1 and n2. 
1) Find a path from the root to n1 and store it in a vector or array. 
2) Find a path from the root to n2 and store it in another vector or array. 
3) Traverse both paths till the values in arrays are the same. Return the common element just before the mismatch.
*/
int LCA(Node* root, int n1, int n2){                                   //Time Complexity: O(N)
    vector<int> path1,path2;                                          //Space Complexity: O(N)

    if (!getPath(root,n1,path1) || !getPath(root,n2,path2))
    {
        return -1;
    }

    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }
    return path1[pc-1];
}
//Method 2 (Using Single Traversal)  //More Optimized
/* The idea is to traverse the tree starting from the root. 
1) If any of the given keys (n1 and n2) matches with the root, then the root is LCA (assuming that both keys are present). 
2) If the root doesn’t match with any of the keys, we recur for the left and right subtree. 

The node which has one key present in its left subtree and the other key present in the right subtree is the LCA. 
If both keys lie in the left subtree, then the left subtree has LCA also, otherwise, LCA lies in the right subtree.   
*/
Node* LCA2(Node* root, int n1, int n2){                  //Time Complexity: O(N)
    if (root == NULL)                                   //Space Complexity: O(1)    
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)       //It fails if either n1 or n2 does not exist in the tree => 
    {                                              //it returns the existing node (it does not return NULL node)
        return root;                              //But it will be present
    }
    
    Node* leftLCA = LCA2(root->left,n1,n2);
    Node* rightLCA = LCA2(root->right,n1,n2);

    if (leftLCA && rightLCA)
    {
        return root;
    }

    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    return rightLCA;    
}
int main()
{
    /*                                                Method 1 (LCA)
.                                                              pc => path change
.              1                                   path1 = 1 3 5 7     
.            /   \                                 path2 = 1 3 6  
.           2     3
.          /     / \                               return path1[pc-1]
.         4     5   6
.              /
.             7

    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    //Method 1
    int n1 = 6;
    int n2 = 7;
    int lca = LCA(root,n1,n2);            ///OR      cout<<LCA(root,7,6);      ans => 3

    if (lca == -1)
    {
        cout<<"LCA doesn't exist"<<endl;
    }
    else
    {
        cout<<"LCA: "<<lca<<endl;
    }

    //Method 2
    // int n1 = 6;
    // int n2 = 7;
    // Node* lca = LCA2(root,n1,n2);            

    // if (lca == NULL)
    // {
    //     cout<<"LCA doesn't exist"<<endl;
    // }
    // else
    // {
    //     cout<<"LCA: "<<lca->data<<endl;
    // }


    
    return 0;
}





