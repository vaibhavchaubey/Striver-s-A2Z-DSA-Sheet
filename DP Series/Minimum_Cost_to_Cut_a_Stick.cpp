/* Leetcode  Submission    (1547. Minimum Cost to Cut a Stick) */


/* Problem Statement: Given a wooden stick of length n units. The stick is labelled from 0 to n.
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. 
When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). 
Please refer to the first example for a better explanation.
Return the minimum total cost of the cuts. */




/* Solution 1: */
/* With Recursion (It will give TLE) */
// Time Complexity: (Exponential)
// Space Complexity: O(N) (Recursion)


// class Solution {
// public:
//     int helper(int i, int j, vector<int>& cuts){
//         if(i > j){                      // base condtion
//             return 0;
//         }

//         int mini = INT_MAX;
//         for(int ind = i; ind <= j; ind++){
//             int cost = cuts[j+1] - cuts[i-1] + helper(i,ind-1,cuts) + helper(ind+1,j,cuts);
//             mini = min(mini, cost); 
//         }

//         return mini;
//     }
//     int minCost(int n, vector<int>& cuts) {
//         int c = cuts.size();

//         // modify the cuts array
//         cuts.insert(cuts.begin(), 0);
//         cuts.push_back(n);

//         sort(cuts.begin(), cuts.end());

//         return helper(1,c,cuts);
//     }
// };



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*N*N) 
// Space Complexity: O(N) (Recursion)   +   O(N*N)  (Array)


// class Solution {
// public:
//     int helper(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
//         if(i > j){                          // base condtion
//             return 0;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int mini = INT_MAX;
//         for(int ind = i; ind <= j; ind++){
//             int cost = cuts[j+1] - cuts[i-1] + helper(i,ind-1,cuts,dp) + helper(ind+1,j,cuts,dp);
//             mini = min(mini, cost); 
//         }

//         return dp[i][j] = mini;
//     }
//     int minCost(int n, vector<int>& cuts) {
//         int c = cuts.size();

//         // modify the cuts array
//         cuts.insert(cuts.begin(), 0);
//         cuts.push_back(n);

//         sort(cuts.begin(), cuts.end());
//         vector<vector<int>> dp(c+1, vector<int>(c+1, -1));

//         return helper(1,c,cuts,dp);
//     }
// };



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*N*N)
// Space Complexity: O(N*N)  (Array) 


// class Solution {
// public:
//     int minCost(int n, vector<int>& cuts) {
//         int c = cuts.size();
        
//         // modify the cuts array
//         cuts.insert(cuts.begin(), 0);
//         cuts.push_back(n);

//         sort(cuts.begin(), cuts.end());
//         vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

//         for(int i = c; i >= 1; i--){
//             for(int j = 1; j <= c; j++){
//                 if(i > j){              // base condtion
//                     continue;
//                 }

//                 int mini = INT_MAX;
//                 for(int ind = i; ind <= j; ind++){
//                     int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
//                     mini = min(mini, cost); 
//                 }
                
//                 dp[i][j] = mini;
//             }
//         }

//         return dp[1][c];
//     }
// };