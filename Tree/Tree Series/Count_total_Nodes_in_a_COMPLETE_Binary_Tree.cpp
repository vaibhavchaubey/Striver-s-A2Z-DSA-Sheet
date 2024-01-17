/* Count total Nodes in a COMPLETE Binary Tree | O(Log^2 N) Approach */

/* Leetcode Submission    (222. Count Complete Tree Nodes) */

/* Problem Statement: Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity. */


/* Solution 1: Brute Force */
// Time Complexity: O(N) 
// Space Complexity: O(logN)            (Recursive space)
/* Space is needed for the recursion stack. As it is a complete tree, the height of that stack will always be logN */


// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }        

//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }
// };



/* Solution 2: Efficient Approach */
// Time Complexity: O(Log^2 N) 
/* LogN for traversing  and   LogN for height (findHeightLeft & findHeightRight)                  
LogN x LogN = Log^2 N */
// Space Complexity: O(Log N)           (Recursive space)
/* Space is needed for the recursion stack. As it is a complete tree, the height of that stack will always be logN */


// class Solution {
// public:
//     int findHeightLeft(TreeNode* node){
//         int h = 0;
//         while(node){
//             h++;
//             node = node->left;
//         }

//         return h;
//     }
//     int findHeightRight(TreeNode* node){
//         int h = 0;
//         while(node){
//             h++;
//             node = node->right;
//         }

//         return h;
//     }
//     int countNodes(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }

//         int lh = findHeightLeft(root);
//         int rh = findHeightRight(root);
        
//         if(lh == rh){
//             return pow(2, lh) - 1;      //OR (1 << lh) - 1 
//         }
        
//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }
// };




#include<iostream>
#include<math.h>                                          // LogN for traversing  and   LogN for height (findHeightLeft & findHeightRight)                  
using namespace std;                                     // LogN x LogN = Log^2 N
struct Node                                             //Time Complexity: O(Log^2 N)
{
    int data;                                         //Space Complexity: O(Log N)     (Recursive space)
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int findHeightLeft(Node* node){
    int h = 0;
    while (node)
    {
        h++;
        node = node->left;
    }
    return h;
}
int findHeightRight(Node* node){
    int h = 0;
    while (node)
    {
        h++;
        node = node->right;
    }
    return h;
}
int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if (lh == rh)
    {
        return pow(2,lh) - 1;            //OR (1 << lh) - 1  
    }  
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);

/* 
.                1
.              /   \
.             2     3             ans = 6
.            / \   /
.           4   5 6
.            
. */


    cout<<countNodes(root)<<endl;


    return 0;
}



/* Brute Force  */
// Time complexity: O(N)
// Auxiliary Space: O(1) 


/* 
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
 */


// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// int countNode(Node* root){
//     if (root == NULL)
//     {
//         return 0;
//     }
//     return countNode(root->left) + countNode(root->right) + 1;
// }
// int sumNode(Node* root){
//     if (root == NULL)
//     {
//         return 0;
//     }
//     return sumNode(root->left) + sumNode(root->right) + root->data;
// }
// int main()
// {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);

//     //Count Of Nodes
//     cout<<countNode(root)<<endl;

//     //Sum Of Nodes
//     cout<<sumNode(root)<<endl;


//     return 0;
// }
