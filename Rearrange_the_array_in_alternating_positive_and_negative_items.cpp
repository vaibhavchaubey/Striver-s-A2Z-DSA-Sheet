/* Leetcode  Submission    (2149. Rearrange Array Elements by Sign) */

/* Problem Statement: You are given a 0-indexed integer array nums of even length consisting of an equal 
number of positive and negative integers.
You should rearrange the elements of nums such that the modified array follows the given conditions:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions. */


/* Solution 1: Brute Force Method */
// Time Complexity: O(N) + O(N/2)
// Space Complexity: O(N)


// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> ans;
//         vector<int> positive;
//         vector<int> negative;
//         int n = nums.size();

//         for(auto num : nums){
//             if(num < 0){
//                 negative.push_back(num);
//             }
//             else{
//                 positive.push_back(num);
//             }
//         }

//         for(int i = 0; i < n/2; i++){
//             ans.push_back(positive[i]);
//             ans.push_back(negative[i]);
//         }

//         return ans;
//     }
// };



/* Solution 2: Optimal Method */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         int posIndex = 0, negIndex = 1;
//         for(auto num : nums){
//             if(num < 0){
//                 ans[negIndex] = num;
//                 negIndex += 2;
//             }
//             else{
//                 ans[posIndex] = num;
//                 posIndex += 2;
//             }
//         }
        
//         return ans;
//     }
// };



/* GFG  Submission    (Alternate positive and negative numbers) */

/* Problem Statement: Given an unsorted array Arr of N positive and negative numbers. 
Your task is to create an array of alternate positive and negative numbers without changing the relative 
order of positive and negative numbers.
Note: Array should start with a positive number. */


/* Solution: */
// Time Complexity: O(N + N) 
// Space Complexity: O(N)


// class Solution{
// public:

// 	void rearrange(int arr[], int n) {
// 	   vector<int> positive;
// 	   vector<int> negative;
	   
// 	   for(int i = 0; i < n; i++){
// 	       if(arr[i] < 0){
// 	           negative.push_back(arr[i]);
// 	       }
// 	       else{
// 	           positive.push_back(arr[i]);
// 	       }
// 	   }
	   
// 	   if(positive.size() > negative.size()){
// 	       for(int i = 0; i < negative.size(); i++){
// 	           arr[2*i] = positive[i]; 
// 	           arr[2*i+1] = negative[i]; 
// 	       }
// 	       int index = 2 * negative.size();
// 	       for(int i = negative.size(); i < positive.size(); i++){
// 	           arr[index] = positive[i];
// 	           index++;
// 	       }
// 	   }
// 	   else{
// 	       for(int i = 0; i < positive.size(); i++){
// 	           arr[2*i] = positive[i]; 
// 	           arr[2*i+1] = negative[i]; 
// 	       }
// 	       int index = 2 * positive.size();
// 	       for(int i = positive.size(); i < negative.size(); i++){
// 	           arr[index] = negative[i];
// 	           index++;
// 	       }
// 	   }
// 	}
// };