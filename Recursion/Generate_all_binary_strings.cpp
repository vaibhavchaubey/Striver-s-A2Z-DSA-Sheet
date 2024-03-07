/* Codestudio  Submission    (Binary strings with no consecutive 1s) */

/* Problem Statement: You have been given an integer 'N'. Your task is to generate and return all binary 
strings of length 'N' such that there are no consecutive 1's in the string.
A binary string is that string which contains only ‘0’ and ‘1’.
For Example:
Let ‘N'=3, hence the length of the binary string would be 3. 
We can have the following binary strings with no consecutive 1s:
000 001 010 100 101  */


/* Solution:  */
// Time Complexity: O(2^N)
// Space Complexity: O(N)                   // recursion stack


// void helper(int ind, string str, bool prevOne, vector<string>& ans){
//     if(ind == 0){
//         ans.push_back(str);
//         return;
//     }

//     // If the previous character is '0', then we put '1' at the end of the string.
//     if(prevOne == false){
//         helper(ind-1, str+'1', true, ans);
//     }
//     // If the previous character is '1' or '0, then we put '0' at the end of the string.
//     helper(ind-1, str+'0', false, ans);
// }

// vector<string> generateString(int N) {
//     vector<string> ans;
//     helper(N, "", false, ans);
//     sort(ans.begin(), ans.end());

//     return ans;
// }