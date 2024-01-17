/* Leetcode Submission    (199. Binary Tree Right Side View) */


/* Solution 1: Recursive Method */
// Time Complexity: O(N)   
// Space Complexity: O(H)       (H -> Height of the Tree)


// class Solution {                         
// public:
//     void recursion(TreeNode* root,int level, vector<int> &v){
//         if(root == NULL){
//             return;
//         }

//         if(level == v.size()){
//             v.push_back(root->val);
//         }

//         recursion(root->right,level+1,v);
//         recursion(root->left,level+1,v);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> v;
//         recursion(root,0,v);
        
//         return v;
//     }
// };




/* Solution 2: Iterative Method (Used Level Order Traversal) */
// Time Complexity: O(N)   
// Space Complexity: O(H)       (H -> Height of the Tree)


// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> v;
//         if(root == NULL){
//             return v;
//         } 

//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int n = q.size();
//             for(int i = 0; i < n; i++){
//                 TreeNode* curr = q.front();
//                 q.pop();
                
//                 if(i == n-1){
//                     v.push_back(curr->val);
//                 }
//                 if(curr->left != NULL){
//                     q.push(curr->left);
//                 }
//                 if(curr->right != NULL){
//                     q.push(curr->right);
//                 }
//             }
//         }

//         return v;
//     }
// };



/* 
              1           <-
            /   \
           2     3        <-               Right View
          / \   / \
         4   5 6   7      <-
              /
             8            <-

ans = 1 3 7 8
 */

// THERE ARE 2 METHODS :- 1) Iterative Method      2) Recursive Method

/*   Iterative Method (Used Level Order Traversal) */


#include<iostream>                              
#include<queue>
using namespace std;
class Node{
    public:
    int data; 
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void rightView(Node* root){          //Time Complexity: O(N)
    if (root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node* curr = q.front();
            q.pop(); 

            if (i == n-1)
            {
                cout<<curr->data<<" ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }            
        }
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);

    //Right View
    rightView(root); 
    cout<<endl;


    return 0;
}



// /*                   OR                    */

// /*   Recursive Method  */


// #include<iostream>                              
// #include<vector>
// using namespace std;
// class Node{
//     public:
//     int data; 
//     Node* left;
//     Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// void recursion(Node* root, int level,vector<int> &v){
//     if (root == NULL)
//     {
//         return;
//     }
//     if (level == v.size())
//     {
//         v.push_back(root->data);
//     }
//     recursion(root->right,level+1,v);
//     recursion(root->left,level+1,v);
// }
// vector<int> rightView(Node* root){          //Time Complexity: O(N)
//     vector<int> v;
//     recursion(root,0,v);

//     return v;
// }
// int main()
// {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);
//     root->right->left->left = new Node(8);

//     //Right View
//     vector<int> ans = rightView(root); 
//     for(auto i : ans){
//         cout<<i<<" ";
//     }
//     cout<<endl;


//     return 0;
// }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* 
            ->          1           
                      /   \
Left View   ->       2     3                       
                    / \   / \
            ->     4   5 6   7      
                        /
            ->         8            

ans = 1 2 4 8   
 */

// THERE ARE 2 METHODS :- 1) Iterative Method      2) Recursive Method

/*   Iterative Method (Used Level Order Traversal) */


// #include<iostream>
// #include<queue>
// using namespace std;
// class Node{
//     public:
//     int data; 
//     Node* left;
//     Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// void leftView(Node* root){                 //Time Complexity: O(N)
//     if (root == NULL)
//     {
//         return;
//     }

//     queue<Node*> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         int n = q.size();
//         for (int i = 0; i < n; i++)
//         {
//             Node* curr = q.front();
//             q.pop(); 

//             if (i == 0)
//             {
//                 cout<<curr->data<<" ";
//             }

//             if (curr->left != NULL)
//             {
//                 q.push(curr->left);
//             }

//             if (curr->right != NULL)
//             {
//                 q.push(curr->right);
//             }            
//         }
//     }
// }
// int main()
// {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);
//     root->right->left->left = new Node(8);

//     //Right View
//     leftView(root); 


//     return 0;
// }




/*                   OR                    */


/*   Recursive Method  */


// #include<iostream>                              
// #include<vector>
// using namespace std;
// class Node{
//     public:
//     int data; 
//     Node* left;
//     Node* right;

//     Node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// void recursion(Node* root, int level,vector<int> &v){
//     if (root == NULL)
//     {
//         return;
//     }

//     if (level == v.size())
//     {
//         v.push_back(root->data);
//     }

//     recursion(root->left,level+1,v);
//     recursion(root->right,level+1,v);
// }
// vector<int> leftView(Node* root){          //Time Complexity: O(N)
//     vector<int> v;
//     recursion(root,0,v);

//     return v;
// }
// int main()
// {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);
//     root->right->left->left = new Node(8);

//     //Right View
//     vector<int> ans = leftView(root); 
//     for(auto i : ans){
//         cout<<i<<" ";
//     }
//     cout<<endl;


//     return 0;
// }