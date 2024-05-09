/* Leetcode  Submission   (17. Letter Combinations of a Phone Number)  */


/* Problem Statement: Given a string containing digits from 2-9 inclusive, return all possible 
letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 
1 does not map to any letters. */


/* Solution 1: Solved using String + Hash Table     (Iterative Approach) */
/* Time Complexity: O(3^N × 4^M) 
where N is the number of digits which have 3 letters( ex: 2,3,4) assigned to it 
and M is the number of digits which has 4 letters(ex: 7,9) assigned to it.

Space Complexity: O(3^N × 4^M) */


// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string> ans;
//         if(digits.empty()){
//             return ans;
//         }

//         vector<string> pad = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};

//         ans.push_back("");
        
//         for(auto digit : digits){
//             vector<string> temp;
//             for(auto candidate : pad[digit - '0']){
//                 for(auto s : ans){
//                     temp.push_back(s + candidate);
//                 }
//             }
//             ans.clear();
//             ans = temp;
//         }

//         return ans;
//     }
// };



/* Solution 2: Using String + Backtracking + Hash Table    (Recursive Approach) */
/* Time Complexity: O(3^N × 4^M) 
where N is the number of digits which have 3 letters( ex: 2,3,4) assigned to it 
and M is the number of digits which has 4 letters(ex: 7,9) assigned to it.

Space Complexity: O(3^N × 4^M) */


// class Solution {
// public:
//     void helper(int index, string temp, string& digits, vector<string>& pad, vector<string>& ans){
//         if(index == digits.size()){
//             ans.push_back(temp);
//             return;
//         }

//         string value = pad[digits[index] - '0'];
//         for(int i = 0; i < value.size(); i++){
//             temp.push_back(value[i]);
//             helper(index+1, temp, digits, pad, ans);
//             temp.pop_back();
//         }
//     }
//     vector<string> letterCombinations(string digits) {
//         vector<string> ans;
//         if(digits.empty()){
//             return ans;
//         }

//         vector<string> pad = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};

//         helper(0, "", digits, pad, ans);     

//         return ans;
//     }
// };