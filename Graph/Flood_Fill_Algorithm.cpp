/* Leetcode  Submission    (733. Flood Fill) */

/* Problem Statement: You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill. */



/* Solution: Using DFS */
// Time Complexity: O(N * M)
// Space Complexity: O(N * M) + O(N * M)      // grid[][], recursion stack


// class Solution {
// public:
//         bool isSafe(int r, int c, vector<vector<int>>& grid, int initialColor, int color){
//         int n = grid.size(), m = grid[0].size();

//         return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == initialColor && grid[r][c] != color);
//     }
//     void dfs(int row, int col, vector<vector<int>>& grid, int initialColor, int color){
//         grid[row][col] = color;

//         // All 4 possible directions (vertical, horizontal)
//         vector<int> dirRow = {-1, 1, 0, 0};
//         vector<int> dirCol = {0, 0, -1, 1};

//         for(int i = 0; i < 4; i++){
//             int r = row + dirRow[i];
//             int c = col + dirCol[i];

//             if(isSafe(r, c, grid, initialColor, color)){
//                 dfs(r, c, grid, initialColor, color);
//             }
//         }
//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int m = image.size(), n = image[0].size();
//         int initialColor = image[sr][sc];

//         if (initialColor == color){
//             return image;
//         }

//         vector<vector<int>> grid = image;
//         dfs(sr, sc, grid, initialColor, color);

//         return grid;
//     }
// };