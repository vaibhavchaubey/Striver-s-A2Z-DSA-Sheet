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
void insertAtTail(node* &head, int val){                    //Time Complexity: O(N)
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
void evenAfterOdd(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;

    while (odd->next!=NULL && even->next!=NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
}
int main()
{
    node* head=NULL;
    int arr[]={1,2,3,4,5,6,7};
    for (int i = 0; i < 7; i++)
    {
        insertAtTail(head,arr[i]);
    }
    display(head);
    evenAfterOdd(head);
    display(head);

    return 0;
}


/* Leetcode Submission  (328. Odd Even Linked List) */

// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(head == NULL || head->next==NULL){
//             return head;
//         }
        
//         ListNode* odd = head;
//         ListNode* even = head->next;
//         ListNode* evenStart = even;
//         while(odd->next!=NULL && even->next!=NULL){
//             odd->next = even->next;
//             odd = odd->next;
//             even->next = odd->next;
//             even = even->next;
//         }
//         odd->next = evenStart;
        
//         return head;
//     }
// };




/* Leetcode Submission          (2. Add Two Numbers)  */

/* Problem Statement: You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */


/* Solution: */
// Time Complexity : O(max(l1,l2))
// Space Complexity : O(max(l1,l2))


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummyNode = new ListNode(0);
//         ListNode* curr = dummyNode;
//         int carry = 0;
//         while(l1 != NULL || l2 != NULL || carry != 0){
//             int sum = 0;
//             if(l1 != NULL){
//                 sum += l1->val;
//                 l1 = l1->next;
//             }
//             if(l2 != NULL){
//                 sum += l2->val;
//                 l2 = l2->next;
//             }
//             sum += carry;
//             carry = sum/10;                           //if 9+9=18 it will give 1
//             curr->next = new ListNode(sum % 10);     //if 9+9=18 it will give 8
//             curr = curr->next;
//         }

//         return dummyNode->next;
//     }
// };



/* Leetcode Submission          (445. Add Two Numbers II)   (Here digits are in correct order)  */

/* Problem Statement: You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */


/* Solution: */
// Time Complexity : O(m+n)              // Here, m and n are is the number of nodes in l1 and l2 respectively
// Space Complexity : O(m+n)


// class Solution {
// public:
//     ListNode* reverse(ListNode* l){
//         ListNode* prevptr = NULL;
//         ListNode* currptr = l;
//         ListNode* nextptr;
//         while(currptr != NULL){
//             nextptr = currptr->next;
//             currptr->next = prevptr;
//             prevptr = currptr;
//             currptr = nextptr;
//         }
//         return prevptr;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummyHead = new ListNode(0);
//         ListNode* p = reverse(l1); 
//         ListNode* q = reverse(l2); 
//         ListNode* curr = dummyHead;
//         int carry = 0;
//         while(p!=NULL || q!=NULL || carry != 0){
//             int sum = 0;
//             if(p != NULL){
//                 sum += p->val;
//                 p = p->next;
//             }
//             if(q != NULL){
//                 sum += q->val;
//                 q = q->next;
//             }
//             sum += carry;
//             carry = sum/10;                           //if 9+9=18 it will give 1
//             curr->next = new ListNode(sum % 10);     //if 9+9=18 it will give 8
//             curr = curr->next;
//         }

//         ListNode* ptr = reverse(dummyHead->next);
//         return ptr;
//     }
// };