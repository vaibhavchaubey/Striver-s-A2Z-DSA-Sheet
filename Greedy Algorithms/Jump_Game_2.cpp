/* Leetcode  Submission    (45. Jump Game II) */

/* Problem Statement: You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], 
you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1]. */


/* Solution 1:  Using Recursion */
/* Approach: For every index we are going to all the forward positions possible */
// Time Complexity: O(k^N)                  // Where, k is max element of nums and n is size of nums.
// Space Complexity: O(N)            (Recursion)


// class Solution {
// public:
//     long long helper(int ind, int dest, vector<int>& nums){
//         if(ind >= dest){
//             return 0;
//         }
        
//         //Try Every jump 1 to nums[curr] jump
//         //and find minimum steps need to reach to end
//         long long minStep = INT_MAX;
//         for(int i = 1; i <= nums[ind]; i++){
//             long long jump = 1 + helper(ind+i, dest, nums);
//             minStep = min(minStep, jump);
//         }

//         return minStep;
//     }
//     int jump(vector<int>& nums) {
//         int n = nums.size();

//         return helper(0, n-1, nums);
//     }
// };



/* Solution 2:  Using DP  (Memoization) */
// Time Complexity: O(k*N)                  // Where, k is max element of nums and n is size of nums.
// Space Complexity: O(N)            (Recursion)


// class Solution {
// public:
//     long long helper(int ind, int dest, vector<int>& nums, vector<int>& dp){
//         if(ind >= dest){
//             return 0;
//         }
//         if(dp[ind] != -1){
//             return dp[ind];
//         }
        
//         //Try Every jump 1 to nums[curr] jump
//         //and find minimum steps need to reach to end
//         long long minStep = INT_MAX;
//         for(int i = 1; i <= nums[ind]; i++){
//             long long jump = 1 + helper(ind+i, dest, nums, dp);
//             minStep = min(minStep, jump);
//         }

//         return dp[ind] = minStep;
//     }
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);

//         return helper(0, n-1, nums, dp);
//     }
// };



/* Solution 3:  */
// Time Complexity: O(N)            
// Space Complexity: O(1)    


// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         // The starting range of the first jump is [0, 0]
//         int minStep = 0, n = nums.size();

//         int curEnd = 0, curFar = 0;
        
//         for (int i = 0; i < n - 1; ++i) {
//             // Update the farthest reachable index of this jump.
//             curFar = max(curFar, i + nums[i]);

//             // If we finish the starting range of this jump,
//             // Move on to the starting range of the next jump.
//             if (i == curEnd) {              // Visited all the items on the current level
//                 minStep++;                  // Increment the level
//                 curEnd = curFar;            // Make the queue size for the next level
//             }
//         }
        
//         return minStep;
//     }
// };