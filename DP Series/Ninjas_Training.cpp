/* Problem Statement: Ninja is planing this 'N' days-long training schedule. Each day, he can perform any one of these three activities. 
(Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his 
skills, he can't do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn? 
You are given a 2D array of size N*3 'POINTS' with the points corresponding to each day and activity. Your task is to calculate the 
maximum number of merit points that Ninja can earn. */


/* CodeStudio   Submission    (Ninja’s Training) */


/* Solution 1: */
/* With Recursion (It will give TLE) */


// int helper(int day, int last, vector<vector<int>> &points){
//     if(day == 0){
//         int maxi = 0;
//         for(int task = 0; task < 3; task++){
//             if(task != last){
//                 maxi = max(maxi, points[0][task]);
//             }
//         }
//         return maxi;
//     }
//     int maxi = 0;
//     for(int task = 0; task < 3; task++){
//         if(task != last){
//             int point = points[day][task] + helper(day-1,task, points);
//             maxi = max(maxi, point);
//         }
//     }
//     return maxi;
// }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     return helper(n-1,3,points);
// }



/* Solution 2: */
/* With DP   (Memoizaton) */
// Time Complexity: O(N*4*3)
// Space Complexity: O(N) (Recursion)   +   O(N*4)  (Array)


// int helper(int day, int last, vector<vector<int>> &points, vector<vector<int>>& dp){
//     if(day == 0){
//         int maxi = 0;
//         for(int task = 0; task < 3; task++){
//             if(task != last){
//                 maxi = max(maxi, points[0][task]);
//             }
//         }
//         return maxi;
//     }
//     if(dp[day][last] != -1){
//         return dp[day][last];
//     }
//     int maxi = 0;
//     for(int task = 0; task < 3; task++){
//         if(task != last){
//             int point = points[day][task] + helper(day-1,task, points, dp);
//             maxi = max(maxi, point);
//         }
//     }
//     return dp[day][last] = maxi;
// }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n, vector<int>(4,-1));
//     return helper(n-1,3,points,dp);
// }



/* Solution 3: */
/* With DP   (Tabulation) */
// Time Complexity: O(N*4*3)
// Space Complexity: O(N*4)  (Array) 


// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n, vector<int>(4,0));
    
//     dp[0][0] = max(points[0][1], points[0][2]);
//     dp[0][1] = max(points[0][0], points[0][2]);
//     dp[0][2] = max(points[0][0], points[0][1]);
//     dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));
    
//     for(int day = 1; day < n; day++){
//         for(int last = 0; last < 4; last++){
//             dp[day][last] = 0;
//             for(int task = 0; task < 3; task++){
//                 if(task != last){
//                     int point = points[day][task] + dp[day-1][task];
//                     dp[day][last] = max(dp[day][last], point);
//                 }
//             }
//         }
//     }
    
//     return dp[n-1][3];
// }



/* Solution 4: */
/* Space Optimization */
// Time Complexity: O(N*4*3)
// Space Complexity: O(4)


// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<int> prev(4,0);
    
//     prev[0] = max(points[0][1], points[0][2]);
//     prev[1] = max(points[0][0], points[0][2]);
//     prev[2] = max(points[0][0], points[0][1]);
//     prev[3] = max(points[0][1], max(points[0][1], points[0][2]));
    
//     for(int day = 1; day < n; day++){
//         vector<int> temp(4, 0);
//         for(int last = 0; last < 4; last++){
//             temp[last] = 0;
//             for(int task = 0; task < 3; task++){
//                 if(task != last){
//                     int point = points[day][task] + prev[task];
//                     temp[last] = max(temp[last], point);
//                 }
//             }
//         }
//         prev = temp;
//     }
    
//     return prev[3];
// }



