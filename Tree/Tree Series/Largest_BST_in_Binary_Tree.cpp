/* GFG Submission    (Largest BST) */

/* Problem Statement: Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree. */


/* Solution: */
// Time complexity: O(N) 
// Space complexity: O(N)


// struct Info{
//     int size;
//     int max; 
//     int min;
//     int ans;
//     bool isBST;
// };
// Info largestBSTinBT(Node* root){
//     if(root == NULL){
//         return {0,INT_MIN,INT_MAX,0,true};
//     }
//     if(root->left == NULL && root->right == NULL){
//         return {1,root->data,root->data,1,true};
//     }
//     Info leftInfo = largestBSTinBT(root->left);
//     Info rightInfo = largestBSTinBT(root->right);
    
//     Info curr;
//     curr.size = 1 + leftInfo.size + rightInfo.size;
//     if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
//         curr.min = min(leftInfo.min, min(rightInfo.min,root->data));
//         curr.max = max(leftInfo.max, max(rightInfo.max,root->data));
        
//         curr.ans = curr.size;
//         curr.isBST = true;
        
//         return curr;
//     }
//     curr.ans = max(leftInfo.ans,rightInfo.ans);
//     curr.isBST = false;
//     return curr;
// }
// class Solution{
//     public:
//     /*You are required to complete this method */
//     // Return the size of the largest sub-tree which is also a BST
//     int largestBst(Node *root)
//     {
//     	int ans = largestBSTinBT(root).ans;
    	
//     	return ans;
//     }
// };