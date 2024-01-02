/* Leetcode  Submission          (25. Reverse Nodes in k-Group)  */

/* Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. 
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is. */


/* Solution 1: 
Time Complexity: O(N)
Space Complexity: O(1) */


// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k == 1){
//             return head;
//         } 
        
//         // check if k nodes exist or not
//         ListNode* check = head;
//         int count = 1;
        
//         while(check->next != NULL && count < k){
//             count++;
//             check = check->next;
//         }
//         if(count < k){
//             return head;
//         }

//         count = 1;
//         ListNode* prevptr = NULL;
//         ListNode* currptr = head;
//         ListNode* nextptr;
//         while(currptr != NULL && count <= k){
//             nextptr = currptr->next;
//             currptr->next = prevptr;
            
//             prevptr = currptr;
//             currptr = nextptr;
//             count++;
//         }
            
//         if(nextptr != NULL){
//             head->next = reverseKGroup(nextptr,k);
//         }
        
//         return prevptr;
//     }
// };




/* Solution 2:
Time Complexity: O(N)
Reason: Nested iteration with O((N/k)*k) which makes it equal to O(N).
Space Complexity: O(1) */


// class Solution {
// public:
//     int length(ListNode* head){
//         int l = 0;
//         ListNode* temp = head;
//         while(temp != NULL){
//             l++;
//             temp = temp->next;
//         }
//         return l;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL || k == 1){
//             return head;
//         } 
        
//         int l = length(head);
        
//         ListNode* dummyNode = new ListNode(0);
//         dummyNode->next = head;
        
//         ListNode* prevptr = dummyNode;
//         ListNode* currptr;
//         ListNode* nextptr;
        
//         while(l >= k){
//             currptr = prevptr->next;
//             nextptr = currptr->next;
//             for(int i = 1; i < k; i++){
//                 currptr->next = nextptr->next;
//                 nextptr->next = prevptr->next;
//                 prevptr->next = nextptr;
//                 nextptr = currptr->next;                
//             }
//             prevptr = currptr;
//             l -= k;
//         }
        
//         return dummyNode->next;
//     }
// };