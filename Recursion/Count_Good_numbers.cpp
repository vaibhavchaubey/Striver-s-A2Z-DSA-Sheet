/* Leetcode  Submission    (1922. Count Good Numbers) */

/* Problem Statement: A digit string is good if the digits (0-indexed) at even indices are even and the digits 
at odd indices are prime (2, 3, 5, or 7).
For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) 
at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, 
return it modulo 109 + 7.
A digit string is a string consisting of digits 0 through 9 that may contain leading zeros. */


/* Solution 1: Brute Force    It will give TLE */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int countGoodNumbers(long long n) {
//         int evenWays = 5, primeWays = 4;
//         int MOD = 1e9 + 7;
        
//         long long ans = 1;
//         for(int i = 0; i < n; i++){
//             if(i % 2 == 0){
//                 ans = (ans * evenWays) % MOD;
//             }
//             else{
//                 ans = (ans * primeWays) % MOD;
//             }
//         }

//         return ans;
//     }
// };



/* Solution 2: Better Approach */
// Time Complexity: O(logN) 
// Space Complexity: O(1)


// class Solution {
// public:
//     long long MOD = 1e9 + 7;
//     long long myPow(long long x, long long n) {
//         long long ans = 1;
//         long long nn = n;
//         if(n < 0){
//             nn = -1 * nn;
//         }

//         while(nn){
//             if(nn % 2 == 1){    //odd
//                 ans = ans * x;
//                 nn = nn - 1;
//             }
//             else{     //even
//                 x = x * x;
//                 nn = nn/2;
//             }
//         }

//         if(n < 0){
//             return 1 / ans;
//         }

//         return ans % MOD;
//     }
//     int countGoodNumbers(long long n) {
//         int evenWays = 5, primeWays = 4;
//         long long numberOfEvenPlaces = n/2 + n%2, numberOfOddPlaces = n/2;

//         long long ans = (myPow(evenWays, numberOfEvenPlaces) * myPow(primeWays, numberOfOddPlaces)) % MOD;
    

//         return ans;
//     }
// };