/* Leetcode  Submission    (560. Subarray Sum Equals K) */

/* Problem Statement: Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array. */


/* Solution: */
// Time Complexity: O(NlogN)
// Space Complexity: O(N)


// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int cnt = 0, sum = 0;
//         unordered_map<int,int> mp;                   // sum, count
//         for(int i = 0; i < nums.size(); i++){
//             sum += nums[i];
//             if(sum - k == 0){
//                 cnt++;
//             }
//             cnt += mp[sum-k];
//             mp[sum]++;
//         }
//         return cnt;
//     }
// };


/* cnt += m[sum-k];

OR

if(m.count(sum - k)){
    cnt++;
} */



/* GFG  Submission    (Longest Sub-Array with Sum K) */

/* Problem Statement: Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array 
with the sum of the elements equal to the given value K. */


/* Solution: Using Hashing */
// Time Complexity: O(NlogN)
// Space Complexity: O(N)


// class Solution{
//     public:
//     int lenOfLongSubarr(int A[],  int N, int K) 
//     { 
//         int curSum = 0;
//         int maxLength = 0;
//         unordered_map<int, int> mp;        // sum, index
//         for(int i = 0; i < N; i++){
//             curSum += A[i];
//             if(curSum - K == 0){
//                 maxLength = max(maxLength, i+1);
//             }
//             if(mp.count(curSum - K)){
//                 int len = i - mp[curSum - K];
//                 maxLength = max(maxLength, len);
//             }
//             if(mp.count(curSum) == 0){
//                 mp[curSum] = i;
//             }
//         }
        
//         return maxLength;
//     } 

// };


