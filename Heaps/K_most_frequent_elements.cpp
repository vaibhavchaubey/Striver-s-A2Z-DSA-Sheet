/* Leetcode  Submission    (347. Top K Frequent Elements) */

/* Problem Statement: Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order. */


/* Solution 1: Using priority queue (maxHeap) */
// Time complexity : O(N logN) 
// Space complexity : O(N) + O(N)


// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;       // num, count
//         for(auto num : nums){
//             mp[num]++;
//         }

//         priority_queue<pair<int, int>> pq;         // maxHeap
//         for(auto it : mp){
//             pq.push({it.second, it.first});          // count, num
//         }

//         vector<int> ans;
//         while(k--){
//             int ele = pq.top().second;
//             pq.pop();
//             ans.push_back(ele);
//         }

//         return ans;
//     }
// };



/* Solution 2: Using priority queue (minHeap) */
// Time complexity : O(N logK) 
// Space complexity : O(N) + O(K)


// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;       // num, count
//         for(auto num : nums){
//             mp[num]++;
//         }

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;         // minHeap

//         for(auto it : mp){
//             pq.push({it.second, it.first});             // count, num
            
//             // So that our pq has always Top K Frequent Elements
//             if(pq.size() > k){  
//                 pq.pop();
//             }
//         }

//         vector<int> ans;
//         while(k--){
//             int ele = pq.top().second;
//             pq.pop();
//             ans.push_back(ele);
//         }

//         return ans;
//     }
// };