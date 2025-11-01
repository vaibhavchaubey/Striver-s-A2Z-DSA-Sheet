/* Problem Statement: Given an integer N, print all of its prime factors.

Input: N = 60
Output: 2, 3, 5  
Explanation: All factors/divisors of 60 include: 1, 2, 3, 4, 5, 6, 10, 12, 18, 20, 30, 60. Out of these only 2, 3 and 5 are prime.

*/



/* Solution 1: Brute Force */
// Time Complexity: O(N * sqrt N)
// Space Complexity: O(1)


// #include <bits/stdc++.h> 
// using namespace std;

// // Solution class containing all methods
// class Solution {
// public:
//     // Function to check if a given number is prime.
//     bool checkPrime(int n){ 
//         // Initialize a counter variable to count the number of factors.
//         int cnt = 0;

//         // Loop through numbers from 1 to the square root of n.
//         for(int i = 1; i <= sqrt(n); i++){ 
//             // If n is divisible by i without any remainder.
//             if(n % i == 0){ 
//                 // Increment the counter.
//                 cnt = cnt + 1;

//                 // If n is not a perfect square, count its reciprocal factor.
//                 if(n / i != i){
//                     cnt = cnt + 1;
//                 }
//             }
//         }

//         // If the number of factors is exactly 2.
//         if(cnt == 2){
//             // Return true, indicating that the number is prime.
//             return true;
//         }
//         // If the number of factors is not 2.
//         else{ 
//             // Return false, indicating that the number is not prime.
//             return false; 
//         }
//     }

//     // Function to return a list of prime factors of input 'n'
//     vector<int> getPrimeFactors(int n){ 
//         // Declare a vector to store the prime factors of n.
//         vector<int> primeFactors; 
        
//         // Start a loop from 2 to n, iterating through each number i.
//         for(int i = 2; i<=n; i++){ 
//             // Check if n is divisible by i without any remainder.
//             if(n%i==0){ 
//                 // If it is, call the function checkPrime to determine if i is prime.
//                 if(checkPrime(i)){ 
//                     // If i is prime, add it to the vector of prime factors.
//                     primeFactors.push_back(i); 
//                 }
//             }
//         }
//         // Return the vector containing the prime factors of n.
//         return primeFactors; 
//     }
// };

// int main() {
//     int n = 60;

//     // Create an object of Solution class
//     Solution sol;

//     // Get prime factors using the Solution class method
//     vector<int> ans = sol.getPrimeFactors(n);

//     // Print the result
//     cout << "Prime Factors for " << n << ": ";
//     for(auto factor: ans){
//         cout << factor << " ";
//     }
//     cout << endl;
// }




/* Solution 2: Better Approach */
// Time Complexity: O(sqrt N * 2 * sqrt N)
// Space Complexity: O(1)


// #include <bits/stdc++.h> 
// using namespace std;

// // Solution class containing all methods
// class Solution {
// public:
//     // Function to check if a given number is prime.
//     bool checkPrime(int n){ 
//         // Initialize a counter variable to count the number of factors.
//         int cnt = 0;

//         // Loop through numbers from 1 to the square root of n.
//         for(int i = 1; i <= sqrt(n); i++){ 
//             // If n is divisible by i without any remainder.
//             if(n % i == 0){ 
//                 // Increment the counter.
//                 cnt = cnt + 1;

//                 // If n is not a perfect square, count its reciprocal factor.
//                 if(n / i != i){
//                     cnt = cnt + 1;
//                 }
//             }
//         }

//         // If the number of factors is exactly 2.
//         if(cnt == 2){
//             // Return true, indicating that the number is prime.
//             return true;
//         }
//         // If the number of factors is not 2.
//         else{ 
//             // Return false, indicating that the number is not prime.
//             return false; 
//         }
//     }

//     // Function to return a list of prime factors of input 'n'
//     vector<int> getPrimeFactors(int n){ 
//         // Declare a vector to store the prime factors of n.
//         vector<int> primeFactors; 
        
//         // Start a loop from 2 to n, iterating through each number i.
//         for(int i = 1; i*i<=n; i++){ 
//             // Check if n is divisible by i without any remainder.
//             if(n%i==0){ 
//                 // If it is, call the function checkPrime to determine if i is prime.
//                 if(checkPrime(i)){ 
//                     // If i is prime, add it to the vector of prime factors.
//                     primeFactors.push_back(i); 
//                 }
//                 if(i != n / i){
//                     if(checkPrime(n / i)){ 
//                         primeFactors.push_back(n / i); 
//                     }
//                 }
//             }
//         }
//         // Return the vector containing the prime factors of n.
//         return primeFactors; 
//     }
// };

// int main() {
//     int n = 60;

//     // Create an object of Solution class
//     Solution sol;

//     // Get prime factors using the Solution class method
//     vector<int> ans = sol.getPrimeFactors(n);

//     // Print the result
//     cout << "Prime Factors for " << n << ": ";
//     for(auto factor: ans){
//         cout << factor << " ";
//     }
//     cout << endl;
// }



/* Solution 3: Optimal Approach */
// Time Complexity: O(sqrt N)
// Space Complexity: O(1)


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to get prime factors of a number
//     vector<int> getPrimeFactors(int n) {
//         vector<int> primeFactors;

//         // Divide by 2 till odd
//         while (n % 2 == 0) {
//             primeFactors.push_back(2);
//             while (n % 2 == 0)
//                 n /= 2;
//         }

//         // Check odd numbers from 3 to sqrt(n)
//         for (int i = 3; i * i <= n; i += 2) {
//             if (n % i == 0) {
//                 primeFactors.push_back(i);
//                 while (n % i == 0)
//                     n /= i;
//             }
//         }

//         // If remaining n is a prime number
//         if (n > 1)
//             primeFactors.push_back(n);

//         return primeFactors;
//     }
// };

// int main() {
//     int n = 60;
//     Solution sol;
//     vector<int> ans = sol.getPrimeFactors(n);

//     cout << "Prime Factors of " << n << ": ";
//     for (int factor : ans)
//         cout << factor << " ";
//     cout << endl;

//     return 0;
// }