/* Leetcode Submission    (124. Binary Tree Maximum Path Sum) */


/* Solution: */
// Time Complexity: O(N) 
// Reason: We are doing a tree traversal.
// Space Complexity: O(N)
// Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).


// class Solution {
// public:
//     int maxPathSumUtil(TreeNode* root, int& ans){
//         if(root == NULL){
//             return 0;
//         }
//         int left = maxPathSumUtil(root->left,ans);
//         int right = maxPathSumUtil(root->right,ans);

//         int maxNodes = max(max(root->val, root->val + left + right), max(root->val + left, root->val + right));
//         ans = max(ans,maxNodes);

//         int singlePathSum = max(root->val, max(root->val + left, root->val + right));
        
//         return singlePathSum;
//     }
//     int maxPathSum(TreeNode* root) {
//         int ans = INT_MIN;
//         maxPathSumUtil(root,ans);
//         return ans;
//     }
// };



/* For each node there can be four ways that the max path goes through the node: 
1. Node only 
2. Max path through Left Child + Node 
3. Max path through Right Child + Node 
4. Max path through Left Child + Node + Max path through Right Child
The idea is to keep trace of four paths and pick up the max one in the end. 
An important thing to note is, root of every subtree need to return maximum 
path sum such that at most one child of root is involved. */


#include<iostream>
#include<climits>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int maxPathSumUtil(Node* root, int& ans){                //Time Complexity: O(N)
    if (root == NULL)
    {
        return 0;
    }
    int left = maxPathSumUtil(root->left,ans);
    int right = maxPathSumUtil(root->right,ans);

    int maxNodes = max(max(root->data,root->data + left + right), max(root->data + left, root->data + right));

    ans = max(ans, maxNodes);
    /* Ans is calculated for whole path traversal and no need to return ans because it is stored 
    in address of variable so it gets changed automatically */

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    /* u might be confused between the util function and the actual answer
    the ans is sum of whole path right
    but the util function just decides what branch of the tree should be part of the path  */

    return singlePathSum;    
}
int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}
int main()
{
    // Node* root = new Node(1);
    // root->left = new Node(-12);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->right->left = new Node(5);
    // root->right->right = new Node(-6);

    // cout<<maxPathSum(root)<<endl;

/*  
.              1
.            /   \                     ans = 9
.          -12    3
.          /     / \
.         4     5  -6
.             
*/   


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(-6);

    cout<<maxPathSum(root)<<endl;

/*  
.              1
.             / \                    ans = 15
.            2   3
.           /     \
.          4       5    
*/



    return 0;
}

