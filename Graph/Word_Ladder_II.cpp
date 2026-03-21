/* GFG  Submission    (Word Ladder II) */

/* Problem Statement: Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
The first part of this problem can be found here. */



/* Solution: Using BFS */
// Time Complexity: O(N * len * 26)                           //  Where N is the number of words, len is the average length of the words
// Space Complexity: O(N * Len)


// class Solution {
//   public:
//     int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
//         unordered_set<string> st(wordList.begin(), wordList.end());
//         st.erase(startWord);
        
//         queue<pair<string, int>> q;             // word, steps
//         q.push({startWord, 1});
        
//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();
            
//             string word = it.first;
//             int steps = it.second;
            
//             // Try changing every character in the current word
//             for(int i = 0; i < word.size(); i++){
//                 char originalChar = word[i];
//                 for(char ch = 'a'; ch <= 'z'; ch++){
//                     word[i] = ch;
                    
//                     // If the transformed word exists in the set
//                     if(st.count(word)){
//                         // If target word is found, return steps
//                         if(word == targetWord){
//                             return steps + 1;
//                         }
                        
//                         // Add it to the queue and remove from set to avoid reprocessing
//                         q.push({word, steps + 1});
//                         st.erase(word);
//                     }
//                 }
//                 word[i] = originalChar;
//             }
//         }
        
//         return 0;
//     }
// };





/* Leetcode  Submission    (126. Word Ladder II) */

/* Problem Statement: A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk]. */



/* Solution: Using BFS */
// Time Complexity: O(N * len * 26)                           //  Where N is the number of words, len is the average length of the words
// Space Complexity: O(N * Len)


// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> st(wordList.begin(), wordList.end());
//         st.erase(beginWord);
        
//         queue<pair<string, int>> q;             // word, steps
//         q.push({beginWord, 1});
        
//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();
            
//             string word = it.first;
//             int steps = it.second;
            
//             // Try changing every character in the current word
//             for(int i = 0; i < word.size(); i++){
//                 char originalChar = word[i];
//                 for(char ch = 'a'; ch <= 'z'; ch++){
//                     word[i] = ch;
                    
//                     // If the transformed word exists in the set
//                     if(st.count(word)){
//                         // If end word is found, return steps
//                         if(word == endWord){
//                             return steps + 1;
//                         }
                        
//                         // Add it to the queue and remove from set to avoid reprocessing
//                         q.push({word, steps + 1});
//                         st.erase(word);
//                     }
//                 }
//                 word[i] = originalChar;
//             }
//         }
        
//         return 0;
//     }
// };