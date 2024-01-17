/* Codestudio Submission          (Binary Search Trees)  */

/* Problem Statement: You are given an array ‘order’ which represents the inorder traversal of a binary search tree.
Find out if this traversal is valid or not.
Note: All values in the BST must be unique.
For Example:
‘order’ = {1, 2, 3, 4,5} is a valid inorder traversal for the following binary search tree:
      4
     / \
    2   5
   / \
  1   3 */



/* Solution: Use property of inorder traversal of BST */
// Time Complexity : O(N)
// Space Complexity : O(1)


// bool isValidBST(vector<int> &order){
//     int n = order.size();
//     for(int i = 0; i < n-1; i++){
//         if(order[i] >= order[i+1]){
//             return false;
//         }
//     }

//     return true;
// }
