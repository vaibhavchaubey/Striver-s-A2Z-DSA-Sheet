/* Problem Statement: Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing 
only 1's and return its area. */


/* Leetcode  Submission    (85. Maximal Rectangle) */


/* Solution: (Using Largest Rectangle in Histogram Approach) */
// Time Complexity: O(N * (M+M)), where N = total no. of rows and M = total no. of columns.
// Space Complexity: Space Complexity: O(M), where M = total no. of columns.


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {                    
//         int n = heights.size();
//         stack<int> st; 
//         int maxA = 0;                               
//         for(int i = 0; i <= n; i++) {
//             while(!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
//                 int h = heights[st.top()];
//                 st.pop();
//                 int len;
//                 if(st.empty()) len = i;
//                 else len = i - st.top() - 1;
//                 maxA = max(maxA, h*len);
//             }
//             st.push(i);
//         }
//         return maxA;        
//     }
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<int> heights(m, 0);

//         int maxArea = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(matrix[i][j] == '1'){
//                     heights[j]++;
//                 }
//                 else{       // matrix[i][j] == '0'
//                     heights[j] = 0;
//                 }
//             }
//             int area = largestRectangleArea(heights);
//             maxArea = max(maxArea, area);
//         }

//         return maxArea;
//     }
// };