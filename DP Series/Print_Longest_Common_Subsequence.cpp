/* Codestudio   Submission    (Print Longest Common Subsequence) */


/* Problem Statement: Problem Statement
You are given two strings 's1'and 's2. Return the longest common subsequence of these strings. If there's no such string, return an empty string. 
If there are multiple possible answers, return any such string. */



/* Solution: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)  (Array) 


// string findLCS(int n, int m,string &s1, string &s2){
// 	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

// 	for(int i = 0; i <= m; i++){    	 // base condition
// 		dp[0][i] = 0;					// ind1 = -1
// 	}	

// 	for(int i = 0; i <= n; i++){
// 		dp[i][0] = 0;					// ind2 = -1
// 	}	

// 	for(int ind1 = 1; ind1 <= n; ind1++){
// 		for(int ind2 = 1; ind2 <= m; ind2++){
// 			if(s1[ind1-1] == s2[ind2-1]){
// 				dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
// 			}
// 			else{
// 				dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
// 			}
// 		}
// 	}

// 	int i = n, j = m;
// 	string ans = "";

// 	while(i > 0 && j > 0){
// 		if(s1[i-1] == s2[j-1]){
// 			ans += s1[i-1];
// 			i--;
// 			j--;
// 		}
// 		else if(dp[i-1][j] > dp[i][j-1]){
// 			i--;
// 		}			
// 		else{								// dp[i-1][j] < dp[i][j-1]
// 			j--;
// 		}
// 	}

// 	reverse(ans.begin(), ans.end());

// 	return ans;
// }




/* Problem Statement: Given two strings text1 and text2, print the longest common subsequence */


// #include<bits/stdc++.h>
// using namespace std;
// void printLongestCommonSubsequence(string text1, string text2) {
//     int n = text1.length(), m = text2.length();
//     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//     for(int i = 0; i <= m; i++){            // base condition
//         dp[0][i] = 0;                       // ind1 = -1
//     }
//     for(int i = 0; i <= n; i++){            
//         dp[i][0] = 0;                       // ind2 = -1
//     }

//     for(int ind1 = 1; ind1 <= n; ind1++){
//         for(int ind2 = 1; ind2 <= m; ind2++){
//             if(text1[ind1-1] == text2[ind2-1]){
//                 dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
//             }
//             else{
//                 dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
//             }
//         }
//     }

//     // O(N+M)

//     int len = dp[n][m];
//     int i = n; 
//     int j = m;

//     int index = len - 1;
//     string ans = "";
//     for(int i = 0; i < len; i++){
//         ans += "$";         // dummy string
//     }

//     while(i > 0 && j > 0){
//         if(text1[i-1] == text2[j-1]){
//             ans[index] = text1[i-1];
//             index--;
//             i--;
//             j--;
//         }
//         else if(dp[i-1][j] > dp[i][j-1]){
//             i--;
//         }
//         else{               // dp[i-1][j] < dp[i][j-1]
//             j--;
//         }
//     }

//     cout<<ans;
// }
// int main()
// {
//     string text1 = "abcde";
//     string text2 = "bdgek";

//     cout << "The Longest Common Subsequence is: ";
//     printLongestCommonSubsequence(text1, text2);
    


//     return 0;
// }