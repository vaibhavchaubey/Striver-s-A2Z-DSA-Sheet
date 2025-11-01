/* Leetocde Submission    (50. Pow(x, n)) */

/* Problem Statement: Implement pow(x, n), which calculates x raised to the power n (i.e., xⁿ). */



/* Solution 1: Brute Force    It will give TLE */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     double myPow(double x, int n) {
//         double ans = 1.0;
//         long long nn = n;
//         if(n < 0){
//             nn = -1 * nn;
//         }
//         for(int i = 0; i < nn; i++){
//             ans = ans * x;
//         }
//         if(n < 0){
//             return (double)(1.0) / (double)(ans);
//         }

//         return ans;
//     }
// };



/* Solution 2: Optimal Approach */
// Time Complexity: O(logN) 
// Space Complexity: O(1)


// class Solution {
// public:
//     double myPow(double x, int n) {
//         double ans = 1.0;
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
//             return (double)(1.0) / (double)(ans);
//         }

//         return ans;
//     }
// };
