/* Problem Statement: We are given an array ‘ARR’ with N positive integers. We need to partition the array 
into two subsets such that the absolute difference of the sum of elements of the subsets is minimum.
We need to return only the minimum absolute difference of the sum of elements of the two partitions. */


/* CodeStudio   Submission    (Partition a set into two subsets such that the difference of subset sums is minimum) */


/* Solution 1: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*totalSum) + O(N) + O(N)
// Space Complexity: O(N*totalSum)  (Array) 


// #include <bits/stdc++.h> 
// int minSubsetSumDifference(vector<int>& arr, int n)
// {
// 	int totalSum = 0;
//     for(int i = 0; i < n; i++){
//         totalSum += arr[i];
//     }
//     int k = totalSum/2;                   // as we have to iterate from 0 to tatalSum/2 only
    
//     vector<vector<bool>> dp(n, vector<bool>(k+1, false));
//     for(int i = 0; i < n; i++){
//         dp[i][0] = true;             // base condtion
//     }
//     if(arr[0] <= k){               // base condtion
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
//     }
    
//     // dp[n-1][col->0...totalSum/2]
//     int mini = 1e9;
//     for(int s1 = 0; s1 <= totalSum/2; s1++){
//         if(dp[n-1][s1] == true){
//             int s2 = totalSum - s1;
//             mini = min(mini, abs(s2-s1));
//         }
//     }
    
//     return mini;
// }




/* Solution 2: */
/* Space Optimization */
// Time Complexity: O(N*totalSum) + O(N) + O(N)
// Space Complexity: O(totalSum)


// #include <bits/stdc++.h> 
// int minSubsetSumDifference(vector<int>& arr, int n)
// {
//     int totalSum = 0;
//     for(int i = 0; i < n; i++){
//         totalSum += arr[i];
//     }
//     int k = totalSum/2;                   // as we have to iterate from 0 to tatalSum/2 only
    
//     vector<bool> prev(k+1, false);
//     prev[0] = true;                   // base condition
    
//     if(arr[0] <= k){                 // base condition
//         prev[arr[0]] = true;
//     }
    
//     for(int ind = 1; ind < n; ind++){
//         vector<bool> cur(k+1, false);
//         cur[0] = true;                       // base condition
//         for(int target = 1; target <= k; target++){
//             bool notTaken = prev[target];
            
//             bool taken = false;
//             if(arr[ind] <= target){
//                 taken = prev[target-arr[ind]];
//             }
//             cur[target] = notTaken || taken;
//         }
//            prev = cur;
//     }
    
//     // prev[col->0...totalSum/2]
//     int mini = 1e9;
//     for(int s1 = 0; s1 <= totalSum/2; s1++){
//         if(prev[s1] == true){
//             int s2 = totalSum - s1;
//             mini = min(mini, abs(s2-s1));
//         }
//     }
    
//     return mini;
// }