/* There are two methods to Reverse a Linked List : */

//1) Iterative

// #include<iostream>
// using namespace std;
// class node{
//     public:
//     int data; 
//     node* next;

//     node(int val){
//         data = val;
//         next = NULL;
//     }
// };
// void insertAtTail(node* &head, int val){
//     node* n = new node(val);

//     if (head==NULL)
//     {
//         head=n;
//         return;
//     }
    
//     node* temp=head;
//     while(temp->next!=NULL){
//         temp = temp->next;
//     }
//     temp->next = n;
// }
// void display(node* head){
//     node* temp=head;
//     while (temp!=NULL)
//     {
//         cout<<temp->data<<"->";
//         temp = temp->next;
//     }
//     cout<<"NULL"<<endl;                                                             
// }
// node* reverse(node* &head){
//     node* prevptr = NULL;
//     node* currptr = head;
//     node* nextptr;
//     while (currptr!=NULL)
//     {
//         nextptr = currptr->next;
//         currptr->next = prevptr;

//         prevptr = currptr;
//         currptr = nextptr;
//     }
//     return prevptr;
// }

// int main(){
//     node* head=NULL;
//     insertAtTail(head,1);
//     insertAtTail(head,2);
//     insertAtTail(head,3);
//     insertAtTail(head,4);
//     display(head);
//     node* newhead = reverse(head);
//     display(newhead);
    
//     return 0;
// }



//2) Recursive

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
void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if (head==NULL)
    {
        head=n;
        return;
    }
    
    node* temp=head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;                                                             
}
node* reverseRecursive(node* &head){
    if (head==NULL || head->next==NULL)              // No element || 1 element
    {
        return head;
    }
    
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    node* newhead = reverseRecursive(head);
    display(newhead);
    
    return 0;
}



/* Leetcode  Submission    (206. Reverse Linked List) */

/* Problem Statement: Given the head of a singly linked list, reverse the list, and return the reversed list. */


/* Solution 1:  Iterative     */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prevptr = NULL;
//         ListNode* currptr = head;
//         ListNode* nextptr;
//         while(currptr != NULL){
//             nextptr = currptr->next;
//             currptr->next = prevptr;
            
//             prevptr = currptr;
//             currptr = nextptr;
//         }
        
//         return prevptr;
//     }
// };



/* Solution 2:  Recursive     */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
//         ListNode* newhead = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
        
//         return newhead;
//     }
// };

