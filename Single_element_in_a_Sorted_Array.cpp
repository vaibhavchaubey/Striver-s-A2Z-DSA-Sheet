/* Leetcode  Submission    (540. Single Element in a Sorted Array) */

/* Problem Statement: You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space. */


/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1){
//             return nums[0];
//         }
//         for(int i = 0; i < n; i++){
//             if(i == 0){
//                 if(nums[i] != nums[i+1]){
//                     return nums[i];
//                 }
//             }
//             else if(i == n-1){
//                 if(nums[i] != nums[i-1]){
//                     return nums[i];
//                 }
//             }
//             else{
//                 if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
//                     return nums[i];
//                 }
//             }
//         }
        
//         return -1;
//     }
// };


/* Solution 2: XOR Approach: */
// Time Complexity: O(N)
// Space Complexity: O(1) 


/* XOR Property */
// XOR of same number is 0   (2 ^ 2 = 0)
// XOR of any number with 0 is the number itself     (0 ^ 2 = 2)


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int XOR = 0;
//         for(int i = 0; i < n; i++){
//             XOR ^= nums[i];
//         }

//         return XOR;
//     }
// };





/* Solution 3: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int low = 0, high = n-1;
//         while(low < high){
//             int mid = low + (high - low) / 2;
//             // even, odd   (Element is in the right half)
//             if((mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 != 0 && nums[mid] == nums[mid-1])){          
//                 low = mid + 1;
//             }
            
//             // odd, even   (Element is in the left half)
//             // high = mid  is done, to also handle case when nums[mid-1] != nums[mid] != nums[mid+1]
//             else{
//                 high = mid;
//             }
//         }

//         return nums[low];
//     }
// };


/* OR */


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int low = 0, high = n-1;
//         while(low < high){
//             int mid = low + (high - low) / 2;
//             // odd, even   (Element is in the left half)
//             if(mid % 2 == 0 && nums[mid] == nums[mid-1]){       
//                 high = mid - 2;
//             }
//             // even, odd   (Element is in the right half)
//             else if(mid % 2 == 0 && nums[mid] == nums[mid+1]){          
//                 low = mid + 2;
//             }
//             // even, odd   (Element is in the right half)
//             else if(mid % 2 != 0 && nums[mid] == nums[mid-1]){      
//                 low = mid + 1;
//             }
//             // odd, even   (Element is in the left half)
//             else if(mid % 2 != 0 && nums[mid] == nums[mid+1]){      
//                 high = mid - 1;
//             }
//             else{
//                 return nums[mid];
//             }
//         }

//         return nums[low];
//     }
// };



