/* Leetcode  Submission    (33. Search in Rotated Sorted Array) */

/* Problem Statement: Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
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