/* Leetcode Submission    (100. Same Tree) */


/* Solution: */
// Time Complexity: O(N).
// Reason: We are doing a tree traversal.
// Space Complexity: O(N)
// Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).


// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p == NULL && q == NULL){
//             return true;
//         }
//         else if(p == NULL || q == NULL){
//             return false;
//         }
//         else{
//             bool cond1 = p->val == q->val;
//             bool cond2 = isSameTree(p->left,q->left);
//             bool cond3 = isSameTree(p->right,q->right);

//             return cond1 && cond2 && cond3;
//         }
//     }
// };




#include<iostream>
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

bool isIdentical(Node* root1, Node* root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        // if (cond1 && cond2 && cond3)
        // {
        //     return true;
        // }
        // return false;

        return cond1 && cond2 && cond3;
    }    
}
int main()
{
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

/*  
.             2 
.            /  \                   
.           1    3                                      
*/ 

    Node* root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);

/*  
.             2 
.            /  \                   
.           1    3                                      
*/ 

    if (isIdentical(root1,root2))
    {
        cout<<"BSTs are Identical"<<endl;
    }
    else
    {
        cout<<"BSTs are Not Identical"<<endl;
    }
    

    return 0;
}