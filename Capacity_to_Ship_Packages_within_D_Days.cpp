/* Leetcode  Submission    (1011. Capacity To Ship Packages Within D Days) */


/* Problem Statement: A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the 
conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped 
within days days. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N) * O(sumAll - manEle)
// Space Complexity: O(1)

/* Range    [maxEle ................... sumAll]   =>  using Linear search for this range */


// class Solution {
// public:
//     bool isPossible(int capacity, int days, int n, vector<int>& weights){
//         int load = 0, requiredDays = 1;
//         for(int i = 0; i < n; i++){
//             if(load + weights[i] > capacity){
//                 requiredDays++;
//                 load = weights[i];
//             }
//             else{
//                 load += weights[i];
//             }
//         }
        
//         if(requiredDays <= days){
//             return true;
//         }

//         return false;
//     }
//     int shipWithinDays(vector<int>& weights, int days) {
//         int n = weights.size();
//         int minCap = 0, maxCap = 0;
//         for(int i = 0; i < n; i++){
//             minCap = max(minCap, weights[i]);
//             maxCap += weights[i];
//         }  

//         for(int i = minCap; i <= maxCap; i++){
//             if(isPossible(i, days, n, weights)){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N) * O(log(sumAll - manEle))
// Space Complexity: O(1)

/* Range    [maxEle ................... sumAll]   =>  using Binary search for this range */


// class Solution {
// public:
//     bool isPossible(int divisor, int threshold, int n, vector<int>& nums){
//         int sum = 0;
//         for(int i = 0; i < n; i++){
//             sum += ceil((double)nums[i] / (double)divisor);
//         }

//         if(sum <= threshold){
//             return true;
//         }

//         return false;
//     }
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n = nums.size();
//         int ans = -1;
//         int maxEle = *max_element(nums.begin(), nums.end());

//         int low = 1, high = maxEle;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(isPossible(mid, threshold, n, nums)){
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

