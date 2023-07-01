/* Leetcode  Submission    (410. Split Array Largest Sum) */


/* Problem Statement: Given an integer array nums and an integer k, split nums into k non-empty subarrays such that 
the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N) * O(sumAll - maxEle)
// Space Complexity: O(1)

/* Range    [maxEle ................... sumAll]   =>  using Linear search for this range */


// class Solution {
// public:
//     bool isPossible(int minSum, int k, int n, vector<int>& nums){
//         int cntSplit = 1;
//         long long sum = 0;
//         for(int i = 0; i < n; i++){
//             if(sum + nums[i] > minSum){
//                 cntSplit++;
//                 sum = nums[i];
//             }
//             else{
//                 sum += nums[i];
//             }
//         }

//         if(cntSplit <= k){
//             return true;
//         }

//         return false;
//     }
//     int splitArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         if(k > n){
//             return -1;
//         }

//         int maxEle = 0, sumAll = 0;
//         for(int i = 0; i < n; i++){
//             maxEle = max(maxEle, nums[i]);
//             sumAll += nums[i];
//         }

//         int low = maxEle, high = sumAll;
//         for(int i = low; i <= high; i++){
//             // checking if by having a minSum i can we split array into k non-empty subarrays
//             if(isPossible(i, k, n, nums)){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N) * O(log(sumAll - maxEle))
// Space Complexity: O(1)

/* Range    [maxEle ................... sumAll]   =>  using Binary search for this range */


// class Solution {
// public:
//     bool isPossible(int minSum, int k, int n, vector<int>& nums){
//         int cntSplit = 1;
//         long long sum = 0;
//         for(int i = 0; i < n; i++){
//             if(sum + nums[i] > minSum){
//                 cntSplit++;
//                 sum = nums[i];
//             }
//             else{
//                 sum += nums[i];
//             }
//         }

//         if(cntSplit <= k){
//             return true;
//         }

//         return false;
//     }
//     int splitArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         if(k > n){
//             return -1;
//         }

//         int maxEle = 0, sumAll = 0;
//         for(int i = 0; i < n; i++){
//             maxEle = max(maxEle, nums[i]);
//             sumAll += nums[i];
//         }
//         int ans = -1;

//         int low = maxEle, high = sumAll;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             // checking if by having a minSum mid can we split array into k non-empty subarrays
//             if(isPossible(mid, k, n, nums)){
//                 ans = mid;
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }

//         return ans;
//     }
// };