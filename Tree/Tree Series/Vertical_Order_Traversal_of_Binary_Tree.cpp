/* 
In GFG it is If there are multiple nodes passing through a vertical line, 
then they should be printed as they appear in level order traversal of the tree 
EX :- 4                     (This example used in solution)
.     2 5
.     1 10 9 6
.     3
.     10
In Leetcode it is There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
EX :- 4                     (This example used in solution)
.     2 5
.     1 9 10 6                    here we sort 10 9 to 9 10
.     3
.     10
*/


/* (GFG SOLUTION)     
Given a binary tree, print it vertically
(Using Level Order Traversal) */


/* Solution: */
// Time complexity: O(N)
// space complexity: O(N)


// #include<bits/stdc++.h>
// using namespace std;
// struct Node
// {
//     int data;
//     Node* left;                                                        //Time Complexity: O(NlogN)
//     Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// void verticleOrder(Node* root){
//     map<int,vector<int>> m;
//     int hd = 0;

//     queue<pair<Node*,int>> q;             // root, hd
//     q.push(make_pair(root,hd));          // OR  q.push({(root,hd)})          {}       OR     make_pair
//     while(!q.empty()){
//         pair<Node*,int> temp = q.front();
//         q.pop();
//         hd = temp.second;
//         Node* node = temp.first;
            
//         m[hd].push_back(node->data);
            
//         if(node->left){
//             q.push(make_pair(node->left,hd-1));
//         }
//         if(node->right){
//             q.push(make_pair(node->right,hd+1));
//         }
//     }

//     for(auto it : m){
// 		for(auto i : it.second){
// 			cout<<i<<" ";
// 		}
// 		cout<<endl;
// 	}

//     /* OR */
//     // map<int,vector<int>> :: iterator it;
//     // for (it = m.begin(); it != m.end(); it++)
//     // {
//     //     for (int i = 0; i < it->second.size(); i++)
//     //     {
//     //         cout<<it->second[i]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
// }
// int main()
// {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->left->right = new Node(10);
//     root->left->left = new Node(4);
//     root->left->left->right = new Node(5);
//     root->left->left->right->right = new Node(6);  
//     root->right = new Node(3);
//     root->right->left = new Node(9);
//     root->right->right = new Node(10);

// /*
// .                1
// .             /     \
// .            2       3
// .          /  \     /  \
// .         4    10  9   10
// .          \        
// .           5      
// .            \    
// .             6  
// .
//   */

//     verticleOrder(root);


//     return 0;
// }



/* GFG Submission      (Vertical Traversal of Binary Tree) */  

/* Solution: */
// Time complexity: O(N)
// space complexity: O(N)


// class Solution
// {
//     public:
//     //Function to find the vertical order traversal of Binary Tree.
//     vector<int> verticalOrder(Node *root)
//     {
//         vector<int> ans;
//         if(root == NULL){
//             return ans;
//         }
        
//         map<int,vector<int>> m;         // hd, elements
//         int hd = 0;
//         queue<pair<Node*,int>> q;       // node, hd
//         q.push({root,hd});
//         while(!q.empty()){
//             pair<Node*,int> temp = q.front();
//             q.pop();
//             hd = temp.second;
//             Node* node = temp.first;
            
//             m[hd].push_back(node->data);
            
//             if(node->left){
//                 q.push(make_pair(node->left,hd-1));
//             }
//             if(node->right){
//                 q.push(make_pair(node->right,hd+1));
//             }
//         }
//         for(auto it : m){
//             for(auto i : it.second){
//                 ans.push_back(i);
//             }
//         }
//         //OR
//         // map<int,vector<int>> :: iterator it;
//         // for(it = m.begin(); it != m.end(); it++){
//         //     for(int i = 0; i < it->second.size(); i++){
//         //         ans.push_back(it->second[i]);
//         //     }
//         // }
//         return ans;
//     }
// };



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* (Leetcode SOLUTION)     
Given a binary tree, print it vertically
(Using Level Order Traversal) */

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;                                                                // Time Complexity: O(NlogN)
    Node *right;                                                              // Space Complexity: O(N)

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};         

// x = horizontal_Level
// y = vertical_Level
void traverse(Node* root, int x, int y,  map<int, multiset<pair<int,int>>> &m){
    if (root == NULL)
    {
        return;
    }
    m[x].insert({y,root->data});         // OR m[x].insert(make_pair(y,root->data));             {}  or make_pair

    traverse(root->left,x-1,y+1,m);
    traverse(root->right,x+1,y+1,m);
}
void verticleOrder(Node* root)
{
    map<int, multiset<pair<int,int>>> m;           // x , y , root->data
    traverse(root,0,0,m);


    for(auto it : m){
        for(auto i : it.second){
            cout<<i.second<<" ";
        }
        cout<<endl;
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
    .         4    10  9   10
    .          \
    .           5
    .            \
    .             6
    .
      */

    verticleOrder(root);

    return 0;
}



/* Leetcode Submission      (987. Vertical Order Traversal of a Binary Tree) */


/* Solution 1: Using Recursion */
// Time complexity: O(N * logN)
// space complexity: O(N)


// class Solution {
// public:
//     void traverse(TreeNode* root, int x, int y, map<int,multiset<pair<int,int>>> &m){
//         if(root == NULL){
//             return;
//         }
//         m[x].insert({y,root->val});         
        
//         traverse(root->left,x-1,y+1,m);
//         traverse(root->right,x+1,y+1,m);
//     }
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<vector<int>> ans;
//         map<int,multiset<pair<int,int>>> m;             // x , y , root->data
//         traverse(root,0,0,m);
        
//         for(auto it : m){
//             vector<int> v;
//             for(auto i : it.second){
//                 v.push_back(i.second);
//             }
//             ans.push_back(v);
//         }
//         return ans; 
//     }
// };

// // x = horizontal_Level
// // y = vertical_Level 



/* Solution 2: Using Queue */
// Time complexity: O(N * logN)
// space complexity: O(N)


// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<vector<int>> ans;
//         map<int,multiset<pair<int,int>>> m;             // x , y , root->data

//         queue<pair<TreeNode*, pair<int, int>>> q;          // node, x, y
//         q.push({root, {0, 0}});
//         while(!q.empty()){
//             auto temp = q.front();
//             q.pop();

//             TreeNode* node = temp.first;
//             int x = temp.second.first, y = temp.second.second;
//             m[x].insert({y, node->val});

//             if(node->left){
//                 q.push({node->left, {x-1, y+1}});
//             }
//             if(node->right){
//                 q.push({node->right, {x+1, y+1}});
//             }
//         }

//         for(auto it : m){
//             vector<int> v;
//             for(auto i : it.second){
//                 v.push_back(i.second);
//             }
//             ans.push_back(v);
//         }
//         return ans; 
//     }
// };

// // x = horizontal_Level
// // y = vertical_Level 
