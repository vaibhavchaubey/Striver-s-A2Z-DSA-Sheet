/* Leetcode  Submission    (703. Kth Largest Element in a Stream) */

/* Problem Statement: Design a class to find the kth largest element in a stream. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Implement KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream. */



/* Solution: Using priority queue */
// Time complexity : O(N * log k) + O(M * log k)       
// Space complexity : O(k)  


// class KthLargest {
// public:
//     priority_queue<int, vector<int>, greater<int>> pq;   // minHeap 
//     int n;
//     KthLargest(int k, vector<int>& nums) {
//         n = k;
//         for(int i = 0; i < nums.size(); i++){
//             pq.push(nums[i]);
//             if(pq.size() > k){
//                 pq.pop();
//             }
//         }
//     }
    
//     int add(int val) {
//         pq.push(val);
//         if(pq.size() > n){
//             pq.pop();
//         }

//         return pq.top();
//     }
// };