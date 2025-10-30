/* Problem Statement: Problem Statement: Given an integer N, return all divisors of N.
A divisor of an integer N is a positive integer that divides N without leaving a remainder. In other words, if N is divisible by another integer without any remainder, then that integer is considered a divisor of N. */



/* Solution 1: Brute Force */
// Time Complexity: O(N)
// Space Complexity: O(1)


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<int> getDivisors(int N) {
//         // Create a vector to store divisors
//         vector<int> res;
//         for (int i = 1; i <= N; i++) {
//             // Check if i is a divisor of N
//             if (N % i == 0) {
//                 res.push_back(i);
//             }
//         }

//         return res;
//     }
// };

// int main() {
//     Solution sol;

//     // Input number
//     int N = 36;

//     vector<int> result = sol.getDivisors(N);

//     cout << "Divisors of " << N << ": ";
//     for (int val : result) {
//         cout << val << " ";
//     }

//     cout << endl;

//     return 0;
// }




/* Solution 2: Optimal Approach
We can optimise the previous approach by using the property that for any non-negative integer n, if d is a divisor of n then n/d is also a divisor of n. This property is symmetric about the square root of N. Thus, by traversing just the first half we can avoid redundant iteration and computations improving the efficiency of the algorithm. */


// Time Complexity: O(sqrt N)
// Space Complexity: O(1)


// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> getDivisors(int N)
//     {
//         vector<int> res;

//         for (int i = 1; i * i <= N; i++)
//         {
//             if (N % i == 0)
//             {
//                 res.push_back(i);

//                 // If N / i is different from i, add N / i too
//                 if (i != N / i)
//                 {
//                     res.push_back(N / i);
//                 }
//             }
//         }

//         return res;
//     }
// };

// int main()
// {
//     Solution sol;

//     int N = 36;

//     vector<int> result = sol.getDivisors(N);

//     cout << "Divisors of " << N << ": ";
//     for (int val : result)
//     {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }