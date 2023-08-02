/* Leetcode  Submission    (42. Trapping Rain Water) */

/* Problem Statement: Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining. */



/* Solution 1: Using array for finding leftMax and rightMax for the current height */
// Time Complexity: O(3N)                                           
// Space Complexity: O(2N)


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int left[n];
//         int right[n]; 
        
//         left[0] = height[0];
//         for(int i = 1; i < n; i++){
//             left[i] = max(left[i-1], height[i]);
//         }
        
//         right[n-1] = height[n-1];
//         for(int i = n-2; i >= 0; i--){
//             right[i] = max(right[i+1], height[i]);
//         }
        
//         int waterTrapped = 0;
//         for(int i = 0; i < n; i++){
//             waterTrapped += (min(left[i],right[i]) - height[i]);
//         }
        
//         return waterTrapped;
//     }
// };



/* Solution 2: Using Two Pointer  */
// Time Complexity: O(N)                                           
// Space Complexity: O(1)


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int left = 0, right = n-1;
//         int waterTrapped = 0;
//         int leftMax = 0, rightMax = 0;
//         while(left <= right){
//             if(height[left] <= height[right]){
//                 if(height[left] >= leftMax){
//                     leftMax = height[left];
//                 }
//                 else{
//                     waterTrapped += leftMax - height[left];
//                 }
//                 left++;
//             }
//             else{                                   // height[right] > height[left]
//                 if(height[right] >= rightMax){
//                     rightMax = height[right];
//                 }
//                 else{
//                     waterTrapped += rightMax - height[right];
//                 }
//                 right--;
//             }
//         }
        
//         return waterTrapped;
//     }
// };