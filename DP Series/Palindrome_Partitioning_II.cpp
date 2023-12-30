/* Leetcode  Submission    (132. Palindrome Partitioning II) */


/* Problem Statement: Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s. */



/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: (Exponential)
// Space Complexity: O(N) (Recursion)


// class Solution {
// public:
//     bool isPalindrome(int i, int j, string& s){
//         while(i < j){
//             if(s[i++] != s[j--]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int helper(int i, int n, string& s){
//         if(i == n){                 // base condition
//             return 0;
//         }

//         int minCost = INT_MAX;
//         for(int j = i; j < n; j++){
//             if(isPalindrome(i,j,s)){
//                 int cost = 1 + helper(j+1, n, s);
//                 minCost = min(minCost, cost);
//             }
//         }

//         return minCost;
//     }
//     int minCut(string s) {
//         int n = s.size();
        
//         // since it is also doing the partition at the end so we need to just substract 1 in the answer
//         return helper(0,n,s) - 1;
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N) 
// Space Complexity: O(N) (Recursion)   +   O(N)  (Array)


// class Solution {
// public:
//     bool isPalindrome(int i, int j, string& s){
//         while(i < j){
//             if(s[i++] != s[j--]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int helper(int i, int n, string& s, vector<int>& dp){
//         if(i == n){                 // base condition
//             return 0;
//         }

//         if(dp[i] != -1){
//             return dp[i];
//         }

//         int minCost = INT_MAX;
//         for(int j = i; j < n; j++){
//             if(isPalindrome(i,j,s)){
//                 int cost = 1 + helper(j+1, n, s, dp);
//                 minCost = min(minCost, cost);
//             }
//         }

//         return dp[i] = minCost;
//     }
//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n, -1);

//         // since it is also doing the partition at the end so we need to just substract 1 in the answer
//         return helper(0,n,s,dp) - 1;
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N) 
// Space Complexity: O(N)  (Array) 


// class Solution {
// public:
//     bool isPalindrome(int i, int j, string& s){
//         while(i < j){
//             if(s[i++] != s[j--]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n+1, 0);
//         dp[n] = 0;                // base condition

//         for(int i = n-1; i >= 0; i--){
//             int minCost = INT_MAX;
//             for(int j = i; j < n; j++){
//                 if(isPalindrome(i,j,s)){
//                     int cost = 1 + dp[j+1];
//                     minCost = min(minCost, cost);
//                 }
//             }

//             dp[i] = minCost;
//         }

//         // since it is also doing the partition at the end so we need to just substract 1 in the answer
//         return dp[0] - 1;
//     }
// };




/* Leetcode  Submission    (131. Palindrome Partitioning) */


/* Problem Statement: Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s. */



/* Solution: Backtracking */
// Time Complexity: O(N * 2^N)
// Space Complexity: O(N) (Recursion)


// class Solution {
// public:
//     bool isPalindrome(int start, int end, string s){
//        while(start <= end){
//            if(s[start++] != s[end--]){
//                return false;
//            }
//        }

//        return true;
//     }
//     void helper(int index, string s, vector<string>& path, vector<vector<string>>& ans){
//         if(index == s.size()){
//             ans.push_back(path);
//             return;
//         }

//         for(int i = index; i < s.size(); i++){
//             if(isPalindrome(index,i,s)){
//                 path.push_back(s.substr(index, i - index + 1));
//                 helper(i+1,s,path,ans);
//                 // backtrack
//                 path.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         vector<string> path;
//         helper(0,s,path,ans);

//         return ans;
//     }
// };