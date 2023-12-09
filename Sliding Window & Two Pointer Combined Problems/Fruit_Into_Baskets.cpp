/* Codestudio  Submission    (Fruits and Baskets) */

/* Problem Statement: There are 'n' fruit trees that are planted along a road. The trees are numbered from 0 to n-1. 
The type of fruit each tree bears is represented by an integer from 1 to 'n'. A Ninja is walking along that road. 
He has two baskets and wants to put the maximum number of fruits in them. The restriction is that each basket can 
have only one type of fruit. Ninja can start with any tree and end at any tree, but once he has started, he cannot 
skip a tree i.e if he picks fruit from the tree , then he has to pick fruit from tree 'i+ 1' before going to the tree 
'¡+2' He will pick one fruit from each tree until he cannot, ie, he will stop when he has to pick a fruit of the third 
type because only two different fruits can fill both baskets You are given an array 'arr. The 'i'th integer in this array 
represents the type of fruit tree 'i* bears. Return the maximum number of fruits Ninja can put in both baskets after 
satisfying all the conditions. */


/* The problem is the same as finding the maximum length of the substring that has at most two different elements. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)
// Space Complexity: O(c)           Where 'n' is the number of fruit trees and 'c' is constant.


// int findMaxFruits(vector<int> &arr, int n) {
//     int maxFruits = 0;
//     for(int i = 0; i < n; i++){
//         unordered_map<int, int> mp;             // num, count
//         // Finding maximum length of substring start from 'i' and having atmost 2
//         // distinct characters.
//         for(int j = i; j < n; j++){
//             mp[arr[j]]++;
//             if(mp.size() > 2){
//                 break;
//             }

//             maxFruits = max(maxFruits, j - i + 1);
//         }
//     }

//     return maxFruits;
// }




/* Solution 2: Two Pointer (Sliding Window) */
// Time Complexity: O(N)
// Space Complexity: O(c)           Where 'n' is the number of fruit trees and 'c' is constant.


// int findMaxFruits(vector<int> &arr, int n) {
//     // Contain unique elements in the current window mapped with their frequency in that window
//     unordered_map<int, int> mp;             // num, count
//     int left = 0, right = 0;
//     int maxFruits = 0;
//     while(right < n){
//         mp[arr[right]]++;
//         while(mp.size() > 2){
//             mp[arr[left]]--;
//             if(mp[arr[left]] == 0){
//                 mp.erase(arr[left]);
//             }
//             left++;
//         }

//         maxFruits = max(maxFruits, right - left + 1);
//         right++;
//     }

//     return maxFruits;
// }