/* Leetcode Submission          (160. Intersection of Two Linked Lists)  */

/* Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null. */


/* Solution 1: Hashing

Iterate through list 1 and hash its node address.
Iterate through list 2 and search the hashed value in the hash table. If found, return node.

Time Complexity: O(n+m)
Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m).
Space Complexity: O(n) */


// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> s;
//         while(headA != NULL){
//             s.insert(headA);
//             headA = headA->next;
//         }

//         while(headB != NULL){
//             if(s.count(headB)){
//                 return headB;
//             }
//             headB = headB->next;
//         }

//         return NULL;
//     }
// };



/* Solution 2: Difference of length

Time Complexity: O(2max(list1, list2)) + O(abs(list1-list2)) + O(min(list1, list2))
Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them.
Moving the head pointer ahead by a difference of them. The next one is for searching.
Space Complexity: O(1) */


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
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int l1 = length(headA);
//         int l2 = length(headB);

//         int d = 0;
//         ListNode* ptr1;
//         ListNode* ptr2;
//         if(l1 > l2){
//             d = l1-l2;
//             ptr1 = headA;
//             ptr2 = headB;
//         }
//         else{
//             d = l2-l1;
//             ptr1 = headB;
//             ptr2 = headA;
//         }
//         while(d){
//             ptr1 = ptr1->next;
//             if(ptr1 == NULL){
//                 return NULL;
//             }
//             d--;
//         }
//         while(ptr1 != NULL && ptr2 != NULL){
//             if(ptr1 == ptr2){
//                 return ptr1;
//             }
//             ptr1 = ptr1->next;
//             ptr2 = ptr2->next;
//         }

//         return NULL;
//     }
// };



/* Solution 3: Optimised

Approach:
The difference of length method requires various steps to work on it. Using the same concept of difference of length, 
a different approach can be implemented. The process is as follows:-
1) Take two dummy nodes for each list. Point each to the head of the lists.
2) Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.

Time Complexity: O(2*max(list1, list2))
Reason: Uses the same concept of difference of lengths of two lists.
Space Complexity: O(1) */


// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* d1 = headA;
//         ListNode* d2 = headB;

//         while(d1 != d2){
//             if(d1 == NULL){
//                 d1 = headB;
//             }
//             else{
//                 d1 = d1->next;
//             }

//             if(d2 == NULL){
//                 d2 = headA;
//             }
//             else{
//                 d2 = d2->next;
//             }
//         }

//         return d1;
//     }
// };


