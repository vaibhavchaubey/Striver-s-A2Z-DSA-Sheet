/* Problem Statement: You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer. */


/* Leetcode   Submission    (518. Coin Change II) */


/* Solution 1: */
// Time Complexity: O(2^N) 
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int ind, vector<int>& coins, int amount){
//         if(ind == 0){
//             if(amount % coins[0] == 0){                  // base condition
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }

//         int notTaken = helper(ind-1,coins,amount);

//         int taken = 0;
//         if(coins[ind] <= amount){
//             // Here we are not incrementing the ind as same coin may be chosen unlimited number of times
//             taken = helper(ind,coins,amount-coins[ind]);
//         }

//         return notTaken + taken;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return helper(n-1,coins,amount);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*Amount) 
// Space Complexity: O(N) (Recursion)   +   O(N*Amount)  (Array)


// class Solution {
// public:
//     int helper(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
//         if(ind == 0){
//             if(amount % coins[0] == 0){             // base condition
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }
//         if(dp[ind][amount] != -1){
//             return dp[ind][amount];
//         }

//         int notTaken = helper(ind-1,coins,amount,dp);

//         int taken = 0;
//         if(coins[ind] <= amount){
//             // Here we are not incrementing the ind as same coin may be chosen unlimited number of times
//             taken = helper(ind,coins,amount-coins[ind],dp);
//         }

//         return dp[ind][amount] = notTaken + taken;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, -1));

//         return helper(n-1,coins,amount,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*Amount)
// Space Complexity: O(N*Amount)  (Array) 


// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, 0));

//         for(int i = 0; i <= amount; i++){             // base condition
//             if(i % coins[0] == 0){
//                 dp[0][i] = 1;
//             }
//             // Else condition is automatically fulfilled,
//             // as dp array is initialized to zero
//         }

//         for(int ind = 1; ind < n; ind++){
//             for(int target = 0; target <= amount; target++){
//                 int notTaken = dp[ind-1][target];

//                 int taken = 0;
//                 if(coins[ind] <= target){
//                     taken = dp[ind][target-coins[ind]];
//                 }

//                 dp[ind][target] = notTaken + taken;
//             }
//         }

//         return dp[n-1][amount];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*Amount) 
// Space Complexity: O(Amount)


// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<int> prev(amount+1, 0);

//         for(int i = 0; i <= amount; i++){             // base condition
//             if(i % coins[0] == 0){
//                 prev[i] = 1;
//             }
//             // Else condition is automatically fulfilled,
//             // as prev array is initialized to zero
//         }

//         for(int ind = 1; ind < n; ind++){
//             vector<int> cur(amount+1, 0);
//             for(int target = 0; target <= amount; target++){
//                 int notTaken = prev[target];

//                 int taken = 0;
//                 if(coins[ind] <= target){
//                     // as we are in the current ind
//                     taken = cur[target-coins[ind]];
//                 }

//                 cur[target] = notTaken + taken;
//             }
//             prev = cur;
//         }

//         return prev[amount];
//     }
// };