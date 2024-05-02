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
//     void findSubsets(int ind, vector<int>& nums, int n, vector<int> temp, set<vector<int>>& ans){
//         if(ind == n){
//             sort(temp.begin(), temp.end());
//             ans.insert(temp);
//             return;
//         }
//         // element is picked
//         temp.push_back(nums[ind]);
//         findSubsets(ind+1,nums,n,temp,ans);

//         // element is not picked
//         temp.pop_back();
//         findSubsets(ind+1,nums,n,temp,ans);
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp;
//         set<vector<int>> ans;
//         findSubsets(0,nums,n,temp,ans);

//         vector<vector<int>> vec;
//         for(auto it : ans){
//             vec.push_back(it);
//         }

//         return vec;
//     }
// };
