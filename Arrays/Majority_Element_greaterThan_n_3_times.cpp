/* Leetcode  Submission    (229. Majority Element II) */

/* Problem Statement: Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. */


/* Solution 1: Naive Approach (Brute Force) */
// Time Complexity: O(N*N) 
// Space Complexity: O(N)


// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         // Set is used in order to prevent duplicate number
//         set<int> s;
//         for(int i = 0; i < n; i++){
//             int cnt = 1;
//             for(int j = i+1; j < n; j++){
//                 if(nums[i] == nums[j]){
//                     cnt++;
//                 }
//             }
//             if(cnt > n/3){
//                 s.insert(nums[i]);
//             }
//         }

//         vector<int> ans(s.begin(), s.end());

//         return ans;
//     }
// };



/* Solution 2: Naive Approach (Brute Force) */
// Time Complexity: O(N*N)
// Space Complexity: O(1) 

/* There can be a maximum of two integers that can occur more than floor(N/3) times.  */


// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         for(int i = 0; i < n; i++){
//             // In order to prevent duplicate number
//             if(ans.size() == 0 || ans[0] != nums[i]){
//                 int cnt = 1;
//                 for(int j = i+1; j < n; j++){
//                     if(nums[i] == nums[j]){
//                         cnt++;
//                     }
//                 }
//                 if(cnt > n/3){
//                     ans.push_back(nums[i]);
//                 }
//             }

//             // At maximun their can only be 2 Majority Element 
//             if(ans.size() == 2){
//                 break;
//             }
//         }

//         return ans;
//     }
// };





/* Solution 3: Better Approach (Using Hashing)  (Two pass) */
// Time Complexity: O(NlogN)
// Space Complexity: O(N) 


// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         unordered_map<int,int> mp;
//         for(int i = 0; i < n; i++){
//             mp[nums[i]]++;
//         }

//         for(auto it : mp){
//             if(it.second > n/3){
//                 ans.push_back(it.first);
//             }
//         }

//         return ans;
//     }
// };



/* Solution 4: Better Approach (Using Hashing)  (One pass) */
// Time Complexity: O(NlogN)
// Space Complexity: O(N) 


// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         // least occurrence of the majority element
//         int mini = (n/3) + 1;
//         unordered_map<int,int> mp;
//         for(int i = 0; i < n; i++){
//             mp[nums[i]]++;
//             // In order to prevent duplicate number we check with mini
//             if( mp[nums[i]] == mini){
//                 ans.push_back(nums[i]);
//             }
//             // At maximun their can only be 2 Majority Element 
//             if(ans.size() == 2){
//                 break;
//             }
//         }

//         return ans;
//     }
// };



/* Solution 5: Optimal Approach (Extended Boyer Moore’s Voting Algorithm) */
// Time Complexity: O(N) + O(N)
// Space Complexity: O(1) 


// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
//         for(int i = 0; i < n; i++){
//             if(count1 == 0 && num2 != nums[i]){
//                 num1 = nums[i];
//                 count1++;
//             }
//             else if(count2 == 0 && num1 != nums[i]){
//                 num2 = nums[i];
//                 count2++;
//             }
//             else if(num1 == nums[i]){
//                 count1++;
//             }
//             else if(num2 == nums[i]){
//                 count2++;
//             }
//             else{
//                 count1--;
//                 count2--;
//             }
//         }

//         count1 = count2 = 0;
//         for(int i = 0; i < n; i++){
//             if(nums[i] == num1){
//                 count1++;
//             }
//             else if(nums[i] == num2){
//                 count2++;
//             }
//         }
        
//         if(count1 > n/3){
//             ans.push_back(num1);
//         }
//         if(count2 > n/3){
//             ans.push_back(num2);
//         }
        
//         return ans;
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