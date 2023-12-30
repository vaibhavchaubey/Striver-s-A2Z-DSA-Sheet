/* Leetcode Submission    (70. Climbing Stairs) */

/* Problem Statement: You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */



/* Solution 1: It will give TLE */
/* With Recursion */
//It will give TLE

// class Solution {
// public:
//     int helper(int n){
//         if(n == 0 || n == 1){                // base case
//             return 1;
//         }

//         return helper(n-1) + helper(n-2);
//     }
//     int climbStairs(int n) {
//         return helper(n);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N)
// Space Complexity: O(N) (Recursion)   +   O(N)  (Array)


// class Solution {
// public:
//     int helper(int n, vector<int>& dp){
//         if(n == 0 || n == 1){               // base case
//             return 1;
//         }

//         if(dp[n] != -1){
//             return dp[n];
//         }

//         return dp[n] = helper(n-1, dp) + helper(n-2, dp);
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1, -1);

//         return helper(n, dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N)
// Space Complexity: O(N)  (Array) 


// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1, -1);
//         dp[0] = 1;
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
//     int climbStairs(int n) {
//         if (n == 0 || n == 1){
//             return 1;
//         } 
//         int one_step_before = 1;
//         int two_steps_before = 1;
//         int all_ways = 0;
//         for (int i = 2; i <= n; i++) {
//             all_ways = one_step_before + two_steps_before;
//     	       two_steps_before = one_step_before;
//             one_step_before = all_ways;
//         }

//         return all_ways;
//     }
// };