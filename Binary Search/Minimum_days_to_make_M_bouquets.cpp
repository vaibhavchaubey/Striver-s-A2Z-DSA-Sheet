/* Leetcode  Submission    (1482. Minimum Number of Days to Make m Bouquets) */


/* Problem Statement: You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
If it is impossible to make m bouquets return -1. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N) * O(maxEle - minEle)
// Space Complexity: O(1)

/* Range    [minEle ................... maxEle]   =>  using Linear search for this range */


// class Solution {
// public:
//     bool isPossible(int day, int m, int k, int n, vector<int>& bloomDay){
//         int cnt = 0, bouquet = 0;
//         for(int i = 0; i < n; i++){
//             if(bloomDay[i] <= day){
//                 cnt++;
//             }
//             else{
//                 bouquet += cnt / k;
//                 cnt = 0;
//             }
//         }

//         bouquet += cnt / k;
//         if(bouquet >= m){
//             return true;
//         }

//         return false;
//     }
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int n = bloomDay.size();
//         long long val = m * 1LL * k * 1LL;
//         if(n < val){
//             return -1;
//         }
        
//         int minEle = *min_element(bloomDay.begin(), bloomDay.end());
//         int maxEle = *max_element(bloomDay.begin(), bloomDay.end());

//         for(int i = minEle; i <= maxEle; i++){
//             if(isPossible(i, m, k, n, bloomDay)){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N) * O(log(maxEle - minEle))
// Space Complexity: O(1)

/* Range    [minEle ................... maxEle]   =>  using Binary search for this range */


// class Solution {
// public:
//     bool isPossible(int day, int m, int k, int n, vector<int>& bloomDay){
//         int cnt = 0, bouquet = 0;
//         for(int i = 0; i < n; i++){
//             if(bloomDay[i] <= day){
//                 cnt++;
//             }
//             else{
//                 bouquet += cnt / k;
//                 cnt = 0;
//             }
//         }

//         bouquet += cnt / k;
//         if(bouquet >= m){
//             return true;
//         }

//         return false;
//     }
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int n = bloomDay.size();
//         long long val = m * 1LL * k * 1LL;
//         if(n < val){
//             return -1;
//         }

//         int ans = -1;
//         int minEle = *min_element(bloomDay.begin(), bloomDay.end());
//         int maxEle = *max_element(bloomDay.begin(), bloomDay.end());

//         int low = minEle, high = maxEle;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(isPossible(mid, m, k, n, bloomDay)){
//                 ans = mid;
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }

//         return ans;
//     }
// };