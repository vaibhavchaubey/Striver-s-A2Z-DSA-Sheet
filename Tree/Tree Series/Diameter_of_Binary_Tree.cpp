/* IMP
In Leetcode
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
The length of a path between two nodes is represented by the number of edges between them.

In GFG
The diameter/width of a tree is defined as the number of nodes on the longest path between two end nodes.  

In Leetcode we take number of edges for Diameter
In GFG we take number of nodes for Diameter
*/

/* 
              1
            /   \                   
           2     3               [4,2,1,3] or [5,2,1,3]
          / \   
         4   5 


For Leetcode                  For GFG
ans = 3 (Edges)               ans = 4 (Nodes)
*/


// Time Complexity: O(N) 
// Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree)



/* Leetcode Submission    (543. Diameter of Binary Tree) */


/* Solution 1: Naive approach */
// Time Complexity: O(N*N)           as we are calling isBalanced N times & height N times */
// Space Complexity: O(N)       


// class Solution {
// public:
//     int calcHeight(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }

//         int lh = calcHeight(root->left);
//         int rh = calcHeight(root->right);

//         return 1 + max(lh, rh);
//     }
//     int calcDiameter(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }

//         int lHeight = calcHeight(root->left);
//         int rHeight = calcHeight(root->right);
//         int currDiameter = lHeight + rHeight + 1;

//         int lDiameter = calcDiameter(root->left);
//         int rDiameter = calcDiameter(root->right);

//         return max(currDiameter, max(lDiameter, rDiameter));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         return calcDiameter(root) - 1;
//     }
// };




/* Solution 2: */
// Time Complexity: O(N)        
// Space Complexity: O(N)      


// class Solution {
// public:
//     int calcDiameter(TreeNode* root, int* height){
//         if(root == NULL){
//             *height = 0;
//             return 0;
//         }
//         int lh = 0, rh = 0;
//         int lDiameter = calcDiameter(root->left,&lh);
//         int rDiameter = calcDiameter(root->right,&rh);

//         int currDiameter = lh + rh + 1;
//         *height = max(lh,rh) + 1;

//         return max(currDiameter,max(lDiameter,rDiameter));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         int height = 0;
//         //As we are counting edges for the length of a path between two nodes  
//         return calcDiameter(root,&height) - 1; 
//     }
// };

/* OR */

// class Solution {
// public:
//     int height(TreeNode* root, int& diameter){
//         if(root == NULL){
//             return 0;
//         }

//         int lh = height(root->left, diameter);
//         int rh = height(root->right, diameter);
//         int currDiameter = lh + rh + 1;
//         diameter = max(diameter, currDiameter);

//         return max(lh, rh) + 1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         int diameter = 0;
//         height(root, diameter);
//         //As we are counting edges for the length of a path between two nodes  
//         return diameter - 1; 
//     }
// };






/* 
              1
            /   \                    Height = 3   (used in code)
           2     3
          / \   / \
         4   5 6   7
*/

/* Diameter of Binary Tree

1) Diamter through root (D = 5, H = 3)         2) Diamter not through root (D = 6, H = 5)      
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

// int calcHeight(Node* root){                             //Time Complexity: O(N)
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int lheight = calcHeight(root->left);
//     int rheight = calcHeight(root->right);
//     return max(lheight,rheight) + 1;
// }

// int calcDiameter(Node* root){                  //Time Complexity: O(N^2)   as we are calling calcDiameter N times & calcHeight N times
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int lheight = calcHeight(root->left);
//     int rheight = calcHeight(root->right);
//     int currDiameter = lheight + rheight + 1;        //For type 1

//     int lDiameter = calcDiameter(root->left);
//     int rDiameter = calcDiameter(root->right);      //For type 2

//     return max(currDiameter,max(lDiameter,rDiameter));
// }

int calcDiameter(Node* root, int* height){               //Time Complexity: O(N)
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    
    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(root->left,&lh);
    int rDiameter = calcDiameter(root->right,&rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh,rh) + 1;

    return max(currDiameter,max(lDiameter,rDiameter));
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


    //Diameter of Binary Tree 
    // cout<<calcDiameter(root)<<endl; 

    //Diameter of Binary Tree Optimized
    int height = 0;
    cout<<calcDiameter(root,&height)<<endl; 




    return 0;
}
