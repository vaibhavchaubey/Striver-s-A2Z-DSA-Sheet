/* Leetcode Submission  (701. Insert into a Binary Search Tree)  */

// Time Complexity: O(logN) 
// Space Complexity: O(1) 


/* Solution 1: Iterative Solution */
// Time Complexity: O(logN) 
// Space Complexity: O(1) 


// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if(root == NULL){
//             return new TreeNode(val);
//         }  

//         TreeNode* cur = root;
//         while(true){
//             if(cur->val <= val){
//                 if(cur->right){
//                     cur = cur->right;
//                 }
//                 else{
//                     cur->right = new TreeNode(val);
//                     break;
//                 }
//             }
//             else{                            //cur->val > val
//                 if(cur->left){
//                     cur = cur->left;
//                 }
//                 else{
//                     cur->left = new TreeNode(val);
//                     break;
//                 }
//             }
//         }

//         return root;
//     }
// };



/* Solution 2: Recursive Solution */
// Time Complexity: O(logN) 
// Space Complexity: O(1) 


// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if(root == NULL){
//             return new TreeNode(val);
//         }
//         if(val < root->val){
//             root->left = insertIntoBST(root->left,val);
//         }
//         else{                               // val > root->val
//             root->right = insertIntoBST(root->right,val);
//         }

//         return root;
//     }
// };