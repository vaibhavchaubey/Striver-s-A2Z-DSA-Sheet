/* Leetcode  Submission    (215. Kth Largest Element in an Array) */

/* Problem Statement: Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting? */



/* Solution 1: Sorting */
// Time Complexity: O(N logN)  
// Space Complexity: O(1)     


// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end(), greater<int>());

//         return nums[k-1];
//     }
// };



/* Solution 2: Using MinHeap (Priority Queue) */
// Time Complexity: O(N logK)  
/* Each of the n elements is processed once. However, heap operations take O(log⁡K) time, 
leading to an overall complexity of O(N logK). */
// Space Complexity: O(K)  


// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;           // minHeap
//         for(int i = 0; i < nums.size(); i++){
//             pq.push(nums[i]);
            
//             if(pq.size() > k){
//                 pq.pop();
//             }
//         }

//         return pq.top();
//     }
// };