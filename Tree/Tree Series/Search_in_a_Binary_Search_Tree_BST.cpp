/* Leetcode Submission  (700. Search in a Binary Search Tree)  */


/* Solution: */
// Time Complexity: O(logN) 
// Space Complexity: O(1) 


// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if(root == NULL || root->val == val){
//             return root;
//         }

//         if(root->val > val){                    
//             return searchBST(root->left,val);
//         }

//         return searchBST(root->right,val);
//     }
// };


/* OR */


// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         while(root != NULL && root->val != val){
//             root = root->val > val ? root->left : root->right;
//         }

//         return root;
//     }
// };
