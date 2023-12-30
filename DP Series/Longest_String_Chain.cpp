/* Leetcode   Submission    (1048. Longest String Chain) */


/* Problem Statement: You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing 
the order of the other characters to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a 
predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
Return the length of the longest possible word chain with words chosen from the given list of words. */




/* Solution: */
/* Tabulation algorithm */
// Time Complexity: O(N*N*l)          // where l is the length of the longest string in the words [ ] array
// Space Complexity: O(N)


// class Solution {
// public:
//     bool isPredecessor(string& s1, string& s2){
//         if(s1.size() != s2.size() + 1){
//             return false;
//         }
//         int first = 0;
//         int second = 0;

//         while(first < s1.size()){
//             if(second < s2.size() && s1[first] == s2[second]){
//                 first++;
//                 second++;
//             }
//             else{
//                 first++;
//             }
//         }

//         if(first == s1.size() && second == s2.size()){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     static bool comp(string& s1, string& s2){
//         return s1.size() < s2.size();
//     }
//     int longestStrChain(vector<string>& words) {
//         int n = words.size();

//         //sort the array
//         sort(words.begin(), words.end(), comp);

//         vector<int> dp(n, 1);

//         int ans = -1;
//         for(int i = 0; i < n; i++){
//             for(int prev_index = 0; prev_index < i; prev_index++){
//                 if(isPredecessor(words[i], words[prev_index]) && 1 + dp[prev_index] > dp[i]){
//                     dp[i] = 1 + dp[prev_index];
//                 }
//             }
//             ans = max(ans, dp[i]);
//         }

//         return ans;
//     }
// };