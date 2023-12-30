/* Problem Statement: You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. 
You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely. */


/* Leetcode  Submission    (312. Burst Balloons) */


/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: (Exponential)
// Space Complexity: O(N) (Recursion)


// class Solution {
// public:
//     int helper(int i, int j, vector<int>& nums){
//         if(i > j){                          // base condition
//             return 0;
//         }

//         int maxi = INT_MIN;
//         for(int ind = i; ind <= j; ind++){
//             int coins = nums[i-1] * nums[ind] * nums[j+1] + helper(i,ind-1,nums) + helper(ind+1,j,nums);
//             maxi = max(maxi, coins);
//         }

//         return maxi;
//     }
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();

//         // modify the nums array
//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);

//         return helper(1,n,nums);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N*N) 
// Space Complexity: O(N) (Recursion)   +   O(N*N)  (Array)


// class Solution {
// public:
//     int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
//         if(i > j){                          // base condition
//             return 0;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int maxi = INT_MIN;
//         for(int ind = i; ind <= j; ind++){
//             int coins = nums[i-1] * nums[ind] * nums[j+1] + helper(i,ind-1,nums,dp) + helper(ind+1,j,nums,dp);
//             maxi = max(maxi, coins);
//         }

//         return dp[i][j] = maxi;
//     }
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();

//         // modify the nums array
//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

//         return helper(1,n,nums,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N*N)
// Space Complexity: O(N*N)  (Array) 


// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();

//         // modify the nums array
//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);
//         vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

//         for(int i = n; i >= 1; i--){
//             for(int j = 1; j <= n; j++){
//                 if(i > j){                  // base condition
//                     continue;
//                 }

//                 int maxi = INT_MIN;
//                 for(int ind = i; ind <= j; ind++){
//                     int coins = nums[i-1] * nums[ind] * nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
//                     maxi = max(maxi, coins);
//                 }

//                 dp[i][j] = maxi;
//             }
//         }

//         return dp[1][n];
//     }
// };