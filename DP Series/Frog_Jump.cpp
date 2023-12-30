/* CodeStudio   Submission    (Frog Jump) */


/* Problem Statement: Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
At a time the frog can climb either one or two steps. A height[N] array is also given. 
Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), 
where abs() means the absolute difference. 
We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1. */



/* Solution 1: It will give TLE */
/* With Recursion */
//It will give TLE


// #include <bits/stdc++.h> 
// int f(int ind, vector<int> &heights){
//     if(ind == 0){
//         return 0;
//     }
//     int jumpOne = f(ind-1,heights) + abs(heights[ind] - heights[ind-1]);
//     int jumpTwo = INT_MAX;
//     if(ind > 1){
//         jumpTwo = f(ind-2,heights) + abs(heights[ind] - heights[ind-2]);
//     }
//     return min(jumpOne,jumpTwo);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     return f(n-1,heights);
// }



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N)
// Space Complexity: O(N) (Recursion)   +   O(N)  (Array)


// #include <bits/stdc++.h> 
// int f(int ind, vector<int> &heights, vector<int>& dp){
//     if(ind == 0){
//         return 0;
//     }
//     if(dp[ind] != -1){
//         return dp[ind];
//     }
//     int jumpOne = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
//     int jumpTwo = INT_MAX;
//     if(ind > 1){
//         jumpTwo = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
//     }
//     return dp[ind] = min(jumpOne,jumpTwo);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n+1,-1);
//     return f(n-1, heights, dp);
// }



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N)
// Space Complexity: O(N)  (Array) 


// #include <bits/stdc++.h> 
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n,0);
//     dp[0] = 0;
//     for(int i = 1; i < n; i++){
//         int jumpOne = dp[i-1] + abs(heights[i] - heights[i-1]);
//         int jumpTwo = INT_MAX;
//         if(i > 1){
//             jumpTwo = dp[i-2] + abs(heights[i] - heights[i-2]);
//         }
//         dp[i] = min(jumpOne, jumpTwo);
//     }
//     return dp[n-1];
// }



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N)
// Space Complexity: O(1)


// #include <bits/stdc++.h> 
// int frogJump(int n, vector<int> &heights)
// {
//     int prev = 0; 
//     int prev2 = 0;
//     for(int i = 1; i < n; i++){
//         int jumpOne = prev + abs(heights[i] - heights[i-1]);
//         int jumpTwo = INT_MAX;
//         if(i > 1){
//             jumpTwo = prev2 + abs(heights[i] - heights[i-2]);
//         }
//         int cur_i = min(jumpOne, jumpTwo);
//         prev2 = prev;
//         prev = cur_i;
//     }
//     return prev;
// }