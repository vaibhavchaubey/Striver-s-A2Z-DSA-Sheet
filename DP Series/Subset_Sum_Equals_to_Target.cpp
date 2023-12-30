/* CodeStudio   Submission    (Subset Sum Equal To K) */


/* Problem Statement: We are given an array ‘ARR’ with N positive integers. 
We need to find if there is a subset in “ARR” with a sum equal to K. If there is, return true else return false. */




/* Solution 1: */
// Time Complexity: O(2^N)
// Space Complexity: O(N) (Recursion)
/* With Recursion (It will give TLE) */


// #include <bits/stdc++.h> 
// bool helper(int ind, int target, vector<int> &arr){
//     if(target == 0){                     // base condition
//         return true;
//     }
//     if(ind == 0){                       // base condition
//         return arr[0] == target; 
//     }
//     bool notTaken = helper(ind-1,target,arr);
    
//     bool taken = false;
//     if(arr[ind] <= target){
//         taken = helper(ind-1,target-arr[ind],arr);
//     }
//     return notTaken || taken;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     return helper(n-1,k,arr);
// }



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*K)
// Space Complexity: O(N) (Recursion)   +   O(N*K)  (Array)


// #include <bits/stdc++.h> 
// bool helper(int ind, int target, vector<int> &arr, vector<vector<int>>& dp){
//     if(target == 0){           // base condition
//         return true;
//     }
//     if(ind == 0){             // base condition
//         return arr[0] == target;
//     }
//     if(dp[ind][target] != -1){
//         return dp[ind][target];
//     }
//     bool notTaken = helper(ind-1,target,arr,dp);
    
//     bool taken = false;
//     if(arr[ind] <= target){
//         taken = helper(ind-1,target-arr[ind],arr,dp);
//     }
//     return dp[ind][target] = notTaken || taken;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>> dp(n, vector<int>(k+1, -1));            
        
//     return helper(n-1,k,arr,dp);
// }



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*K)
// Space Complexity: O(N*K)  (Array) 


// #include <bits/stdc++.h> 
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>> dp(n, vector<bool>(k+1, false));  
//     for(int i = 0; i < n; i++){       // base condition
//         dp[i][0] = true;
//     }
//     if(arr[0] <= k){                 // base condition
//         dp[0][arr[0]] = true;
//     }
    
//     for(int ind = 1; ind < n; ind++){
//         for(int target = 1; target <= k; target++){
//             bool notTaken = dp[ind-1][target];
            
//             bool taken = false;
//             if(arr[ind] <= target){
//                 taken = dp[ind-1][target-arr[ind]];
//             }
//             dp[ind][target] = notTaken || taken;
//         }
//      }
    
//     return dp[n-1][k];
// }



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*K)
// Space Complexity: O(K)


// #include <bits/stdc++.h> 
// bool subsetSumToK(int n, int k, vector<int> &arr) {
    // vector<bool> prev(k+1, false);
    
    // prev[0] = true;                   // base condition
    
    // if(arr[0] <= k){                 // base condition
    //     prev[arr[0]] = true;
    // }
    
    // for(int ind = 1; ind < n; ind++){
    //     vector<bool> cur(k+1, false);
    //     cur[0] = true;                       // base condition
    //     for(int target = 1; target <= k; target++){
    //         bool notTaken = prev[target];
            
    //         bool taken = false;
    //         if(arr[ind] <= target){
    //             taken = prev[target-arr[ind]];
    //         }
    //         cur[target] = notTaken || taken;
    //     }
    //    	prev = cur;
    //  }
    
//     return prev[k];
// }