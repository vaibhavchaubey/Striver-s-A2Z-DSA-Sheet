/* Leetcode  Submission    (18. 4Sum) */

/* Problem Statement: Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    •  0 <= a, b, c, d < n
    •  a, b, c, and d are distinct.
    •  nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.
*/


/* Solution 1: Brute Force      (Using 4 pointers)
Approach: We keep four-pointers i,j, k and l. For every triplet we find the sum of A[i]+A[j]+A[k]+A[l]. If this sum is equal to target, we’ve found one of the quads. We add it to our data structure and continue with the rest.

Time Complexity: O(N^4)
Space Complexity: O(2*k)     // k is the no.of quads 
*/


// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         //In order to get the unique quads, we use a set data structure to store them
//         set<vector<int>> st;
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 for(int k = j+1; k < n; k++){
//                     for(int l = k+1; l < n; l++){
//                         long long sum = nums[i];
//                         sum += nums[j];
//                         sum += nums[k];
//                         sum += nums[l];
//                         if(sum == target){
//                             vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                             sort(temp.begin(), temp.end());
//                             st.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }

//         vector<vector<int>> ans(st.begin(), st.end());

//         return ans;
//     }
// };




/* Solution 2: Using 3 pointers and Set */

/*               2 loops    set
Time Complexity : O(N^3) * O(log M)
Space Complexity : O(N) + O(2*k)     // k is the no.of quads  */


// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         //In order to get the unique quads, we use a set data structure to store them
//         set<vector<int>> st;
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 unordered_set<long long> hashSet; 
//                 for(int k = j+1; k < n; k++){
//                     long long x = target;
//                     x -= nums[i];
//                     x -= nums[j];
//                     x -= nums[k];
                    
//                     if(hashSet.count(x)){
//                         // we have to typecast x to int
//                         vector<int> temp = {nums[i], nums[j], nums[k], (int) x};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                     hashSet.insert(nums[k]);
//                 }
//             }
//         }
        
//         vector<vector<int>> ans(st.begin(), st.end());

//         return ans;
//     }
// };



/* Solution 3: Using 3 pointers and Binary Search
Approach:
The main idea is to sort the array, and then we can think of searching in the array using the binary search technique. Since we need the 4 numbers which sum up to target. So we will fix three numbers as nums[i], nums[j] and nums[k], and search for the remaining (target – (nums[i] + nums[j] + nums[k])) in the array. Since we sorted the array during the start, we can apply binary search to search for this value, and if it occurs we can store them. In order to get the unique quads, we use a set data structure to store them. 

Time Complexity: O(NlogN) + O(N^3 * logN)
Reason: Sorting the array takes N log N and three nested loops will be taking N^3 and for binary search, it takes another log N.
Space Complexity: O(2*k)     // k is the no.of quads 
*/


// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         //In order to get the unique quads, we use a set data structure to store them
//         set<vector<int>> st;
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 for(int k = j+1; k < n; k++){
//                     long long x = target;
//                     x -= nums[i];
//                     x -= nums[j];
//                     x -= nums[k];
                    
//                     if(binary_search(nums.begin()+k+1, nums.end(), x)){
//                         // we have to typecast x to int
//                         vector<int> temp = {nums[i], nums[j], nums[k], (int) x};
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
        
//         vector<vector<int>> ans(st.begin(), st.end());

//         return ans;
//     }
// };



/* Solution 4: Optimized Approach

Intuition: In the previous approach we fixed three-pointers and did a binary search to find the fourth. Over here we will fix two-pointers and then find the remaining two elements using two pointer technique as the array will be sorted at first.

Approach: Sort the array, and then fix two pointers, so the remaining sum will be (target – (nums[i] + nums[j])). Now we can fix two-pointers, one front, and another back, and easily use a two-pointer to find the remaining two numbers of the quad. In order to avoid duplications, we jump the duplicates, because taking duplicates will result in repeating quads. We can easily jump duplicates, by skipping the same elements by running a loop.

Time Complexity: O(NlogN) + O(N^3) 
Reason: There are 2 nested loops and the front pointer as well as the right pointer (Third nested loop)
Space Complexity: O(k)     // k is the no.of quads 
*/


// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         for(int i = 0; i < n; i++){
//             // Processing the duplicates of number 1
//             if(i > 0 && nums[i] == nums[i-1]) continue;
//             for(int j = i+1; j < n; j++){
//                 // Processing the duplicates of number 2
//                 if(j > i+1 && nums[j] == nums[j-1]) continue;
//                 int lo = j+1, hi = n-1;
//                 while(lo < hi){
//                     long long sum = nums[i]; 
//                     sum += nums[j];
//                     sum += nums[lo];
//                     sum += nums[hi];

//                     if(sum < target){
//                         lo++;
//                     }
//                     else if(sum > target){
//                         hi--;
//                     }
//                     else{
//                         ans.push_back(vector<int>{nums[i], nums[j], nums[lo], nums[hi]});
//                         lo++; hi--;
//                         // Processing the duplicates of number 3
//                         while(lo < hi && nums[lo] == nums[lo-1]) lo++;
//                         // Processing the duplicates of number 4
//                         while(lo < hi && nums[hi] == nums[hi+1]) hi--;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };