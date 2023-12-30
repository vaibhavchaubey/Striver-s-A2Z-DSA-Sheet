/* Problem Statement: Given an integer array nums, return the length of the longest strictly increasing subsequence. */


/* Leetcode   Submission    (300. Longest Increasing Subsequence) */


/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: O(2^N) (Exponential)
// Space Complexity: O(N) (Recursion)


// class Solution {
// public:
//     int helper(int ind, int prev_index, int n, vector<int>& nums){
//         if(ind == n){                           // base condition
//             return 0;
//         }

//         int notTaken = 0 + helper(ind+1,prev_index,n,nums);

//         int taken = 0;
//         if(prev_index == -1 || nums[ind] > nums[prev_index]){
//             taken = 1 + helper(ind+1,ind,n,nums);
//         }

//         return max(notTaken, taken);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();

//         return helper(0,-1,n,nums);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N) 
// Space Complexity: O(N) (Recursion)   +   O(N*N)  (Array)


// class Solution {
// public:
//     int helper(int ind, int prev_index, int n, vector<int>& nums, vector<vector<int>>& dp){
//         if(ind == n){                           // base condition
//             return 0;
//         }

//         if(dp[ind][prev_index+1] != -1){
//             return dp[ind][prev_index+1];
//         }

//         int notTaken = 0 + helper(ind+1,prev_index,n,nums,dp);

//         int taken = 0;
//         if(prev_index == -1 || nums[ind] > nums[prev_index]){
//             taken = 1 + helper(ind+1,ind,n,nums,dp);
//         }

//         return dp[ind][prev_index+1] = max(notTaken, taken);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n+1, -1));

//         return helper(0,-1,n,nums,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N)
// Space Complexity: O(N*N)  (Array) 


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

//         // As dp array is intialized to 0, we have already covered the base case
        
//         for(int ind = n-1; ind >= 0; ind--){
//             for(int prev_index = ind-1; prev_index >= -1; prev_index--){
//                 int notTaken = 0 + dp[ind+1][prev_index+1];

//                 int taken = 0;
//                 if(prev_index == -1 || nums[ind] > nums[prev_index]){
//                     taken = 1 + dp[ind+1][ind+1];
//                 }

//                 dp[ind][prev_index+1] = max(notTaken, taken);
//             }
//         }

//         return dp[0][0];            // return dp[0][-1+1];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*N) 
// Space Complexity: O(N)


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> next(n+1, 0), cur(n+1, 0);

//         // As next and cur array is intialized to 0, we have already covered the base case

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int prev_index = ind-1; prev_index >= -1; prev_index--){
//                 int notTaken = 0 + next[prev_index+1];

//                 int taken = 0;
//                 if(prev_index == -1 || nums[ind] > nums[prev_index]){
//                     taken = 1 + next[ind+1];
//                 }

//                 cur[prev_index+1] = max(notTaken, taken);
//             }
//             next = cur;
//         }

//         return cur[0];            // return cur[-1+1];
//     }
// };



/* Solution 5: */
/* Tabulation Algorithm */
// Time Complexity: O(N*N) 
// Space Complexity: O(N)


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);

//         int ans = -1;
//         for(int i = 0; i < n; i++){
//             for(int prev_index = 0; prev_index < i; prev_index++){
//                 if(nums[prev_index] < nums[i]){
//                     dp[i] = max(dp[i], 1 + dp[prev_index]);
//                 }
//             }
//             ans = max(ans, dp[i]);
//         }
        
//         return ans;
//     }
// };



/* Solution 6: */
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


