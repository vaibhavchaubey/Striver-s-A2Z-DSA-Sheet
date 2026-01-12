/* Leetcode Submission  (297. Serialize and Deserialize Binary Tree)   same code for (449. Serialize and Deserialize BST)  */

/* Problem Statement: Serialization is the process of converting a data structure or object into a sequence of bits so that
it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in
the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization
algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized
to the original tree structure.
Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow
this format, so please be creative and come up with different approaches yourself.
*/

/*
Serialize =   Tree -> String
Deserialize = String -> Tree
*/

/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(N)

// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if(root == NULL){
//             return "";
//         }

//         string s = "";
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* node = q.front();
//             q.pop();

//             if(node == NULL){
//                 s.append("#,");
//             }
//             else{
//                 s.append(to_string(node->val) + ',');
//             }
//             if(node != NULL){
//                 q.push(node->left);
//                 q.push(node->right);
//             }
//         }

//         return s;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if(data.size() == 0){
//             return NULL;
//         }

//         // Creates a stream object s from the string data
//         stringstream s(data);
//         string str;

//         // Read characters from s
//         // Stop when ',' is encountered
//         // Store the result in str
//         // Move the stream pointer forward
//         getline(s,str,',');

//         TreeNode* root = new TreeNode(stoi(str));
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* node = q.front();
//             q.pop();

//             getline(s,str,',');
//             if(str == "#"){
//                 node->left = NULL;
//             }
//             else{
//                 TreeNode* leftNode = new TreeNode(stoi(str));
//                 node->left = leftNode;
//                 q.push(leftNode);
//             }

//             getline(s,str,',');
//             if(str == "#"){
//                 node->right = NULL;
//             }
//             else{
//                 TreeNode* rightNode = new TreeNode(stoi(str));
//                 node->right = rightNode;
//                 q.push(rightNode);
//             }
//         }

//         return root;
//     }
// };

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
struct Node
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

string serialize(Node *root)
{
    if (root == NULL)
    {
        return "";
    }
    string s = "";
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node == NULL)
        {
            s.append("#,");
        }
        else
        {
            s.append(to_string(node->data) + ',');
        }

        if (node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

Node *deserialize(string data)
{
    if (data.size() == 0)
    {
        return NULL;
    }
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node *root = new Node(stoi(str));
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
        {
            node->left = NULL;
        }
        else
        {
            Node *leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if (str == "#")
        {
            node->right = NULL;
        }
        else
        {
            Node *rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    // /*
    // .                1
    // .               / \
// .              2   3
    // .                 / \
// .                4   5
    // .
    // . */

    inorder(root);
    cout << endl;

    string s = serialize(root);
    cout << s << endl;

    Node *root1 = deserialize(s);
    inorder(root1);
    cout << endl;

    //     /*OUTPUT
    //     2 1 4 3 5
    //     1,2,3,#,#,4,5,#,#,#,#,
    //     2 1 4 3 5
    //     */

    return 0;
}
