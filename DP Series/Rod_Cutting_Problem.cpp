/* Problem Statement: Given a rod of length N inches and an array of prices, price[]. 
pricei denotes the value of a piece of length i. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. */


/* GFG   Submission    (Rod Cutting) */


/* Solution 1: */
// Time Complexity: O(2^N) 
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// class Solution{
//   public:
//     int helper(int ind, int price[], int len){
//         if(ind == 0){                            // base condition
//             return len * price[0]; 
//         }
        
//         int notTaken = 0 + helper(ind-1,price,len);
        
//         int taken = INT_MIN;
//         int rodLength = ind+1;
//         if(rodLength <= len){
//             // Here we are not incrementing the ind as same rodLength can be taken any number of times
//             taken = price[ind] + helper(ind,price,len-rodLength);
//         }
        
//         return max(notTaken, taken);
//     }
//     int cutRod(int price[], int n) {
//         int len = n;
//         return helper(n-1,price,len);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N) 
// Space Complexity: O(N) (Recursion)   +   O(N*N)  (Array)


// class Solution{
//   public:
//     int helper(int ind, int price[], int len, vector<vector<int>>& dp){
//         if(ind == 0){                                    // base condition
//             return len * price[0]; 
//         }
//         if(dp[ind][len] != -1){
//             return dp[ind][len];
//         }
        
//         int notTaken = 0 + helper(ind-1,price,len,dp);
        
//         int taken = INT_MIN;
//         int rodLength = ind+1;
//         if(rodLength <= len){
//             // Here we are not incrementing the ind as same rodLength can be taken any number of times
//             taken = price[ind] + helper(ind,price,len-rodLength,dp);
//         }
        
//         return dp[ind][len] = max(notTaken, taken);
//     }
//     int cutRod(int price[], int n) {
//         int len = n;
//         vector<vector<int>> dp(n, vector<int>(len+1, -1));
        
//         return helper(n-1,price,len,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N)
// Space Complexity: O(N*N)  (Array) 


// class Solution{
//   public:
//     int cutRod(int price[], int n) {
//         int len = n;
//         vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
//         for(int i = 0; i <= len; i++){               // base condition
//             dp[0][i] = i * price[0];
//         }
        
//         for(int ind = 1; ind < n; ind++){
//             for(int length = 0; length <= len; length++){
//                 int notTaken = 0 + dp[ind-1][length];
                
//                 int taken = INT_MIN;
//                 int rodLength = ind+1;
//                 if(rodLength <= length){
//                     taken = price[ind] + dp[ind][length-rodLength];
//                 }
                
//                 dp[ind][length] = max(notTaken, taken);
//             }
//         }
        
//         return dp[n-1][len];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*N) 
// Space Complexity: O(N)


/* Two Row Optimization */


// class Solution{
//   public:
//     int cutRod(int price[], int n) {
//         int len = n;
//         vector<int> prev(n+1, 0);
        
//         for(int i = 0; i <= len; i++){                 // base condition    
//             prev[i] = i * price[0];
//         }
        
//         for(int ind = 1; ind < n; ind++){
//             vector<int> cur(n+1, 0);
//             for(int length = 0; length <= len; length++){
//                 int notTaken = 0 + prev[length];
                
//                 int taken = INT_MIN;
//                 int rodLength = ind+1;
//                 if(rodLength <= length){
//                     // as we are in the current ind
//                     taken = price[ind] + cur[length-rodLength];
//                 }
                
//                 cur[length] = max(notTaken, taken);
//             }
//             prev = cur;
//         }
        
//         return prev[len];
//     }
// };



/* One Row Optimization */


// class Solution{
//   public:
//     int cutRod(int price[], int n) {
//         int len = n;
//         vector<int> prev(n+1, 0);
        
//         for(int i = 0; i <= len; i++){             // base condition
//             prev[i] = i * price[0];
//         }
        
//         for(int ind = 1; ind < n; ind++){
//             for(int length = 0; length <= len; length++){
//                 int notTaken = 0 + prev[length];
                
//                 int taken = INT_MIN;
//                 int rodLength = ind+1;
//                 if(rodLength <= length){
//                     taken = price[ind] + prev[length-rodLength];
//                 }
                
//                 prev[length] = max(notTaken, taken);
//             }
//         }
        
//         return prev[len];
//     }
// };