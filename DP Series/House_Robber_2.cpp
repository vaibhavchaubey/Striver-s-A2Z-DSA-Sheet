/* Leetcode   Submission    (213. House Robber II) */

/* Problem Statement: A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. 
Therefore the first and the last house are adjacent to each other. The security system in the street is such that if adjacent 
houses are robbed, the police will get notified.
Given an array of integers “Arr” which represents money at each house, we need to return the maximum amount of money 
that the thief can rob without alerting the police. */



/* Space Optimization */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int maximumNonAdjacentSum(vector<int>& nums){
//         int n = nums.size();
//         int prev = nums[0];
//         int prev2 = 0;
//         for(int i = 1; i < n; i++){
//             int pick = nums[i];
//             if(i > 1){
//                 pick += prev2;
//             }
//             int nonPick = 0 + prev;
//             int cur_i = max(pick, nonPick);
//             prev2 = prev;
//             prev = cur_i;
//         }
//         return prev;
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1){
//             return nums[0]; 
//         }
//         vector<int> temp1, temp2;
//         for(int i = 0; i < n; i++){
//             if(i != 0){      // First Element in taken
//                 temp1.push_back(nums[i]);
//             }
//             if(i != n-1){    // Last Element in taken
//                 temp2.push_back(nums[i]);
//             }
//         }  

//         int ans1 = maximumNonAdjacentSum(temp1);
//         int ans2 = maximumNonAdjacentSum(temp2);

//         return max(ans1, ans2);    
//     }
// };



/* Without using temp vectors just by passing the initial and end indices */
/* Here we can also use Memoization & Tabulation Solution */

// class Solution {
// public:
//     int maximumNonAdjacentSum(vector<int>& nums, int start, int n){
//         int prev = nums[start];
//         int prev2 = 0;
//         for(int i = start + 1; i < n; i++){
//             int pick = nums[i];
//             if(i > 1){
//                 pick += prev2;
//             }
//             int nonPick = 0 + prev;
//             int cur_i = max(pick, nonPick);
//             prev2 = prev;
//             prev = cur_i;
//         }
//         return prev;
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1){
//             return nums[0]; 
//         } 

//         int ans1 = maximumNonAdjacentSum(nums, 0, n-1);     // First Element in taken and Last Element is not taken
//         int ans2 = maximumNonAdjacentSum(nums, 1, n);      // Last Element in taken and First Element is not taken

//         return max(ans1, ans2);    
//     }
// };