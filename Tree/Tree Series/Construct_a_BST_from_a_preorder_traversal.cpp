/* Leetcode Submission    (1008. Construct Binary Search Tree from Preorder Traversal) */



/* Solution: */
// Time complexity: O(N) 
// Space Complexity: O(H)          //  where H is the height of the binary search tree


// class Solution {
// public:
//     TreeNode* constructBST(vector<int>& preorder, int* preorderIdx, int key, int min, int max, int n){
//         if(*preorderIdx >= n){
//             return NULL;
//         }

//         TreeNode* root = NULL;
//         if(key > min && key < max){
//             root = new TreeNode(key);
//             *preorderIdx = *preorderIdx + 1;
            
//             if(*preorderIdx < n){
//                 root->left =
//                 constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
//             }
//             if(*preorderIdx < n){
//                 root->right =
//                 constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
//             }
//         }

//         return root;
//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int n = preorder.size();
//         int preorderIdx = 0;
        
//         return constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
//     }
// };


/* OR */

/* The preorderIdx is now passed by reference (int& preorderIdx) instead of using a pointer (int* preorderIdx). 
Both versions achieve the same goal of allowing the function to modify the original value of preorderIdx and 
keep track of the current index in the preorder array across recursive calls.
So, the modification doesn't change the logic or functionality of the code; it's just an alternative way of 
passing the index variable by reference instead of using a pointer. */


// class Solution {
// public:
//     TreeNode* constructBST(vector<int>& preorder, int& preorderIdx, int key, int min, int max, int n){
//         if(preorderIdx >= n){
//             return NULL;
//         }

//         TreeNode* root = NULL;
//         if(key > min && key < max){
//             root = new TreeNode(key);
//             preorderIdx = preorderIdx + 1;

//             if(preorderIdx < n){
//                 root->left = constructBST(preorder,preorderIdx,preorder[preorderIdx],min,key,n);
//             }
//             if(preorderIdx < n){
//                 root->right = constructBST(preorder,preorderIdx,preorder[preorderIdx],key,max,n);
//             }
//         }
        
//         return root;
//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int n = preorder.size();
//         int preorderIdx = 0;
        
//         return constructBST(preorder,preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
//     }
// };