/* Leetcode Submission  (230. Kth Smallest Element in a BST) */



/* Solution 1: Brute Force (Using Vector to store nodes) */
// Time Complexity: O(N) 
// Space Complexity: O(N) + O(H)                    //  where H is the height of the binary search tree


// class Solution {
// public:
//     vector<int> ans;
//     void inorder(TreeNode* root, int k){
//         if(root == NULL){
//             return;
//         }
//         inorder(root->left,k);
//         ans.push_back(root->val);
//         inorder(root->right,k);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         inorder(root,k);

//         return ans[k-1];
//     }
// };



/* Solution 2: Optimal Approach */
// Time Complexity: O(N) 
// Space Complexity: O(H)                    //  where H is the height of the binary search tree


// class Solution {
// public:
//     int cnt = 0;
//     int ans = 0;
//     void inorder(TreeNode* root, int k){
//         if(root == NULL){
//             return;
//         }
//         inorder(root->left,k);
//         cnt++;
//         if(cnt == k){
//             ans = root->val;
//             return;
//         }
//         inorder(root->right,k);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         inorder(root,k);

//         return ans;
//     }
// };


// (using vector)

#include<iostream>   
#include<vector>                                                    
using namespace std;                                                 //Time Complexity: O(N)
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

vector<int> ans;
void inorder(Node* root   ){                                    //Time Complexity: O(N)
    if(root == NULL){
        return;
    }
    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);
}

int kthSmallest(Node* root, int k){
    inorder(root);

    return ans[k-1];         // As there is 0 based indexing
}

int countNode(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    return countNode(root->left) + countNode(root->right) + 1;
}
int kthLargest(Node* root, int k){
    inorder(root);
    int count = countNode(root);

    return ans[count-k];         // As there is 0 based indexing      
}
int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->left->right = new Node(2);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

/* 
.                 5
.               /   \
.              3     7            
.             / \   / \
.            1   4 6   8
.             \   
.              2   
.
*/

    cout<<kthSmallest(root,3)<<endl;      // 3
    cout<<kthLargest(root,3)<<endl;      // 6


    return 0;
}

/* K-th Smallest */

// #include<iostream>                                                       
// using namespace std;                                                 //Time Complexity: O(N)
// struct Node                                                         //Space Complexity: O(N)
// {
//     int data;                                         
//     Node* left;
//     Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// int cnt = 0;
// int ans = 0;
 
// void inorder(Node* root, int k){                                
//     if(root == NULL){
//         return;
//     }
//     inorder(root->left,k);
//     cnt++;
//     if(cnt == k){
//         ans = root->data;
//     }
//     inorder(root->right,k);
// }

// int kthSmallest(Node* root, int k){
//     inorder(root,k);

//     return ans;
// }
// int main()
// {
//     Node* root = new Node(5);
//     root->left = new Node(3);
//     root->left->left = new Node(1);
//     root->left->right = new Node(4);
//     root->left->left->right = new Node(2);
//     root->right = new Node(7);
//     root->right->left = new Node(6);
//     root->right->right = new Node(8);

// /* 
// .                 5
// .               /   \
// .              3     7            ans = 3
// .             / \   / \
// .            1   4 6   8
// .             \   
// .              2   
// .
// */

//     cout<<kthSmallest(root,3)<<endl; 


//     return 0;
// }


/* K-th Largest */

// #include<iostream>                                                       
// using namespace std;                                                 //Time Complexity: O(N)
// struct Node                                                         //Space Complexity: O(N)    
// {
//     int data;                                         
//     Node* left;
//     Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// int cnt = 0;
// int ans = 0;

// int countNode(Node* root){
//     if (root == NULL)
//     {
//         return 0;
//     }
//     return countNode(root->left) + countNode(root->right) + 1;
// }

// void inorder(Node* root, int k, int count){                                    
//     if(root == NULL){
//         return;
//     }
//     inorder(root->left,k,count);
//     cnt++;
//     if(cnt == count-k+1){
//         ans = root->data;
//     }
//     inorder(root->right,k,count);
// }

// int kthLargest(Node* root, int k){
//     int count = countNode(root);
//     inorder(root,k,count);

//     return ans;
// }
// int main()
// {
//     Node* root = new Node(5);
//     root->left = new Node(3);
//     root->left->left = new Node(1);
//     root->left->right = new Node(4);
//     root->left->left->right = new Node(2);
//     root->right = new Node(7);
//     root->right->left = new Node(6);
//     root->right->right = new Node(8);

// /* 
// .                 5
// .               /   \
// .              3     7            ans = 3
// .             / \   / \
// .            1   4 6   8
// .             \   
// .              2   
// .
// */

//     cout<<kthLargest(root,3)<<endl; 


//     return 0;
// }





