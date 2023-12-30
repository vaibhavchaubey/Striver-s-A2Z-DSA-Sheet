/* Leetcode   Submission    (494. Target Sum) */


/* Problem Statement: You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each 
integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target. */



/* Solution 1: */
// Time Complexity: O(2^N) 
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int ind, int target, vector<int> &num){
//         if(ind == 0){                                         // base condition
//             if(target == 0 && num[0] == 0){                  // two case either take 0 or not take 0
//                 return 2;
//             }
//             if(target == 0 || num[0] == target){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }
//         int notTaken = helper(ind-1,target,num);

//         int taken = 0;
//         if(num[ind] <= target){
//             taken = helper(ind-1,target-num[ind],num);
//         }

//         return notTaken + taken;
//     }
//     int findWays(vector<int> &num, int tar)
//     {
//         int n = num.size();  
//         return helper(n-1,tar,num);
//     }
//     int countPartitions(int n, int d, vector<int> &arr) {
//         int totalSum = 0;
//         for(int i = 0; i < n; i++){
//             totalSum += arr[i];
//         }
//         // Edge Case
//         if(totalSum - d < 0 || (totalSum - d) % 2 != 0){
//             return 0;
//         }

//         return findWays(arr, (totalSum - d) / 2);
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         return countPartitions(n, target, nums);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*K) 
// Space Complexity: O(N) (Recursion)   +   O(N*K)  (Array)


// class Solution {
// public:
//         int helper(int ind, int target, vector<int> &num, vector<vector<int>>& dp){
//         if(ind == 0){                                         // base condition
//             if(target == 0 && num[0] == 0){                  // two case either take 0 or not take 0
//                 return 2;
//             }
//             if(target == 0 || num[0] == target){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }
//         if(dp[ind][target] != -1){
//             return dp[ind][target];
//         }

//         int notTaken = helper(ind-1,target,num,dp);

//         int taken = 0;
//         if(num[ind] <= target){
//             taken = helper(ind-1,target-num[ind],num,dp);
//         }

//         return dp[ind][target] = notTaken + taken;
//     }
//     int findWays(vector<int> &num, int tar)
//     {
//         int n = num.size();
//         vector<vector<int>> dp(n, vector<int>(tar+1, -1));

//         return helper(n-1,tar,num,dp);
//     }
//     int countPartitions(int n, int d, vector<int> &arr) {
//         int totalSum = 0;
//         for(int i = 0; i < n; i++){
//             totalSum += arr[i];
//         }
//         // Edge Case
//         if(totalSum - d < 0 || (totalSum - d) % 2 != 0){
//             return 0;
//         }

//         return findWays(arr, (totalSum - d) / 2);
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         return countPartitions(n, target, nums);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*K)
// Space Complexity: O(N*K)  (Array) 


// class Solution {
// public:
//     int findWays(vector<int> &num, int tar)
//     {
//         int n = num.size();
//         vector<vector<int>> dp(n, vector<int>(tar+1, 0));

//         if(num[0] == 0){                         // 2 cases - pick and not pick      // base condition
//             dp[0][0] = 2;                       // ind = 0, target = 0    
//         }
//         else{                                // 1 case - not pick
//             dp[0][0] = 1;
//         }
//         if(num[0] != 0 && num[0] <= tar){            // 1 case - pick        // base condition
//             dp[0][num[0]] = 1;
//         }

//         for(int ind = 1; ind < n; ind++){
//             for(int target = 0; target <= tar; target++){
//                 int notTaken = dp[ind-1][target];

//                 int taken = 0;
//                 if(num[ind] <= target){
//                     taken = dp[ind-1][target-num[ind]];
//                 } 
//                 dp[ind][target] = notTaken + taken;
//             }
//         }

//         return dp[n-1][tar];
//     }
//     int countPartitions(int n, int d, vector<int> &arr) {
//         int totalSum = 0;
//         for(int i = 0; i < n; i++){
//             totalSum += arr[i];
//         }
//         // Edge Case
//         if(totalSum - d < 0 || (totalSum - d) % 2 != 0){
//             return 0;
//         }

//         return findWays(arr, (totalSum - d) / 2);
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         return countPartitions(n, target, nums);
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*K) 
// Space Complexity: O(K)


// class Solution {
// public:
//     int findWays(vector<int> &num, int tar)
//     {
//         int n = num.size();
//         vector<int> prev(tar+1, 0);

//         if(num[0] == 0){                 // 2 cases - pick and not pick  // base condition
//             prev[0] = 2;                // ind = 0, target = 0    
//         }
//         else{                          // 1 case - not pick
//             prev[0] = 1;
//         }
//         if(num[0] != 0 && num[0] <= tar){            // 1 case - pick   // base condition
//             prev[num[0]] = 1;
//         }

//         for(int ind = 1; ind < n; ind++){
//             vector<int> cur(tar+1, 0);
//             for(int target = 0; target <= tar; target++){
//                 int notTaken = prev[target];

//                 int taken = 0;
//                 if(num[ind] <= target){
//                     taken = prev[target-num[ind]];
//                 } 
//                 cur[target] = notTaken + taken;
//             }
//             prev = cur;
//         }

//         return prev[tar];
//     }
//     int countPartitions(int n, int d, vector<int> &arr) {
//         int totalSum = 0;
//         for(int i = 0; i < n; i++){
//             totalSum += arr[i];
//         }
//         // Edge Case
//         if(totalSum - d < 0 || (totalSum - d) % 2 != 0){
//             return 0;
//         }

//         return findWays(arr, (totalSum - d) / 2);
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         return countPartitions(n, target, nums);
//     }
// };