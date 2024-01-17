/* Leetcode Submission    (145. Binary Tree Postorder Traversal) */


/* Solution: Iterative (using 2 Stack)*/
// Time Complexity: O(N)
// Space Complexity: O(2N)           // (stack)


// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(root == NULL){
//             return ans;
//         }

//         stack<TreeNode*> st1, st2;
//         st1.push(root);
//         while(!st1.empty()){
//             TreeNode* node = st1.top();
//             st1.pop();
//             st2.push(node);

//             if(node->left){
//                 st1.push(node->left);
//             }
//             if(node->right){
//                 st1.push(node->right);
//             }
//         }

//         while(!st2.empty()){
//             ans.push_back(st2.top()->val);
//             st2.pop();
//         }

//         return ans;
//     }
// };