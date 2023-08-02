/* Leetcode  Submission      (85. Maximal Rectangle) */

/* Problem Statement: Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle 
containing only 1's and return its area. */



/* Solution: (Using Largest Rectangle in Histogram Approach) */
/* where N = total no. of rows and M = total no. of columns.
Time Complexity: O(N * (M+M))
Space Complexity: O(M) */


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
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int row = matrix.size();
//         int col = matrix[0].size();
//         vector<int> heights(col, 0);

//         int maxArea = 0;
//         for(int i = 0; i < row; i++){
//             for(int j = 0; j < col; j++){
//                 if(matrix[i][j] == '1'){
//                     heights[j]++;
//                 }
//                 else{                   // matrix[i][j] == '0'
//                     heights[j] = 0;
//                 }
//             }

//             int area = largestRectangleArea(heights);
//             maxArea = max(maxArea, area);
//         }

//         return maxArea;
//     }
// };



