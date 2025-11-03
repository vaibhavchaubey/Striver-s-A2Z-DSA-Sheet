/* Problem Statement: You are given an integer array queries of length n.

Return the prime factorization of each number in array queries in sorted order.

Example 1:
Input: queries = [2, 3, 4, 5, 6]
Output: [ [2], [3], [2, 2], [5], [2, 3] ]
Explanation:The values 2, 3, and 5 are prime numbers.  
The prime factorization of 4 will be --> 2 * 2.  
The prime factorization of 6 will be --> 2 * 3.

Example 2:
Input: queries = [7, 12, 18]
Output: [ [7], [2, 2, 3], [2, 3, 3] ]
Explanation:The value 7 itself is a prime number.  
The prime factorization of 12 will be --> 2 * 2 * 3.  
The prime factorization of 18 will be --> 2 * 3 * 3.

*/



/* Solution 1: Better Approach (Using Sieve of Eratosthenes and Prefix Sum) */
// Time Complexity: O(Q * sqrt N)
// Space Complexity: O(Q * log N)           (for storing factors)



// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to get prime factorization (including duplicates)
//     vector<int> getPrimeFactors(int n) {
//         vector<int> factors;

//         // Handle factor 2 separately
//         while (n % 2 == 0) {
//             factors.push_back(2);
//             n /= 2;
//         }

//         // Handle odd factors
//         for (int i = 3; i * i <= n; i += 2) {
//             while (n % i == 0) {
//                 factors.push_back(i);
//                 n /= i;
//             }
//         }

//         // If n is still > 1, it's a prime number
//         if (n > 1)
//             factors.push_back(n);

//         return factors;
//     }

//     // Function to get prime factorization of all numbers in queries
//     vector<vector<int>> getAllPrimeFactors(vector<int>& queries) {
//         vector<vector<int>> result;
//         for (int num : queries)
//             result.push_back(getPrimeFactors(num));
//         return result;
//     }
// };

// int main() {
//     vector<int> queries = {2, 3, 4, 5, 6};

//     Solution sol;
//     vector<vector<int>> ans = sol.getAllPrimeFactors(queries);

//     cout << "[ ";
//     for (auto& factors : ans) {
//         cout << "[";
//         for (int i = 0; i < factors.size(); i++) {
//             cout << factors[i];
//             if (i != factors.size() - 1) cout << ", ";
//         }
//         cout << "] ";
//     }
//     cout << "]" << endl;

//     return 0;
// }




/* Solution 2: Optimal Approach (Smallest Prime Factor) */
// Time Complexity: O(N log(log N)) + O(Q * log N) 
// Space Complexity: O(N)    



// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to build SPF (Smallest Prime Factor) array using Sieve
//     vector<int> buildSPF(int maxN) {
//         vector<int> spf(maxN + 1);
//         for (int i = 0; i <= maxN; i++) spf[i] = i; // initialize

//         for (int i = 2; i * i <= maxN; i++) {
//             if (spf[i] == i) { // i is prime
//                 for (int j = i * i; j <= maxN; j += i) {
//                     if (spf[j] == j)  // mark only first time
//                         spf[j] = i;
//                 }
//             }
//         }
//         return spf;
//     }

//     // Function to get prime factorization using precomputed SPF
//     vector<int> getPrimeFactors(int n, const vector<int>& spf) {
//         vector<int> factors;
//         while (n > 1) {
//             factors.push_back(spf[n]);
//             n /= spf[n];
//         }
//         return factors;
//     }

//     // Function to get all prime factorizations for the queries array
//     vector<vector<int>> getAllPrimeFactors(vector<int>& queries) {
//         int maxN = *max_element(queries.begin(), queries.end());
//         vector<int> spf = buildSPF(maxN);

//         vector<vector<int>> result;
//         for (int num : queries)
//             result.push_back(getPrimeFactors(num, spf));

//         return result;
//     }
// };

// int main() {
//     vector<int> queries = {2, 3, 4, 5, 6};

//     Solution sol;
//     vector<vector<int>> ans = sol.getAllPrimeFactors(queries);

//     cout << "[ ";
//     for (auto& factors : ans) {
//         cout << "[";
//         for (int i = 0; i < factors.size(); i++) {
//             cout << factors[i];
//             if (i != factors.size() - 1) cout << ", ";
//         }
//         cout << "] ";
//     }
//     cout << "]" << endl;

//     return 0;
// }
