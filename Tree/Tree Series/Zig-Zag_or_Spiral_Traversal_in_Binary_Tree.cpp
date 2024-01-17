// Time Complexity: O(N)   
// Space Complexity: O(N)


/* Leetcode Submission    (103. Binary Tree Zigzag Level Order Traversal) */



/* Solution 1: Using 2 stack */
// Time Complexity: O(N)   
// Space Complexity: O(N)


// class Solution{
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode *root){
//         vector<vector<int>> ans;
//         if (root == NULL){
//             return ans;
//         }
//         vector<int> vec;
//         stack<TreeNode*> currLevel;
//         stack<TreeNode*> nextLevel;

//         bool leftToRight = true;
//         currLevel.push(root);
//         while (!currLevel.empty()){
//             TreeNode* temp = currLevel.top();
//             currLevel.pop();

//             if (temp){
//                 vec.push_back(temp->val);

//                 if (leftToRight){
//                     if (temp->left){
//                         nextLevel.push(temp->left);
//                     }
//                     if (temp->right){
//                         nextLevel.push(temp->right);
//                     }
//                 }
//                 // Right To Left
//                 else{
//                     if (temp->right){
//                         nextLevel.push(temp->right);
//                     }
//                     if (temp->left){
//                         nextLevel.push(temp->left);
//                     }
//                 }
//             }
//             if (currLevel.empty()){
//                 leftToRight = !leftToRight;
//                 swap(currLevel, nextLevel); // reversing stack
//                 ans.push_back(vec);
//                 vec.clear();
//             }
//         }
//         return ans;
//     }
// };



/* Solution 2: Using 1 Queue */
// Time Complexity: O(N)   
// Space Complexity: O(N)


// class Solution{
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode *root){
//         vector<vector<int>> ans;
//         if (root == NULL){
//             return ans;
//         }

//         bool leftToRight = true;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int size = q.size();
//             vector<int> row(size);
//             for(int i = 0; i < size; i++){
//                 TreeNode* node = q.front();
//                 q.pop();

//                 // find position to fill node's value
//                 int index = (leftToRight) ? i : (size - 1 - i);
//                 row[index] = node->val;

//                 if(node->left){
//                     q.push(node->left);
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                 }
//             }
//             // after this level
//             leftToRight = !leftToRight;
//             ans.push_back(row);
//         }
//         return ans;
//     }
// };




#include<iostream>
#include<stack>
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

void zigzagTraversal(Node* root){
    if (root == NULL)
    {
        return;
    }
    
    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);
    while (!currLevel.empty())
    {
        Node* temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout<<temp->data<<" ";

            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            //Right To Left
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if (currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel,nextLevel);           //reversing stack
        }
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);


/*  
.              1 
.            /   \                   
.           2     3                 => 1 3 2 4 5 7 6    
.            \   /  \
.             4  3   8
.            / \ 
.           6   7  
.
*/ 

    zigzagTraversal(root);






    return 0;
}