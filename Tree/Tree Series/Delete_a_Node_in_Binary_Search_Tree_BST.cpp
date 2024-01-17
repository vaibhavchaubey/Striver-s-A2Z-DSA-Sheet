/* Leetcode Submission  (450. Delete Node in a BST) */


/* Solution: */
// Time Complexity: O(logN) 
// Space Complexity: O(1) 


// class Solution {
// public:
//     TreeNode* inorderSucc(TreeNode* root){
//         TreeNode* cur = root;
//         while(cur && cur->left){
//             cur = cur->left;
//         }
//         return cur;
//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == NULL){
//             return root;
//         }
//         if(key < root->val){
//             root->left = deleteNode(root->left,key);
//         }
//         else if(key > root->val){
//             root->right = deleteNode(root->right,key);
//         }
//         else{                         // key = root->val
//             // case 1: node is a leaf 
//             if(root->left == NULL && root->right == NULL){
//                 return NULL;
//             }
//             // case 2: node has 1 child
//             else if(root->left == NULL){
//                 TreeNode* temp = root->right;
//                 delete(root);
//                 return temp;
//             }                                             
//             else if(root->right == NULL){
//                 TreeNode* temp = root->left;
//                 delete(root);
//                 return temp;
//             }
//             // case 3: node has 2 child
//             // Get the inorder successor
//             // (smallest in the right subtree)
//             TreeNode* temp = inorderSucc(root->right);
//             root->val = temp->val;
//             root->right = deleteNode(root->right,temp->val);
//         }
//         return root;
//     }
// };



//When we do inorder traversal in BST it will give a sequence which is the sorted sequence of all the elements

/*  
.              3
.            /   \                     Binary Search Tree (BST)
.           2     7                    inorder = 1 2 3 4 5 6 7 8
.          /     / \
.         1     5   8
.              / \
.             4   6
*/ 


#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val){
    if (root == NULL)
    {
        return new Node(val);
    }
    
    if (val < root->data)
    {
        root->left = insertBST(root->left,val);
    }
    else    //val > root->data
    {
        root->right = insertBST(root->right,val);
    }
    return root;
}

Node* searchInBST(Node* root, int key){                     //Time Complexity: O(logN)
    if (root == NULL || root->data == key)
    {
        return root;
    }
    //data > key
    if (root->data > key)
    {
        return searchInBST(root->left,key);
    }
    //data < key
    return searchInBST(root->right,key);   
}

Node* inorderSucc(Node* root){
    Node* curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root, int key){
    if (key < root->data)
    {
        root->left = deleteInBST(root->left,key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right,key);
    }
    else     //key = root->data
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            free(root);                                             // delete(root)   used in Leetcode
            return temp;                            //case 1 & 2
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            free(root);                                             // delete(root)   used in Leetcode
            return temp;
        }
        //case 3
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right,temp->data);
    }
    return root;
}

void inorder(Node* root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);    
}
int main()
{
    Node* root = NULL;
    root = insertBST(root,4);
    insertBST(root,2);
    insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,6);

/*  
.             4 
.            / \                   
.           2   5              
.          / \   \
.         1   3   6
.                    
*/ 

    if (searchInBST(root,5) == NULL)
    {
        cout<<"Key doesn't exist"<<endl;
    }
    else
    {
        cout<<"Key exist"<<endl;
    }

    inorder(root);       
    cout<<endl;
    root = deleteInBST(root,2);
    inorder(root);
    cout<<endl;
    
/*  
.             4                  4                  4
.            / \                / \                / \               
.           2   5     ->       3   5     ->       3   5            ans = 1 3 4 5 6
.          / \   \            / \   \            /     \
.         1   3   6          1   3   6          1       6          inorder successor of 2 is 3
.                    
*/ 




    return 0;
}   

