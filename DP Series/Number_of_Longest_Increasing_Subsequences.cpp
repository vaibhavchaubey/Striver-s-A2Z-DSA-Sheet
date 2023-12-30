/* Problem Statement: Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing. */


/* Leetcode  Submission    (673. Number of Longest Increasing Subsequence) */


/* Solution: */
/* Tabulation algorithm */
// Time Complexity: O(N*N)       
// Space Complexity: O(N)


// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         vector<int> cnt(n, 1);

//         int maxi = -1;
//         for(int i = 0; i < n; i++){
//             for(int prev = 0; prev < i; prev++){
//                 if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
//                     dp[i] = 1 + dp[prev];
//                     //inherit
//                     cnt[i] = cnt[prev];
//                 }
//                 else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i]){
//                     //increase the count
//                     cnt[i] += cnt[prev];
//                 }
//             }
//             maxi = max(maxi, dp[i]);
//         }

//         int ans = 0;
//         for(int i = 0; i < n; i++){
//             if(dp[i] == maxi){
//                 ans += cnt[i];
//             }
//         }

//         return ans;
//     }
// };



/* Similar Question     (IMP)  */

/* Leetcode  Submission    (845. Longest Mountain in Array) */


/* Solution 1: */
// Time Complexity: O(N)       
// Space Complexity: O(N)


// class Solution {
// public:
//     int longestMountain(vector<int>& arr) {
//         int n = arr.size();

//         if(n < 3){
//             return 0;
//         }

//         vector<int> left(n, 1);
//         for(int i = 1; i < n; i++){
//             if(arr[i] > arr[i-1]){
//                 left[i] = 1 + left[i-1];
//             }
//         }

//         vector<int> right(n, 1);
//         for(int i = n-2; i >= 0; i--){
//             if(arr[i] > arr[i+1]){
//                 right[i] = 1 + right[i+1];
//             }
//         }

//         int ans = 0;
//         for(int i = 0; i < n; i++){
//             // check for valid mountain array
//             if(left[i] > 1 && right[i] > 1){                 
//                 ans = max(ans, left[i] + right[i] - 1);
//             }
//         }

//         return ans;
//     }
// };



/* Solution 2: */
// Time Complexity: O(N)       
// Space Complexity: O(1)


// class Solution {
// public:
//     int longestMountain(vector<int>& arr) {
//         int n = arr.size();

//         if(n < 3){
//             return 0;
//         }

//         int i = 0;
//         int ans = 0;
//         while(i < n){
//             int up = 1;
//             // upside
//             while(i+1 < n && arr[i] < arr[i+1]){
//                 i++;
//                 up++;
//             }

//             int down = 0;
//             // downside
//             while(i+1 < n && arr[i] > arr[i+1]){
//                 i++;
//                 down++;
//             }

//             // check for valid mountain array
//             if(up > 1 && down > 0){
//                 ans = max(ans, up+down);
//             }

//             /* if there is  down means the break point will be at arr[i] <= arr[i+1] in this case arr[i] 
// 			can be part of new mountrain array in upside so we will miss one element in further 
// 			creation . thats why if(down!=0) we will again start from same index i, else we can take
// 			new i+1 */

//             if(down == 0){          // when arr[i] == arr[i+1] 
//                 i++;
//             }
//         }

//         return ans;
//     }
// };



/* OR */


// Time Complexity: O(N)       
// Space Complexity: O(1)


// class Solution {
// public:
//     int longestMountain(vector<int>& arr) {
//         int n = arr.size();

//         if(n < 3){
//             return 0;
//         }

//         int ans = 0;
//         int i = 1;
//         while(i <= n-2){
//             if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){         // condition for peak element
//                 int count = 1;
//                 int j = i;
//                 while(j > 0 && arr[j] > arr[j-1]){          // traversing left side of peak element
//                     j--;
//                     count++;
//                 }
//                 while(i+1 < n && arr[i] > arr[i+1]){       // traversing right side of peak element
//                     i++;
//                     count++;
//                 }

//                 ans = max(ans, count);
//             }
//             else{
//                 i++;
//             }
//         }

//         return ans;
//     }
// };

