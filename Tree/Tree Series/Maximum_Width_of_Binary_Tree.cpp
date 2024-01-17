/* Leetcode Submission    (662. Maximum Width of Binary Tree) */


/* QUESTION 
Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes are also counted into the length calculation. */


/* Solution: */
// Time complexity: O(N)
// Space complexity: O(N)

/* IMP NOTE: 
If you are getting runtime error while submiting the same code on leetcode,no need to worry,just do a minute change in the code,
just typecast the value of index while pushing in the queue.You may ask since we applied a trick to tackle the integer overflow 
here,yes we did,but through this method we just ensure that the index we push everytime just comes under INT_MAX,and index difference 
is always under singed 32 bit ,i.e at max below 2^32 as stated in question itself. 
At everytime we are pushing (2*index+1) or (2*index+2),so its not exactly twice,its getting more than that ,thats why we need to 
typecast with long long.Hope its clear now. That's why we use     (long long)cur_id*2+1    (long long)cur_id*2+2  */



// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }

//         int ans = 0;
//         queue<pair<TreeNode*,int>> q;
//         q.push({root,0});                 // root, index
//         while(!q.empty()){
//             int size = q.size();
//             int min = q.front().second;
//             int first, last;
//             for(int i = 0; i < size; i++){
//                 int cur_id = q.front().second - min;
//                 TreeNode* node = q.front().first;
//                 q.pop();

//                 if(i == 0) first = cur_id;
//                 if(i == size-1) last = cur_id;
//                 if(node->left){
//                     q.push({node->left,(long long)cur_id*2+1});
//                 }
//                 if(node->right){
//                     q.push({node->right,(long long)cur_id*2+2});
//                 }
//             }
//             ans = max(ans,last-first+1);
//         }
//         return ans;
//     }
// };



#include<iostream>
#include<queue>
using namespace std;
struct Node
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

int widthOfBinaryTree(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while (!q.empty())
    {
        int size = q.size();
        int min = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int cur_id = q.front().second - min;
            Node* node = q.front().first;
            q.pop();
            if(i == 0) first = cur_id;
            if(i == size-1) last = cur_id;
            if (node->left)
            {
                q.push({node->left,cur_id*2+1});
            }
            if (node->right)
            {
                q.push({node->right,cur_id*2+2});
            }
        }
        ans = max(ans,last-first+1);
    }
    return ans;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->right->right = new Node(4);

/* 
.               1
.              / \
.             3   7             ans = 4
.            /     \
.           8       4
.
. */



    cout<<widthOfBinaryTree(root)<<endl;


    return 0;
}






