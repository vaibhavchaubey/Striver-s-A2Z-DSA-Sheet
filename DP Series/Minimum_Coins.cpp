/* Leetcode   Submission    (322. Coin Change) */


/* Problem Statement: You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin. */



/* Solution 1: */
// Time Complexity: O(2^N) 
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int ind, vector<int>& coins, int amount){
//         if(ind == 0){                            // base condition
//             if(amount % coins[0] == 0){
//                 return (amount / coins[0]);
//             }
//             else{
//                 return 1e9;
//             }
//         }
//         int notTaken = 0 + helper(ind-1,coins,amount);

//         int taken = INT_MAX;
//         if(coins[ind] <= amount){
//             // Here we are not incrementing the ind as same coin may be chosen unlimited number of times
//             taken = 1 + helper(ind,coins,amount-coins[ind]);
//         }

//         return min(notTaken, taken);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         int ans = helper(n-1, coins, amount);

//         if(ans >= 1e9){
//             return -1;
//         }

//         return ans;
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*Amount)
// Space Complexity: O(N) (Recursion)   +   O(N*Amount)  (Array)


// class Solution {
// public:
//     int helper(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
//         if(ind == 0){                                   // base condition
//             if(amount % coins[0] == 0){                 
//                 return (amount / coins[0]);
//             }
//             else{
//                 return 1e9;
//             }
//         }
//         if(dp[ind][amount] != -1){
//             return dp[ind][amount];
//         }

//         int notTaken = 0 + helper(ind-1,coins,amount,dp);

//         int taken = INT_MAX;
//         if(coins[ind] <= amount){
//             // Here we are not incrementing the ind as same coin may be chosen unlimited number of times
//             taken = 1 + helper(ind,coins,amount-coins[ind],dp);
//         }

//         return dp[ind][amount] = min(notTaken, taken);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, -1));


//         int ans = helper(n-1, coins, amount, dp);
        
//         if(ans >= 1e9){
//             return -1;
//         }

//         return ans;
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*Amount) 
// Space Complexity: O(N*Amount)  (Array) 


// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, 0));

//         for(int i = 0; i <= amount; i++){                // base condition
//             if(i % coins[0] == 0){
//                 dp[0][i] = (i / coins[0]);
//             }
//             else{
//                 dp[0][i] = 1e9;
//             }
//         }

//         for(int ind = 1; ind < n; ind++){
//             for(int target = 0; target <= amount; target++){
//                 int notTaken = 0 + dp[ind-1][target];

//                 int taken = INT_MAX;
//                 if(coins[ind] <= target){
//                     taken = 1 + dp[ind][target-coins[ind]];
//                 }

//                 dp[ind][target] = min(notTaken, taken);
//             }
//         }

//         int ans = dp[n-1][amount];
        
//         if(ans >= 1e9){
//             return -1;
//         }

//         return ans;
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*Amount)  
// Space Complexity: O(Amount)


// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<int> prev(amount+1, 0);

//         for(int i = 0; i <= amount; i++){                // base condition
//             if(i % coins[0] == 0){
//                 prev[i] = (i / coins[0]);
//             }
//             else{
//                 prev[i] = 1e9;
//             }
//         }

//         for(int ind = 1; ind < n; ind++){
//             vector<int> cur(amount+1, 0);
//             for(int target = 0; target <= amount; target++){
//                 int notTaken = 0 + prev[target];

//                 int taken = INT_MAX;
//                 if(coins[ind] <= target){
//                     // as we are in the current ind
//                     taken = 1 + cur[target-coins[ind]];
//                 }

//                 cur[target] = min(notTaken, taken);
//             }
//             prev = cur;
//         }

//         int ans = prev[amount];
        
//         if(ans >= 1e9){
//             return -1;
//         }

//         return ans;
//     }
// };