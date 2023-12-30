/* Problem Statement: Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. 
After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer. */



/* Leetcode  Submission    (1043. Partition Array for Maximum Sum) */


/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: (Exponential)
// Space Complexity: O(N) (Recursion)


// class Solution {
// public:
//     int helper(int ind, int k, int n, vector<int>& arr){
//         if(ind == n){               // base condition
//             return 0;
//         }

//         int len = 0;
//         int maxi = INT_MIN;
//         int maxAns = INT_MIN;;
//         for(int j = ind; j < min(ind + k, n); j++){
//             len++;
//             maxi = max(maxi, arr[j]);           // to find max Element in subarray
//             int sum = len * maxi + helper(j+1,k,n,arr);
//             maxAns = max(maxAns, sum);
//         }

//         return maxAns;
//     }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
        
//         return helper(0,k,n,arr);
//     }
// };


/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*K) 
// Space Complexity: O(N) (Recursion)   +   O(N)  (Array)


// class Solution {
// public:
//     int helper(int ind, int k, int n, vector<int>& arr, vector<int>& dp){
//         if(ind == n){               // base condition
//             return 0;
//         }

//         if(dp[ind] != -1){
//             return dp[ind];
//         }

//         int len = 0;
//         int maxi = INT_MIN;
//         int maxAns = INT_MIN;;
//         for(int j = ind; j < min(ind + k, n); j++){
//             len++;
//             maxi = max(maxi, arr[j]);           // to find max Element in subarray
//             int sum = len * maxi + helper(j+1,k,n,arr,dp);
//             maxAns = max(maxAns, sum);
//         }

//         return dp[ind] = maxAns;
//     }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> dp(n, -1);
        
//         return helper(0,k,n,arr,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*K) 
// Space Complexity: O(N)  (Array) 


// class Solution {
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> dp(n+1, 0);
//         dp[n] = 0;              // base condition

//         for(int ind = n-1; ind >= 0; ind--){
//             int len = 0;
//             int maxi = INT_MIN;
//             int maxAns = INT_MIN;;
//             for(int j = ind; j < min(ind + k, n); j++){
//                 len++;
//                 maxi = max(maxi, arr[j]);           // to find max Element in subarray
//                 int sum = len * maxi + dp[j+1];
//                 maxAns = max(maxAns, sum);
//             }

//             dp[ind] = maxAns;
//         }
       
//         return dp[0];
//     }
// };