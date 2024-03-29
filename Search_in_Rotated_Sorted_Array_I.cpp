/* Leetcode  Submission    (33. Search in Rotated Sorted Array) */

/* Problem Statement: There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the 
resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible. */



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

//             // identifying sorted half and eliminate left/right

//             // left sorted
//             else if(nums[low] <= nums[mid]){
//                 // eliminate right half
//                 if(nums[low] <= target && target <= nums[mid]){
//                     high = mid - 1;
//                 }
//                 // eliminate left half
//                 else{
//                     low = mid + 1;
//                 }
//             }
//             // right sorted
//             else {                          // if(nums[mid] <= nums[high])
//                 // eliminate left half
//                 if(nums[mid] <= target && target <= nums[high]){
//                     low = mid + 1;
//                 }
//                 // eliminate right half
//                 else{
//                     high = mid - 1;
//                 }
//             }
//         }

//         return -1;
//     }
// };