/* Problem Statement: You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order. A number which completely divides another number is called it's divisor. */



/* Solution 1: Brute Force */
// Time Complexity: O(N)
// Space Complexity: O(1)


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     /* Function to find all 
//     divisors of n */
//     vector<int> divisors(int n) {
        
//         // To store the divisors;
//         vector<int> ans;
        
//         // Iterate from 1 to n
//         for(int i=1; i <= n; i++) {
            
//             // If a divisor is found
//             if(n % i == 0) {
//                 //Add it to the answer
//                 ans.push_back(i);
//             }
//         }
        
//         // Return the result
//         return ans;
//     }
// };

// int main()
// {
//     int n = 6;
    
//     /* Creating and instance of 
//     Solution class */
//     Solution sol; 
    
//     /* Function call to find 
//     all divisors of n */
//     vector<int> ans = sol.divisors(n);
    
//     cout << "The divisors of " << n << " are: ";
//     for(int i=0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//     }
    
//     return 0;
// }




/* Solution 2: Optimal Approach
We can optimise the previous approach by using the property that for any non-negative integer n, if d is a divisor of n then n/d is also a divisor of n. This property is symmetric about the square root of N. Thus, by traversing just the first half we can avoid redundant iteration and computations improving the efficiency of the algorithm. */


// Time Complexity: O(sqrt N) + + O(K*Log(K))          // K is the number of divisors of the number
// Space Complexity: O(1)


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     /* Function to find all 
//     divisors of n */
//     vector<int> divisors(int n) {
        
//         // To store the divisors;
//         vector<int> ans;
        
//         int sqrtN = sqrt(n);
        
//         // Iterate from 1 to sqrtN
//         for(int i=1; i <= sqrtN; i++) {
            
//             // If a divisor is found
//             if(n % i == 0) {
//                 //Add it to the answer
//                 ans.push_back(i);
                
//                 /* Add the counterpart divisor
//                  if it's different from i */
//                 if(i != n / i) {
//                     ans.push_back(n/i);
//                 }
//             }
//         }
        
//         // Sorting the result 
//         sort(ans.begin(), ans.end());
        
//         // Return the result
//         return ans;
//     }
// };

// int main()
// {
//     int n = 6;
    
//     /* Creating and instance of 
//     Solution class */
//     Solution sol; 
    
//     /* Function call to find 
//     all divisors of n */
//     vector<int> ans = sol.divisors(n);
    
//     cout << "The divisors of " << n << " are: ";
//     for(int i=0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//     }
    
//     return 0;
// }