/* Problem Statement: Problem Statement: Given two integers N1 and N2, find their greatest common divisor.

The Greatest Common Divisor of any two integers is the largest number that divides both integers. */



/* Solution 1: Brute Force */
// Time Complexity: O(min(N1, N2))
// Space Complexity: O(1)


// #include <iostream>
// #include <algorithm>
// using namespace std;

// int findGcd(int n1, int n2) {
//     int gcd = 1;

//     for(int i = 1; i <= min(n1, n2); i++) {
//         // Check if i is a common
//         // factor of both n1 and n2
//         if(n1 % i == 0 && n2 % i == 0) {
//             gcd = i;
//         }
//     }

//     return gcd;
// }

// int main() {
//     int n1 = 20, n2 = 15;
    
//     int gcd = findGcd(n1, n2);

//     cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

//     return 0;
// }




/* Solution 2: Better Approach */
// Time Complexity: O(min(N1, N2))
// Space Complexity: O(1)


// #include <iostream>
// #include <algorithm>
// using namespace std;

// int findGcd(int n1, int n2) {
//     for(int i = min(n1, n2); i > 0; i--) {
//         // Check if i is a common
//         // factor of both n1 and n2
//         if(n1 % i == 0 && n2 % i == 0) {
//             return i;
//         }
//     }

//     return 1;
// }


// int main() {
//     int n1 = 20, n2 = 15;

//     int gcd = findGcd(n1, n2);

//     cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

//     return 0;
// }




/* Solution 3: Optimal Approach (Euclidean Algorithm) 
The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. It operates on the principle that the GCD of two numbers remains the same even if the smaller number is subtracted from the larger number.

To find the GCD of n1 and n2 where n1 > n2:

    1) Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
    2)  Once one of them becomes 0, the other number is the GCD of the original numbers. 

Eg, n1 = 20, n2 = 15:

gcd(20, 15) = gcd(20-15, 15) = gcd(5, 15)

gcd(5, 15) = gcd(15-5, 5) = gcd(10, 5)

gcd(10, 5) = gcd(10-5, 5) = gcd(5, 5)

gcd(5, 5) = gcd(5-5, 5) = gcd(0, 5)

Hence, return 5 as the gcd. */

// Time Complexity: O(log min(N1, N2))
// Space Complexity: O(1)


// #include <iostream>
// #include <algorithm>
// using namespace std;

// int findGcd(int a, int b) {
//     while(a > 0 && b > 0) {
//         // If a is greater than b,
//         // subtract b from a and update a
//         if(a > b) {
//              // Update a to the remainder
//              // of a divided by b
//             a = a % b;
//         }
//         // If b is greater than or equal
//         // to a, subtract a from b and update b
//         else {
//             // Update b to the remainder
//             // of b divided by a
//             b = b % a; 
//         }
//     }

//     if(a == 0) {
//         return b;
//     }

//     return a;
// }
// int main() {
//     int n1 = 20, n2 = 15;
    
//     // Find the GCD of n1 and n2
//     int gcd = findGcd(n1, n2);

//     cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

//     return 0;
// }