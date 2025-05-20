/* Leetcode  Submission   (51. N-Queens)  */

/* Problem Statement: The n-queens puzzle is the problem of placing n queens on an n x n chessboard
such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer
in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
both indicate a queen and an empty space, respectively. */

/* Solution 1: Backtracking */
/* Time Complexity: O(N! * 3N)   ~    O(N! * N)
Exponential in nature, since we are trying out all ways.

Space Complexity: O(N^2)    */

// class Solution {
// public:
//     bool isSafe(int row, int col, vector<string>& board, int n) {
//         // Check for upper left diagonal
//         int duprow = row;
//         int dupcol = col;
//         while (row >= 0 && col >= 0) {                   O(N)
//             if (board[row][col] == 'Q') {
//                 return false;
//             }
//             row--;
//             col--;
//         }

//         // Check this row on left side
//         row = duprow;
//         col = dupcol;
//         while (col >= 0) {                               O(N)
//             if (board[row][col] == 'Q') {
//                 return false;
//             }
//             col--;
//         }

//         // Check for lower left diagonal
//         row = duprow;
//         col = dupcol;
//         while (row < n && col >= 0) {                    O(N)
//             if (board[row][col] == 'Q') {
//                 return false;
//             }
//             row++;
//             col--;
//         }

//         return true;
//     }
//     void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
//         if (col == n) {
//             ans.push_back(board);
//             return;
//         }

//         for (int row = 0; row < n; row++) {
//             if (isSafe(row, col, board, n)) {
//                 board[row][col] = 'Q';
//                 solve(col + 1, board, ans, n);
//                 // backtracking
//                 board[row][col] = '.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;

//         // vector<string> board(n);
//         // string s(n, '.');
//         // for (int i = 0; i < n; i++) {
//         //     board[i] = s;
//         // }

//         vector<string> board(n, string(n, '.'));

//         solve(0, board, ans, n);

//         return ans;
//     }
// };

/* Solution 2: Backtracking
Intuition: This is the optimization of the issafe function. In the previous issafe function,
we need o(N) for a row, o(N) for the column, and o(N) for the diagonal. Here, we will use
hashing to maintain a list to check whether that position can be the right one or not. */

/* Time Complexity: O(N! * N)
Exponential in nature, since we are trying out all ways.

Space Complexity: O(N * N)    */

// class Solution {
// public:

//     void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int n) {
//         if (col == n) {
//             ans.push_back(board);
//             return;
//         }

//         for (int row = 0; row < n; row++) {
//             if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0){
//                 board[row][col] = 'Q';
//                 leftRow[row] = 1;
//                 lowerDiagonal[row + col] = 1;
//                 upperDiagonal[n - 1 + col - row] = 1;
//                 solve(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
//                 // backtracking
//                 board[row][col] = '.';
//                 leftRow[row] = 0;
//                 lowerDiagonal[row + col] = 0;
//                 upperDiagonal[n - 1 + col - row] = 0;
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;

//         // vector<string> board(n);
//         // string s(n, '.');
//         // for (int i = 0; i < n; i++) {
//         //     board[i] = s;
//         // }

//         vector<string> board(n, string(n, '.'));
//         vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);

//         solve(0, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);

//         return ans;
//     }
// };