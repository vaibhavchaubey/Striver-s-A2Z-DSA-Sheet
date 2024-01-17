/* Ceil - The smallest possible integer value which is greater than or equal to the given key
val >= key  */


/* GFG Submission  (Ceil in BST)  */


/* Solution: */
// Time Complexity: O(logN) 
// Space Complexity: O(1) 


// int findCeil(Node* root, int input) {
//     if (root == NULL){
//         return -1;
//     } 
//     int ceil = -1;
//     while(root){
//         if(root->data == input){
//             ceil = root->data;
//             return ceil;
//         }
//         if(input > root->data){
//             root = root->right;
//         }
//         else{
//             ceil = root->data;
//             root = root->left;
//         }
//     }
//     return ceil;
// }



#include<bits/stdc++.h>                                                       
using namespace std;                                                 //Time Complexity: O(logN)
struct Node                                                         //Space Complexity: O(1)                                              
{
    int data;                                         
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int findCeil(Node* root, int key){
    int ceil = -1;
    while (root)
    {
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key > root->data){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;  
        }
    }
    return ceil;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->right = new Node(13);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

/* 
.                 10
.               /    \
.              5      13            ans = 9
.             / \     / \
.            3   6   11 14
.           / \   \
.          2   4   9
.
*/

    cout<<findCeil(root,8)<<endl; 


    return 0;
}