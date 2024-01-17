/* Leetcode Submission    (99. Recover Binary Search Tree) */


/* Solution: */
// Time complexity: O(N) 
// Space complexity: O(N)           (Recursion)


// class Solution {
// private:
//     TreeNode* first;
//     TreeNode* mid;
//     TreeNode* last;
//     TreeNode* prev;
// private:
//     void calcPointer(TreeNode* root){
//         if(root == NULL){
//             return;
//         }
//         calcPointer(root->left);
//         if(prev && root->val < prev->val){
//             if(first == NULL){
//                 first = prev;
//                 mid = root;
//             }
//             else{
//                 last = root;
//             }
//         }
//         prev = root;
//         calcPointer(root->right);
//     }
// public:
//     void recoverTree(TreeNode* root) {
//         first = mid = last = prev = NULL;
//         calcPointer(root);
//         //case 1       (Swapped elements are not adjacent to each other)
//         if(first && last){
//             swap(first->val,last->val);
//         }
//         //case 2       (Swapped elements are adjacent to each other)
//         else if(first && mid){
//             swap(first->val,mid->val);
//         }
//     }
// };



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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointer(Node* root, Node** first, Node** mid, Node** last, Node** prev){
    if (root == NULL)
    {
        return;
    }

    calcPointer(root->left,first,mid,last,prev);

    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)         // OR  first == NULL        
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointer(root->right,first,mid,last,prev);
}

void restoreBST(Node* root){
    Node* first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointer(root, &first, &mid, &last, &prev);

    //case 1       (Swapped elements are not adjacent to each other)
    if (first && last)       
    {
        swap(&(first->data), &(last->data));
    }
    //case 2       (Swapped elements are adjacent to each other)
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
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
    Node* root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

/*  
.             6 
.            /  \                   
.           9    3                    
.          / \    \
.         1   4    13
.                    
*/ 
   
   inorder(root);
   cout<<endl;

   restoreBST(root);

   inorder(root);
   cout<<endl;




    return 0;
}