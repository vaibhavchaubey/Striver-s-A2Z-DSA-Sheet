/* Problem Statement: We are given an array ‘ARR’ with N positive integers and an integer D. 
We need to count the number of ways we can partition the given array into two subsets, 
S1 and S2 such that S1 – S2 = D and S1 is always greater than or equal to S2. 
Since the answer may be too large, return it modulo '10^9 + 7' */


/* CodeStudio   Submission    (416. Partition Equal Subset Sum) */


/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: O(2^N) + O(N)
// Space Complexity: O(N) (Recursion)


// #include <bits/stdc++.h>
// int mod = (int)(1e9 + 7);
// int helper(int ind, int target, vector<int> &num){
//     if(ind == 0){                                         // base condition
//         if(target == 0 && num[0] == 0){                  // two case either take 0 or not take 0
//             return 2;
//         }
//         if(target == 0 || num[0] == target){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     int notTaken = helper(ind-1,target,num);
    
//     int taken = 0;
//     if(num[ind] <= target){
//         taken = helper(ind-1,target-num[ind],num);
//     }
    
//     return (notTaken + taken) % mod;
// }
// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();  
//     return helper(n-1,tar,num);
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     int totalSum = 0;
//     for(int i = 0; i < n; i++){
//         totalSum += arr[i];
//     }
//     // Edge Case
//     if(totalSum - d < 0 || (totalSum - d) % 2 != 0){
//         return 0;
//     }

//     return findWays(arr, (totalSum - d) / 2);
// }



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*K)
// Space Complexity: O(N) (Recursion)   +   O(N*K)  (Array)


// #include <bits/stdc++.h>
// int mod = (int)(1e9 + 7);
// int helper(int ind, int target, vector<int> &num, vector<vector<int>>& dp){
//     if(ind == 0){                                         // base condition
//         if(target == 0 && num[0] == 0){                  // two case either take 0 or not take 0
//             return 2;
//         }
//         if(target == 0 || num[0] == target){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     if(dp[ind][target] != -1){
//         return dp[ind][target];
//     }
    
//     int notTaken = helper(ind-1,target,num,dp);
    
//     int taken = 0;
//     if(num[ind] <= target){
//         taken = helper(ind-1,target-num[ind],num,dp);
//     }
    
//     return dp[ind][target] = (notTaken + taken) % mod;
// }
// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    
//     return helper(n-1,tar,num,dp);
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     int totalSum = 0;
//     for(int i = 0; i < n; i++){
//         totalSum += arr[i];
//     }
//     // Edge Case
//     if(totalSum - d < 0 || (totalSum - d) % 2 != 0){
//         return 0;
//     }

//     return findWays(arr, (totalSum - d) / 2);
// }



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*K) 
// Space Complexity: O(N*K)  (Array) 


// #include <bits/stdc++.h>
// int mod = (int)(1e9 + 7);
// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    
//     if(num[0] == 0){                         // 2 cases - pick and not pick      // base condition
//         dp[0][0] = 2;                       // ind = 0, target = 0    
//     }
//     else{                                // 1 case - not pick
//         dp[0][0] = 1;
//     }
//     if(num[0] != 0 && num[0] <= tar){            // 1 case - pick        // base condition
//         dp[0][num[0]] = 1;
//     }
    
//     for(int ind = 1; ind < n; ind++){
//         for(int target = 0; target <= tar; target++){
//             int notTaken = dp[ind-1][target];
            
//             int taken = 0;
//             if(num[ind] <= target){
//                 taken = dp[ind-1][target-num[ind]];
//             } 
//             dp[ind][target] = (notTaken + taken) % mod;
//         }
//     }
    
//     return dp[n-1][tar];
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     int totalSum = 0;
//     for(int i = 0; i < n; i++){
//         totalSum += arr[i];
//     }
//     // Edge Case
//     if(totalSum - d < 0 || (totalSum - d) % 2 != 0){
//         return 0;
//     }
    
//     return findWays(arr, (totalSum - d) / 2);
// }



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*K)
// Space Complexity: O(K)


// #include <bits/stdc++.h>
// int mod = (int)(1e9 + 7);
// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     vector<int> prev(tar+1, 0);
    
//     if(num[0] == 0){                 // 2 cases - pick and not pick  // base condition
//         prev[0] = 2;                // ind = 0, target = 0    
//     }
//     else{                          // 1 case - not pick
//         prev[0] = 1;
//     }
//     if(num[0] != 0 && num[0] <= tar){            // 1 case - pick   // base condition
//         prev[num[0]] = 1;
//     }
    
//     for(int ind = 1; ind < n; ind++){
//         vector<int> cur(tar+1, 0);
//         for(int target = 0; target <= tar; target++){
//             int notTaken = prev[target];
            
//             int taken = 0;
//             if(num[ind] <= target){
//                 taken = prev[target-num[ind]];
//             } 
//             cur[target] = (notTaken + taken) % mod;
//         }
//         prev = cur;
//     }
    
//     return prev[tar];
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     int totalSum = 0;
//     for(int i = 0; i < n; i++){
//         totalSum += arr[i];
//     }
//     // Edge Case
//     if(totalSum - d < 0 || (totalSum - d) % 2 != 0){
//         return 0;
//     }
    
//     return findWays(arr, (totalSum - d) / 2);
// }


