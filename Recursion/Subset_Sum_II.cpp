/* Leetcode  Submission   (90. Subsets II)  */


/* Problem Statement: Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order. */


/* Solution 1: Brute Force (Using set to store unique Subsets)*/
/* Approach:
At every index, we make a decision whether to pick or not pick the element at that index. This will help us in generating all possible combinations but does not take care of the duplicates. Hence we will use a set to store all the combinations that will discard the duplicates. */


/* Time Complexity: O( 2^n *(k log (x) )). 
2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x. 
After this, we have to convert the set of combinations back into a list of list /vector of vectors which takes more time.

Space Complexity: O(2^n * k) to store every subset of average length k. Since we are initially using a set to store 
the answer another O(2^n *k) is also used. */



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




/* Solution 2: Optimal */


/* Time Complexity: O(k * 2^n)
O(2^n) for generating every subset and O(k)  to insert every subset in another data structure 
if the average length of every subset is k. 

Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  
if n is the depth of the recursion tree. */


// class Solution {
// public:
//     void findSubsets(int ind, vector<int>& nums, int n, vector<int>& temp, vector<vector<int>>& ans){
//         ans.push_back(temp);
//         // as here we are running a loop so there is no need of base case Recursion automatically gets over
//         for(int i = ind; i < n; i++){       
//             if(i > ind && nums[i] == nums[i-1]){
//                 continue;
//             }
//             temp.push_back(nums[i]);
//             findSubsets(i+1,nums,n,temp,ans);
//             temp.pop_back();
//         }
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp;
//         vector<vector<int>> ans;
//         sort(nums.begin(), nums.end());
//         findSubsets(0,nums,n,temp,ans);

//         return ans;
//     }
// };




/* Leetcode  Submission   (78. Subsets)  */


/* Problem Statement: Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order. */


/* Time Complexity: O(2^n)
Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n. */


/* Solution: Using recursion */


// class Solution {
// public:
//     void findSubsets(int ind, vector<int>& nums, int n, vector<int>& temp, vector<vector<int>>& ans){
//         if(ind == n){
//             ans.push_back(temp);
//             return;
//         }
//         // element is picked
//         temp.push_back(nums[ind]);
//         findSubsets(ind+1,nums,n,temp,ans);

//         // element is not picked
//         temp.pop_back();
//         findSubsets(ind+1,nums,n,temp,ans);
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp;
//         vector<vector<int>> ans;
//         findSubsets(0,nums,n,temp,ans);

//         return ans;
//     }
// };