/* Leetcode Submission    (104. Maximum Depth of Binary Tree) */


/* Solution 1: Using Level Order Traversal */
// Time Complexity: O(N) 
// Space Complexity: O(N)       // queue


// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }

//         queue<TreeNode*> q;
//         q.push(root);

//         int level = 0;
//         while(!q.empty()){
//             int len = q.size();
//             for(int i = 0; i < len; i++){
//                 TreeNode* node = q.front();
//                 q.pop();

//                 if(node->left != NULL) q.push(node->left);
//                 if(node->right != NULL) q.push(node->right);
//             }
//             level++;
//         }

//         return level;
//     }
// };




/* Solution 2: Recursion */
// Time Complexity: O(N) 
// Space Complexity: O(H) Recursion Stack space (Where “H”  is the height of binary tree)


// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }
//         int lh = maxDepth(root->left);
//         int rh = maxDepth(root->right);
        
//         return max(lh,rh) + 1;
//     }
// };



/* 
              1
            /   \                    Height = 3   (used in code)
           2     3
          / \   / \
         4   5 6   7
 */

/*

1) Height = 3                                        2) Height = 5     
              1                                             1          
            /   \                                          /   
           2     3                                        2     
          / \   / \                                      / \   
         4   5 6   7                                    3   4
.                                                      /     \                          
.                                                     5       6
.                                                    /
.                                                   7
 
*/

#include<iostream>
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
int calcHeight(Node* root){                             //Time Complexity: O(N)
    if (root == NULL)
    {
        return 0;
    }
    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);
    return max(lheight,rheight) + 1;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);  
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //Height of Binary Tree 
    cout<<calcHeight(root)<<endl;




    return 0;
}
