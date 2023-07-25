/* Leetcode Submission          (19. Remove Nth Node From End of List)  */

/* Problem Statement: Given the head of a linked list, remove the nth node from the end of the list and return its head. */


/* Solution 1: Naive Approach [Traverse 2 times]

Intuition: We can traverse through the Linked List while maintaining a count of nodes, let’s say in the variable count, 
and then traversing for the 2nd time for (n – count) nodes to get to the nth node of the list. 

Time Complexity: O(2*N)
Space Complexity: O(1) */

// class Solution {
// public:
//     int length(ListNode* head){
//         int l=0;
//         ListNode* temp = head;
//         while (temp!=NULL){
//             l++;
//             temp = temp->next;
//         }
//         return l;
//     }
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int l = length(head);
//         int pos = l-n+1;
//         if(pos==1){
//             return head->next;
//         }

//         ListNode* temp = head;
//         int count = 1;
//         while(count!=pos-1){
//             temp = temp->next;
//             count++;
//         }
//         ListNode* todelete = temp->next;
//         temp->next = temp->next->next;
//         delete todelete;
        
//         return head;
//     }
// };



/* Solution 2: [Efficient] Two pointer Approach
    
Intuition: With two pointers in hand out of which one is at the n-th node from start, we can just advance both of them 
till the end simultaneously, once the faster reaches the end, the slower will stand at the n-th node from the end. 

Time Complexity: O(N)
Space Complexity: O(1) */

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* start = new ListNode(0);
//         start->next = head;
//         ListNode* slow = start;
//         ListNode* fast = start;
        
//         for(int i = 1; i <= n; i++){
//             fast = fast->next;
//         }
        
//         while(fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next;
//         }
//         ListNode* todelete = slow->next;
//         slow->next= slow->next->next;
//         delete todelete;
        
//         return start->next;
//     }
// };