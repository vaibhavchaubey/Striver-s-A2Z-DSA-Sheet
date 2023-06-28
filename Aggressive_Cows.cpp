/* GFG  Submission    (Aggressive Cows) */


/* Problem Statement: You are given an array consisting of n integers which denote the position of a stall. 
You are also given an integer k which denotes the number of aggressive cows. 
You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N) * O(maxEle - minEle)   +   O(NlogN)   (sorting)
// Space Complexity: O(1)

/* Range    [1 ................... maxD]   (maxD = maxEle - minELe)   =>    using Linear search for this range */

// class Solution {
// public: 
//     bool isPossible(int dist, int cows, int n, vector<int> &stalls){
//         // inorder to get max distance we place cow at starting as array is sorted
//         int lastPlacedCow = stalls[0];
//         int cntCows = 1;
//         for(int i = 1; i < n; i++){
//             if(stalls[i] - lastPlacedCow >= dist){
//                 cntCows++;
//                 lastPlacedCow = stalls[i];
//             }
//         }
        
//         if(cntCows >= cows){
//             return true;
//         }
        
//         return false;
//     }
//     int solve(int n, int k, vector<int> &stalls) {
//         sort(stalls.begin(), stalls.end());
    
//         int maxD = stalls[n-1] - stalls[0];         // maxEle - minEle
//         int ans = 0;
        
//         for(int i = 1; i <= maxD; i++){
//             // by keeping a distance i is it possible to place all the cows
//             if(isPossible(i, k, n, stalls)){
//                 ans = i;
//             }
//         }
        
//         return ans;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N) * O(log(maxEle - minEle))  +   O(NlogN)   (sorting)
// Space Complexity: O(1)

/* Range    [1 ................... maxD]   (maxD = maxEle - minELe)   =>    using Binary search for this range */


// class Solution {
// public: 
//     bool isPossible(int dist, int cows, int n, vector<int> &stalls){
//         // inorder to get max distance we place cow at starting as array is sorted
//         int lastPlacedCow = stalls[0];
//         int cntCows = 1;
//         for(int i = 1; i < n; i++){
//             if(stalls[i] - lastPlacedCow >= dist){
//                 cntCows++;
//                 lastPlacedCow = stalls[i];
//             }
//         }
        
//         if(cntCows >= cows){
//             return true;
//         }
        
//         return false;
//     }
//     int solve(int n, int k, vector<int> &stalls) {
//         sort(stalls.begin(), stalls.end());
    
//         int maxD = stalls[n-1] - stalls[0];         // maxEle - minEle
//         int ans = 0;
        
//         int low = 1, high = maxD;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             // by keeping a distance mid is it possible to place all the cows
//             if(isPossible(mid, k, n, stalls)){
//                 ans = mid;
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
        
//         return ans;
//     }
// };