/* Leetcode  Submission    (424. Longest Repeating Character Replacement) */

/* Problem Statement: You are given a string s and an integer k. You can choose any character of the string and change it 
to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();
//         int maxLength = 0;
//         for(int i = 0; i < n; i++){
//             int cnt = 0;
//             char ch = s[i];
//             for(int j = i; j < n; j++){
//                 if(ch != s[j]){
//                     cnt++;
//                 }
//                 if(cnt > k){
//                     break;
//                 }
                
//                 maxLength = max(maxLength, j - i + 1);
//             }
//         }

//         return maxLength;
//     }
// };




/* Solution 2: Sliding Window */
// Time Complexity: O(N)
// Space Complexity: O(N)


/* Intuition
To solve this problem, we can use the sliding window technique where we keep expanding the window until we have k characters 
different from the most frequent character in the window, and then slide the window to the right until we have fewer than k 
different characters. We can keep track of the maximum length of the window we encounter during this process and return it 
as the answer. */


// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();
//         unordered_map<char, int> mp;
//         int i = 0, j = 0;
//         int ans = 0, maxi = 0;
//         while(j < n){
//             mp[s[j]]++;
//             maxi = max(maxi, mp[s[j]]);            // count of most frequent character
//             if((j-i+1) - maxi > k){
//                 mp[s[i]]--;
//                 i++;
//             }

//             ans = max(ans, (j-i+1));
//             j++;
//         }
        
//         return ans;
//     }
// };