/* Leetcode  Submission    (26. Remove Duplicates from Sorted Array) */

/* Problem Statement: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place 
such that each unique element appears only once. The relative order of the elements should be kept the same. 
Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the unique elements in the order they 
were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k. */


/* Solution: 1  */
// Time Complexity: O(N)
// Space Complexity: O(1)  


// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if(nums.size() == 0){
//             return 0;
//         }
//         int left = 0;
//         for(int right = 1; right < nums.size(); right++){
//             if(nums[left] != nums[right]){
//                 left++;
//                 nums[left] = nums[right];
//             }
//         }
        
//         return left+1;
//     }
// };