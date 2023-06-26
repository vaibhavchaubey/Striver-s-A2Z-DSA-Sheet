/* Leetcode  Submission    (875. Koko Eating Bananas) */


/* Problem Statement: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas 
from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N * maxEle)
// Space Complexity: O(1)

/* Range    [1 ................... maxEle]   =>  using Linear search for this range */


// class Solution {
// public:
//     int calcHour(int k, int n, vector<int>& piles){
//         long long totalHour = 0;
//         for(int i = 0; i < n; i++){
//             // totalHour += ceil((piles[i] * 1.0) / k);
//             totalHour += ceil((double)piles[i] / (double)k);
//         }

//         return totalHour;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n = piles.size();
//         int maxEle = *max_element(piles.begin(), piles.end());
//         for(int i = 1; i <= maxEle; i++){
//             long long reqTime = calcHour(i, n, piles);
//             if(reqTime <= h){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N * log(maxEle))
// Space Complexity: O(1)

/* Range    [1 ................... maxEle]   =>  using Binary search for this range */


// class Solution {
// public:
//     long long calcHour(int k, int n, vector<int>& piles){
//         long long totalHour = 0;
//         for(int i = 0; i < n; i++){
//             // totalHour += ceil((piles[i] * 1.0) / k);
//             totalHour += ceil((double)piles[i] / (double)k);
//         }

//         return totalHour;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n = piles.size();
//         int ans = -1;
//         int maxEle = *max_element(piles.begin(), piles.end());
//         int low = 1, high = maxEle;

//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             long long reqTime = calcHour(mid, n, piles);
//             if(reqTime <= h){
//                 ans = mid;
//                 high = mid - 1;
//             }
//             else {                      // if(reqTime > h)
//                 low = mid + 1;
//             }
//         }

//         return ans;
//     }
// };