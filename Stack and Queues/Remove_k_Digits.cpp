/* Leetcode  Submission    (402. Remove K Digits) */

/* Problem Statement: Given string num representing a non-negative integer num, and an integer k, return the smallest 
possible integer after removing k digits from num. */



/* Solution: Using Stack */
// Time Complexity: O(N)                                           
// Space Complexity: O(N)


// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         int n = num.size();
//         stack<char> st;
        
//         for(int i = 0; i < n; i++){
//             // Wheneven we find peek element we remove it
//             while(k > 0 && !st.empty() && st.top() > num[i]){
//                 st.pop();
//                 k--;
//             }
//             if(!st.empty() || num[i] != '0'){
//                 st.push(num[i]);
//             }
//         }

//         // To handle the case when numbers are increasing and there is no dip
//         while(!st.empty() && k > 0){
//             st.pop();
//             k--;
//         }

//         if(st.empty()){
//             return "0";
//         }

//         string ans = "";
//         while(!st.empty()){
//             ans += st.top();
//             st.pop();
//         }

//         reverse(ans.begin(), ans.end());

//         return ans;
//     }
// };


