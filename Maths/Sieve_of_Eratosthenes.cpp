/* Leetocde Submission    (204. Count Primes) */

/* Problem Statement: Given an integer n, return the number of prime numbers that are strictly less than n. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * sqrt N)
// Space Complexity: O(1)


// class Solution {
// public:
//     bool isPrime(int num) {
//         if (num <= 1){               // 0 and 1 are not prime numbers
//             return false;  
            
//         } 

//         for (int i = 2; i * i <= num; i++) {
//             if (num % i == 0) {
//                 return false;
//             }
//         }

//         return true;
//     }
//     int countPrimes(int n) {
//         if(n <= 2){
//             return 0;
//         }

//         int count = 0;
//         for(int i = 2; i < n; i++){
//             if(isPrime(i)){
//                 count++;
//             }
//         }  

//         return count;
//     }
// };




/* Solution 2: Optimal Approach (Using Sieve of Eratosthenes) */
// Time Complexity: O(N log(log N)) + O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     int countPrimes(int n) {
//         if(n <= 2){
//             return 0;
//         }

//         vector<bool> prime(n+1, true);
//         prime[0] = false, prime[1] = false;
//         for(int i = 2; i*i <= n; i++){                          // O(N log(log N))
//             if(prime[i]){
//                 for(int j = i*i; j <= n; j += i){
//                     prime[j] = false;
//                 }
//             }
//         }

//         int count = 0;
//         for(int i = 2; i < n; i++){              // O(N)
//             if(prime[i]){
//                 count++;
//             }
//         }  

//         return count;
//     }
// };