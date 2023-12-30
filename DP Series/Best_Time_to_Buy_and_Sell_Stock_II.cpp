/* Problem Statement: You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve. */


/* Leetcode   Submission    (122. Best Time to Buy and Sell Stock II) */


/* Solution 1: */
// Time Complexity: O(2^N) (Exponential)
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution {
// public:
//     int helper(int ind, int buy, int n, vector<int>& prices){
//         if(ind == n){                       // base condition
//             return 0;
//         }

//         int profit = 0;
//         // We can buy the stock
//         if(buy == 1){           // taken                            // not taken
//             profit = max(-prices[ind]+helper(ind+1,0,n,prices), 0+helper(ind+1,1,n,prices));
//         }
//         // We can sell the stock
//         else{                 // taken                              // not taken
//             profit = max(prices[ind]+helper(ind+1,1,n,prices), 0+helper(ind+1,0,n,prices));
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
//         if(ind == n){                       // base condition
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
//         else{              // taken                              // not taken
//             profit = max(prices[ind]+helper(ind+1,1,n,prices,dp), 0+helper(ind+1,0,n,prices,dp));
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
//         vector<vector<int>> dp(n+1, vector<int>(2, 0));

//         dp[n][0] = dp[n][1] = 0;            // base condition

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int buy = 0; buy <= 1; buy++){
//                 int profit = 0;
//                 // We can buy the stock
//                 if(buy == 1){       // taken                  // not taken
//                     profit = max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
//                 }
//                 // We can sell the stock
//                 else{             // taken                  // not taken
//                     profit = max(prices[ind]+dp[ind+1][1], 0+dp[ind+1][0]);
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
//         vector<int> ahead(2, 0), cur(2, 0);

//         ahead[0] = ahead[1] = 0;            // base condition

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int buy = 0; buy <= 1; buy++){
//                 int profit = 0;
//                 // We can buy the stock
//                 if(buy == 1){       // taken                  // not taken
//                     profit = max(-prices[ind]+ahead[0], 0+ahead[1]);
//                 }
//                 // We can sell the stock
//                 else{             // taken                  // not taken
//                     profit = max(prices[ind]+ahead[1], 0+ahead[0]);
//                 }

//                 cur[buy] = profit;
//             }
//             ahead = cur;
//         }

//         return ahead[1];
//     }
// };



/* Solution 5: */
/* Using 4 varaibles */
// Time Complexity: O(N) 
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();

//         int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
//         aheadNotBuy = aheadBuy = 0; 

//         for(int ind = n-1; ind >= 0; ind--){
            
//             // We can buy the stock
//             curBuy = max(-prices[ind]+aheadNotBuy, 0+aheadBuy);

//             // We can sell the stock
//             curNotBuy = max(prices[ind]+aheadBuy, 0+aheadNotBuy);

//             aheadBuy = curBuy;
//             aheadNotBuy = curNotBuy;
//         }

//         return aheadBuy;
//     }
// };



/* Solution 6: */
/* Simple One Pass */
// Time Complexity: O(N) 
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int mxProfit = 0;
//         for(int i = 1; i < n; i++){
//             if(prices[i] > prices[i-1]){
//                 mxProfit += prices[i] - prices[i-1];
//             }
//         }
        
//         return mxProfit;
//     }
// };