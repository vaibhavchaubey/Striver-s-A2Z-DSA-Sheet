/* Leetcode  Submission   (37. Sudoku Solver)  */

/* Problem Statement: Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells. */

/* Solution: Recursion   */
/* Time Complexity : O(9^(N^2))
in the worst case, for each cell in the n2 board, we have 9 possible numbers.

Space Complexity : O(1)  */

// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }
//     bool solve(vector<vector<char>>& board){
//         for(int i = 0; i < board.size(); i++){
//             for(int j = 0; j < board[0].size(); j++){
//                 if(board[i][j] == '.'){
//                     for(char c = '1'; c <= '9'; c++){
//                         if(isValid(board,i,j,c)){
//                             board[i][j] = c;

//                             if(solve(board)){
//                                 return true;
//                             }
//                             else{
//                                 board[i][j] = '.';      //backtracking
//                             }
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     bool isValid(vector<vector<char>>& board, int row, int col, char c){
//         for(int i = 0; i < 9; i++){
//             if(board[i][col] == c){
//                 return false;
//             }
//             if(board[row][i] == c){
//                 return false;
//             }
//             if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c){
//                 return false;
//             }
//         }
//         return true;
//     }
// };