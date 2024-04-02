/* Leetcode  Submission    (78. Subsets) */

/* Problem Statement: Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order. */


/* Solution: */
// Time Complexity: O(2^N)
// Space Complexity: O(N)                 //  recursion stack


// class Solution {
// public:
//     void helper(int ind, int n, vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans){
//         if(ind == n){
//             ans.push_back(arr);
//             return;
//         }

//         // element is picked
//         arr.push_back(nums[ind]);
//         helper(ind+1, n, nums, arr, ans);

//         // element is not picked
//         arr.pop_back();                         // backtrack
//         helper(ind+1, n, nums, arr, ans);
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> arr;
//         vector<vector<int>> ans;
//         helper(0, n, nums, arr, ans);

//         return ans;
//     }
// };