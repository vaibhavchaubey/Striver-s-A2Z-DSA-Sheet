/* Leetcode  Submission    (930. Binary Subarrays With Sum) */

/* Problem Statement: Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int cnt = 0;
//         for(int i = 0; i < n; i++){
//             int sum = 0;
//             for(int j = i; j < n; j++){
//                 sum += nums[j];
//                 if(sum == goal){
//                     cnt++;
//                 }
//             }
//         }

//         return cnt;
//     }
// };




/* Solution 2: Using Hashmap */
// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int cnt = 0, sum = 0;
//         unordered_map<int, int> mp;             // sum, count
//         for(int i = 0; i < n; i++){
//             sum += nums[i];;
//             if(sum == goal){
//                 cnt++;
//             }
//             cnt += mp[sum - goal];
//             mp[sum]++;
//         }

//         return cnt;
//     }
// };



/* Solution 3: Sliding Window */
// Time Complexity: O(2*N)
// Space Complexity: O(1)


/* Intuition
--> Count total number of subarray with sum atmost GOAL and GOAL-1.
--> Then subtract both to get exact number of subarray with GOAL.

QUESTION : How to count total number of subarray with atmost sum = GOAL.

ANS: (Simple Keep adding length of window size whenever window size is changed) Count=(right-left+1);

More Clarify Above ans:
As we iterate through an array ,one by one elements to the existing array adds up and as an element is added to the existing 
array then it contributes to (right-left+1) subarrays and so till the current j pointer we will get all the possible subarrays.
For an example : if array is {1,2,3,4,5} then it will have n(n+1)/2 subarrays i.e 5*(6)/2 = 15 subarrays and lets suppose we add 
one more element to existing array(ele:6) then here right = 5 and lets take left = 0, then total (right-left+1) extra subarrays 
will be added i.e (5 - 0 + 1) = 6 subarrays namely {6}, {5,6}, {4,5,6}, {3,4,5,6}, {2,3,4,5,6}, {1,2,3,4,5,6} respectively. */


// class Solution {
// public:
//     int countSubArrs(vector<int>& nums, int sum){
//         int n = nums.size();
//         if(sum < 0){
//             return 0;
//         }
//         int i = 0, j = 0, count = 0;
//         int preSum = 0;
//         while(j < n){
//             preSum += nums[j];
//             while(preSum > sum){
//                 preSum -= nums[i];
//                 i++;
//             }

//             count += (j - i + 1);       // this counts the subarrays in that window
//             j++;
//         } 

//         return count;
//     }

//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         return countSubArrs(nums, goal) - countSubArrs(nums, goal-1);
//     }
// };