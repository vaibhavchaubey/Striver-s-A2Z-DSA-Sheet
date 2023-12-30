/* Leetcode Submission          (2095. Delete the Middle Node of a Linked List)  */

/* Problem Statement: You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively. */


/* Solution 1:  2 Passes */
// Time Complexity: O(N/2) + O(N/2)  ~  O(N)
// Space Complexity: O(1) 

// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return NULL;
//         }

//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         ListNode* middleNode = slow;

//         ListNode* temp = head;
//         while(temp->next != middleNode){
//             temp = temp->next;
//         }

//         ListNode* todelete = temp->next;
//         temp->next = temp->next->next;          
//         delete todelete;

//         return head;
//     }
// };



/* Solution 2: 1 Passes */
// Time Complexity: O(N/2)
// Space Complexity: O(1) 


// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return NULL;
//         }

//         /* As we want to delete middleNode and slow will point to middleNode */
//         /* So we can show this one less step on slow (as slow->next will be middleNode) by letting fast moves forward one more step (by two nodes) */
//         ListNode* slow = head;
//         ListNode* fast = head->next->next;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         ListNode* todelete = slow->next;
//         slow->next = slow->next->next;          
//         delete todelete;

//         return head;
//     }
// };


/* OR Both have same complexity */

// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return NULL;
//         }

//         /* Here ListNode(0,head) means we assign value 0 and its next points to head */
//         ListNode* prev = new ListNode(0, head);
//         ListNode* slow = head;
//         ListNode* fast = head;
        
//         while(fast != NULL && fast->next != NULL){
//             prev = prev->next;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         prev->next = slow->next;
//         delete slow;
        
//         return head;
//     }
// };