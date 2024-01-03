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