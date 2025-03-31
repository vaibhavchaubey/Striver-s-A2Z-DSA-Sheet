/* Leetcode  Submission    (152. Maximum Product Subarray) */

/* Problem Statement: Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N*N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int ans = INT_MIN;
//         for(int i = 0; i < n; i++){
//             int p = 1;
//             for(int j = i; j < n; j++){
//                 p *= nums[j];
//                 ans = max(ans, p);
//             }
//         }

//         return ans;
//     }
// };



/* Not much intuitive Solution 3 should be used */

/* Solution 2: Optimal Approach  (using Kadane’s Algorithm)  */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int prod1 = nums[0], prod2 = nums[0], ans = nums[0];
//         for(int i = 1; i < n; i++){
//             int temp = max({nums[i], prod1 * nums[i], prod2 * nums[i]});
//             prod2 = min({nums[i] , prod1 * nums[i], prod2 * nums[i]});
//             prod1 = temp;
            
//             ans = max(ans,prod1);
//         }
    
//         return ans;
//     }
// };



/* Solution 3: Optimal Approach   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int ans = INT_MIN;
//         int pre = 1, suff = 1;
//         for(int i = 0; i < n; i++){
//             // If 0 is encountered, set pre or suff to 0
//             if(pre == 0){
//                 pre = 1;
//             }
//             if(suff == 0){
//                 suff = 1;
//             }

//             pre *= nums[i];
//             suff *= nums[n-i-1];
//             ans = max(ans, max(pre, suff));
//         }

//         return ans;
//     }
// };
