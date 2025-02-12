/* Leetcode  Submission    (75. Sort Colors) */

/* Problem Statement: Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int low = 0; 
//         int mid = 0;
//         int high = n-1;
//         while(mid <= high){
//             if(nums[mid] == 0){
//                 swap(nums[low], nums[mid]);
//                 low++; mid++;
//             }
//             else if(nums[mid] == 1){
//                 mid++;
//             }
//             else{           // nums[mid] == 2
//                 swap(nums[mid], nums[high]);
//                 high--;
//             }
//         }
//     }
// };

