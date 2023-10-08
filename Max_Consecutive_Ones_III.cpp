/* Leetcode  Submission    (1004. Max Consecutive Ones III) */

/* Problem Statement: Given a binary array nums and an integer k, return the maximum number of consecutive 1's in 
the array if you can flip at most k 0's. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int maxLength = 0;
//         for(int i = 0; i < n; i++){
//             int countZero = 0;
//             for(int j = i; j < n; j++){
//                 if(nums[j] == 0){
//                     countZero++;
//                 }
//                 if(countZero > k){
//                     break;
//                 }
                
//                 maxLength = max(maxLength, j - i + 1);
//             } 
//         }

//         return maxLength;
//     }
// };




/* Solution 2: Two Pointer */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int l = 0, r = 0;
//         int countZero = 0, maxLength = 0;
//         while(r < n){
//             if(nums[r] == 0){
//                 countZero++;
//             }
//             while(countZero > k){
//                 if(nums[l] == 0){
//                     countZero--;
//                 }
//                 l++;
//             }

//             maxLength = max(maxLength, r - l + 1);
//             r++;
//         }

//         return maxLength;
//     }
// };