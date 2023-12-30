/* Problem Statement: Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. 
Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times. */


/* GFG   Submission    (Knapsack with Duplicate Items) */


/* Solution 1: */
// Time Complexity: O(2^N) 
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution{
// public:
//     int helper(int ind, int W, int val[], int wt[]){
//         if(ind == 0){                                   // base condition
//             return ((int)(W/wt[0])) * val[0];
//         }
        
//         int notTaken = 0 + helper(ind-1,W,val,wt);
        
//         int taken = INT_MIN;
//         if(wt[ind] <= W){
//             // Here we are not incrementing the ind as Each item can be taken any number of times
//             taken = val[ind] + helper(ind,W-wt[ind],val,wt);
//         }
        
//         return max(notTaken, taken);
//     }
//     int knapSack(int N, int W, int val[], int wt[])
//     {
//         return helper(N-1,W,val,wt);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*W)
// Space Complexity: O(N) (Recursion)   +   O(N*W)  (Array)


// class Solution{
// public:
//     int helper(int ind, int W, int val[], int wt[], vector<vector<int>>& dp){
//         if(ind == 0){                                   // base condition
//             return ((int)(W/wt[0])) * val[0];
//         }
//         if(dp[ind][W] != -1){
//             return dp[ind][W];
//         }
        
//         int notTaken = 0 + helper(ind-1,W,val,wt,dp);
        
//         int taken = INT_MIN;
//         if(wt[ind] <= W){
//             // Here we are not incrementing the ind as Each item can be taken any number of times
//             taken = val[ind] + helper(ind,W-wt[ind],val,wt,dp);
//         }
        
//         return dp[ind][W] = max(notTaken, taken);
//     }
//     int knapSack(int N, int W, int val[], int wt[])
//     {
//         vector<vector<int>> dp(N, vector<int>(W+1, -1));
        
//         return helper(N-1,W,val,wt,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*W) 
// Space Complexity: O(N*W)  (Array) 


// class Solution{
// public:
//     int knapSack(int N, int W, int val[], int wt[])
//     {
//         vector<vector<int>> dp(N, vector<int>(W+1, 0));
        
//         for(int i = wt[0]; i <= W; i++){                // base condition
//             dp[0][i] = ((int)(i/wt[0])) * val[0];
//         }
        
//         for(int ind = 1; ind < N; ind++){
//             for(int cap = 0; cap <= W; cap++){
//                 int notTaken = 0 + dp[ind-1][cap];
                
//                 int taken = INT_MIN;
//                 if(wt[ind] <= cap){
//                     taken = val[ind] + dp[ind][cap-wt[ind]];
//                 }
                
//                 dp[ind][cap] = max(notTaken, taken);
//             }
//         }
        
//         return dp[N-1][W];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*W)
// Space Complexity: O(W)


/* Two Row Optimization */


// class Solution{
// public:
//     int knapSack(int N, int W, int val[], int wt[])
//     {
//         vector<int> prev(W+1, 0);
        
//         for(int i = wt[0]; i <= W; i++){                // base condition
//             prev[i] = ((int)(i/wt[0])) * val[0];
//         }
        
//         for(int ind = 1; ind < N; ind++){
//             vector<int> cur(W+1, 0);
//             for(int cap = 0; cap <= W; cap++){
//                 int notTaken = 0 + prev[cap];
                
//                 int taken = INT_MIN;
//                 if(wt[ind] <= cap){
//                     // as we are in the current ind
//                     taken = val[ind] + cur[cap-wt[ind]];
//                 }
                
//                 cur[cap] = max(notTaken, taken);
//             }
//             prev = cur;
//         }
        
//         return prev[W];
//     }
// };



/* One Row Optimization */


// class Solution{
// public:
//     int knapSack(int N, int W, int val[], int wt[])
//     {
//         vector<int> prev(W+1, 0);
        
//         for(int i = wt[0]; i <= W; i++){                // base condition
//             prev[i] = ((int)(i/wt[0])) * val[0];
//         }
        
//         for(int ind = 1; ind < N; ind++){
//             for(int cap = 0; cap <= W; cap++){
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