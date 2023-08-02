/* Leetcode  Submission      (901. Online Stock Span) */

/* Problem Statement: Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's 
price for the current day.
The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) 
for which the stock price was less than or equal to the price of that day. 
Implement the StockSpanner class:
StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price. */



/* Solution: Using monotonic decreasing stack */
/* Declare a monotonic decreasing stack stack, and push stock prices onto stack. For any given call to next(price), 
look at the top of the stack. While the top of the stack has a value (stock price) less than or equal to price, 
it should be included in our answer, so pop it off the stack. */

// Time Complexity: O(1) 
// Space Complexity: O(N) 


// class StockSpanner {
// public:
//     stack<pair<int, int>> st;               // price, span
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         int span = 1;
//         while(!st.empty() && st.top().first <= price){
//             span += st.top().second;
//             st.pop();
//         }
//         st.push({price, span});

//         return span;
//     }
// };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */




/* Codestudio  Submission      (Stock Span) */

/* Problem Statement: Afzal has been working with an organization called 'Money Traders for the past few years. 
The organization is in the money trading business. His manager assigned him a task. Given an array 'prices* which 
denotes stock prices for 'n'days, e.g. 'prices[ i ]' = price of the stock at 'ith' day, Find the stock's span for each day. 
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backward) 
for which the price of the stock was less than today's price. */



/* Solution: Using monotonic decreasing stack */
/* Declare a monotonic decreasing stack stack, and push stock prices onto stack. For any given call to next(price), 
look at the top of the stack. While the top of the stack has a value (stock price) less than or equal to price, 
it should be included in our answer, so pop it off the stack. */

// Time Complexity: O(N) 
// Space Complexity: O(N) 


// vector<int> findStockSpans(vector<int>& prices) {
//     vector<int> ans;
//     stack<pair<int, int>> st;               // price, span
//     for(auto price : prices){
//         int span = 1;
//         while(!st.empty() && st.top().first < price){
//             span += st.top().second;
//             st.pop();
//         }
//         st.push({price, span});
//         ans.push_back(span);
//     }

//     return ans;
// }


