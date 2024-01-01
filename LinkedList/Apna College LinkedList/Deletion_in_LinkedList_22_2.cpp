#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if (head==NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;   
}
void display(node* head){
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;    
}
void deleteAtHead(node* &head){         //When we want to delete the 1st element of the list
    node* todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(node* &head, int val){
    if (head==NULL)                   //Corner case - when there is no element in the list
    {
        return;
    }
    if (head->next==NULL)            //Corner case - when there only 1 element in the list
    {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    while (temp->next->data!=val)    //When we want to delete any element of the list(not 1st element)
    {
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);

    deletion(head,3);                 //Here 3 is val   //To delete any of the given element
    display(head);

    // deleteAtHead(head);             //To delete 1st element
    // display(head);


    return 0;
}

//IMPORTANT

/* In above code when we want to delete an element, we come at one position before then node which was to be deleted
and then from here we point to the next element of the node to be deleted  */


/* Here we are given access to the node to be deleted directly */


// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//     //we copy the value of next varibale and move the pointer to next
//     //also remove the node so to escape memory leak
        
//        ListNode* temp = node->next;
//         node->val = node->next->val;
//         node->next = node->next->next;
//         delete temp;
//     }
// };

