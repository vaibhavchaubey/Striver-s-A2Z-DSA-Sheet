/* Leetcode  Submission   (216. Combination Sum III)  */


/* Problem Statement: Find all valid combinations of k numbers that sum up to n such that the following 
conditions are true:
    Only numbers 1 through 9 are used.
    Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, 
and the combinations may be returned in any order. */


/* Solution: Using Recursion */

/* Time Complexity: O(2^k)            // where 'k' is the number of elements in the combination.
The function helper is recursively called with num increasing from 1 to 9. 
So, the time complexity of the helper function is O(9).
Within each recursive call, there are two branches: one where the current number is included in the 
combination and one where it is not included.

Space Complexity:  O(2^k)  */


// class Solution {
// public:
//     void helper(int num, int k, int sum, vector<int>& arr, vector<vector<int>>& ans){
//         if(k == 0){
//             if(sum == 0){
//                 ans.push_back(arr);
//             }
//             return;
//         }
//         if(num > 9){
//             return;
//         }

//         // pick up the element
//         if(num <= sum){
//             arr.push_back(num);
//             helper(num+1, k-1, sum-num, arr, ans);
//             arr.pop_back();
//         }

//         // not picking the element
//         helper(num+1, k, sum, arr, ans);
//     }
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<int> arr;
//         vector<vector<int>> ans;

//         helper(1, k, n, arr, ans);

//         return ans;
//     }
// };
