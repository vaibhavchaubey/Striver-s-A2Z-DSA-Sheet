/* Leetcode  Submission    (153. Find Minimum in Rotated Sorted Array) */

/* Problem Statement: Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time. */


/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int n = nums.size();
//         int minEle = INT_MAX;
//         for(int i = 0; i < n; i++){
//             minEle = min(minEle, nums[i]);
//         }

//         return minEle;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int n = nums.size();
//         int minEle = INT_MAX;
//         int low = 0, high = n-1;

//         while(low <= high){
//             if(nums[low] <= nums[high]){
//                 minEle = min(minEle, nums[low]);
//                 break;
//             }
//             int mid = low + (high - low) / 2;

//             // STEP 1: identifying sorted half

//             // left sorted
//             if(nums[low] <= nums[mid]){
//                 // STEP 2: take min from that sorted part
//                 minEle = min(minEle, nums[low]);
//                 // STEP 3: then eliminate that part
//                 low = mid + 1;

//             }
//             // right sorted
//             else {                          // if(nums[mid] <= nums[high])
//                 // STEP 2: take min from that sorted part
//                 minEle = min(minEle, nums[mid]);
//                 // STEP 3: then eliminate that part
//                 high = mid - 1;
//             }
//         }

//         return minEle;
//     }
// };