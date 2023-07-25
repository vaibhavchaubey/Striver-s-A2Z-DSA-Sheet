/* Leetcode  Submission    (142. Linked List Cycle II) */

/* Problem Statement: Given the head of a linked list, return the node where the cycle begins. 
If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously 
following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer 
is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list. */


/* Solution 1:  Hashing     */
// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> hash;
//         ListNode* temp = head;
//         while(temp != NULL){
//             if(hash.count(temp)){
//                 return temp;
//             }
//             hash.insert(temp);
//             temp = temp->next;
//         }
        
//         return NULL;
//     }
// };



/* Solution 2:  (Tortoise-Hare-Approach)   (Slow and Fast Pointer Method)  */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if(head == NULL || head->next == NULL) {
//             return NULL;
//         }

//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow == fast){
//                 fast = head;
//                 while(slow != fast){
//                     slow = slow->next;
//                     fast = fast->next;
//                 }
                
//                 return slow;
//             }
//         }
        
//         return NULL;
//     }
// };