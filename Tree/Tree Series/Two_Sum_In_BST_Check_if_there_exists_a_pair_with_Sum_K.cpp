/* Leetcode Submission    (653. Two Sum IV - Input is a BST) */

/* Problem Statement: he root of a binary search tree and an integer k, return true if there exist two elements 
in the BST such that their sum is equal to k, or false otherwise. */



/* Solution 1: We find inorder and store it in vector */
// Time complexity: O(N) + O(N) 
// Space complexity: O(N)


// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int> &v){
//         if(root == NULL){
//             return;
//         }
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
//     bool findTarget(TreeNode* root, int k) {
//         vector<int> v;
//         inorder(root,v);
        
//         int i = 0;
//         int j = v.size()-1;
//         while(i < j){
//             int sum = v[i] + v[j];
//             if(sum == k){
//                 return true;
//             }
//             else if(sum > k){
//                 j--;
//             }
//             else{
//                 i++;
//             }
//         }

//         return false;
//     }
// };




/* Solution 2: Here we use BSTIterator */
// Time complexity: O(N) 
// Space complexity: O(H) + O(H)


// class BSTIterator{
//     stack<TreeNode*> st;
//     bool reverse = true;
//     public:
//     BSTIterator(TreeNode* root, bool isReverse){
//         reverse = isReverse;
//         pushAll(root);
//     }
    
//     bool hasNext(){
//         return !st.empty();
//     }
    
//     int next(){
//         TreeNode* temp = st.top();
//         st.pop();
//         if(reverse == false){           //increasing order
//             pushAll(temp->right);
//         } 
//         else{
//             pushAll(temp->left);       //decreasing order
//         } 
//         return temp->val;
//     }
    
// private:
//     void pushAll(TreeNode* node){
//         while(node != NULL){
//             st.push(node);
//         if(reverse == true){               //decreasing order
//                 node = node->right;
//             }
//                 else{                     //increasing order
//                 node = node->left;
//             }
//         }
//     }
// };
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         if(root == NULL){
//             return false;
//         }
//         BSTIterator l(root,false);       // next
//         BSTIterator r(root,true);        // before
        
//         int i = l.next();
//         int j = r.next();
        
//         while(i < j){
//             if(i+j == k){
//                 return true;
//             } 
//             else if(i+j < k){
//                 i = l.next();
//             } 
//             else{
//                 j = r.next();
//             } 
//         }
//         return false;
//     }
// };



/* Method 1     TC: O(N)   SC: O(N) */

#include <iostream>
#include <vector>
using namespace std;                                // Time Complexity: O(N) + O(N) => O(N)
struct Node                                        // Space Complexity: O(N)
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool findTarget(Node *root, int k)
{
    vector<int> v;
    inorder(root, v);

    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == k)
        {
            return true;
        }
        else if (sum > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(6);
    root->right->right = new Node(7);

    /*
    .                5
    .               / \
    .              3   6            ans = 4 2 5 6 1 3
    .             / \   \
    .            2   4   7
    .                 
    */

    int k = 9;
    if(findTarget(root,k)){
        cout<<"There exist two elements"<<endl;
    }
    else{
        cout<<"There doesn't exist two elements"<<endl;
    }


    return 0;
}



/* Method 2     TC: O(N)   SC: O(H) */

// #include <iostream>
// #include <stack>
// using namespace std;                            // Time Complexity: O(N)
// struct Node                                    // Space Complexity: O(H)
// {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// class BSTIterator
// {
//     stack<Node*> st;                          
//     bool reverse = true;

// public:
//     BSTIterator(Node *root, bool isReverse)
//     {
//         reverse = isReverse;
//         pushAll(root);
//     }

//     bool hasNext()
//     {
//         return !st.empty();
//     }

//     int next()
//     {
//         Node *temp = st.top();
//         st.pop();
//         if (!reverse)
//             pushAll(temp->right);
//         else
//             pushAll(temp->left);
//         return temp->data;
//     }

// private:
//     void pushAll(Node *node)
//     {
//         while (node != NULL)
//         {
//             st.push(node);
//             if (reverse == true)
//             {
//                 node = node->right;
//             }
//             else
//             {
//                 node = node->left;
//             }
//         }
//     }
// };

// bool findTarget(Node *root, int k)
// {
//     if (root == NULL)
//     {
//         return false;
//     }
//     BSTIterator l(root, false);
//     BSTIterator r(root, true);

//     int i = l.next();
//     int j = r.next();

//     while (i < j)
//     {
//         if (i + j == k)
//             return true;
//         else if (i + j < k)
//             i = l.next();
//         else
//             j = r.next();
//     }
//     return false;
// }

// int main()
// {
//     Node *root = new Node(5);
//     root->left = new Node(3);
//     root->left->left = new Node(2);
//     root->left->right = new Node(4);
//     root->right = new Node(6);
//     root->right->right = new Node(7);

//     /*
//     .                5
//     .               / \
//     .              3   6            ans = 4 2 5 6 1 3
//     .             / \   \
//     .            2   4   7
//     .
//     */

//     int k = 9;
//     if (findTarget(root, k))
//     {
//         cout << "There exist two elements" << endl;
//     }
//     else
//     {
//         cout << "There doesn't exist two elements" << endl;
//     }

//     return 0;
// }





