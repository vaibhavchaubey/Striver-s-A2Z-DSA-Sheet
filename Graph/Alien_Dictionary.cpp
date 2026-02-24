/* GFG  Submission    (Alien Dictionary) */

/* Problem Statement: A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false. */



/* Solution: Using BFS 
Step 1: Build a directed graph based on the given list of words. Compare adjacent words and create edges between the first different characters.
Step 2: Perform a topological sort on the graph to determine the order of characters. If the given list of words is inconsistent with any possible letter ordering, return an empty string. */


// Time Complexity: O(N * len) + O(26 + E) + O(26) ~ O(N * len)
/* Where N is the number of words, len is the average length of the words, and E is the number of edges in the graph. */

// Space Complexity: O(26) + O(26) + O(26) + O(26) ~ O(1)                 // adj[], indegree[], exists[], queue


// class Solution {
//   public:
//     string topoSort(vector<int> adj[], vector<int> &indegree, vector<bool> &exists){
//         queue<int> q;
//         for(int i = 0; i < 26; i++){
//             if(exists[i] && indegree[i] == 0){
//                 q.push(i);
//             }
//         }
        
//         string ans = "";
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             ans += char(node + 'a');
            
//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it] == 0){
//                     q.push(it);
//                 }
//             }
//         }
        
//         return ans;
//     }
//     string findOrder(vector<string> &words) {
//         int n = words.size();
//         vector<int> adj[26];
//         vector<int> indegree(26, 0);
        
//         // Tracks which characters are present
//         vector<bool> exists(26, false);                  // O(K) where K is total characters in all words
//         for(auto word : words){
//             for(auto ch : word){
//                 exists[ch - 'a'] = true;
//             }
//         }
        
//         // Build graph by comparing adjacent words in dictionary
//         for(int i = 0; i < n - 1; i++){                                  // O(N * len)
//             string word1 = words[i];
//             string word2 = words[i+1];
//             int len = min(word1.size(), word2.size());
//             int j = 0;
            
//             while(j < len && word1[j] == word2[j]){
//                 j++;
//             }
            
//             // First different character and create edge
//             if(j < len){
//                 int u = word1[j] - 'a';
//                 int v = word2[j] - 'a';
//                 adj[u].push_back(v);
//                 indegree[v]++;
//             }
//             // Invalid input 
//             else if(word1.size() > word2.size()){
//                 return "";
//             }
//         }
        
//         string ans = topoSort(adj, indegree, exists);                  // O(26 + E) ~ O(1)
        
//         // Check, there was a cycle or not
//         for(int i = 0; i < 26; i++){                             // O(26) ~ O(1)
//             if(exists[i] && indegree[i] != 0){
//                 return "";
//             }
//         }
        
//         return ans;
//     }
// };