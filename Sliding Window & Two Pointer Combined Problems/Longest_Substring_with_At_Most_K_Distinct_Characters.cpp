/* Codestudio  Submission    (Longest Substring with At Most K Distinct Characters) */

/* Problem Statement: You are given a string 'str' and an integer 'K'. 
Your task is to find the length of the largest substring with at most 'K' distinct characters. */


/* The problem is the same as finding the maximum length of the substring that has at most two different elements. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)
// Space Complexity: O(k)           Where 'n' is the number of fruit trees and 'k' is constant.


// #include<bits/stdc++.h>
// int kDistinctChars(int k, string &str)
// {
//     int n = str.size();
//     int maxLength = 0;
//     for(int i = 0; i < n; i++){
//         unordered_map<char, int> mp;            // char, count
//          // Finding maximum length of substring start from 'i' and having atmost k distinct characters.
//         for(int j = i; j < n; j++){
//             mp[str[j]]++;
//             if(mp.size() > k){
//                 break;
//             }

//             maxLength = max(maxLength, j - i + 1);
//         }
//     }

//     return maxLength;
// }





/* Solution 2: Two Pointer (Sliding Window) */
// Time Complexity: O(N)
// Space Complexity: O(k)           Where 'n' is the size of string and 'k' is constant.


// #include<bits/stdc++.h>
// int kDistinctChars(int k, string &str)
// {
//     int n = str.size();
//     unordered_map<char, int> mp;            // char, count
//     int maxLength = 0;
//     int left = 0, right = 0;
//     while(right < n){
//         mp[str[right]]++;
//         while(mp.size() > k){
//             mp[str[left]]--;
//             if(mp[str[left]] == 0){
//                 mp.erase(str[left]);
//             }
//             left++;
//         }

//         maxLength = max(maxLength, right - left + 1);
//         right++;
//     }

//     return maxLength;
// }