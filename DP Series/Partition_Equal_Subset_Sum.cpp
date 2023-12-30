/* Leetcode   Submission    (416. Partition Equal Subset Sum) */


/* Problem Statement: Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise. */



/* Solution 1: */
// Time Complexity: O(2^N) + O(N)
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     bool helper(int ind, int target, vector<int> &arr){
//         if(target == 0){                     // base condition
//             return true;
//         }
//         if(ind == 0){                       // base condition
//             return arr[0] == target; 
//         }
//         bool notTaken = helper(ind-1,target,arr);

//         bool taken = false;
//         if(arr[ind] <= target){
//             taken = helper(ind-1,target-arr[ind],arr);
//         }
//         return notTaken || taken;
//     }
//     bool subsetSumToK(int n, int k, vector<int> &arr) {
//         return helper(n-1,k,arr);
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int totalSum = 0;
//         for(int i = 0; i < n; i++){
//             totalSum += nums[i];
//         }
//         if(totalSum % 2 != 0){              // totalSum is odd
//             return false;
//         }
//         int target = totalSum/2;            // totalSum is even

//         return subsetSumToK(n, target, nums);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*K) + O(N)
// Space Complexity: O(N) (Recursion)   +   O(N*K)  (Array)


// class Solution {
// public:
//     bool helper(int ind, int target, vector<int> &arr, vector<vector<int>>& dp){
//         if(target == 0){           // base condition
//             return true;
//         }
//         if(ind == 0){             // base condition
//             return arr[0] == target;
//         }
//         if(dp[ind][target] != -1){
//             return dp[ind][target];
//         }
//         bool notTaken = helper(ind-1,target,arr,dp);

//         bool taken = false;
//         if(arr[ind] <= target){
//             taken = helper(ind-1,target-arr[ind],arr,dp);
//         }
//         return dp[ind][target] = notTaken || taken;
//     }
//     bool subsetSumToK(int n, int k, vector<int> &arr) {
//         vector<vector<int>> dp(n, vector<int>(k+1, -1));            

//         return helper(n-1,k,arr,dp);
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int totalSum = 0;
//         for(int i = 0; i < n; i++){
//             totalSum += nums[i];
//         }
//         if(totalSum % 2 != 0){              // totalSum is odd
//             return false;
//         }
//         int target = totalSum/2;            // totalSum is even

//         return subsetSumToK(n, target, nums);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*K) + O(N)
// Space Complexity: O(N*K)  (Array) 


// class Solution {
// public:
//     bool subsetSumToK(int n, int k, vector<int> &arr) {
//         vector<vector<bool>> dp(n, vector<bool>(k+1, false));  
//         for(int i = 0; i < n; i++){       // base condition
//             dp[i][0] = true;
//         }
//         if(arr[0] <= k){                 // base condition
//             dp[0][arr[0]] = true;
//         }

//         for(int ind = 1; ind < n; ind++){
//             for(int target = 1; target <= k; target++){
//                 bool notTaken = dp[ind-1][target];

//                 bool taken = false;
//                 if(arr[ind] <= target){
//                     taken = dp[ind-1][target-arr[ind]];
//                 }
//                 dp[ind][target] = notTaken || taken;
//             }
//          }

//         return dp[n-1][k];
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int totalSum = 0;
//         for(int i = 0; i < n; i++){
//             totalSum += nums[i];
//         }
//         if(totalSum % 2 != 0){              // totalSum is odd
//             return false;
//         }
//         int target = totalSum/2;            // totalSum is even

//         return subsetSumToK(n, target, nums);
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*K) + O(N)
// Space Complexity: O(K)


// class Solution {
// public:
//     bool subsetSumToK(int n, int k, vector<int> &arr) {
//         vector<bool> prev(k+1, false);

//         prev[0] = true;                   // base condition

//         if(arr[0] <= k){                 // base condition
//             prev[arr[0]] = true;
//         }

//         for(int ind = 1; ind < n; ind++){
//             vector<bool> cur(k+1, false);
//             cur[0] = true;                       // base condition
//             for(int target = 1; target <= k; target++){
//                 bool notTaken = prev[target];

//                 bool taken = false;
//                 if(arr[ind] <= target){
//                     taken = prev[target-arr[ind]];
//                 }
//                 cur[target] = notTaken || taken;
//             }
//                prev = cur;
//          }

//         return prev[k];
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int totalSum = 0;
//         for(int i = 0; i < n; i++){
//             totalSum += nums[i];
//         }
//         if(totalSum % 2 != 0){              // totalSum is odd
//             return false;
//         }
//         int target = totalSum/2;            // totalSum is even

//         return subsetSumToK(n, target, nums);
//     }
// };