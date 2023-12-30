/* Codestudio  Submission          (Find pairs with given sum in doubly linked list)  */

/* Problem Statement: A doubly-linked list is a data structure that consists of sequentially linked nodes, 
and the nodes have reference to both the previous and the next nodes in the sequence of nodes. 
You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, 
and a number "k' Find out all the pairs in the doubly linked list with sum equal to 'k'. */


/* Solution 1:  (Finding the sum of all possible pairs)   */
// Time Complexity : O(N*N)
// Space Complexity : O(1)


// vector<pair<int, int>> findPairs(Node* head, int k)
// {
//     vector<pair<int,int>> ans;
//     Node* ptr1 = head;
//     while (ptr1 != NULL){
//         Node* ptr2 = ptr1->next;
//         while(ptr2 != NULL){
//             if(ptr1->data + ptr2->data == k){
//                 ans.push_back({ptr1->data, ptr2->data});
//             }

//             ptr2 = ptr2->next;
//         }

//         ptr1 = ptr1->next;
//     }

//     return ans;
// }



/* Solution 2:  (Hash or we can say knowing all the previous encountered elements)   */
// Time Complexity : O(N)
// Space Complexity : O(N)


// #include<bits/stdc++.h>
// vector<pair<int, int>> findPairs(Node* head, int k)
// {
//     vector<pair<int,int>> ans;
//     Node* ptr = head;

//     unordered_set<int> hash;

//     while(ptr != NULL){
//         int val = ptr->data;
//         if(hash.count(k - val)){
//             ans.push_back({val, k - val});
//         }
//         else{
//             hash.insert(val);
//         }

//         ptr = ptr->next;
//     }

//     return ans;
// }



/* Solution 3:  (Two Pointer)   */
// Time Complexity : O(N)
// Space Complexity : O(1)


// vector<pair<int, int>> findPairs(Node* head, int k)
// {
//     vector<pair<int, int>> ans;
//     Node* start = head;
//     Node* end = head;
//     while(end->next != NULL){
//         end = end->next;
//     }

//     while(start->data < end->data){
//         int sum = start->data + end->data;
//         if(sum == k){
//             ans.push_back({start->data, end->data});
//             start = start->next;
//             end = end->prev;
//         }
//         else if(sum < k){
//             start = start->next;
//         }
//         else{                           // if(sum > k)
//             end = end->prev;
//         }
//     }

//     return ans;
// }
