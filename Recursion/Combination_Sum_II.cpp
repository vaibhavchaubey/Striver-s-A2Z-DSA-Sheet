/* Leetocde  Submission   (40. Combination Sum II)  */


/* Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations. */


// Time Complexity: O(2^n * k)     k is the average length

/* Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get 
will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average 
space for the ds.  */

// Space Complexity: O(k*x)        k is the average length and x is the no. of combinations


// class Solution {
// public:
//     void findCombination(int ind, int target, vector<int>& candidates, int n, vector<int>& temp, vector<vector<int>>& ans){
//         if(target == 0){
//             ans.push_back(temp);
//             return;
//         }
//         for(int i = ind; i < n; i++){
//             // to avoid duplicate
//             if(i > ind && candidates[i] == candidates[i-1]){
//                 continue;
//             }
//             // there is no use to check as the array is sorted
//             if(candidates[i] > target){
//                 break;
//             }
//             temp.push_back(candidates[i]);
//             findCombination(i+1,target-candidates[i],candidates,n,temp,ans);
//             temp.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         // sort the elements because the ans should contain the combinations in sorted order and should not be repeated
//         sort(candidates.begin(), candidates.end());
//         vector<int> temp;
//         vector<vector<int>> ans;
//         int n = candidates.size();
//         findCombination(0,target,candidates,n,temp,ans);

//         return ans;
//     }
// };