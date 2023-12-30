/* Leetcode Submission          (148. Sort List)  */

/* Problem Statement: Given the head of a linked list, return the list after sorting it in ascending order. */


/* Solution 1: */
// Time Complexity: O(N) + O(N) + O(N * logN)
// Space Complexity: O(N)


// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> vec;
//         ListNode* temp = head;
//         while(temp != NULL){
//             vec.push_back(temp->val);
//             temp = temp->next;
//         }

//         sort(vec.begin(), vec.end());
        
//         ListNode* dummyNode = new ListNode(0);
//         ListNode* curr = dummyNode;
//         for(int i = 0; i < vec.size(); i++){
//             curr->next = new ListNode(vec[i]);
//             curr = curr->next;
//         }

//         return dummyNode->next;
//     }
// };



/* Solution 2:   (using merge sort) */
// Time Complexity: O(N * logN)
// Space Complexity: O(N)


// class Solution {
// public:
//     ListNode* merge(ListNode* list1, ListNode* list2){
//         ListNode* dummyHead = new ListNode(0);
//         ListNode* ptr = dummyHead;
//         while(list1 != NULL && list2 != NULL){
//             if(list1->val < list2->val){
//                 ptr->next = list1;
//                 list1 = list1->next;
//             }
//             else{
//                 ptr->next = list2;
//                 list2 = list2->next;
//             }
//             ptr = ptr->next;
//         }

//         if(list1 != NULL){
//             ptr->next = list1;
//         }
//         if(list2 != NULL){
//             ptr->next = list2;
//         }
        
//         return dummyHead->next;
//     }
//     ListNode* getMid(ListNode* head){
//         ListNode* prev = NULL;      // to store one step before slow
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != NULL && fast->next != NULL){
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         prev->next = NULL;            //end of first left half

//         return slow;            // middle
//     }
//     ListNode* sortList(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
        
//         ListNode* mid = getMid(head);
//         ListNode* left = sortList(head);
//         ListNode* right = sortList(mid);
        
//         return merge(left, right);   
//     }
// };

