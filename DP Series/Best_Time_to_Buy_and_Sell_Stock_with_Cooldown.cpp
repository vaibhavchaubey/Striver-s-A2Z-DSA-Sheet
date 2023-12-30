/* Problem Statement: You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share 
of the stock multiple times) with the following restrictions:
    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). */


/* Leetcode   Submission    (309. Best Time to Buy and Sell Stock with Cooldown) */


/* Solution 1: */
// Time Complexity: O(2^N) (Exponential)
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int ind, int buy, int n, vector<int>& prices){
//         if(ind >= n){                       // base condition
//             return 0;
//         }

//         int profit = 0;
//         // We can buy the stock
//         if(buy == 1){           // taken                            // not taken
//             profit = max(-prices[ind]+helper(ind+1,0,n,prices), 0+helper(ind+1,1,n,prices));
//         }
//         // We can sell the stock
//         else{                 // taken   // +2 for cooldown          // not taken
//             profit = max(prices[ind]+helper(ind+2,1,n,prices), 0+helper(ind+1,0,n,prices));
//         }

//         return profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();

//         return helper(0,1,n,prices);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*2) 
// Space Complexity: O(N) (Recursion)   +   O(N*2)  (Array)


// class Solution {
// public:
//     int helper(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>& dp){
//         if(ind >= n){                       // base condition
//             return 0;
//         }

//         if(dp[ind][buy] != -1){
//             return dp[ind][buy];
//         }

//         int profit = 0;
//         // We can buy the stock
//         if(buy == 1){           // taken                            // not taken
//             profit = max(-prices[ind]+helper(ind+1,0,n,prices,dp), 0+helper(ind+1,1,n,prices,dp));
//         }
//         // We can sell the stock
//         else{                // taken       // +2 for cooldown          // not taken
//             profit = max(prices[ind]+helper(ind+2,1,n,prices,dp), 0+helper(ind+1,0,n,prices,dp));
//         }

//         return dp[ind][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));

//         return helper(0,1,n,prices,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*2)
// Space Complexity: O(N*2)  (Array) 


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n+2, vector<int>(2, 0));

//         // As dp array is intialized to 0, we have already covered the base case

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int buy = 0; buy <= 1; buy++){
//                 int profit = 0;
//                 // We can buy the stock
//                 if(buy == 1){       // taken                  // not taken
//                     profit = max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
//                 }
//                 // We can sell the stock
//                 else{         // taken    // +2 for cooldown   // not taken
//                     profit = max(prices[ind]+dp[ind+2][1], 0+dp[ind+1][0]);
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
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> front2(2, 0); 
//         vector<int> front1(2, 0); 
//         vector<int> cur(2, 0); 

//         // As front2, front1 and cur array is intialized to 0, we have already covered the base case

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int buy = 0; buy <= 1; buy++){
//                 int profit = 0;
//                 // We can buy the stock
//                 if(buy == 1){       // taken                  // not taken
//                     profit = max(-prices[ind]+front1[0], 0+front1[1]);
//                 }
//                 // We can sell the stock
//                 else{                // taken              // not taken
//                     profit = max(prices[ind]+front2[1], 0+front1[0]);
//                 }              // front2 for cooldown             

//                 cur[buy] = profit;
//             }
//             front2 = front1;
//             front1 = cur;
//         }

//         return cur[1];
//     }
// };