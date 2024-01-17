// When we do inorder traversal in BST it will give a sequence which is the sorted sequence of all the elements

/*  
.              3
.            /   \                     Binary Search Tree (BST)
.           2     7                    inorder = 1 2 3 4 5 6 7 8
.          /     / \
.         1     5   8
.              / \
.             4   6
*/ 


#include<bits/stdc++.h>
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
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

/*  
.              5
.            /   \                     5 1 3 4 2 7
.           1     7              ans = 1 2 3 4 5 7 
.            \
.             3
.            / \
.           2   4 
*/ 

    //print inorder
    inorder(root);

  


    return 0;
}