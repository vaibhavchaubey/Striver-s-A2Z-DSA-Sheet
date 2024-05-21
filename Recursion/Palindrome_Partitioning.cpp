/* Leetcode  Submission   (131. Palindrome Partitioning)  */


/* Problem Statement: Given a string s, partition s such that every substring of the partition is a  palindrome.
Return all possible palindrome partitioning of s. */


/* Solution: Backtracking */
/* Time Complexity: O((2^N) * K *(N/2))
O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. 
O(k) is for inserting the palindromes in another data structure, where k  is the average length of 
the palindrome list.

Space Complexity: O(N) (Recursion) */


// class Solution
// {
// public:
//     bool isPalindrome(int start, int end, string s)
//     {
//         while (start <= end)
//         {
//             if (s[start++] != s[end--])
//             {
//                 return false;
//             }
//         }

//         return true;
//     }
//     void helper(int index, string s, vector<string> &path, vector<vector<string>> &ans)
//     {
//         if (index == s.size())
//         {
//             ans.push_back(path);
//             return;
//         }

//         for (int i = index; i < s.size(); i++)
//         {
//             if (isPalindrome(index, i, s))
//             {
//                 path.push_back(s.substr(index, i - index + 1));
//                 helper(i + 1, s, path, ans);
//                 // backtrack
//                 path.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s)
//     {
//         vector<vector<string>> ans;
//         vector<string> path;
//         helper(0, s, path, ans);

//         return ans;
//     }
// };
