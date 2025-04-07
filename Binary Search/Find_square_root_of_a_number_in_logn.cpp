/* Leetcode  Submission    (69. Sqrt(x)) */


/* Problem Statement: Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python. */


/* By using inbuilt function    ans = pow(x, 0.5)  or  ans = sqrt(x) */


/* Solution 1: Brute Force   */
// Time Complexity: O(sqrt(N))
// Space Complexity: O(1)


// class Solution {
// public:
//     int mySqrt(int x) {
//         int ans = 0;
//         for(int i = 1; i <= x; i++){
//             // (i * i <= x) changes to (i <= x / i) to avoid integer overflow
//             if(i <= x / i){
//                 ans = i;
//             }
//             else{
//                 break;
//             }
//         }

//         return ans;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// class Solution {
// public:
//     int mySqrt(int x) {
//         int ans = 0;
//         int low = 1, high = x;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             // (mid * mid <= x) changes to (mid <= x / mid) to avoid integer overflow
//             if(mid <= x / mid){            
//                 ans = mid;
//                 low = mid + 1;
//             }
//             else{                   // mid > x / mid
//                 high = mid - 1;
//             }
//         }
        
//         return ans;
//     }
// };