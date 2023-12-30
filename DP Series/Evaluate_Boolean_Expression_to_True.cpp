/* Problem Statement: You are given an expression ‘EXP’ in the form of a string where operands will be : 
(TRUE and FALSE) and operators will be : (AND, OR, XOR). Now you have to find the number of ways we can 
parenthesize the expression such that it will evaluate to TRUE.
As the answer can be very large, return the output modulo 1000000007. */


/* Codestudio  Submission    (Boolean Evaluation) */


/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: (Exponential)
// Space Complexity: O(N) (Recursion)


// #include <bits/stdc++.h>
// int mod = 1e9 + 7;
// long long helper(int i, int j, bool isTrue, string& exp){
//     if(i > j){                  // base condition
//         return 0;
//     }
    
//     if(i == j){
//         if(isTrue == 1){
//             return exp[i] == 'T'; 
//         }
//         else{
//             return exp[i] == 'F'; 
//         }
//     }
    
//     long long ways = 0;
//     for(int ind = i+1; ind <= j-1; ind += 2){
//         long long lT = helper(i,ind-1,1,exp);           // number of ways in which left is true        
//         long long lF = helper(i,ind-1,0,exp);           // number of ways in which left is false
//         long long rT = helper(ind+1,j,1,exp);           // number of ways in which right is true
//         long long rF = helper(ind+1,j,0,exp);           // number of ways in which right is false
        
//         if(exp[ind] == '&'){
//             if(isTrue == 1){            // isTrue = true
//                 ways = (ways + (lT * rT) % mod) % mod;
//             }
//             else{       // isTrue = false
//                 ways = (ways + (lF * rF) % mod + (lF * rT) % mod + (lT * rF) % mod) % mod;
//             }
//         }
//         else if(exp[ind] == '|'){
//             if(isTrue == 1){            // isTrue = true
//                 ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
//             }
//             else{               // isTrue = false
//                 ways = (ways + (lF * rF) % mod) % mod; 
//             }
//         } 
//         else if(exp[ind] == '^'){
//             if(isTrue == 1){            // isTrue = true
//                 ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
//             }   
//             else{               // isTrue = false
//                 ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
//             }        
//         } 
//     }
    
//     return ways;
// } 
// int evaluateExp(string & exp) {
//     int n = exp.size();

//     return helper(0,n-1,1,exp);
// }



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N*2*N) 
// Space Complexity: O(N) (Recursion)   +   O(N*N*2)  (Array)


// #include <bits/stdc++.h>
// int mod = 1e9 + 7;
// long long helper(int i, int j, bool isTrue, string& exp, vector<vector<vector<long long>>>& dp){
//     if(i > j){                  // base condition
//         return 0;
//     }
    
//     if(i == j){
//         if(isTrue == 1){
//             return exp[i] == 'T'; 
//         }
//         else{
//             return exp[i] == 'F'; 
//         }
//     }
    
//     if(dp[i][j][isTrue] != -1){
//         return dp[i][j][isTrue];
//     }
    
//     long long ways = 0;
//     for(int ind = i+1; ind <= j-1; ind += 2){
//         long long lT = helper(i,ind-1,1,exp,dp);           // number of ways in which left is true        
//         long long lF = helper(i,ind-1,0,exp,dp);           // number of ways in which left is false
//         long long rT = helper(ind+1,j,1,exp,dp);           // number of ways in which right is true
//         long long rF = helper(ind+1,j,0,exp,dp);           // number of ways in which right is false
        
//         if(exp[ind] == '&'){
//             if(isTrue == 1){            // isTrue = true
//                 ways = (ways + (lT * rT) % mod) % mod;
//             }
//             else{       // isTrue = false
//                 ways = (ways + (lF * rF) % mod + (lF * rT) % mod + (lT * rF) % mod) % mod;
//             }
//         }
//         else if(exp[ind] == '|'){
//             if(isTrue == 1){            // isTrue = true
//                 ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
//             }
//             else{               // isTrue = false
//                 ways = (ways + (lF * rF) % mod) % mod; 
//             }
//         } 
//         else if(exp[ind] == '^'){
//             if(isTrue == 1){            // isTrue = true
//                 ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
//             }   
//             else{               // isTrue = false
//                 ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
//             }        
//         } 
//     }
    
//     return dp[i][j][isTrue] = ways;
// } 
// int evaluateExp(string & exp) {
//     int n = exp.size();
//     vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));

//     return helper(0,n-1,1,exp,dp);
// }



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N*2*N) 
// Space Complexity: O(N*N*2)  (Array) 


// #include <bits/stdc++.h>
// int mod = 1e9 + 7; 
// int evaluateExp(string & exp) {
//     int n = exp.size();
//     vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));

//     for(int i = 0; i < n; i++){                 // base condition
//         dp[i][i][true] = exp[i] == 'T'; 
//         dp[i][i][false] = exp[i] == 'F'; 
//     }

//     for(int i = n-1; i >= 0; i--){
//         for(int j = i+1; j < n; j++){    // since i<j & i==j are base cases.
//             for(int isTrue = 0; isTrue < 2; isTrue++){
//                 long long ways = 0;
//                 for(int ind = i+1; ind <= j-1; ind += 2){
//                     long long lT = dp[i][ind-1][1];           // number of ways in which left is true        
//                     long long lF = dp[i][ind-1][0];           // number of ways in which left is false
//                     long long rT = dp[ind+1][j][1];           // number of ways in which right is true
//                     long long rF = dp[ind+1][j][0];           // number of ways in which right is false
                    
//                     if(exp[ind] == '&'){
//                         if(isTrue == 1){            // isTrue = true
//                             ways = (ways + (lT * rT) % mod) % mod;
//                         }
//                         else{       // isTrue = false
//                             ways = (ways + (lF * rF) % mod + (lF * rT) % mod + (lT * rF) % mod) % mod;
//                         }
//                     }
//                     else if(exp[ind] == '|'){
//                         if(isTrue == 1){            // isTrue = true
//                             ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
//                         }
//                         else{               // isTrue = false
//                             ways = (ways + (lF * rF) % mod) % mod; 
//                         }
//                     } 
//                     else if(exp[ind] == '^'){
//                         if(isTrue == 1){            // isTrue = true
//                             ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
//                         }   
//                         else{               // isTrue = false
//                             ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
//                         }        
//                     } 
//                 }
                
//                 dp[i][j][isTrue] = ways;
//             }
//         }
//     }

//     return dp[0][n-1][1];
// }