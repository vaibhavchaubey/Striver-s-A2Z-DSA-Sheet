/* Codestudio Submission          (Minimum element in BST)  */

/* Problem Statement: You are given a Binary Search Tree.
Find the minimum value in it.
Note:
All the values in the given binary search tree are unique. */



/* Solution 1: Recursive Solution */
// Time Complexity : O(N)
// Space Complexity : O(1)


// int minVal(Node* root){
// 	if(root == NULL){
// 		return -1;
// 	}
// 	if(root->left){
// 		return minVal(root->left);
// 	}
	
// 	return root->data;
// }



/* Solution 2: Iterative Solution */
// Time Complexity : O(N)
// Space Complexity : O(1)


// int minVal(Node* root){
// 	if(root == NULL){
// 		return -1;
// 	}
// 	while(root->left){
// 		root = root->left;
// 	}

// 	return root->data;
// }