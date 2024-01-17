/* CodeStudio   Submission    (Longest Common Substring) */


/* Problem Statement: You are given two strings, 'str1' and 'str2'. You have to find the length of the longest common substring.
A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not. */



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





/* (Print Longest Common Substring) */

/* Problem Statement: You are given two strings, 'str1' and 'str2'. You have to print the longest common substring.
A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not. */


#include<bits/stdc++.h>
using namespace std;
string printLongestCommonSubstring(string str1, string str2){
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Base Case is covered as we have initialized the dp array to 0
    
    int ans = 0;
    int i = -1, j = -1;
    for(int ind1 = 1; ind1 <= n; ind1++){
        for(int ind2 = 1; ind2 <= m; ind2++){
            if(str1[ind1-1] == str2[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                if(ans < dp[ind1][ind2]){
                    ans = dp[ind1][ind2];
                    i = ind1;
                    j = ind2;
                }
            }
            else{
                dp[ind1][ind2] = 0;
            }
        }
    }

    string str = "";
    while(i > 0 && j > 0 && dp[i][j] > 0){
        
        str += str1[i-1];
        i--;
        j--;
    }

    reverse(str.begin(), str.end());

    return str;
}
int main()
{
    // string text1 = "abcd";
    // string text2 = "abzd";

    string text1 = "abcjklp";
    string text2 = "acjkp";

    cout << "The Longest Common Subsequence is: ";
    cout<<printLongestCommonSubstring(text1, text2);
    


    return 0;
}