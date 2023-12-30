/* Leetcode   Submission    (300. Longest Increasing Subsequence) */


/* Problem Statement: Given an integer array nums, return the length of the longest strictly increasing subsequence. */



/* Solution: */
/* Binary Search */
// Time Complexity: O(N*logN)
// Space Complexity: O(N)


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp;

//         temp.push_back(nums[0]);
//         int len = 1;
//         for(int i = 1; i < n; i++){
//             // nums[i] > the last element of temp array 
//             if(nums[i] > temp.back()){
//                 temp.push_back(nums[i]);
//                 len++;
//             }
//             else{
//                 // replacement step
//                 int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
//                 temp[ind] = nums[i];
//             }
//         }
        
//         return len;
//     }
// };


