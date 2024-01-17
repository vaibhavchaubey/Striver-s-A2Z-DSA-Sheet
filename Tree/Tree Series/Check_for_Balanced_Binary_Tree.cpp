/* Leetcode Submission    (110. Balanced Binary Tree) */


/* Solution 1: Naive approach
Approach: For a Balanced Binary Tree, Check left subtree height and right subtree height for every node present in the tree. 
Hence, traverse the tree recursively and calculate the height of left and right subtree from every node, and whenever the 
condition of Balanced tree violates, simply return false. */

// Time Complexity: O(N*N)           as we are calling isBalanced N times & height N times */
// Space Complexity: O(H)        (Recursive Stack Space where “H” is the height of tree)    


// class Solution {
// public:
//     int height(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }

//         int lh = height(root->left);
//         int rh = height(root->right);

//         return 1 + max(lh, rh);
//     }
//     bool heightBalanced(TreeNode* root){
//         if(root == NULL){
//             return true;
//         }
//         if(heightBalanced(root->left) == false){
//             return false;
//         }
//         if(heightBalanced(root->right) == false){
//             return false;
//         }

//         int lh = height(root->left);
//         int rh = height(root->right);

//         if(abs(lh - rh) <= 1){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     bool isBalanced(TreeNode* root) {
//         return heightBalanced(root);
//     }
// };


/* OR */


// class Solution {
// public:
//     int height(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }

//         int lh = height(root->left);
//         int rh = height(root->right);

//         return 1 + max(lh, rh);
//     }
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL){
//             return true;
//         }

//         int lh = height(root->left);
//         int rh = height(root->right);

//         if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };




/* Solution 2: Calculating the height in the same recursion rather than calling a height() function separately. 
Approach: So, the idea is to use post-order traversal. Since, in postorder traversal, we first traverse the left 
and right subtrees and then visit the parent node, similarly instead of calculating the height of the left subtree 
and right subtree every time at the root node, use post-order traversal, and keep calculating the heights of the left 
and right subtrees and perform the validation. */

// Time Complexity: O(N)        
// Space Complexity: O(H)        (Recursive Stack Space where “H” is the height of tree)    


// class Solution {
// public:
//     int dfsHeight(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }

//         int leftHeight = dfsHeight(root->left);
//         if(leftHeight == -1){
//             return -1;
//         }

//         int rightHeight = dfsHeight(root->right);
//         if(rightHeight == -1){
//             return -1;
//         }

//         if(abs(leftHeight - rightHeight) > 1){
//             return -1;
//         }

//         return max(leftHeight, rightHeight) + 1;
//     }
//     bool isBalanced(TreeNode* root) {
//         return dfsHeight(root) != -1;
//     }
// };





/* 
              1
            /   \                    
           2     3
          / \   / \
         4   5 6   7
 */

/* For each node the difference between the height of the left subtree & right subtree <= 1
abs(lh-rh) <= 1 */

/* Time Complexity: O(N^2)   as we are calling isBalanced N times & height N times */

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
// int height(Node* root){                             //Time Complexity: O(N)
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int lh = height(root->left);
//     int rh = height(root->right);
//     return max(lh,rh) + 1;
// }
// bool isBalanced(Node* root){                     //Time Complexity: O(N^2)   as we are calling isBalanced N times & height N times
//     if (root == NULL)
//     {
//         return true;
//     }
//     if (isBalanced(root->left) == false)
//     {
//         return false;
//     }
//     if (isBalanced(root->right) == false)
//     {
//         return false;
//     }
//     int lh = height(root->left);
//     int rh = height(root->right);
//     if (abs(lh-rh) <= 1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// int main()
// {
//     //Balanced
//     /* 
//               1
//             /   \                    
//            2     3
//           / \   / \
//          4   5 6   7
//     */
//     Node* root1 = new Node(1);
//     root1->left = new Node(2);
//     root1->right = new Node(3);  
//     root1->left->left = new Node(4);
//     root1->left->right = new Node(5);
//     root1->right->left = new Node(6);
//     root1->right->right = new Node(7);


//     //Not Balanced
//     /* 
//              1
//             /                    
//            2
//           /
//          3
//     */
//     Node* root2 = new Node(1);
//     root2->left = new Node(2);
//     root2->left->left = new Node(3);

//     //Height Balanced Tree

//     if (isBalanced(root1))
//     {
//         cout<<"Balanced Tree"<<endl;
//     }
//     else
//         {
//         cout<<"Unbalanced Tree"<<endl;
//     }

//     if (isBalanced(root2))
//     {
//         cout<<"Balanced Tree"<<endl;
//     }
//     else
//         {
//         cout<<"Unbalanced Tree"<<endl;
//     }


//     return 0;
// }




/* 
              1
            /   \                    
           2     3
          / \   / \
         4   5 6   7
 */


/* Time Complexity: O(N)  */

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
bool isBalanced(Node* root,int* height){                     //Time Complexity: O(N)
    if (root == NULL)
    {
        *height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    if (isBalanced(root->left,&lh) == false)
    {
        return false;
    }
    if (isBalanced(root->right,&rh) == false)
    {
        return false;
    }
    *height = max(lh,rh) + 1;
    if (abs(lh-rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    //Balanced
    /* 
              1
            /   \                    
           2     3
          / \   / \
         4   5 6   7
    */
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);  
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);


    //Not Balanced
    /* 
             1
            /                    
           2
          /
         3
    */
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    //Height Balanced Tree
    int height = 0;

    if (isBalanced(root1,&height))
    {
        cout<<"Balanced Tree"<<endl;
    }
    else
        {
        cout<<"Unbalanced Tree"<<endl;
    }

    if (isBalanced(root2,&height))
    {
        cout<<"Balanced Tree"<<endl;
    }
    else
        {
        cout<<"Unbalanced Tree"<<endl;
    }




    return 0;
}
