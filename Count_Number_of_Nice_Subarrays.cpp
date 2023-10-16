/* Leetcode  Submission    (1248. Count Number of Nice Subarrays) */

/* Problem Statement: Given an array of integers nums and an integer k. A continuous subarray is called nice if there are
k odd numbers on it. Return the number of nice sub-arrays. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             int oddCount = 0;
//             for(int j = i; j < n; j++){
//                 if(nums[j] % 2 == 1){
//                     oddCount++;
//                 }
//                 if(oddCount == k){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };



/* Solution 2: Using Hashmap */
// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();

//         // replacing each even by zero and every odd by one
//         for(int i = 0; i < n; i++){
//             if(nums[i] % 2 == 0){
//                 nums[i] = 0;
//             }
//             else{
//                 nums[i] = 1;
//             }
//         }

//         // Now it is same as no. of subarray sum equals k
        
//         unordered_map<int, int> mp;             // sum, count
//         int count = 0, sum = 0;
//         for(int i = 0; i < n; i++){
//             sum += nums[i];
//             if(sum == k){
//                 count++;
//             }
//             count += mp[sum - k];
//             mp[sum]++;
//         }

//         return count;
//     }
// };



/* OR */


// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();

//         // Without replacing each even by zero and every odd by one
//         // Now it is same as no. of subarray sum equals k
        
//         unordered_map<int, int> mp;             // sum, count
//         int count = 0, sum = 0;
//         for(int i = 0; i < n; i++){
//             sum += nums[i] % 2;
//             if(sum == k){
//                 count++;
//             }
//             count += mp[sum - k];
//             mp[sum]++;
//         }

//         return count;
//     }
// };




/* Solution 3: Sliding Window */
// Time Complexity: O(2*N)
// Space Complexity: O(1)


/* Intuition
--> Count total number of subarray with sum atmost (less than equal to) GOAL and GOAL-1.
--> Then subtract both to get exact number of subarray with GOAL.

QUESTION : How to count total number of subarray with atmost (less than equal to) sum = GOAL.

ANS: (Simple Keep adding length of window size whenever window size is changed) Count=(right-left+1);

More Clarify Above ans:
As we iterate through an array ,one by one elements to the existing array adds up and as an element is added to the existing 
array then it contributes to (right-left+1) subarrays and so till the current j pointer we will get all the possible subarrays.
For an example : if array is {1,2,3,4,5} then it will have n(n+1)/2 subarrays i.e 5*(6)/2 = 15 subarrays and lets suppose we add 
one more element to existing array(ele:6) then here right = 5 and lets take left = 0, then total (right-left+1) extra subarrays 
will be added i.e (5 - 0 + 1) = 6 subarrays namely {6}, {5,6}, {4,5,6}, {3,4,5,6}, {2,3,4,5,6}, {1,2,3,4,5,6} respectively. */


// class Solution {
// public:
//     int countSubArrs(vector<int>& nums, int sum){
//         int n = nums.size();
//         if(sum < 0){
//             return 0;
//         }

//         int i = 0, j = 0, count = 0;
//         int preSum = 0;
//         while(j < n){
//             preSum += nums[j];
//             while(preSum > sum){
//                 preSum -= nums[i];
//                 i++;
//             }

//             count += (j - i + 1);          // this counts the subarrays in that window
//             j++;
//         }

//         return count;
//     }

//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();

//         // replacing each even by zero and every odd by one
//         for(int i = 0; i < n; i++){
//             if(nums[i] % 2 == 0){
//                 nums[i] = 0;
//             }
//             else{
//                 nums[i] = 1;
//             }
//         }

//         // Now it is same as no. of subarray sum equals k

//         return countSubArrs(nums, k) - countSubArrs(nums, k-1);
//     }
// };


/* OR */


// class Solution {
// public:
//     int countSubArrs(vector<int>& nums, int sum){
//         int n = nums.size();
//         if(sum < 0){
//             return 0;
//         }

//         int i = 0, j = 0, count = 0;
//         int preSum = 0;
//         while(j < n){
//             preSum += nums[j] % 2;
//             while(preSum > sum){
//                 preSum -= nums[i] % 2;
//                 i++;
//             }

//             count += (j - i + 1);          // this counts the subarrays in that window
//             j++;
//         }

//         return count;
//     }

//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();

//         // Without replacing each even by zero and every odd by one
//         // Now it is same as no. of subarray sum equals k

//         return countSubArrs(nums, k) - countSubArrs(nums, k-1);
//     }
// };

