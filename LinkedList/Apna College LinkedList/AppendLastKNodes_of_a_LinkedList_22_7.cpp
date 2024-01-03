#include <iostream>
using namespace std;
class node
{
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
{ // Time Complexity: O(N)
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
int length(node *head)
{

    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
node *kappend(node *&head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }
    node *newHead;
    node *newTail;
    node *tail = head;

    int l = length(head);
    k = k % l; // When k > l

    if (k == 1)
    {
        while (tail->next->next != NULL)
        {
            tail = tail->next;
        }
        tail->next->next = head;
        newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }

    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}
int main()
{
    node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);
    node *newHead = kappend(head, 3); // Here 3 is number of nodes to append
    display(newHead);

    return 0;
}


/* Leetcode  Submission          (61. Rotate List)  */

/* Problem Statement: Given the head of a linked list, rotate the list to the right by k places.
(Append last k nodes) */



/* Solution 1: Brute Force     (It will give TLE)
Approach: We have to move the last element to first for each k. For each k, find the last element from the list. Move it to the first.

Time Complexity: O(N * k)
Reason: For k times, we are iterating through the entire list to get the last element and move it to first.
Space Complexity: O(1) */


// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k == 0){
//             return head;
//         }

//         for(int i = 0; i < k; i++){
//             ListNode* temp = head;
//             while(temp->next->next != NULL){
//                 temp = temp->next;
//             }
//             ListNode* end = temp->next;
//             temp->next = NULL;
//             end->next = head;
//             head = end;
//         }

//         return head;
//     }
// };



/* Solution 2: Optimal Solution
Approach: We can see that for every k which is multiple of the length of the list, we get back the original list. 
Try to operate brute force on any linked list for k as multiple of the length of the list.
This gives us a hint that for k greater than the length of the list, we have to rotate the list for k%length of the list. T
his reduces our time complexity.

Time Complexity: O(N) + O(N – (N%k))
Reason: O(length of the list) for calculating the length of the list. O(length of the list – (N%k)) for breaking link.
Space Complexity: O(1) */


// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k == 0){
//             return head;
//         }

//         ListNode* temp = head;
//         int l = 1;
//         while(temp->next != NULL){
//             l++;
//             temp = temp->next;
//         }

//         temp->next = head;            //link last node to first node
//         k = k % l;                   //If k > l
//         int end = l-k;              //to get end of the list
//         while(end--){
//             temp = temp->next;
//         }
//         head = temp->next;        //breaking last node link and pointing to NULL
//         temp->next = NULL;
        
//         return head;    
//     }
// };


//OR

// class Solution {
// public:
//     int length(ListNode* head){
//         ListNode* temp = head;
//         int l = 0;
//         while(temp != NULL){
//             l++;
//             temp = temp->next;
//         }
//         return l;
//     }
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k == 0){
//             return head;
//         }
//         ListNode* newHead = NULL;
//         ListNode* newTail = NULL;
//         ListNode* temp = head;
        
//         int l = length(head);
//         k = k % l;                  //If k > l
        
//         if(k == 1){
//             while(temp->next->next != NULL){
//                 temp = temp->next;
//             }
//             temp->next->next = head;
//             newHead = temp->next;
//             temp->next = NULL;
//             return newHead;
//         }
        
//         int count = 1;
//         while(temp->next != NULL){
//             if(count == l-k){
//                 newTail = temp;
//             }
//             if(count == l-k+1){
//                 newHead = temp;
//             }
//             temp = temp->next;
//             count++;
//         }
//         newTail->next = NULL;
//         temp->next = head;

//         return newHead;
//     }
// };
