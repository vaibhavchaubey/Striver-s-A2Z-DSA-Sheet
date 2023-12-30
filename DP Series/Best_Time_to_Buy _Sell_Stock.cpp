/* Leetcode   Submission    (121. Best Time to Buy and Sell Stock) */


/* Problem Statement: You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */



/* Solution: */
// Time Complexity: (N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int mxProfit = 0, minSoFar = INT_MAX;
//         for(int i = 0; i < n; i++){
//             minSoFar = min(minSoFar,prices[i]);
//             mxProfit = max(mxProfit,prices[i]-minSoFar);
//         }
        
//         return mxProfit;
//     }
// };
