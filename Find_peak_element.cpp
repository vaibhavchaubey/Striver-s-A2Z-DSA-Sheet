/* Leetcode  Submission    (162. Find Peak Element) */

/* Here Peak Element means   =>  arr[i-1] < arr[i] > arr[i+1] */

/* Problem Statement: A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, 
return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a 
neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time. */


/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             if((i == 0 || nums[i-1] < nums[i]) && (i == n-1 || nums[i] > nums[i+1])){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         // single element
//         if(n == 1) return 0; 

//         // check if 0th/n-1th index is the peak element
//         if(nums[0] > nums[1]) return 0;
//         if(nums[n-1] > nums[n-2]) return n-1;

//         // search in the remaining array
//         int low = 1, high = n-2;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
//                 return mid;
//             } 

//             // mid on the increasing path that means our ans will be in right
//             else if(nums[mid] > nums[mid-1]){
//                 low = mid + 1;
//             }

//             // mid is on the decreasing path  peak will be on left side
//             // also handle the case when  nums[mid-1]  > nums[mid] < nums[mid+1]
//             else{                           // if(nums[mid] > nums[mid-1])
//                 high = mid - 1;
//             }
//         }

//         return -1;
//     }
// };



/* GFG  Submission    (Peak element) */

/* Here Peak Element means   =>  arr[i-1] <= arr[i] >= arr[i+1] */

/* Problem Statement: An element is called a peak element if its value is not smaller than the value of its adjacent 
elements(if they exists).
Given an array arr[] of size N, Return the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0.  */


/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution
// {
//     public:
//     int peakElement(int arr[], int n)
//     {
//         for(int i = 0; i < n; i++){
//             if((i == 0 || arr[i-1] <= arr[i]) && (i == n-1 || arr[i] >= arr[i+1])){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// class Solution
// {
//     public:
//     int peakElement(int arr[], int n)
//     {
//         // single element
//         if(n == 1) return 0; 

//         // check if 0th/n-1th index is the peak element
//         if(arr[0] >= arr[1]) return 0;
//         if(arr[n-1] >= arr[n-2]) return n-1;

//         // search in the remaining array
//         int low = 1, high = n-2;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]){
//                 return mid;
//             } 

//             // mid on the increasing path that means our ans will be in right
//             else if(arr[mid] > arr[mid-1]){
//                 low = mid + 1;
//             }

//             // mid is on the decreasing path  peak will be on left side
//             // also handle the case when  arr[mid-1]  > arr[mid] < arr[mid+1]
//             else{                           // if(arr[mid] > arr[mid-1])
//                 high = mid - 1;
//             }
//         }

//         return -1;
//     }
// };