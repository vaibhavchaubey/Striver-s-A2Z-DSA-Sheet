/* The only difference between a struct and class in C++ is the default accessibility of 
member variables and methods. In a struct they are public; in a class they are private. */


//Here we use class

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int main()
{
    node* root = new node(1);
    /* following is the tree after above statement
 
             1
            / \
          NULL NULL
    */
    root->left = new node(2);
    root->right = new node(3);
    /* 2 and 3 become left and right children of 1
                    1
                  /    \
                 2       3
               /  \     /  \
            NULL NULL  NULL NULL
    */
    root->left->left = new node(4);
    root->left->right = new node(5);
    /* 4 and 5 become left and right children of 2
               1
            /     \
           2       3
          / \     / \
         4   5   NULL NULL
        / \
     NULL NULL
    */
    

    return 0;
}



//Here we use struct

// #include<iostream>
// using namespace std;
// struct node{
//     int data;
//     struct node* left;
//     struct node* right;

//     node(int val){
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// int main()
// {
//     struct node* root = new node(1);
//     root->left = new node(2);
//     root->right = new node(3);
//     root->left->left = new node(4);
//     root->left->right = new node(5);
    

//     return 0;
// }