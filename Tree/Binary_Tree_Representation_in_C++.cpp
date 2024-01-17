/* Codestudio Submission          (Create Binary Tree)  */

/* Problem Statement: Given an array 'arr' that contains 7 integers representing the values of nodes in a binary tree. 
This represents level order. The first element of the array represents the value of the root node.
Your objective is to construct a binary tree using the remaining 6 elements of the array, creating nodes for each of these 
values and return root node. */


/* Solution: Level order traversal */
// Time Complexity : O(N)
// Space Complexity : O(N)


// Node* createTree(vector<int>&arr){
//     // Create the root node with the value from the first element of the array
//     Node* root = new Node(arr[0]);
//     queue<Node*> q;
//     q.push(root);
//     int i = 0;
//     while(!q.empty() && i < 3){
//         Node* node = q.front();
//         q.pop();

//         // Create the left child node with the value from the corresponding index in the array
//         Node* left = new Node(arr[2*i+1]);
//         node->left = left;
//         q.push(left);

//         // Create the right child node with the value from the corresponding index in the array
//         Node* right = new Node(arr[2*i+2]);
//         node->right = right;
//         q.push(right);

//         i++;
//     }

//     return root;
// }