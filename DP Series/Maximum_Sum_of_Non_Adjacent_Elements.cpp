/* CodeStudio   Submission    (Maximum sum of non-adjacent elements) */

/* Problem Statement: Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence 
such that no two elements of the subsequence are adjacent elements in the array.
Note: A subsequence of an array is a list with elements of the array where some elements are deleted 
( or not deleted at all) and the elements should be in the same order in the subsequence as in the array. */



/* Solution 1: It will give TLE */
/* With Recursion */
//It will give TLE


// #include <bits/stdc++.h> 
// int helper(int ind, vector<int> &nums){
//     if(ind == 0){
//         return nums[ind];
//     }
//     if(ind < 0){
//         return 0;
//     }
//     int pick = nums[ind] + helper(ind-2, nums);
//     int nonPick = 0 + helper(ind-1, nums);
    
//     return max(pick, nonPick);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     return helper(n-1, nums);
// }



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N)
// Space Complexity: O(N) (Recursion)   +   O(N)  (Array)


// #include <bits/stdc++.h> 
// int helper(int ind, vector<int> &nums, vector<int> &dp){
//     if(ind == 0){
//         return nums[ind];
//     }
//     if(ind < 0){
//         return 0;
//     }
//     if(dp[ind] != -1){
//         return dp[ind];
//     }
//     int pick = nums[ind] + helper(ind-2, nums, dp);
//     int nonPick = 0 + helper(ind-1, nums, dp);
    
//     return dp[ind] = max(pick, nonPick);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n,-1);
//     return helper(n-1, nums, dp);
// }



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N)
// Space Complexity: O(N)  (Array) 


// #include <bits/stdc++.h> 
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n,-1);
//     dp[0] = nums[0];
//     for(int i = 1; i < n; i++){
//         int pick = nums[i];
//         if(i > 1){
//             pick += dp[i-2];
//         }
//         int nonPick = 0 + dp[i-1];
//         dp[i] = max(pick, nonPick);
//     }
//     return dp[n-1];
// }



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N)
// Space Complexity: O(1)


// #include <bits/stdc++.h> 
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     int prev = nums[0];
//     int prev2 = 0;
//     for(int i = 1; i < n; i++){
//         int pick = nums[i];
//         if(i > 1){
//             pick += prev2;
//         }
//         int nonPick = 0 + prev;
//         int cur_i = max(pick, nonPick);
//         prev2 = prev;
//         prev = cur_i;
//     }
//     return prev;;
// }



/* GFG   Submission    (Stickler Thief) */


// class Solution
// {
//     public:
//     //Function to find the maximum money the thief can get.
//     int FindMaxSum(int arr[], int n)
//     {
//         int prev = arr[0];
//         int prev2 = 0;
//         for(int i = 1; i < n; i++){
//             int pick = arr[i];
//             if(i > 1){
//                 pick += prev2;
//             }
//             int nonPick = 0 + prev;
//             int cur_i = max(pick, nonPick);
//             prev2 = prev;
//             prev = cur_i;
//         }
//         return prev;
//     }
// };