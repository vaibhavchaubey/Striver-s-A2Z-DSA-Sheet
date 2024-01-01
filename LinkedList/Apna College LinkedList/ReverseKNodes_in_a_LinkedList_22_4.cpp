#include <iostream>
using namespace std;
class node
{ // Time Complexity: O(N)
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
node *reversek(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    node *check;
    check = currptr;
    int count = 1;
    while (check->next != NULL && count <= k)
    {
        count++;
        check = check->next;
    }
    if (count < k)
    {
        return head;
    }
    count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reversek(nextptr, k);
    }
    return prevptr;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    int k = 2;
    node *newhead = reversek(head, k);
    display(newhead);

    return 0;
}


/* RELATED QUESTION - (25. Reverse Nodes in k-Group) */

// class Solution {
// public:
//     int length(ListNode* head){
//         int l = 0;
//         ListNode* temp = head;
//         while(temp != NULL){
//             l++;
//             temp = temp->next;
//         }
//         return l;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k == 1){
//             return head;
//         }

//         int l = length(head);

//         ListNode* dummyNode = new ListNode(0);
//         dummyNode->next = head;

//         ListNode* prevptr = dummyNode;
//         ListNode* currptr;
//         ListNode* nextptr;

//         while(l >= k){
//             currptr = prevptr->next;
//             nextptr = currptr->next;
//             for(int i = 1; i < k; i++){
//                 currptr->next = nextptr->next;
//                 nextptr->next = prevptr->next;
//                 prevptr->next = nextptr;
//                 nextptr = currptr->next;
//             }
//             prevptr = currptr;
//             l -= k;
//         }

//         return dummyNode->next;
//     }
// };


/* OR */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k == 1){
//             return head;
//         } 
        
//         ListNode* prevptr = NULL;
//         ListNode* currptr = head;
//         ListNode* nextptr;
//         ListNode* check = currptr;
//         int count = 1;
        
//         while(check->next != NULL && count <= k){
//             count++;
//             check = check->next;
//         }
//         if(count < k){
//             return head;
//         }
        
//         count = 0;
//         while(currptr != NULL && count < k){
//             nextptr = currptr->next;
//             currptr->next = prevptr;
            
//             prevptr = currptr;
//             currptr = nextptr;
//             count++;
//         }
        
//         if(nextptr != NULL){
//             head->next = reverseKGroup(nextptr,k);
//         }
        
//         return prevptr;
//     }
// };



/* Sort a Linked List */
/* 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        ListNode* curr = dummy;
        for(int i = 0; i < v.size(); i++){
            curr->next = new ListNode(v[i]);
            curr = curr->next;
        }
        return dummy->next;
    }
};
 */