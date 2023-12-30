/* Fibonacci Series */

/* Leetcode   Submission    (509. Fibonacci Number) */

/* Problem Statement: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n). */



/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: O(2^N) (Exponential)
// Space Complexity: O(N) (Recursion)


// class Solution {
// public:
//     int helper(int n){
//         if(n <= 1){                              // base condition
//             return n;
//         }
//         return helper(n-1) + helper(n-2);
//     }
//     int fib(int n) {

//         return helper(n);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N) 
// Space Complexity: O(N) (Recursion)   +   O(N*N)  (Array)


// class Solution {
// public:
//     int helper(int n, vector<int>& dp){
//         if(n <= 1){                     // base condition
//             return n;
//         }
//         if(dp[n] != -1){
//             return dp[n];
//         }

//         return dp[n] = helper(n-1,dp) + helper(n-2,dp);
//     }
//     int fib(int n) {
//         vector<int> dp(n+1, -1);

//         return helper(n,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N)
// Space Complexity: O(N*N)  (Array) 


// class Solution {
// public:
//     int fib(int n) {
//         vector<int> dp(n+2, 0);

//         // base condition
//         dp[0] = 0;
//         dp[1] = 1;

//         for(int i = 2; i <= n; i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }

//         return dp[n];
//     }
// };



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int fib(int n) {
//         if(n <= 1){
//             return n;
//         }
//         int a = 0, b = 1, c;
//         for(int i = 2; i <= n; i++){
//             c = a + b;
//             a = b;
//             b = c;
//         }

//         return b;
//     }
// };











/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*N) 
// Space Complexity: O(N)


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> next(n+1, 0), cur(n+1, 0);

//         // As next and cur array is intialized to 0, we have already covered the base case

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int prev_index = ind-1; prev_index >= -1; prev_index--){
//                 int notTaken = 0 + next[prev_index+1];

//                 int taken = 0;
//                 if(prev_index == -1 || nums[ind] > nums[prev_index]){
//                     taken = 1 + next[ind+1];
//                 }

//                 cur[prev_index+1] = max(notTaken, taken);
//             }
//             next = cur;
//         }

//         return cur[0];            // return cur[-1+1];
//     }
// };




/* With Recursion */
// Time Complexity: Exponential, as every function calls two other functions.

// #include<bits/stdc++.h>
// using namespace std;
// int f(int n){
//     if(n <= 1){
//         return n;
//     }

//     return f(n-1) + f(n-2);
// }
// int main()
// {
//     int n;
//     cin>>n;

//     cout<<f(n);
    
//     return 0;
// }



/* With DP   (Memoizaton) */
// Time Complexity: O(N)
// Space Complexity: O(N) (Recursion)   +   O(N)  (Array)


// #include<bits/stdc++.h>
// using namespace std;
// int f(int n, vector<int>& dp){
//     if(n <= 1){
//         return n;
//     }
//     if(dp[n] != -1){
//         return dp[n];
//     }
//     return dp[n] = f(n-1, dp) + f(n-2, dp);
// }
// int main()
// {
//     int n;
//     cin>>n;

//     vector<int> dp(n+1, -1);
//     cout<<f(n, dp);
    
//     return 0;
// }



/* With DP   (Tabulation) */
// Time Complexity: O(N)
// Space Complexity: O(N)  (Array) 


// #include <bits/stdc++.h>
// using namespace std;
// int main() {

//   int n=5;
//   vector<int> dp(n+1,-1);
  
//   dp[0]= 0;
//   dp[1]= 1;
  
//   for(int i=2; i<=n; i++){
//       dp[i] = dp[i-1]+ dp[i-2];
//   }
//   cout<<dp[n];
//   return 0;
// }



/* Space Optimization */
// Time Complexity: O(N)
// Space Complexity: O(1)


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;

    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    cout<<b;
    
    return 0;
}