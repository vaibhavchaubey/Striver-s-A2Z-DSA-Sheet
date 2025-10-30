/* Problem Statement: Given an integer N, check whether it is prime or not. A prime number is a number that is only divisible by 1 and itself and the total number of divisors is 2. */



/* Solution 1: Brute Force */
// Time Complexity: O(N)
// Space Complexity: O(1)


// #include <bits/stdc++.h> 
// #include <iostream>
// using namespace std;

// bool checkPrime(int n){ 
//     int cnt = 0;

//     for(int i = 1; i<=n; i++){ 
//         if(n%i == 0){ 
//             cnt = cnt+1;
//         }
//     }

//     if(cnt==2){
//         return true;
//     }
//     else{
//         return false; 
//     }
// }

// int main() {
//     int n = 1483;
//     bool isPrime = checkPrime(n);
//     if(isPrime){
//         cout << n << " is a prime number." << endl;
//     } else {
//         cout << n << " is not a prime number." << endl;
//     }

//     return 0;
// }




/* Solution 2: Optimal Approach
We can optimise the previous approach by using the property that for any non-negative integer n, if d is a divisor of n then n/d is also a divisor of n. This property is symmetric about the square root of N. Thus, by traversing just the first half we can avoid redundant iteration and computations improving the efficiency of the algorithm. */


// Time Complexity: O(sqrt N)
// Space Complexity: O(1)


// #include <bits/stdc++.h> 
// #include <iostream>
// using namespace std;

// bool checkPrime(int n){ 
//     int cnt = 0;

//     for(int i = 1; i * i <= n; i++){ 
//         if(n % i == 0){ 
//             cnt = cnt + 1;
//             if(n / i != i){
//                 cnt = cnt + 1;
//             }
//         }
//     }

//     if(cnt == 2){
//         return true;
//     }
//     else{ 
//         return false; 
//     }
// }


// int main() {
//     int n = 1483;
//     bool isPrime = checkPrime(n);
//     if(isPrime){
//         cout << n << " is a prime number." << endl;
//     } else {
//         cout << n << " is not a prime number." << endl;
//     }

//     return 0;
// }