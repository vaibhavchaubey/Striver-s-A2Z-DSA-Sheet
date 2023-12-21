/* Leetcode  Submission    (992. Subarrays with K Different Integers) */

/* Problem Statement: Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)
// Space Complexity: O(k)          


// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             unordered_map<int, int> mp;                          // num, count
//             for(int j = i; j < n; j++){
//                 mp[nums[j]]++;
//                 if(mp.size() > k){
//                     break;
//                 }
//                 if(mp.size() == k){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };




/* Solution 2: Sliding Window */
// Time Complexity: O(2*N)
// Space Complexity: O(k)


/* Intuition
First you may have feeling of using sliding window.
Then this idea get stuck in the middle as some of the subarray may left out.

This problem will be a very typical sliding window,
if it asks the number of subarrays with at most K distinct elements.

Just need one more step to reach the folloing equation:
exactly(K) = atMost(K) - atMost(K-1) 

QUESTION : How to count total number of subarray with atmost k different integers.

ANS: (Simple Keep adding length of window size whenever window size is changed) Count=(right-left+1);

More Clarify Above ans:
As we iterate through an array ,one by one elements to the existing array adds up and as an element is added to the existing 
array then it contributes to (right-left+1) subarrays and so till the current j pointer we will get all the possible subarrays.
For an example : if array is {1,2,3,4,5} then it will have n(n+1)/2 subarrays i.e 5*(6)/2 = 15 subarrays and lets suppose we add 
one more element to existing array(ele:6) then here right = 5 and lets take left = 0, then total (right-left+1) extra subarrays 
will be added i.e (5 - 0 + 1) = 6 subarrays namely {6}, {5,6}, {4,5,6}, {3,4,5,6}, {2,3,4,5,6}, {1,2,3,4,5,6} respectively.   */



// class Solution {
// public:
//     int atMostK(vector<int>& nums, int k){
//         int n = nums.size();
//         unordered_map<int, int> mp;          // num, count
//         int left = 0, right = 0;
//         int count = 0;
//         while(right < n){
//             mp[nums[right]]++;
//             while(mp.size() > k){
//                 mp[nums[left]]--;
//                 if(mp[nums[left]] == 0){
//                     mp.erase(nums[left]);
//                 }
//                 left++;
//             }

//             count +=  right - left + 1;                  // this counts the subarrays in that window
//             right++;
//         }

//         return count;
//     }
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         return atMostK(nums, k) - atMostK(nums, k - 1);
//     }
// };