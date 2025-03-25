/* Leetcode  Submission    (121. Best Time to Buy and Sell Stock) */

/* Problem Statement: You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int maxProfit = 0, minSoFar = INT_MAX;
//         for(int i = 0; i < n; i++){
//             minSoFar = min(minSoFar, prices[i]);
//             maxProfit = max(maxProfit, prices[i] - minSoFar);
//         }
        
//         return maxProfit;
//     }
// };




/* GFG  Submission    (Stock buy and sell) */

/* Problem Statement: The cost of stock on each day is given in an array A[] of size N. 
Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, the output should be in a single line, i.e. It's important to move to a new/next 
line for printing the output of other test cases. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// void stockBuySell(int price[], int n) {
//     int start = 0, end = 0;
//     bool noProfit = true;
//     for(int i = 0; i < n-1; i++){
//         if(price[i] > price[i+1]){
//             end = i;
//             if(start != end){
//                 cout<<"("<<start<<" "<<end<<")"<<" ";
//                 noProfit = false;
//             }
//             start = i+1;
//         }
//     }
//     if(price[n-2] < price[n-1]){
//         end = n-1;
//         cout<<"("<<start<<" "<<end<<")"<<" ";
//         noProfit = false;
//     }
    
//     if(noProfit){
//         cout<<"No Profit";
//     }
    
//     cout<<endl;
// }