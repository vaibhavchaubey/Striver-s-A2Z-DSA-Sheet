/* Leetcode  Submission    (23. Merge k Sorted Lists) */


/* Problem Statement: You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it. */



/* Solution 1: Merge lists one by one*/
/* Convert merge k lists problem to merge 2 lists (k-1) times. */
// Time complexity : N + 2N + 3N + ..... + kN = N(1 + 2 + 3 + ..... + k) = O(N * k(k+1)/2)      where k is the number of linked lists
// Space complexity : O(1)


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(l1 == NULL){
//             return l2;
//         }
//         if(l2 == NULL){
//             return l1;
//         }

//         ListNode* result;
//         if(l1->val < l2->val){
//             result = l1;
//             result->next = mergeTwoLists(l1->next,l2);
//         }
//         else{
//             result = l2;
//             result->next = mergeTwoLists(l1,l2->next);
//         }

//         return result;
//     }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.size() == 0){
//             return NULL;
//         }
//         if(lists.size() == 1){
//             return lists[0];
//         }

//         ListNode* ans = mergeTwoLists(lists[0],lists[1]);
//         for(int i = 2; i < lists.size(); i++){
//             ans = mergeTwoLists(ans,lists[i]);
//         }

//         return ans;
//     }
// };




/* Solution 2: Using Min Heap   */
// Time complexity : O(K * logK) + O(K * N * 3logK) where k is the number of linked lists
// Space complexity : O(K)


// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.size() == 0){
//             return NULL;
//         }
//         if(lists.size() == 1){
//             return lists[0];
//         }

//         priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;           // minHeap
//         for(int i = 0; i < lists.size(); i++){               // O(K * logK)
//             if(lists[i]){
//                 pq.push({lists[i]->val, lists[i]});
//             }
//         }

//         ListNode* dummy = new ListNode(-1);
//         ListNode* temp = dummy;
//         while(!pq.empty()){                          // Total elements => K * N   --->  O(K * N * 3logK)
//             pair<int, ListNode*> p = pq.top();
//             pq.pop();
//             temp->next = p.second;
//             if(p.second->next){
//                 pq.push({p.second->next->val, p.second->next});
//             }
//             temp = temp->next;
//         }

//         return dummy->next;
//     }
// };




/* Solution 3: Merge with Divide And Conquer        (TO BE USED)   */
/* This approach walks alongside the one above but is improved a lot. We don't need to traverse most nodes many times repeatedly

1) Pair up k lists and merge each pair.
2) After the first pairing, k lists are merged into k/2 lists with average 2N/k length, then k/4, k/8 and so on.
3) Repeat this procedure until we get the final sorted linked list.

Thus, we'll traverse almost N nodes per pairing and merging, and repeat this procedure about logk times */


// Time complexity : O(N logK) where k is the number of linked lists
// Space complexity : O(1)



// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
//         if(l1 == NULL){
//             return l2;
//         }
//         if(l2 == NULL){
//             return l1;
//         }

//         ListNode* result;
//         if(l1->val < l2->val){
//             result = l1;
//             result->next = mergeTwoLists(l1->next,l2);
//         }
//         else{
//             result = l2;
//             result->next = mergeTwoLists(l1,l2->next);
//         }

//         return result;
//     }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.size() == 0){
//             return NULL;
//         }
//         if(lists.size() == 1){
//             return lists[0];
//         }

//         int interval = 1;
//         while(interval < lists.size()){
//             for(int i = 0; i < lists.size() - interval; i = i + interval*2){
//                 lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
//             }
//             interval *= 2;
//         }

//         return lists[0];
//     }
// };