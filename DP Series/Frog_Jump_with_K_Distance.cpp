/* Problem Statement: This is a follow-up question to “Frog Jump” discussed in the previous article. 
In the previous question, the frog was allowed to jump either one or two steps at a time. 
In this question, the frog is allowed to jump up to ‘K’ steps at a time. 
If K=4, the frog can jump 1,2,3, or 4 steps at every index. */


/* Solution 1: It will give TLE */
/* With Recursion */
//It will give TLE


// #include<bits/stdc++.h>
// using namespace std;
// int helper(int ind, vector<int>& heights, int k){
//     if(ind == 0){
//         return 0;
//     }
//     int minStep = INT_MAX;
//     for(int j = 1; j <= k; j++){
//         if(ind-j >= 0){
//             int jump = helper(ind-j, heights, k) + abs(heights[ind] - heights[ind-j]);
//             minStep = min(minStep, jump);
//         }
//     }
//     return minStep;
// }
// int frogKJump(int n, vector<int>& heights, int k){
//     return helper(n-1, heights, k);
// }
// int main()
// {
//     vector<int> heights{30, 10, 60 , 10 , 60 , 50};
//     int n = heights.size();
//     int k = 2;

//     cout<<frogKJump(n, heights, k);

    
//     return 0;
// }



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*K)
// Space Complexity: O(N) (Recursion)   +   O(N)  (Array)


// #include<bits/stdc++.h>
// using namespace std;
// int helper(int ind, vector<int>& heights, vector<int>& dp, int k){
//     if(ind == 0){
//         return 0;
//     }
//     if(dp[ind] != -1){
//         return dp[ind];
//     }
//     int minStep = INT_MAX;
//     for(int j = 1; j <= k; j++){
//         if(ind-j >= 0){
//             int jump = helper(ind-j, heights, dp, k) + abs(heights[ind] - heights[ind-j]);
//             minStep = min(minStep, jump);
//         }
//     }
//     return dp[ind] = minStep;
// }
// int frogKJump(int n, vector<int>& heights, int k){
//     vector<int> dp(n,-1);
//     return helper(n-1, heights, dp, k);
// }
// int main()
// {
//     vector<int> heights{30, 10, 60 , 10 , 60 , 50};
//     int n = heights.size();
//     int k = 2;

//     cout<<frogKJump(n, heights, k);

    
//     return 0;
// }



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*K)
// Space Complexity: O(N)  (Array) 


// #include<bits/stdc++.h>
// using namespace std;
// int frogKJump(int n, vector<int>& heights, int k){
//     vector<int> dp(n,-1);
//     dp[0] = 0;
//     for(int i = 1; i < n; i++){
//         int minStep = INT_MAX;
//         for(int j = 1; j <= k; j++){
//             if(i-j >= 0){
//                 int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
//                 minStep = min(minStep, jump);
//             }
//         }
//         dp[i] = minStep;
//     }
//     return dp[n-1];
// }
// int main()
// {
//     vector<int> heights{30, 10, 60 , 10 , 60 , 50};
//     int n = heights.size();
//     int k = 2;

//     cout<<frogKJump(n, heights, k);

    
//     return 0;
// }




/* AtCoder   Submission    (Frog 2) */
/* Solution: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*K)
// Space Complexity: O(N)  (Array) 


#include<bits/stdc++.h>
using namespace std;
int frogKJump(int n, vector<int>& heights, int k){
    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int minStep = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i-j >= 0){
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                minStep = min(minStep, jump);
            }
        }
        dp[i] = minStep;
    }
    return dp[n-1];
}
int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin>>heights[i];
    }
 
    cout<<frogKJump(n, heights, k);
 
    
    return 0;
}