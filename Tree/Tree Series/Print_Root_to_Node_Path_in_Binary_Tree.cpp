/* InterviewBit Submission    (Path to Given Node) */

/* Print Root To Node Path in Binary Tree */

/* Given a Binary Tree A containing N nodes. You need to find the path from Root to a given node B.
NOTE:
No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists. */


/* Solution: */
// Time Complexity: O(N)
// Reason: We are doing a simple tree traversal.
// Space Complexity: O(N)
// Reason: In the worst case (skewed tree), space complexity can be O(N).



// bool getPath(TreeNode* root, vector<int> &ans, int B){
//     // if root is NULL
//     // there is no path
//     if(root == NULL){
//         return false;
//     }
    
//     // push the node's value in 'ans'
//     ans.push_back(root->val);
    
//     // if it is the required node
//     // return true
//     if(root->val == B){
//         return true;
//     }
    
//     // else check whether the required node lies
//     // in the left subtree or right subtree of
//     // the current node
//     if(getPath(root->left,ans,B) || getPath(root->right,ans,B)){
//         return true;
//     }
    
//     // required node does not lie either in the
//     // left or right subtree of the current node
//     // Thus, remove current node's value from
//     // 'ans'and then return false  
//     ans.pop_back();
//     return false;
// }
// vector<int> Solution::solve(TreeNode* A, int B) {
//     vector<int> ans;
//     if(A == NULL){
//         return ans;
//     }
//     getPath(A,ans,B);
    
//     return ans;
// }



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Also Open Print_Root_to_Leaf_Paths_in_Binary_Tree.cpp

/* Print Root To Leaf Path in Binary Tree */



/* GFG Solution     (Root to Leaf Paths)   */
/* Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 10 20 40 #10 20 60 #10 30 #    */


/* Problem Statement: Given a Binary Tree of size N, you need to find all the possible paths from root node to all the 
leaf node's of the binary tree. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(H)


// void getPath(Node* root, vector<vector<int>>& ans, vector<int> path){
//     if(root == NULL){
//         return;
//     }
//     path.push_back(root->data);
    
//     if(root->left == NULL && root->right == NULL){
//         ans.push_back(path);
//         return;
//     }
//     getPath(root->left,ans,path);
//     getPath(root->right,ans,path);
// }
// vector<vector<int>> Paths(Node* root)
// {
//     vector<vector<int>> ans;
//     if(root == NULL){
//         return ans;
//     }
//     vector<int> path;
//     getPath(root,ans,path);
    
//     return ans;
// }




/* Leetcode Solution  (257. Binary Tree Paths) */
/* 
         1
       /   \
      2    3
       \
        5
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]   */


/* Problem Statement: Given the root of a binary tree, return all root-to-leaf paths in any order. 
A leaf is a node with no children. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(H)


// class Solution {
// public:
//     void path(vector<string>& ans, TreeNode* root, string s){
//         //It is called when one path is completed
//         if(root->left == NULL && root->right == NULL){       
//             ans.push_back(s);
//             return;
//         }
//         if(root->left){
//             path(ans, root->left ,s + "->" + to_string(root->left->val));
//         }
//         if(root->right){
//             path(ans, root->right ,s + "->" + to_string(root->right->val));
//         }
//     }
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> ans;
//         if(root == NULL){
//             return ans;
//         }
//         path(ans,root,to_string(root->val));
        
//         return ans;
//     }
// };

