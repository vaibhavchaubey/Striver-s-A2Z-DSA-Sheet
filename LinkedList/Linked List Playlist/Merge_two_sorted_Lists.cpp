/* Leetcode Submission          (21. Merge Two Sorted Lists)    */

/* Problem Statement: You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list. */



/* Solution 1: Using an externally linked list to store answers
Time Complexity: O(N+M).
Let N be the number of nodes in list l1 and M be the number of nodes in list l2. We have to iterate through both lists. So, the total time complexity is O(N+M).
Space Complexity: O(N+M).
We are creating another linked list that contains the (N+M) number of nodes in the list. So, space complexity is O(N+M). */


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL) return list2;
//         if(list2 == NULL) return list1;
//         ListNode* p1 = list1;
//         ListNode* p2 = list2;
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* p3 = dummyNode;
//         while(p1 != NULL && p2 != NULL){
//             if(p1->val < p2->val){
//                 p3->next = p1;
//                 p1 = p1->next;
//             }
//             else{
//                 p3->next = p2;
//                 p2 = p2->next;
//             }
//             p3 = p3->next;
//         }
//         if(p1 != NULL){
//             p3->next = p1;
//         }
//         else{
//             p3->next = p2;
//         }

//         return dummyNode->next;
//     }
// };



/* Solution 2: Inplace method without using extra space.
Time Complexity: O(N+M)
Let N be the number of nodes in list l1 and M be the number of nodes in list l2. We have to iterate through both lists. So, the total time complexity is O(N+M).
Space Complexity: O(1)
We are using the same lists just changing links to create our desired list. So no extra space is used. 
Hence, its space complexity is O(1).  */


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL) return list2;
//         if(list2 == NULL) return list1;
//         if(list1->val > list2->val) swap(list1,list2);
//         ListNode* res = list1;
//         while(list1 != NULL && list2 != NULL){
//             ListNode* temp = NULL;
//             while(list1 != NULL && list1->val <= list2->val){
//                 temp = list1;
//                 list1 = list1->next;
//             }
//             temp->next = list2;
//             swap(list1,list2);
//         }
        
//         return res;
//     }
// };

