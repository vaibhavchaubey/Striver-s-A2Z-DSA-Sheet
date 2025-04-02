/* Leetcode  Submission    (704. Binary Search) */

/* Problem Statement: Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             if(nums[i] == target){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int low = 0, high = n-1;
//         while(low <= high){
//             int mid = low + (high - low) / 2;

//             if(nums[mid] == target){
//                 return mid;
//             }
//             else if(nums[mid] < target){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }

//         return -1;
//     }
// };