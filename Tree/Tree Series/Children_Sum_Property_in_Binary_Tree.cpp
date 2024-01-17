/* CodeStudio Submission   (Children Sum Property) */


/* Problem Statement: Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the
tree holds the Children sum property.
A binary tree is said to follow the children sum property if, for every node of that tree, the
value of that node is equal to the sum of the value(s) of all of its children nodes( left child
and the right child).

Note: 
1. You can only increment the value of the nodes, in other words, the
modified value must be at least equal to the original value of that node.
2. You can not change the structure of the original binary tree.
3. A binary tree is a tree in which each node has at most two children.
4. You can assume the value can be for a NULL node and there can also
be an empty tree. */


/* Solution: */
// Time complexity: O(N)
// Space complexity: O(N)


// void changeTree(BinaryTreeNode < int > * root) {
//     if(root == NULL){
//         return;
//     }
//     int child = 0;
//     if(root->left){
//         child += root->left->data;
//     }
//     if(root->right){
//         child += root->right->data;
//     }
//     if(child >= root->data){
//         root->data = child;
//     }
//     else{
//         if(root->left){
//             root->left->data = root->data;
//         }
//         else if(root->right){
//             root->right->data = root->data;
//         }
//     }
//     changeTree(root->left);
//     changeTree(root->right);
    
//     int tot = 0;
//     if(root->left){
//         tot += root->left->data;
//     }
//     if(root->right){
//         tot += root->right->data;
//     }
//     if(root->left || root->right){
//         root->data = tot;
//     }
// }  




/* GFG Submission    (Children Sum Parent) */


/* Given a binary tree, the task is to check for every node, its value is equal to the sum of values of its immediate left and right child. 
For NULL values, consider the value to be 0. */

/* Problem Statement: Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes. */


// Time Complexity: O(N), we are doing a complete traversal of the tree.
// Auxiliary Space: O(log N), Auxiliary stack space used by recursion calls



// class Solution{
//     public:
//     //Function to check whether all nodes of a tree have the value 
//     //equal to the sum of their child nodes.
//     int isSumProperty(Node *root)
//     {
//         int sum = 0;
//         if(root == NULL || root->left == NULL && root->right == NULL){
//             return 1;
//         }
//         else{
//             if(root->left){
//                 sum += root->left->data;
//             }
//             if(root->right){
//                 sum += root->right->data;
//             }
            
//             return (root->data == sum) && isSumProperty(root->left) && isSumProperty(root->right);
//         }
//     }
// };


