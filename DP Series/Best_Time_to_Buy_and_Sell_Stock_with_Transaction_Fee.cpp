/* Problem Statement: You are given an array prices where prices[i] is the price of a given stock on the ith day, 
and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay 
the transaction fee for each transaction.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). */


/* Leetcode   Submission    (714. Best Time to Buy and Sell Stock with Transaction Fee) */


/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: O(2^N) (Exponential)
// Space Complexity: O(N) (Recursion)


// class Solution {
// public:
//     int helper(int ind, int buy, int fee, int n, vector<int>& prices){
//         if(ind == n){                       // base condition
//             return 0;
//         }

//         int profit = 0;
//         // We can buy the stock
//         if(buy == 1){           // taken                            // not taken
//             profit = max(-prices[ind] + helper(ind+1,0,fee,n,prices), 0 + helper(ind+1,1,fee,n,prices));
//         }
//         // We can sell the stock
//         else{             // taken   - Transaction Fee                           // not taken
//             profit = max(prices[ind] - fee + helper(ind+1,1,fee,n,prices), 0 + helper(ind+1,0,fee,n,prices));
//         }

//         return profit;
//     }
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();

//         return helper(0,1,fee,n,prices);
        
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*2) 
// Space Complexity: O(N) (Recursion)   +   O(N*2)  (Array)


// class Solution {
// public:
//     int helper(int ind, int buy, int fee, int n, vector<int>& prices, vector<vector<int>>& dp){
//         if(ind == n){                       // base condition
//             return 0;
//         }

//         if(dp[ind][buy] != -1){
//             return dp[ind][buy];
//         }
//         int profit = 0;
//         // We can buy the stock
//         if(buy == 1){             // taken                                         // not taken
//             profit = max(-prices[ind] + helper(ind+1,0,fee,n,prices,dp), 0 + helper(ind+1,1,fee,n,prices,dp));
//         }
//         // We can sell the stock
//         else{               // taken   - Transaction Fee                                 // not taken
//             profit = max(prices[ind] - fee + helper(ind+1,1,fee,n,prices,dp), 0 + helper(ind+1,0,fee,n,prices,dp));
//         }

//         return dp[ind][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));

//         return helper(0,1,fee,n,prices,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*2)
// Space Complexity: O(N*2)  (Array) 


// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1, vector<int>(2, 0));

//         dp[n][0] = dp[n][1] = 0;            // base condition

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int buy = 0; buy <= 1; buy++){
//                 int profit = 0;
//                 // We can buy the stock
//                 if(buy == 1){         // taken                  // not taken
//                     profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
//                 }
//                 // We can sell the stock
//                 else{             // taken   - Transaction Fee         // not taken
//                     profit = max(prices[ind] - fee + dp[ind+1][1], 0 + dp[ind+1][0]);
//                 }

//                 dp[ind][buy] = profit;
//             }
//         }

//         return dp[0][1];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*2) 
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         vector<int> ahead(2, 0), cur(2, 0);

//         ahead[0] = ahead[1] = 0;            // base condition

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int buy = 0; buy <= 1; buy++){
//                 int profit = 0;
//                 // We can buy the stock
//                 if(buy == 1){       // taken                  // not taken
//                     profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
//                 }
//                 // We can sell the stock
//                 else{             // taken   - Transaction Fee   // not taken
//                     profit = max(prices[ind] - fee + ahead[1], 0 + ahead[0]);
//                 }

//                 cur[buy] = profit;
//             }
//             ahead = cur;
//         }

//         return ahead[1];
//     }
// };