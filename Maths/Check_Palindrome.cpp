/* Leetcode Submission    (9. Palindrome Number) */

/* Problem Statement: Given an integer x, return true if x is a palindrome, and false otherwise. */


/* Solution 1: Reversing the Entire Number */
// Time Complexity: O(log10N + 1)
// Space Complexity: O(1)


// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x < 0){
//             return false;
//         }
        
//         int num = x;
//         long long revNum = 0;

//         while(num){
//             int ld = num % 10;
//             revNum = (revNum * 10) + ld;
//             num /= 10;
//         }

//         return x == revNum;
//     }
// };

/* OR */

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         string s = to_string(x);
//         int n = s.size();
//         for(int i = 0; i < n/2; i++){
//             if(s[i] != s[n-i-1]){
//                 return false;
//             }
//         }

//         return true;
//     }
// };




/* Solution 2: Reversing Half of the Number */
// Time Complexity: O(log10N + 1)
// Space Complexity: O(1)


// class Solution {
// public:
//     int reverse(int x) {
//         int revNum = 0;
//         while(x){
//             if(revNum < INT_MIN/10 || revNum > INT_MAX/10){
//                 return 0;
//             }
//             else{
//                 int ld = x % 10;
//                 revNum = (revNum * 10) + ld;
//                 x /= 10;
//             }
//         }

//         return revNum;
//     }
// };