/* Iterative Method */

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next= NULL;
    }
};
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
node* merge(node* &head1, node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode = new node(-1);
    node* p3=dummyNode;
    while (p1!=NULL && p2!=NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
           p3->next = p2;
           p2 = p2->next;
        }
        p3 = p3->next;
    }
    if (p1!=NULL)
    {
        p3->next = p1;
    }
    if (p2!=NULL)
    {
        p3->next = p2;
    }

    return dummyNode->next;
}
int main()
{
    node* head1=NULL;
    node* head2=NULL;
    int arr1[] = {1,4,5,7};
    int arr2[] = {2,3,6};
    for (int i = 0; i < 4; i++)
    {
        insertAtTail(head1,arr1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        insertAtTail(head2,arr2[i]);
    }
    display(head1);
    display(head2);
    node* newHead = merge(head1,head2);
    display(newHead);

    return 0;
}



/* Recursive Method */

// #include <iostream>
// using namespace std;
// class node
// {
// public:
//     int data;
//     node *next;

//     node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };
// void insertAtTail(node *&head, int val)
// {
//     node *n = new node(val);
//     if (head == NULL)
//     {
//         head = n;
//         return;
//     }
//     node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = n;
// }
// void display(node *head)
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << "->";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
// }
// node *mergeRecursive(node *&head1, node *&head2)
// {
//     if (head1 == NULL)
//     {
//         return head2;
//     }
//     if (head2 == NULL)
//     {
//         return head1;
//     }
//     node *result;
//     if (head1->data < head2->data)
//     {
//         result = head1;
//         result->next = mergeRecursive(head1->next, head2);
//     }
//     else
//     {
//         result = head2;
//         result->next = mergeRecursive(head1, head2->next);
//     }

//     return result;
// }
// int main()
// {
//     node *head1 = NULL;
//     node *head2 = NULL;
//     int arr1[] = {1, 4, 5, 7};
//     int arr2[] = {2, 3, 6};
//     for (int i = 0; i < 4; i++)
//     {
//         insertAtTail(head1, arr1[i]);
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         insertAtTail(head2, arr2[i]);
//     }
//     display(head1);
//     display(head2);
//     node *newHead = mergeRecursive(head1, head2);
//     display(newHead);

//     return 0;
// }



/* Leetcode Submission          (21. Merge Two Sorted Lists)    */

/* Problem Statement: You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list. */


/* Solution 1: Using an externally linked list to store answers

Time Complexity: O(N+M).
Let N be the number of nodes in list l1 and M be the number of nodes in list l2. We have to iterate through both lists. So, the total time complexity is O(N+M).
Space Complexity: O(N+M).
We are creating another linked list that contains the (N+M) number of nodes in the list. So, space complexity is O(N+M). */

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL) return list2;
//         if(list2 == NULL) return list1;
//         ListNode* p1 = list1;
//         ListNode* p2 = list2;
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* p3 = dummyNode;
//         while(p1 != NULL && p2 != NULL){
//             if(p1->val < p2->val){
//                 p3->next = p1;
//                 p1 = p1->next;
//             }
//             else{
//                 p3->next = p2;
//                 p2 = p2->next;
//             }
//             p3 = p3->next;
//         }
//         if(p1 != NULL){
//             p3->next = p1;
//         }
//         else{
//             p3->next = p2;
//         }

//         return dummyNode->next;
//     }
// };


/* Solution 2: Inplace method without using extra space.

Time Complexity: O(N+M)
Let N be the number of nodes in list l1 and M be the number of nodes in list l2. We have to iterate through both lists. So, the total time complexity is O(N+M).
Space Complexity: O(1)
We are using the same lists just changing links to create our desired list. So no extra space is used. 
Hence, its space complexity is O(1).  */

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL) return list2;
//         if(list2 == NULL) return list1;
//         if(list1->val > list2->val) swap(list1,list2);
//         ListNode* res = list1;
//         while(list1 != NULL && list2 != NULL){
//             ListNode* temp = NULL;
//             while(list1 != NULL && list1->val <= list2->val){
//                 temp = list1;
//                 list1 = list1->next;
//             }
//             temp->next = list2;
//             swap(list1,list2);
//         }
        
//         return res;
//     }
// };

