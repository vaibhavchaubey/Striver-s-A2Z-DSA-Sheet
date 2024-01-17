/* Leetcode Submission  (98. Validate Binary Search Tree) */



/* Solution: */
// Time Complexity: O(N) 
// Space Complexity: O(H)          //  where H is the height of the binary search tree


// class Solution {
// public:
//     bool isValid(TreeNode* root, long minVal, long maxVal) {
//         if(root == NULL){
//             return true;
//         } 
//         if(root->val <= minVal || root->val >= maxVal){
//             return false;
//         }                        // leftSubtree                  // rightSubtree
//         return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
//     }
//     bool isValidBST(TreeNode* root) {
//         return isValid(root, LONG_MIN, LONG_MAX);
//     }
// };


/* OR */


// class Solution {
// public:
//     bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
//         if(root == NULL){
//             return true;
//         } 
//         if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val){
//             return false;
//         }                     // leftSubtree                  // rightSubtree
//         return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
//     }
//     bool isValidBST(TreeNode* root) {
//         return isValid(root, NULL, NULL);
//     }
// };

