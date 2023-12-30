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