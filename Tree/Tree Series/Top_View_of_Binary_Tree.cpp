/* GFG Submission    (Top View of Binary Tree) */


/* Solution: 
Intuition:  We can mark straight lines like in the image below and mark them with +ve and -ve indexes. 
The first node of every line will be my top view. */

// Time Complexity: O(N)   
// Space Complexity: O(N)


// class Solution
// {
//     public:
//     //Function to return a list of nodes visible from the top view 
//     //from left to right in Binary Tree.
//     vector<int> topView(Node *root)
//     {
//         vector<int> ans;
//         if(root == NULL){
//             return ans;
//         }

//         map<int,int> m;                                // line, node->data
//         queue<pair<Node*,int>> q;                      // node, line
//         q.push({root,0});                        
//         while(!q.empty()){
//             pair<Node*,int> it = q.front();
//             q.pop();
            
//             Node* node = it.first;
//             int line = it.second;
            
//             if(m.find(line) == m.end()){
//                 m[line] = node->data;
//             }
            
//             if(node->left){
//                 q.push({node->left,line-1});
//             }
//             if(node->right){
//                 q.push({node->right,line+1});
//             }
//         }

//         for(auto it : m){
//             ans.push_back(it.second);
//         }
        
//         return ans;
//     }
// };


/* Another approach also exist where we use recursion. Thier we have to introduce the logic of height */

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;                                                                // Time Complexity: O(N)
    Node *right;                                                              // Space Complexity: O(N)

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};         

void topView(Node* root){
    if (root == NULL)
    {
        return;
    }
    map<int,int> m;               // line , root->data
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while (!q.empty())
    {
        pair<Node*,int> it = q.front();           // OR    auto it = q.front();
        q.pop();

        Node* node = it.first;
        int line = it.second;

        if (m.find(line) == m.end())     //It checks if line is already exist in map m
        {
            m[line] = node->data;
        }
        
        if (node->left)
        {
            q.push({node->left,line-1});
        }
        if (node->right)
        {
            q.push({node->right,line+1});
        }
    }
    for(auto it : m){
        cout<<it.second<<" ";
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(10);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    /*
    .                1
    .             /     \
    .            2       3
    .          /  \     /  \
    .         4    10  9   10             // 4 2 1 3 10 
    .          \
    .           5
    .            \
    .             6
    .
      */

    topView(root);

    return 0;
}