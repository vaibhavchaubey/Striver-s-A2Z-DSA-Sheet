/* Leetcode  Submission      (84. Largest Rectangle in Histogram) */

/* Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram. */



/* Solution 1: Brute Force Approach */
/* Intuition: The intuition behind the approach is taking different bars and finding the maximum width possible using the bar. */

// Time Complexity: O(N * N) 
// Space Complexity: O(1) 


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea = 0;
//         for(int i = 0; i < n; i++){
//             int minHeight = INT_MAX;
//             for(int j = i; j < n; j++){
//                 minHeight = min(minHeight, heights[j]);
//                 int len = j-i+1;                            // As there is 0 base indexing that's why +1
//                 maxArea = max(maxArea, minHeight * len);
//             }
//         }

//         return maxArea;
//     }
// };



/* Solution 2: Optimised Approach 1 */
/* Intuition: The intuition behind the approach is the same as finding the smaller element on both sides but in an optimized 
way using the concept of the next greater element and the next smaller element. */

/*.                  leftSamll     rightSamll  (one O(N) for linearing traversing and second O(N) for stack)
Time Complexity: O(N) + O(N)  + O(N) + O(N)   ~   O(N)
Space Complexity: O(3N) where 3 is for the stack, left small array and a right small array */


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int leftSmall[n], rightSmall[n];
//         stack<int> st;
//         for(int i = 0; i < n; i++){
//             while(!st.empty() && heights[st.top()] >= heights[i]){
//                 st.pop();
//             }
//             if(st.empty()){
//                 leftSmall[i] = 0;
//             }
//             else{
//                 leftSmall[i] = st.top() + 1;
//             }
//             st.push(i);
//         }

//         // clear the stack to be re-used
//         while(!st.empty()){
//             st.pop();
//         }
        
//         for(int i = n-1; i >= 0; i--){
//             while(!st.empty() && heights[st.top()] >= heights[i]){
//                 st.pop();
//             }
//             if(st.empty()){
//                 rightSmall[i] = n-1;
//             }
//             else{
//                 rightSmall[i] = st.top() - 1;
//             }
//             st.push(i);
//         }

//         int maxArea = 0;
//         for(int i = 0; i < n; i++){
//             maxArea = max(maxArea, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
//         }

//         return maxArea;
//     }
// };



/* Solution 3: Optimised approach 2 */
// Time Complexity: O(N) + O (N)
// Space Complexity: O(N) 

/* Intuition:
This approach is a single pass approach instead of a two-pass approach. When we traverse the array by finding the next greater element, 
we found that some elements were inserted into the stack which signifies that after them the smallest element is themselves
So we can find the area of the rectangle by using arr[i] * (right smaller – left smaller -1 ). */


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         stack<int> st;
//         int maxArea = 0;
//         for(int i = 0; i <= n; i++){
//             while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
//                 int h = heights[st.top()];
//                 st.pop();
//                 int len;
//                 if(st.empty()){
//                     len = i;
//                 }
//                 else{
//                     len = i - st.top() - 1;         // (rightSmall - leftSmall - 1)
//                 }

//                 maxArea = max(maxArea, h * len);      // arr[i] * (rightSmall – leftSmall - 1)
//             }
//             st.push(i);
//         }

//         return maxArea;
//     }
// };



