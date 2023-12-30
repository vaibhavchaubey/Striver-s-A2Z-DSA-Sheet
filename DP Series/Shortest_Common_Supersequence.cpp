/* Leetcode   Submission    (1092. Shortest Common Supersequence) */


/* Problem Statement: Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
If there are multiple valid strings, return any of them. */



/* Solution: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)  (Array) 


// class Solution {
// public:
//     string shortestCommonSupersequence(string str1, string str2) {
//         int n = str1.length(), m = str2.length();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//         // Base Case is covered as we have initialized the dp array to 0

//         for(int ind1 = 1; ind1 <= n; ind1++){
//             for(int ind2 = 1; ind2 <= m; ind2++){
//                 if(str1[ind1-1] == str2[ind2-1]){
//                     dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
//                 }
//                 else{
//                     dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
//                 }
//             }
//         }

//         int i = n;
//         int j = m;
//         string ans = "";

//         while(i > 0 && j > 0){
//             if(str1[i-1] == str2[j-1]){
//                 ans += str1[i-1];
//                 i--;
//                 j--;
//             }
//             else if(dp[i-1][j] > dp[i][j-1]){
//                 ans += str1[i-1];
//                 i--;
//             }
//             else{
//                 ans += str2[j-1];
//                 j--;
//             }
//         }

//         //Adding Remaing Characters - Only one of the below two while loops will run 
//         while(i > 0){
//             ans += str1[i-1];
//             i--;
//         }
//         while(j > 0){
//             ans += str2[j-1];
//             j--;
//         }

//         reverse(ans.begin(), ans.end());

//         return ans;
//     }
// };



