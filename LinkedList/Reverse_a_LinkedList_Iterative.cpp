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

