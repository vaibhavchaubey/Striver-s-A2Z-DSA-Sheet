/* Leetcode  Submission      (239. Sliding Window Maximum) */

/* Problem Statement: You are given an array of integers nums, there is a sliding window of size k which is moving from the 
very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves 
right by one position.
Return the max sliding window. */



/* Solution 1: Brute Force Approach */
// Time Complexity: O(N * K) 
// Space Complexity: O(1) 


// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
//         for(int i = 0; i <= n-k; i++){
//             int maxEle = INT_MIN;
//             for(int j = i; j < i+k; j++){
//                 maxEle = max(maxEle, nums[j]);
//             }
//             ans.push_back(maxEle);
//         }
        
//         return ans;
//     }
// };




/* Solution 2: Using Deque */
/* Time Complexity: O(N) + O(N)
It seems more than O(N) at first look. It can be observed that every element of array is added and removed at most once. 
So there are total 2N operations.
Space Complexity: O(k)  */


// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
//         deque<int> dq;
        
//         for(int i = 0; i < k; i++){
//             while(!dq.empty() && nums[dq.back()] < nums[i]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//         }
//         ans.push_back(nums[dq.front()]);
        
//         for(int i = k; i < n; i++){
//             // It is done to remove the index which is not in the next window
//             if(dq.front() == i-k){
//                 dq.pop_front();
//             }

//             while(!dq.empty() && nums[dq.back()] < nums[i]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//             ans.push_back(nums[dq.front()]);
//         }
        
//         return ans;
//     }
// };



