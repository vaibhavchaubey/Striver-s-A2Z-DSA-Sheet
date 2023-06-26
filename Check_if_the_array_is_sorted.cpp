/* Leetcode  Submission    (1752. Check if Array Is Sorted and Rotated) */


/* Problem Statement: Given an array nums, return true if the array was originally sorted in non-decreasing order, 
then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], 
where % is the modulo operation. */


/* Solution:  */
// Time Complexity: O(N)
// Space Complexity: O(1)  


// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 1; i < n; i++){
//             if(nums[i-1] > nums[i]){
//                 count++;
//             }
//         }

//         if(nums[n-1] > nums[0]){
//             count++;
//         }
            
//         return count <= 1;
//     }
// };




/* GFG  Submission    (Check if array is sorted) */


/* Problem Statement: Given an array arr[] of size N, check if it is sorted in non-decreasing order or not.  */


/* Solution:  */
// Time Complexity: O(N)
// Space Complexity: O(1)  


// class Solution {
//   public:
//     bool arraySortedOrNot(int arr[], int n) {
//         for(int i = 1; i < n; i++){
//             if(arr[i-1] > arr[i]){
//                 return false;
//             }
//         }
        
//         return true;
//     }
// };