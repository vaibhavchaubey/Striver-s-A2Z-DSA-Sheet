/* Floor - The largest possible integer value which is equal to or smaller than key
val <= key   */


/* GFG Submission  (Floor in BST)  */


/* Solution: */
// Time Complexity: O(logN) 
// Space Complexity: O(1) 


// int findFloor(Node* root, int input) {
//     if (root == NULL){
//         return -1;
//     } 
//     int floor = -1;
//     while(root){
//         if(root->data == input){
//             floor = root->data;
//             return floor;
//         }
//         if(input > root->data){
//             floor = root->data;
//             root = root->right;
//         }
//         else{
//             root = root->left;
//         }
//     }
//     return floor;
// }



#include<bits/stdc++.h>                                                      
using namespace std;                                                 //Time Complexity: O(logN)
struct Node                                                         //Space Complexity: O(1)                                                     //Space Complexity: O(1)
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

int findFloor(Node* root, int key){
    int floor = -1;
    while (root)
    {
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        if(key > root->data){
            floor = root->data;
            root = root->right;
        }
        else{
            root = root->left;  
        }
    }
    return floor;
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
.              5      13            ans = 6
.             / \     / \
.            3   6   11 14
.           / \   \
.          2   4   9
.
*/

    cout<<findFloor(root,8)<<endl; 


    return 0;
}
