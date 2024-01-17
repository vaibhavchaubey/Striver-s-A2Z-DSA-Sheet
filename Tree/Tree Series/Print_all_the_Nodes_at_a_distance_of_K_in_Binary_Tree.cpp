/* Leetcode Solution      (863. All Nodes Distance K in Binary Tree)   */


/* Solution: */
// Time complexity: O(N)
// Space complexity: O(N)


// class Solution {
// public:
//     //case 1 (Node's Subtree)
//     void printSubtreeNodes(TreeNode* root, int k, vector<int>& ans){
//         // Base Case
//         if(root == NULL || k < 0){
//             return;
//         }
//         // If we reach a k distant node, print it
//         if(k == 0){
//             ans.push_back(root->val);
//         }

//         // Recur for left and right subtrees
//         printSubtreeNodes(root->left, k-1, ans);
//         printSubtreeNodes(root->right, k-1, ans);
//     }
    
//     //case 2 (Node's Ancestor)
//     // Prints all nodes at distance k from a given target node.
//     // The k distant nodes may be upward or downward.  This function
//     // Returns distance of root from target node, it returns -1 if target
//     // node is not present in tree rooted with root.
//     int printNodesAtk(TreeNode* root, TreeNode* target, int k, vector<int>& ans){
//         // If tree is empty, return -1
//         if(root == NULL){
//             return -1;
//         }
//         // If target is same as root.  Use the printSubtreeNodes function
//         // to print all nodes at distance k in subtree rooted with
//         // target or root
//         if(root == target){
//             printSubtreeNodes(root,k,ans);
//             return 0;
//         }
        
//         // Recur for left subtree
//         int dl = printNodesAtk(root->left, target, k,ans);
//         // Check if target node was found in left subtree
//         if(dl != -1){               //we found our target in left subtree
//             // If root is at distance k from target, print root
//             // Note that dl is Distance of root's left child from target
//             if(dl + 1 == k){
//                 ans.push_back(root->val);
//             }
//             // Else go to right subtree and print all k-dl-2 distant nodes
//             // Note that the right child is 2 edges away from left child
//             else{
//                 printSubtreeNodes(root->right, k-dl-2,ans);
//             }
//             // Add 1 to the distance and return value for parent calls
//             return 1+dl;
//         }

//         // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
//         // Note that we reach here only when node was not found in left subtree
//         int dr = printNodesAtk(root->right, target, k, ans);
//         if(dr != -1){      //we found our target in right subtree
//             if(dr + 1 == k){
//                 ans.push_back(root->val);
//             }
//             else{
//                 printSubtreeNodes(root->left, k-dr-2, ans);
//             }
//             return 1+dr;
//         }
//         return -1;
//     }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         vector<int> ans;
//         printNodesAtk(root, target, k, ans);
        
//         return ans;
//     }
// };





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
//case 1 (Node's Subtree)
void printSubtreeNodes(Node* root, int k){
    // Base Case
    if (root == NULL || k < 0)
    {
        return;
    }
    // If we reach a k distant node, print it
    if (k == 0)
    {
        cout<<root->data<<" ";
    }
    // Recur for left and right subtrees
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

//case 2 (Node's Ancestor)
// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int printNodesAtk(Node* root, Node* target, int k){
    // If tree is empty, return -1
    if (root == NULL)
    {
        return -1;
    }
    // If target is same as root.  Use the printSubtreeNodes function
    // to print all nodes at distance k in subtree rooted with
    // target or root
    if (root == target)
    {
        printSubtreeNodes(root,k);
        return 0;
    }

    // Recur for left subtree
    int dl = printNodesAtk(root->left, target, k);

    // Check if target node was found in left subtree
    if (dl != -1)       //we found our target in left subtree
    {
        // If root is at distance k from target, print root
        // Note that dl is Distance of root's left child from target
        if (dl + 1 == k)
        {
            cout<<root->data<<" ";
        }
        // Else go to right subtree and print all k-dl-2 distant nodes
        // Note that the right child is 2 edges away from left child
        else
        {
            printSubtreeNodes(root->right, k-dl-2);
        }
        // Add 1 to the distance and return value for parent calls
        return 1+dl;
    }

    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int dr = printNodesAtk(root->right, target, k);
    if (dr != -1)      //we found our target in right subtree
    {
        if (dr + 1 == k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubtreeNodes(root->left, k-dr-2);
        }
        return 1+dr;
    }
    
    return -1;    
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(2);
    root->left->left = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
    root->left->left->left = new Node(7);
    root->left->left->left->left = new Node(8);
    root->left->left->left->right = new Node(9);

    printNodesAtk(root, root->left, 3);

    /*  Binary Tree

              1
            /   \                    
           5     2
          /     / \
         6     3   4
        /
       7
      / \
     8   9

    */

    
    return 0;
}


