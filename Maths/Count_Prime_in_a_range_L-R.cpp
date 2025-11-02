/* Problem Statement: You are given an 2D array queries of dimension n*2.
The queries[i] represents a range from queries[i][0] to queries[i][1] (include the end points).

Example 1:
Input: queries = [ [2, 5], [4, 7] ]  
Output: [3, 2]  
Explanation:  
The range 2 to 5 contains three prime numbers: 2, 3, 5.  
The range 4 to 7 contains two prime numbers: 5, 7.

Example 2:
Input: queries = [ [1, 7], [3, 7] ]  
Output: [4, 3]  
Explanation:  
The range 1 to 7 contains four prime numbers: 2, 3, 5, 7.  
The range 3 to 7 contains three prime numbers: 3, 5, 7.

*/



/* Solution: Optimal Approach (Using Sieve of Eratosthenes and Prefix Sum) */
// Time Complexity: O(N log(log N)) + O(N)
// Space Complexity: O(N) + O(N)


// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<int> primesInRange(vector<vector<int>>& queries) {
//         if (queries.empty()) {
//             return {};
//         }

//         // Find the maximum value in the queries 
//         // to determine the sieve range
//         int maxVal = 0;
//         for (const auto& query : queries) {
//             maxVal = max(maxVal, query[1]);
//         }

//         // Step 1: Use the Sieve of Eratosthenes 
//         // to find all primes up to maxVal
//         vector<bool> isPrime(maxVal + 1, true);
//         isPrime[0] = isPrime[1] = false;  // 0 and 1 are not primes
//         for (int i = 2; i * i <= maxVal; ++i) {
//             if (isPrime[i]) {
//                 for (int j = i * i; j <= maxVal; j += i) {
//                     isPrime[j] = false;
//                 }
//             }
//         }

//         // Step 2: Create a prefix sum array 
//         // to count primes up to each number
//         vector<int> primeCount(maxVal + 1, 0);
//         for (int i = 1; i <= maxVal; ++i) {
//             primeCount[i] = primeCount[i - 1];
//             if (isPrime[i]) {
//                 primeCount[i]++;
//             }
//         }

//         // Step 3: Process each query to find the number of primes 
//         // in the given range
//         vector<int> result;
//         for (const auto& query : queries) {
//             int start = query[0];
//             int end = query[1];
//             if (start == 0) {
//                 result.push_back(primeCount[end]);
//             } else {
//                 result.push_back(primeCount[end] - primeCount[start - 1]);
//             }
//         }

//         return result;
//     }
// };

// int main() {
//     // Example usage
    
    
//     // Create an instance of the Solution class
//     Solution solution;
    
//     // Call the function and store the result
//     auto result = solution.primesInRange(queries);
    
//     // Output the result
//     cout << "The number of primes in the given ranges are: ";
//     for (int count : result) {
//         cout << count << " ";
//     }
//     cout << endl;

//     return 0;
// }