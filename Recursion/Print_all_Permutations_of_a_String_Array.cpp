/* Leetcode  Submission   (46. Permutations)  */


/* Problem Statement: Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order. */



/* Solution 1:  */
// Time Complexity:  O(N! x N)
// Space Complexity:  O(N) + O(N)


// class Solution {
// public:
//     void recurPermute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, vector<int> &freq){
//         if(ds.size() == nums.size()){               // base case
//             ans.push_back(ds);
//             return;
//         }
        
//         for(int i = 0; i < nums.size(); i++){
//             if(freq[i] == 0){               // element at index i is not taken
//                 ds.push_back(nums[i]);
//                 freq[i] = 1;
//                 recurPermute(ds, nums, ans, freq);
//                 freq[i] = 0;
//                 ds.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> ans;
//         vector<int> ds;
//         vector<int> freq(n, 0);     // to check if the perticular index is taken or not
//         recurPermute(ds, nums, ans, freq);

//         return ans;
//     }
// };



/* Solution 2:  */
// Time Complexity:  O(N! x N)
// Space Complexity:  O(1)


// class Solution {
// public:
//     void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans){
//         if(index == nums.size()){               // base case
//             ans.push_back(nums);
//             return;
//         }
        
//         for(int i = index; i < nums.size(); i++){
//             swap(nums[index], nums[i]);
//             recurPermute(index+1, nums, ans);
//             swap(nums[index], nums[i]);
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         recurPermute(0, nums, ans);

//         return ans;
//     }
// };