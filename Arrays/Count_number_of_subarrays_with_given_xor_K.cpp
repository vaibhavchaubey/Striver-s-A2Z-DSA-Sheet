/* Codestudio  Submission    (Subarrays with XOR ‘K’) */

/* Problem Statement: Given an array 'A' consisting of 'N' integers and an integer 'B', find the number of subarrays of 
array 'A' whose bitwise XOR(^) of all elements is equal to 'B'. */


/* Solution 1: Brute Force    (It will give TLE) */
// Time Complexity: O(N^2)
// Space Complexity: O(1)     


// int subarraysWithSumK(vector < int > a, int b) {
//     int n = a.size();
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         int current_xor = 0;
//         for(int j = i; j < n; j++){
//             current_xor ^= a[j];
//             if(current_xor == b){
//                 count++;
//             }
//         }
//     }
        
//     return count;
// }


    
/* Solution 2: Prefix xor and map */
// Time Complexity: O(NlogN)
// Space Complexity: O(N)     


// #include<bits/stdc++.h>
// int subarraysWithSumK(vector < int > a, int b) {
//     int n = a.size();
//     unordered_map<int,int> mp;
//     int count = 0;
//     int current_xor = 0;
//     for(int i = 0; i < n; i++){
//         current_xor ^= a[i];
//         if(current_xor == b){
//             count++;
//         }

//         count += mp[current_xor ^ b];

//         mp[current_xor]++;
//     }

//     return count;
// }
