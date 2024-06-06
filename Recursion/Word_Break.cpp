/* Leetcode  Submission   (139. Word Break)  */


/* Problem Statement: Given a string s and a dictionary of strings wordDict, return true if s can be 
segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation. */


/* Solution 1: Backtracking + Hash Table   (It will give TLE)  */
/* Time Complexity : O(2^N)
Given a string of length N, there are N+1 ways to split it into two parts. At eachstep, we have a choice: 
to split or not to split. In the worse case, when all choices are to be checked, that results in O(2^N).

Space Complexity : O(N)
The depth of the recursion tree can go upto N. */


// class Solution {
// public:
//     bool helper(string s, unordered_set<string>& set){
//         if(s.size() == 0){
//             return true;
//         }

//         for(int i = 0; i < s.size(); i++){
//             if(set.count(s.substr(0, i+1)) && helper(s.substr(i+1), set)){
//                 return true;
//             }
//         }

//         return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> set(wordDict.begin(), wordDict.end());

//         return helper(s, set);
//     }
// };



/* Solution 2: Backtracking + Hash Table   (It will give TLE)  */
/* Time Complexity : O(2^N)
Given a string of length N, there are N+1 ways to split it into two parts. At eachstep, we have a choice: 
to split or not to split. In the worse case, when all choices are to be checked, that results in O(2^N).

Space Complexity : O(N)
The depth of the recursion tree can go upto N. */


// class Solution {
// public:
//     bool helper(int ind, string s, unordered_set<string>& set){
//         if(ind == s.size()){
//             return true;
//         }

//         for(int i = ind; i < s.size(); i++){
//             if(set.count(s.substr(ind, i+1-ind)) && helper(i+1, s, set)){
//                 return true;
//             }
//         }

//         return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> set(wordDict.begin(), wordDict.end());

//         return helper(0, s, set);
//     }
// };



/* Solution 3: DP(Memoisation) + Hash Table */
/* Time Complexity : O(N*N)
Each subproblem, defined by the starting index ind, is solved at most once due to memoization. 
For each starting index ind, the helper function checks all possible end indices from ind+1 to s.size(). 
Thus, in the worst case, it checks all substrings of the given string s.

Space Complexity : O(N) + O(N) + O(M)              
Memoization Array, Recursion Stack, Hash Set(O(M))     
where m is the total number of characters in all words in wordDict. */


// class Solution {
// public:
//     bool helper(int ind, string s, unordered_set<string>& set, vector<int>& dp){
//         if(ind == s.size()){
//             return true;
//         }

//         if(dp[ind] != -1){
//             return dp[ind];
//         }

//         for(int i = ind; i < s.size(); i++){
//             if(set.count(s.substr(ind, i+1-ind)) && helper(i+1, s, set, dp)){
//                 return dp[ind] = true;
//             }
//         }

//         return dp[ind] = false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.size();
//         unordered_set<string> set(wordDict.begin(), wordDict.end());

//         vector<int> dp(n, -1);

//         return helper(0, s, set, dp);
//     }
// };



/* Solution 4: DP(Tabulation) + Hash Table */
/* Time Complexity : O(N*N)

Space Complexity : O(N) + O(M)              
Memoization Array, Hash Set(O(M))     
where m is the total number of characters in all words in wordDict. */


// class Solution {
// public:
//     bool helper(int ind, string s, unordered_set<string>& set, vector<int>& dp){
//         if(ind == s.size()){
//             return true;
//         }

//         if(dp[ind] != -1){
//             return dp[ind];
//         }

//         for(int i = ind; i < s.size(); i++){
//             if(set.count(s.substr(ind, i+1-ind)) && helper(i+1, s, set, dp)){
//                 return dp[ind] = true;
//             }
//         }

//         return dp[ind] = false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.size();
//         unordered_set<string> set(wordDict.begin(), wordDict.end());

//         vector<bool> dp(n+1, false);
//         dp[0] = true;

//         for(int i = 1; i <= n; i++){
//             for(int j = 0; j < i; j++){
//                 if(dp[j] && set.count(s.substr(j, i-j))){
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }

//         return dp[n];
//     }
// };