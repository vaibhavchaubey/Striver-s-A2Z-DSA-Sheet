/* Leetcode Submission    (173. Binary Search Tree Iterator) */


/* Solution: */
// Time complexity: O(1) 
// Space complexity: O(H)


// class BSTIterator {
//     stack<TreeNode*> st;
// public:
//     BSTIterator(TreeNode* root) {
//         pushAll(root);
//     }
    
//     int next() {
//         TreeNode* temp = st.top();
//         st.pop();
//         pushAll(temp->right);
//         return temp->val;  
//     }
    
//     bool hasNext() {
//         return !st.empty();
//     }
    
// private:
//     void pushAll(TreeNode* node){
//         while(node != NULL){
//             st.push(node);
//             node = node->left;
//         }
//     }
// };