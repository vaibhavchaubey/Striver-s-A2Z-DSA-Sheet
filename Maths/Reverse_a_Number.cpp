/* Leetcode Submission    (7. Reverse Integer) */

/* Problem Statement: Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned). */


/* Solution */
// Time Complexity: O(log10N + 1)
// Space Complexity: O(1)


// class Solution {
// public:
//     int reverse(int x) {
//         int revNum = 0;
//         while(x){
//             if(revNum < INT_MIN/10 || revNum > INT_MAX/10){
//                 return 0;
//             }
//             else{
//                 int ld = x % 10;
//                 revNum = (revNum * 10) + ld;
//                 x /= 10;
//             }
//         }

//         return revNum;
//     }
// };