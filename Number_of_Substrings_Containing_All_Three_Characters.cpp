/* Leetcode  Submission    (1358. Number of Substrings Containing All Three Characters) */

/* Problem Statement: Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)
// Space Complexity: O(1)       //  string s will only contain [a,b and c] as characters , so size of frequency map will always be 3 , so Space is O(1)


// class Solution {
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int count = 0;
//         for(int i = 0; i < n; i++){             // outer loop for traversing the string
//             unordered_set<char> set;
//             // nested loop for getting different string starting with s[i]
//             for(int j = i; j < n; j++){
//                 if(s[j] == 'a' || s[j] == 'b' || s[j] == 'c'){
//                     set.insert(s[j]);
//                 }
//                 if(set.size() == 3){
//                     count++;
//                 }
//             }
//         }

//         return count++;
//     }
// };



/* Solution 2: Using Hashmap */
// Time Complexity: O(N)
// Space Complexity: O(1)       //  string s will only contain [a,b and c] as characters , so size of frequency map will always be 3 , so Space is O(1)


// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         unordered_map<char, int> mp;            // char, count
//         int i = 0, j = 0, count = 0;;
//         while(j < n){
//             mp[s[j]]++;

//             while(mp['a'] && mp['b'] && mp['c']){
//                 // by keeping a window of atleast one a, b, c no. of subarray form till the end
//                 //  including current substring and also considering all those substrings which are bigger in size than current substring and also fully contains our current substring
//                 count += (n - j);

//                 // removing first element[means shrinking window from front to form new window]
//                 mp[s[i]]--;
//                 i++;
//             }

//             j++;
//         }

//         return count;
//     }
// };

