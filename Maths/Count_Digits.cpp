/* Problem Statement: Given an integer N, return the number of digits in N. */


/* Solution 1: Brute Force */
// Time Complexity: O(log10N + 1)
// Space Complexity: O(1)


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int countDigits(int n){
//     // Initialize a counter variable
//     // 'cnt' to store the count of digits.
//     int cnt = 0;
//     // While loop iterates until 'n'
//     // becomes 0 (no more digits left).
//     while(n > 0){
//         // Increment the counter
//         // for each digit encountered.
//         cnt = cnt + 1;
//         // Divide 'n' by 10 to
//         // remove the last digit.
//         n = n / 10;
//     }
//     // Return the
//     // count of digits.
//     return cnt;
// }
// int main() {
//     int N = 329823;
//     cout << "N: "<< N << endl;
//     int digits = countDigits(N);
//     cout << "Number of Digits in N: "<< digits << endl;
//     return 0;
// }



/* Solution 2: Optimal Approach */
// Time Complexity: O(1)
// Space Complexity: O(1)


// #include <iostream>
// #include <cmath>
// #include <algorithm>
// using namespace std;
// int countDigits(int n){
//     // Initialize a variable 'cnt' to
//     // store the count of digits.
//     int cnt = (int)(log10(n)+1);

//     // The expression (int)(log10(n)+1)
//     // calculates the number of digits in 'n'
//     // and casts it to an integer.
    
//     // Adding 1 to the result accounts
//     // for the case when 'n' is a power of 10,
//     // ensuring that the count is correct.
   
//     // Finally, the result is cast
//     // to an integer to ensure it is rounded
//     // down to the nearest whole number.
    
//     // Return the count of digits in 'n'.
//     return cnt;
// }
// int main() {
//     int N = 329823;
//     cout << "N: "<< N << endl;
//     int digits = countDigits(N);
//     cout << "Number of Digits in N: "<< digits << endl;
//     return 0;
// }