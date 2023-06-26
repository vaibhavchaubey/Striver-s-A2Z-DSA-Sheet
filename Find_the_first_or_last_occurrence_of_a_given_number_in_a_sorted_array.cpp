/* Leetcode  Submission    (34. Find First and Last Position of Element in Sorted Array) */

/* Problem Statement: Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity. */


/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int first = -1, last = -1;
//         for(int i = 0; i < n; i++){
//             if(nums[i] == target){
//                 if(first == -1){
//                     first = i;
//                 }
//                 last = i;
//             }
//         }

//         return {first, last};
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search) (lower_bound & upper_bound)    */
// Time Complexity: O(2 * logN)
// Space Complexity: O(1)


// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//         if(first == n || nums[first] != target){
//             return {-1, -1};
//         }
//         int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

//         return {first, last};
//     }
// };


/* OR  By implementing lower_bound and upper_bound  */

// class Solution {
// public:
//     int lowerBound(vector<int>& nums, int n, int x) {
//         int low = 0, high = n - 1;
//         int ans = n;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             // maybe an answer
//             if (nums[mid] >= x) {
//                 ans = mid;
//                 //look for smaller index on the left
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1; // look on the right
//             }
//         }
//         return ans;
//     }

//     int upperBound(vector<int>& nums, int n, int x) {
//         int low = 0, high = n - 1;
//         int ans = n;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;    
//             // maybe an answer
//             if (nums[mid] > x) {
//                 ans = mid;
//                 //look for smaller index on the left
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1; // look on the right
//             }
//         }
//         return ans;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int first = lowerBound(nums, n, target);
//         if(first == n || nums[first] != target){
//             return {-1, -1};
//         }
//         int last = upperBound(nums, n, target) - 1;

//         return {first, last};
//     }
// };



/* Solution 3: Optimal Approach   (Only Using Binary Search)   */
// Time Complexity: O(2 * logN)
// Space Complexity: O(1)


// class Solution {
// public:
//     int firstPos(vector<int>& nums, int n, int target){
//         int low = 0, high = n - 1;
//         int first = -1;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if (nums[mid] == target) {
//                 first = mid;
//                 high = mid - 1;
//             }
//             else if(nums[mid] < target){
//                 low = mid + 1;
//             }
//             else {
//                 high = mid - 1;
//             }
//         }
//         return first; 
//     }

//     int lastPos(vector<int>& nums, int n, int target){
//         int low = 0, high = n - 1;
//         int last = -1;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if (nums[mid] == target) {
//                 last = mid;
//                 low = mid + 1;
//             }
//             else if(nums[mid] < target){
//                 low = mid + 1;
//             }
//             else {
//                 high = mid - 1;
//             }
//         }
//         return last; 
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int first = firstPos(nums, n, target);
//         if(first == -1){
//             return {-1, -1};
//         }
//         int last = lastPos(nums, n, target);

//         return {first, last};
//     }
// };