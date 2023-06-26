/* Leetcode  Submission    (1283. Find the Smallest Divisor Given a Threshold) */


/* Problem Statement: Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, 
divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above 
is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. 
(For example: 7/3 = 3 and 10/2 = 5).
The test cases are generated so that there will be an answer. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N * maxEle)
// Space Complexity: O(1)

/* Range    [1 ................... maxEle]   =>  using Linear search for this range */


// class Solution {
// public:
//     bool isPossible(int divisor, int threshold, int n, vector<int>& nums){
//         int sum = 0;
//         for(int i = 0; i < n; i++){
//             sum += ceil((double)nums[i] / (double)divisor);
//         }

//         if(sum <= threshold){
//             return true;
//         }

//         return false;
//     }
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n = nums.size();
//         int maxEle = *max_element(nums.begin(), nums.end());
//         for(int i = 1; i <= maxEle; i++){
//             if(isPossible(i, threshold, n, nums)){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N * log(maxEle))
// Space Complexity: O(1)

/* Range    [1 ................... maxEle]   =>  using Binary search for this range */


// class Solution {
// public:
//     bool isPossible(int divisor, int threshold, int n, vector<int>& nums){
//         int sum = 0;
//         for(int i = 0; i < n; i++){
//             sum += ceil((double)nums[i] / (double)divisor);
//         }

//         if(sum <= threshold){
//             return true;
//         }

//         return false;
//     }
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n = nums.size();
//         int ans = -1;
//         int maxEle = *max_element(nums.begin(), nums.end());

//         int low = 1, high = maxEle;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(isPossible(mid, threshold, n, nums)){
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

