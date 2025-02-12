/* Leetcode  Submission    (268. Missing Number) */

/* Problem Statement: Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array. */


/* Solution 1: using Hashing  */
// Time Complexity: O(2N)
// Space Complexity: O(N)


// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int> mp;
//         for(int i = 0; i < n; i++){
//             mp[nums[i]]++;
//         }

//         for(int i = 0; i <= n; i++){
//             if(mp[i] == 0){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };



/* Solution 2: Summation Approach */
// Time Complexity: O(N)
// Space Complexity: O(1) 


// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int totalSum = (n * (n + 1)) / 2;        // Sum of all numbers from 1 to n
//         int sum = 0;
//         for(int i = 0; i < n; i++){
//             sum += nums[i];
//         }
//         int ans = totalSum - sum;

//         return ans;
//     }
// };



/* Solution 3: XOR Approach: */
// Time Complexity: O(N)
// Space Complexity: O(1) 


/* XOR Property */
// XOR of same number is 0   (2 ^ 2 = 0)
// XOR of any number with 0 is the number itself     (0 ^ 2 = 2)


// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int XOR1 = 0;       // XOR of all numbers from 1 to n
//         int XOR2 = 0;       // XOR of all numbers in nums
//         for(int i = 0; i < n; i++){
//             XOR2 ^= nums[i];
//             XOR1 ^= i+1;
//         }

//         // Same number will cancel out and at last we get our missing number
//         int ans = XOR1 ^ XOR2;

//         return ans;
//     }
// };