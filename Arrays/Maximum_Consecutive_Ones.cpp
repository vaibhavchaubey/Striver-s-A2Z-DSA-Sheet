/* Leetcode  Submission    (485. Max Consecutive Ones) */

/* Problem Statement: Given a binary array nums, return the maximum number of consecutive 1's in the array. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int count = 0, ans = 0;
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == 1){
//                 count++;
//                 ans = max(ans, count);
//             }
//             else{
//                 count = 0;
//             }
//         }

//         return ans;
//     }
// };



/* GFG  Submission    (Maximize Number of 1's) */

/* Problem Statement: Given a binary array arr of size N and an integer M. Find the maximum number of 
consecutive 1's produced by flipping at most M 0's. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution{
// public:
//     // m is maximum of number zeroes allowed to flip
//     // n is size of array
//     int findZeroes(int arr[], int n, int m) {
//         int j = -1;
//         int cntZero = 0;
//         int maxOne = 0;
//         for(int i = 0; i < n; i++){
//             if(arr[i] == 0){
//                 cntZero++;
//             }
//             while(cntZero > m){
//                 j++;
//                 if(arr[j] == 0){
//                     cntZero--;
//                 }
//             }
//             int len = i - j;
//             maxOne = max(maxOne, len);
//         }
        
//         return maxOne;
//     }  
// };