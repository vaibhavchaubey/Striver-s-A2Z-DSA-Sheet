/* Leetcode  Submission    (189. Rotate Array) */

/* Problem Statement: Given an integer array nums, rotate the array to the right by k steps, where k is non-negative. */


/* Solution: 1  */
// Time Complexity: O(N)
// Space Complexity: O(N)  


// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> temp;
//         k = k % n;
//         for(int i = n - k; i < n; i++){
//             temp.push_back(nums[i]);
//         }
//         for(int i = 0; i < n - k; i++){
//             temp.push_back(nums[i]);
//         }

//         for(int i = 0; i < n; i++){
//             nums[i] = temp[i];
//         }
//     }
// };


/* Solution: 2  */
// Time Complexity: O(N)
// Space Complexity: O(1)  


// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n;

//         // Reverse first n-k elements
//         reverse(nums.begin(), nums.begin() + (n - k));
//         // Reverse last k elements
//         reverse(nums.begin() + (n - k), nums.end());
//         // Reverse whole array
//         reverse(nums.begin(), nums.end());
//     }
// };



/* GFG  Submission    (Quick Left Rotation) */

/* Problem Statement: Given an array of size N. The task is to rotate array by D elements where D ≤ N. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)  


// class Solution{   
// public:
//     void leftRotate(int arr[], int n, int d) {
//         d = d % n;
	   
// 	   // Reverse first d elements
// 	   reverse(arr, arr + d);
// 	   // Reverse last n-d elements
// 	   reverse(arr + d, arr + n);
// 	   // Reverse whole array
// 	   reverse(arr, arr + n);
//     }
// };