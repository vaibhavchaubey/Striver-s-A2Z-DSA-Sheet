/* Leetcode  Submission    (76. Minimum Window Substring) */

/* Problem Statement: Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)    where N is the length of string s
// Space Complexity: O(M)       where M is the length of string t  


// class Solution {
// public:
//     string minWindow(string s, string t) {
//         unordered_map<char, int> mp;
//         for(auto str : t){
//             mp[str]++;
//         }

//         string ans = "";
//         int minLen = INT_MAX;
//         for(int i = 0; i < s.size(); i++){
//             int count = 0;
//             string str = "";
//             unordered_map<char, int> mp1 = mp;
//             for(int j = i; j < s.size(); j++){
//                 str += s[j];
//                 if(mp1[s[j]] > 0){
//                     mp1[s[j]]--;
//                     count++;
//                 }
//                 if(minLen > str.size() && count == t.size()){
//                     minLen = str.size();
//                     ans = str;
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
// };




/* Solution 2: Sliding Window */
// Time Complexity: O(N)            where N is the length of string s
// Space Complexity: O(M)           where M is the length of string t


// class Solution {
// public:
//     string minWindow(string s, string t) {
//         unordered_map<char, int> mp;
//         for(auto str : t){
//             mp[str]++;
//         }

//         int count = mp.size();
//         int minLen = INT_MAX;
//         int i = 0, j  = 0, start = 0;
//         while(j < s.size()){
//             mp[s[j]]--;
//             if(mp[s[j]] == 0){
//                 count--;
//             }
//             if(count == 0){
//                 while(count == 0){
//                     if(minLen > (j - i + 1)){
//                         minLen = j - i + 1;
//                         start = i;
//                     }
//                     mp[s[i]]++;
//                     if(mp[s[i]] > 0){
//                         count++;
//                     }
//                     i++;
//                 }
//             }
//             j++;
//         }

//         if(minLen != INT_MAX){
//             return s.substr(start, minLen);
//         }
//         else{
//             return "";
//         }
//     }
// };

