/* Leetcode Submission    (101. Symmetric Tree) */

/* Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center). */

/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(N)

// class Solution {
// public:
//     bool isSymmetricHelp(TreeNode* root1, TreeNode* root2){
//         if(root1 == NULL || root2 == NULL){
//             return root1 == root2;
//         }
//         if(root1->val != root2->val){
//             return false;
//         }

//         return isSymmetricHelp(root1->left,root2->right) && isSymmetricHelp(root1->right,root2->left);
//     }
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL){
//             return true;
//         }

//         return isSymmetricHelp(root->left,root->right);
//     }
// };


/* OR */

// class Solution {
// public:
//     bool isSymmetricHelp(TreeNode* root1, TreeNode* root2){
//         if(root1 == NULL && root2 == NULL){
//             return true;
//         }
//         else if(root1 == NULL || root2 == NULL){
//             return false;
//         }
//         else{
//             bool cond1 = root1->val == root2->val;
//             bool cond2 = isSymmetricHelp(root1->left,root2->right);
//             bool cond3 = isSymmetricHelp(root1->right,root2->left);

//             return cond1 && cond2 && cond3;
//         }
//     }
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL){
//             return true;
//         }

//         return isSymmetricHelp(root->left,root->right);
//     }
// };