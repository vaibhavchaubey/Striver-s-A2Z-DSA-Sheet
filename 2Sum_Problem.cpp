/* Leetcode  Submission    (1. Two Sum) */

/* Problem Statement: Given an array of integers nums and an integer target, return indices of the two 
numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order. */


/* Solution 1: Naive Approach (Brute Force) */
// Time Complexity: O(N^2)
// Space Complexity: O(1)


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> ans;
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(nums[i] + nums[j] == target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     return ans;
//                 }
//             }
//         }
//         return ans;
//     }
// };



/* Solution 2: Two-Pointer Approach */
// Time Complexity: O(N + NlogN)
// Space Complexity: O(N) 


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> ans;
//         vector<int> store = nums;
//         sort(store.begin(), store.end());
//         int left = 0, right = n-1;
//         int n1, n2;
        
//         while(left < right){
//             if(store[left] + store[right] == target){
//                 n1 = store[left];
//                 n2 = store[right];
//                 break;
//             }
//             else if(store[left] + store[right] > target){
//                 right--;
//             }
//             else{
//                 left++;
//             }
//         }
//         for(int i = 0; i < n; i++){
//             if(nums[i] == n1){
//                 ans.push_back(i);
//             }
//             else if(nums[i] == n2){
//                 ans.push_back(i);
//             }
//         }
        
//         return ans;
//     }
// };



/* Solution 3: Using Hashing */
// Time Complexity: O(NlogN)
// Space Complexity: O(N) 


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> ans;
//         unordered_map<int,int> mp;         //element , index
//         for(int i = 0; i < n; i++){
//             if(mp.count(target-nums[i])){
//                 ans.push_back(mp[target-nums[i]]);
//                 ans.push_back(i);
//                 return ans;
//             }
//             mp[nums[i]] = i;
//         }
//         return ans;
//     }
// };