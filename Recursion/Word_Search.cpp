/* Leetcode  Submission   (79. Word Search)  */


/* Problem Statement: Given an m x n grid of characters board and a string word, return true if word 
exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
horizontally or vertically neighboring. The same letter cell may not be used more than once. */


/* Solution: Backtracking */
/* Time Complexity: O(N * M * 4^K)
where “K” is the length of the word. And we are searching for the letter m*n times 
in the worst case. Here 4 in 4^k is because at each level of our decision tree we 
are making 4 recursive calls which equal 4^k in the worst case.

Space Complexity: O(K)                   // recursive stack     */


// class Solution {
// public:
//     bool helper(int i, int j, int index, vector<vector<char>>& board, string word){
//         // if index reaches at the end that means we have found the word
//         if(word.size() == index){
//             return true;
//         }  

//         // check for boundary                                  // curr char is not same with word char
//         if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]){
//             return false;
//         }
        
//         char temp = board[i][j];           // curr char
//         board[i][j] = '.';                // mark as visited

//         // up , down , left , right (possible moves)
//         bool ans = helper(i-1, j, index+1, board, word) ||
//                    helper(i+1, j, index+1, board, word) ||
//                    helper(i, j-1, index+1, board, word) ||
//                    helper(i, j+1, index+1, board, word); 

//         // backtrack
//         board[i][j] = temp;         // make board as it is for the upcoming calls

//         return ans;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size();             // rows
//         int n = board[0].size();         // cols

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(board[i][j] == word[0] && helper(i, j, 0, board, word)){
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };