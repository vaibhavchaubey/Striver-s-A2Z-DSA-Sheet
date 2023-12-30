/* Problem Statement: You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). */


/* Leetcode   Submission    (188. Best Time to Buy and Sell Stock IV) */


/* Solution 1: */
// Time Complexity: (Exponential)
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int ind, int buy, int cap, int n, vector<int>& prices){
//         if(ind == n || cap == 0){                       // base condition
//             return 0;
//         }
        
//         int profit = 0;
//         // We can buy the stock
//         if(buy == 1){           // taken                            // not taken
//             profit = max(-prices[ind]+helper(ind+1,0,cap,n,prices), 0+helper(ind+1,1,cap,n,prices));
//         }
//         // We can sell the stock
//         else{                 // taken                              // not taken
//             profit = max(prices[ind]+helper(ind+1,1,cap-1,n,prices), 0+helper(ind+1,0,cap,n,prices));
//         }

//         return profit;
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();

//         return helper(0,1,k,n,prices);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*2*k)  
// Space Complexity: O(N) (Recursion)   +   O(N*2*k)   (Array)


// class Solution {
// public:
//     int helper(int ind, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){
//         if(ind == n || cap == 0){                       // base condition
//             return 0;
//         }

//         if(dp[ind][buy][cap] != -1){
//             return dp[ind][buy][cap];
//         }

//         int profit = 0;
//         // We can buy the stock
//         if(buy == 1){           // taken                                       // not taken
//             profit = max(-prices[ind]+helper(ind+1,0,cap,n,prices,dp), 0+helper(ind+1,1,cap,n,prices,dp));
//         }
//         // We can sell the stock
//         else{                 // taken                                      // not taken
//             profit = max(prices[ind]+helper(ind+1,1,cap-1,n,prices,dp), 0+helper(ind+1,0,cap,n,prices,dp));
//         }

//         return dp[ind][buy][cap] = profit;
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

//         return helper(0,1,k,n,prices,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*2*k) 
// Space Complexity: O(N*2*k)   (Array) 


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

//         // As dp array is intialized to 0, we have already covered the base case

//         for(int ind = n-1; ind >= 0; ind--){                     // ind = n is covered in base case
//             for(int buy = 0; buy <= 1; buy++){
//                 for(int cap = 1; cap <= k; cap++){              // cap = 0 is covered in base case
//                     int profit = 0;
//                     // We can buy the stock
//                     if(buy == 1){          // taken                       // not taken
//                         profit = max(-prices[ind]+dp[ind+1][0][cap], 0+dp[ind+1][1][cap]);
//                     }
//                     // We can sell the stock
//                     else{                 // taken                        // not taken
//                         profit = max(prices[ind]+dp[ind+1][1][cap-1], 0+dp[ind+1][0][cap]);
//                     }

//                     dp[ind][buy][cap] = profit;
//                 }
//             }
//         }

//         return dp[0][1][k];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*2*k)  
// Space Complexity: O(k)


// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//          vector<vector<int>> ahead(2, vector<int>(k+1, 0)), cur(2, vector<int>(k+1, 0));

//         // As ahead and cur array is intialized to 0, we have already covered the base case

//         for(int ind = n-1; ind >= 0; ind--){                     // ind = n is covered in base case
//             for(int buy = 0; buy <= 1; buy++){
//                 for(int cap = 1; cap <= k; cap++){              // cap = 0 is covered in base case
//                     int profit = 0;
//                     // We can buy the stock
//                     if(buy == 1){          // taken                   // not taken
//                         profit = max(-prices[ind]+ahead[0][cap], 0+ahead[1][cap]);
//                     }
//                     // We can sell the stock
//                     else{                 // taken                    // not taken
//                         profit = max(prices[ind]+ahead[1][cap-1], 0+ahead[0][cap]);
//                     }

//                     cur[buy][cap] = profit;
//                 }
//             }
//             ahead = cur;
//         }

//         return ahead[1][k];
//     }
// };