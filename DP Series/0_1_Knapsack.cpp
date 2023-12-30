/* Problem Statement: A thief wants to rob a store. He is carrying a bag of capacity W. 
The store has ‘n’ items. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. 
He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. 
We need to find the maximum value of items that the thief can steal. */


/* GFG   Submission    (0 - 1 Knapsack Problem) */


/* Solution 1: */
// Time Complexity: O(2^N) 
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution
// {
//     public:
//     int helper(int wt[], int val[], int ind, int W){
//         if(ind == 0){
//             if(wt[0] <= W){
//                 return val[0];
//             }
//             else{
//                 return 0;
//             }
//         }
//         int notTaken = 0 + helper(wt,val,ind-1,W);
        
//         int taken = INT_MIN;
//         if(wt[ind] <= W){
//             taken = val[ind] + helper(wt,val,ind-1,W-wt[ind]);
//         }
        
//         return max(notTaken, taken);
//     }
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//        return helper(wt,val,n-1,W);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*W)
// Space Complexity: O(N) (Recursion)   +   O(N*W)  (Array)


// class Solution
// {
//     public:
//     int helper(int wt[], int val[], int ind, int W, vector<vector<int>>& dp){
//         if(ind == 0){
//             if(wt[0] <= W){
//                 return val[0];
//             }
//             else{
//                 return 0;
//             }
//         }
//         if(dp[ind][W] != -1){
//             return dp[ind][W];
//         }
        
//         int notTaken = 0 + helper(wt,val,ind-1,W,dp);
        
//         int taken = INT_MIN;
//         if(wt[ind] <= W){
//             taken = val[ind] + helper(wt,val,ind-1,W-wt[ind],dp);
//         }
        
//         return dp[ind][W] = max(notTaken, taken);
//     }
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//         vector<vector<int>> dp(n, vector<int>(W+1, -1));
        
//        return helper(wt,val,n-1,W,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*W) 
// Space Complexity: O(N*W)  (Array) 


// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//         vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
//         for(int i = wt[0]; i <= W; i++){              // base condition
//             dp[0][i] = val[0];
//         }
        
//         for(int ind = 1; ind < n; ind++){
//             for(int cap = 0; cap <= W; cap++){
//                 int notTaken = 0 + dp[ind-1][cap];
                
//                 int taken = INT_MIN;
//                 if(wt[ind] <= cap){
//                     taken = val[ind] + dp[ind-1][cap-wt[ind]];
//                 }
                
//                 dp[ind][cap] = max(notTaken, taken);
//             }
//         }
        
//         return dp[n-1][W];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*W)
// Space Complexity: O(W)


/* Two Row Optimization */

// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//         vector<int> prev(W+1, 0);
        
//         for(int i = wt[0]; i <= W; i++){              // base condition
//             prev[i] = val[0];
//         }
        
//         for(int ind = 1; ind < n; ind++){
//             vector<int> cur(W+1, 0);
//             for(int cap = 0; cap <= W; cap++){
//                 int notTaken = 0 + prev[cap];
                
//                 int taken = INT_MIN;
//                 if(wt[ind] <= cap){
//                     taken = val[ind] + prev[cap-wt[ind]];
//                 }
                
//                 cur[cap] = max(notTaken, taken);
//             }
//             prev = cur;
//         }
        
//         return prev[W];
//     }
// };


/* One Row Optimization */

// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//         vector<int> prev(W+1, 0);
        
//         for(int i = wt[0]; i <= W; i++){              // base condition
//             prev[i] = val[0];
//         }
        
//         for(int ind = 1; ind < n; ind++){
//             for(int cap = W; cap >= 0; cap--){
//                 int notTaken = 0 + prev[cap];
                
//                 int taken = INT_MIN;
//                 if(wt[ind] <= cap){
//                     taken = val[ind] + prev[cap-wt[ind]];
//                 }
                
//                 prev[cap] = max(notTaken, taken);
//             }
//         }
        
//         return prev[W];
//     }
// };