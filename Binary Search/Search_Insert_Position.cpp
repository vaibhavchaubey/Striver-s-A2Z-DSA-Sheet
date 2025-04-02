/* Leetcode  Submission    (35. Search Insert Position) */

/* Problem Statement: Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity. */


/* This question is same as finding lower_bound */


/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             if(nums[i] >= target){
//                 return i;
//             }
//         }

//         return n;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();
//         int index = n;
//         int low = 0, high = n-1;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(nums[mid] >= target){
//                 index = mid;
//                 high = mid-1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }

//         return index;
//     }
// };


/* OR */

// return lower_bound(nums.begin(), nums.end(), target) - nums.begin();