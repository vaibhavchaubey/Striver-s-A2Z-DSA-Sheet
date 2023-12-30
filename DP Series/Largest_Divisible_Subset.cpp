/* Leetcode   Submission    (368. Largest Divisible Subset) */


/* Problem Statement: Given a set of distinct positive integers nums, return the largest subset answer 
such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
If there are multiple solutions, return any of them. */




/* Solution: */
/* Tabulation algorithm */
// Time Complexity: O(N*N) 
// Space Complexity: O(N)


// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n = nums.size();

//         //sort the array  (We can sort the array as in subset there is no constraint on the order)
//         sort(nums.begin(), nums.end());
        
//         vector<int> dp(n, 1), hash(n);
        
//         int ans = -1;
//         int lastIndex = -1;
//         for(int i = 0; i < n; i++){
//             hash[i] = i;                // initializing with current index 
//             for(int prev_index = 0; prev_index < i; prev_index++){
//                 if(nums[i] % nums[prev_index] == 0 && 1 + dp[prev_index] > dp[i]){
//                     dp[i] = 1 + dp[prev_index];
//                     hash[i] = prev_index;
//                 }
//             }
//             if(dp[i] > ans){
//                 ans = dp[i];
//                 lastIndex = i;
//             }
//         }

//         vector<int> temp;
//         temp.push_back(nums[lastIndex]);
//         while(hash[lastIndex] != lastIndex){          // till not reach the initialization value
//             lastIndex = hash[lastIndex];
//             temp.push_back(nums[lastIndex]);
//         }

//         // reverse the array 
//         reverse(temp.begin(), temp.end());

//         return temp;
//     }
// };