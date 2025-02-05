/* Leetcode  Submission    (283. Move Zeroes) */

/* Problem Statement: Given an integer array nums, move all 0's to the end of it while maintaining the relative 
order of the non-zero elements.
Note that you must do this in-place without making a copy of the array. */


/* Solution: 1  (Brute Force)  */
// Time Complexity: O(N)
// Space Complexity: O(N)  


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         vector<int> temp;
//         int cntZero = 0;
//         for(auto i : nums){
//             // Count the zeroes
//             if(i == 0){
//                 cntZero++;
//             }
//             // Make all the non-zero elements retain their original order.
//             else{
//                 temp.push_back(i);
//             }
//         }

//         // Move all zeroes to the end
//         while(cntZero--){
//             temp.push_back(0);
//         }

//         // Combine the result
//         nums = temp;
//     }
// };


/* Solution: 2  */
// Time Complexity: O(N)
// Space Complexity: O(1)  


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int cntZero = 0;
//         int idx = 0;
//         for(int i = 0; i < n; i++){
//             // Count the zeroes
//             if(nums[i] == 0){
//                 cntZero++;
//             }
//             else{
//                 nums[idx] = nums[i];
//                 idx++;
//             }
//         }

//         // Move all zeroes to the end
//         while(cntZero--){
//             nums[idx] = 0;
//             idx++;
//         }
//     }
// };



/* Solution: 3  */
// Time Complexity: O(N)
// Space Complexity: O(1)  


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int idx = 0;
//         for(int cur = 0; cur < n; cur++){
//             if(nums[cur] != 0){
//                 swap(nums[idx], nums[cur]);
//                 idx++;
//             }
//         }
//     }
// };