/* CodeStudio   Submission    (Longest Common Substring) */


/* Problem Statement: A substring of a string is a subsequence in which all the characters are consecutive. 
Given two strings, we need to find the longest common substring. */



/* Solution 1: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)  (Array) 


// #include <bits/stdc++.h>
// int lcs(string &str1, string &str2){
//     int n = str1.size(), m = str2.size();
//     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
//     // Base Case is covered as we have initialized the dp array to 0
    
//     int ans = 0;
//     for(int ind1 = 1; ind1 <= n; ind1++){
//         for(int ind2 = 1; ind2 <= m; ind2++){
//             if(str1[ind1-1] == str2[ind2-1]){
//                 dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
//                 ans = max(ans, dp[ind1][ind2]);
//             }
//             else{
//                 dp[ind1][ind2] = 0;
//             }
//         }
//     }
    
//     return ans;
// }



/* Solution 2: */
/* Space Optimization */
// Time Complexity: O(N*M) 
// Space Complexity: O(M)


// #include <bits/stdc++.h>
// int lcs(string &str1, string &str2){
//     int n = str1.size(), m = str2.size();
//     vector<int> prev(m+1, 0), cur(m+1, 0);
    
//     // Base Case is covered as we have initialized the prev and cur to 0
    
//     int ans = 0;
//     for(int ind1 = 1; ind1 <= n; ind1++){
//         for(int ind2 = 1; ind2 <= m; ind2++){
//             if(str1[ind1-1] == str2[ind2-1]){
//                 cur[ind2] = 1 + prev[ind2-1];
//                 ans = max(ans, cur[ind2]);
//             }
//             else{
//                 cur[ind2] = 0;
//             }
//         }
//         prev = cur;
//     }
    
//     return ans;
// }