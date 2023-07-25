/* Leetcode  Submission    (876. Middle of the Linked List) */

/* Problem Statement: Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node. */


/* Solution:  (Tortoise-Hare-Approach)   (Slow and Fast Pointer Method)  */
// Time Complexity: O(N/2) ~ O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         return slow;
//     }
// };

