/* Leetcode  Submission    (234. Palindrome Linked List) */

/* Problem Statement: Given the head of a singly linked list, return true if it is a palindrome or false otherwise. */


/* Solution 1: */
// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> vec;
//         ListNode* temp = head;
//         while(temp != NULL){
//             vec.push_back(temp->val);
//             temp = temp->next;
//         }

//         int n = vec.size();
//         for(int i = 0; i < n/2; i++){
//             if(vec[i] != vec[n-i-1]){
//                 return false;
//             }
//         }

//         return true;
//     }
// };



/* Solution 2:  (Slow and Fast Pointer Method)  */
// Time Complexity: O(N/2) + O(N/2) + O(N/2) ~ O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* reverse(ListNode* head){
//         ListNode* prevptr = NULL;
//         ListNode* currptr = head;
//         ListNode* nextptr;
//         while(currptr!=NULL){
//             nextptr = currptr->next;
//             currptr->next = prevptr;
//             prevptr = currptr;
//             currptr = nextptr;
//         }
//         return prevptr;
//     }
//     bool isPalindrome(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return true;
//         }

//         // STEP 1: Find the middle element
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast!=NULL && fast->next!=NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // STEP 2: Reverse the end half
//         slow = reverse(slow);

//         // STEP 3: Compare the start half and end half if found any inequality then return false otherwise return true.
        
//         fast = head;
//         while(slow!=NULL && fast!=NULL){
//             if(slow->val != fast->val){
//                 return false;
//             }
//             slow = slow->next;
//             fast = fast->next;
//         }

//         return true;
//     }
// };