/* 
              1
            /   \
           2     3
          / \   / \
         4   5 6   7

Preorder (root,left,right)    Ex:- 1 2 4 5 3 6 7
Inorder (left,root,right)     Ex:- 4 2 5 1 6 3 7
Postorder (left,right,root)   Ex:- 4 5 2 6 7 3 1
*/

// Time Complexity: O(3N)
// Space Complexity: O(4N) 

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preInPostTraversal(struct Node* root){
    stack<pair<Node*,int>> st;
    st.push({root,1});
    vector<int> pre, in, post;
    if (root == NULL){
        return;
    }

    while (!st.empty()){
        auto it = st.top();
        st.pop();
        // this is part of pre
        // increment 1 to 2
        // push the left side of the tree
        if (it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left){
                st.push({it.first->left, 1});
            }
        }
        // this is a part of in
        // increment 2 to 3
        // push right
        else if (it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right){
                st.push({it.first->right, 1});
            }
        }
        // don't push it back again
        else{
            post.push_back(it.first->data);
        }
    }

    //Now printing Preorder, Inorder nad Postorder

    cout<<"Preorder Traversal: ";
    for(auto it : pre){
        cout<<it<<" ";
    }
    cout<<endl<<"Inorder Traversal: ";
    for(auto it : in){
        cout<<it<<" ";
    }
    cout<<endl<<"Postorder Traversal: ";
    for(auto it : post){
        cout<<it<<" ";
    }
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    preInPostTraversal(root);   


    return 0;
}


/* Codestudio Submission          (Tree Traversals)  */

/* Problem Statement: You have been given a Binary Tree of 'N'
nodes, where the nodes have integer values.
Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree. */


/* Solution: */
// Time Complexity : O(3N)
// Space Complexity : O(4N)


// vector<vector<int>> getTreeTraversal(TreeNode *root){
//     vector<vector<int>> ans;
//     if(root == NULL){
//         return ans;
//     }

//     vector<int> preorder, inorder, postorder;
//     stack<pair<TreeNode*, int>> st;
//     st.push({root, 1});

//     while(!st.empty()){
//         auto it = st.top();
//         st.pop();

//         // this is part of pre
//         // increment 1 to 2
//         // push the left side of the tree
//         if(it.second == 1){
//             preorder.push_back(it.first->data);
//             it.second++;
//             st.push(it);

//             if(it.first->left){
//                 st.push({it.first->left, 1});
//             }
//         }

//         // this is a part of in
//         // increment 2 to 3
//         // push right
//         else if(it.second == 2){
//             inorder.push_back(it.first->data);
//             it.second++;
//             st.push(it);

//             if(it.first->right){
//                 st.push({it.first->right, 1});
//             }
//         }

//         // don't push it back again
//         else{
//             postorder.push_back(it.first->data);
//         }
//     }

//     // return {inorder, preorder, postorder};

//     /* OR */

//     ans.push_back(inorder);
//     ans.push_back(preorder);
//     ans.push_back(postorder);


//     return ans;
// }