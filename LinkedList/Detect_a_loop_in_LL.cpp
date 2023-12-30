/* Leetcode  Submission    (141. Linked List Cycle) */

/* Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously 
following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false. */


/* Solution 1:  Hashing     */
// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_set<ListNode*> hash;
//         ListNode* temp = head;
//         while(temp != NULL){
//             if(hash.count(temp)){
//                 return true;
//             }
//             hash.insert(temp);
//             temp = temp->next;
//         }
        
//         return false;
//     }
// };



/* Solution 2:  (Tortoise-Hare-Approach)  (Slow and Fast Pointer Method)   */
// Time Complexity: O(N/2) ~ O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow == fast){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

