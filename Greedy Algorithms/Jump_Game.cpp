/* Leetcode  Submission    (55. Jump Game) */

/* Problem Statement: You are given an integer array nums. You are initially positioned at the array's first index, and each 
element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise. */


/* Solution: 1 */
// Time Complexity: O(N)
// Space Complexity: O(N)


/* The question states "each element in the array represents your maximum jump length at that position."
It means if we are at a position k and nums[k] = 4, then it means we can jump forward a maximum of 4 steps from this position. It's our choice to jump 1,2,3 or 4 positions, but not more than 4.

For example
In this test case [2,3,1,4]
nums[0] = 2
It means we can jump either 1 or 2 steps

At the end, if we reached the last index or greater than that we win! */


// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         int last = n-1;
//         for(int i = n-2; i >= 0; i--){
//             // from current i can we reach last
//             if(i + nums[i] >= last){
//                 last = i;
//             }
//         }

//         return last == 0;
//     }
// };

/* OR */

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         int maxReach = 0;
//         for(int i = 0; i < n; i++){
//             if(i > maxReach){
//                 return false;
//             }
//             maxReach = max(maxReach, i + nums[i]);
//         }

//         return true;
//     }
// };




