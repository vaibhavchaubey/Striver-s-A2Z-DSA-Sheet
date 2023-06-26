/* Leetcode  Submission    (169. Majority Element) */

/* Problem Statement: Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array. */


/* Solution 1: Naive Approach (Brute Force) */
// Time Complexity: O(N^2)
// Space Complexity: O(1)


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             int cnt = 1;
//             for(int j = i+1; j < n; j++){
//                 if(nums[i] == nums[j]){
//                     cnt++;
//                 }
//             }
//             if(cnt > n/2){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };



/* Solution 2: Sorting */
// Time Complexity: O(NlogN)
// Space Complexity: O(1) 


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         return nums[n/2];         //It always return the majority element
//     }
// };



/* Solution 3: Using Hashing */
// Time Complexity: O(NlogN)
// Space Complexity: O(N) 


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> mp;
//         for(int i = 0; i < n; i++){
//             mp[nums[i]]++;
//             if(mp[nums[i]] > n/2){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };



/* Solution 4: Moore’s Voting Algorithm */
// Time Complexity: O(N)
// Space Complexity: O(1) 


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int count = 0;
//         int candidate = 0;
//         for(auto num : nums){
//             if(count == 0){
//                 candidate = num;
//                 count = 1;
//             }
//             else if(num == candidate){
//                 count++;
//             }
//             else{
//                 count--;
//             }
//         }
        
//         return candidate;
//     }
// };



/* GFG  Submission    (Majority Element) */

/* Problem Statement: Given an array A of N elements. Find the majority element in the array. 
A majority element in an array A of size N is an element that appears more than N/2 times in the array. */


/* Solution: Moore’s Voting Algorithm */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution{
//   public:
//      // Function to find majority element in the array
//     // a: input array
//     // size: size of input array
//     int majorityElement(int a[], int size)
//     {
//         int count = 0;
//         int candidate = 0;
//         for(int i = 0; i < size; i++){
//             if(count == 0){
//                 candidate = a[i];
//                 count = 1;
//             }
//             else if(a[i] == candidate){
//                 count++;
//             }
//             else{
//                 count--;
//             }
//         }
        
//         int cnt = 0; 
//         for(int i = 0; i < size; i++){
//             if(a[i] == candidate){
//                 cnt++;
//             }
//         }
        
//         if(cnt > size/2){
//             return candidate;
//         }
        
//         return -1;
        
//     }
// };