/* Leetcode  Submission    (31. Next Permutation) */

/* Problem Statement: A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
then the next permutation of that array is the permutation that follows it in the sorted container. 
If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory. */


/* Solution 1: Using inbuilt function */
/* The complexity of next_permutation that transforms the permutation to the next permutation in the 
lexicographic order is O(n) in the worst case. */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) { 
//         //using inbuilt function
//         next_permutation(nums.begin(),nums.end());
//     }
// };   



/* Solution 2: */
// Time Complexity: O(3N)
// Space Complexity: O(1)


// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();

//         // Step 1: Find the break point
//         int ind = -1;
//         for(int i = n-2; i >= 0; i--){
//             if(nums[i] < nums[i+1]){
//                 // index i is the break point
//                 ind = i;                
//                 break;
//             }
//         }

//         // If break point does not exist
//         if(ind == -1){
//             // reverse the whole array
//             reverse(nums.begin(), nums.end());
//         }
//         else{
//             // Step 2: Find the next greater element and swap it with arr[ind]
//             for(int i = n-1; i > ind; i--){
//                 if(nums[i] > nums[ind]){
//                     swap(nums[i], nums[ind]);
//                     break;
//                 }
//             }
//             // Step 3: reverse the right half
//             reverse(nums.begin() + ind + 1, nums.end());
//         }
//     }
// };