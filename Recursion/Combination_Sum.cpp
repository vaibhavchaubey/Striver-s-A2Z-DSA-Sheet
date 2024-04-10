/* Leetcode  Submission    (39. Combination Sum) */

/* Problem Statement: Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are 
unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is 
less than 150 combinations for the given input. */


/* Solution: Using Recursion */
// Time Complexity: O(2^t * k)     where t is the target, k is the average length

/* Reason: Assume if you were not allowed to pick a single element multiple times, every element will 
have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that 
the average length of every combination generated is k. (to put length k data structure into another 
data structure)
Why not (2^n) but (2^t) (where n is the size of an array)?
Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not 
pick” an element. */

// Space Complexity: O(k * x)        k is the average length and x is the no. of combinations


// class Solution {
// public:
//     void findCombination(int ind, int target, vector<int>& candidates, int n, vector<int>& temp, vector<vector<int>>& ans){
//         if(ind == n){
//             if(target == 0){
//                 ans.push_back(temp);
//             }
//             return;
//         }

//         // pick up the element
//         if(candidates[ind] <= target){
//             temp.push_back(candidates[ind]);
//             // Here we are not incrementing the ind as same number may be chosen from candidates an unlimited number of times
//             findCombination(ind,target-candidates[ind],candidates,n,temp,ans);
//             temp.pop_back();        // backtrack
//         }

//         //not picking the element
//         findCombination(ind+1,target,candidates,n,temp,ans);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> temp;
//         vector<vector<int>> ans;
//         int n = candidates.size();
//         findCombination(0,target,candidates,n,temp,ans);

//         return ans;
//     }
// };