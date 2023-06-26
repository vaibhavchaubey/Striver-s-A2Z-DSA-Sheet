/* Leetcode  Submission    (15. 3Sum) */

/* Problem Statement: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and 
j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets. */


/* Solution 1: Brute Force   (It will give TLE)    */
/*               3 loops    set
Time Complexity : O(N^3 * log(k))   
Space Complexity : O(2*k)     // k is the no.of triplets  */

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         // set is used to prevent duplicate triplets
//         set<vector<int>> st;
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 for(int k = j+1; k < n; k++){
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         vector<int> temp = {nums[i], nums[j], nums[k]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
        
//         vector<vector<int>> ans(st.begin(), st.end());

//         return ans;
//     }
// };



/* Solution 2: Using 2 pointers and Set    (It will give TLE)     */
/*               2 loops    set
Time Complexity : O(N^2) * O(log M)
Space Complexity : O(N) + O(2*k)     // k is the no.of triplets  */

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         // set is used to prevent duplicate triplets
//         set<vector<int>> st;
//         for(int i = 0; i < n; i++){
//             set<int> hashSet;
//             for(int j = i+1; j < n; j++){
//                 int third = -(nums[i] + nums[j]);
//                 if(hashSet.count(third)){
//                     vector<int> temp = {nums[i], nums[j], third};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashSet.insert(nums[j]);
//             }
//         }
        
//         vector<vector<int>> ans(st.begin(), st.end());

//         return ans;
//     }
// };



/* Solution 3: Optimized Approach */
/* Approach:
we are fixing the i pointer and then applying the traditional 2 pointer approach to check whether the sum of three numbers equals zero. 
If the sum is less than zero, it indicates our sum is probably too less and we need to increment our j pointer to get a larger sum. 
On the other hand, if our sum is more than zero, it indicates our sum is probably too large and we need to decrement the k pointer  
to reduce the sum and bring it closer to zero. */

// Time Complexity : O(NlogN) + O(N^2)
// Space Complexity : O(k)        // k is the no.of triplets. 


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> ans;
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i < n-2; i++){
//             // Processing the duplicates of number 1
//             if(i > 0 && nums[i] == nums[i-1]) continue;
//             int lo = i+1, hi = n-1;
//             while(lo < hi){
//                 int sum = nums[i] + nums[lo] + nums[hi];

//                 if(sum < 0){
//                     lo++;
//                 }
//                 else if(sum > 0){
//                     hi--;
//                 }
//                 else{
//                     ans.push_back(vector<int>{nums[i], nums[lo], nums[hi]});
//                     lo++; hi--;
//                     // Processing the duplicates of number 2
//                     while(lo < hi && nums[lo] == nums[lo-1]) lo++;
//                     // Processing the duplicates of number 3
//                     while(lo < hi && nums[hi] == nums[hi+1]) hi--;
//                 }
//             } 
//         }

//         return ans;
//     }
// };




/* GFG  Submission    (3 sum closest) */

/* Problem Statement: Given an array A[] of N integers and an integer X. The task is to find the sum of 
three integers in A[] such that it is closest to X. */


/* Solution:  */
// Time Complexity: O(N*N)
// Space Complexity: O(1)


// class Solution{
//     public:
//     int closest3Sum(int A[], int N, int X)
//     {
//         int ans = 0, mini = INT_MAX;
//         sort(A, A+N);
//         for(int i = 0; i < N-2; i++){
//             int lo = i+1, hi = N-1;
//             while(lo < hi){
//                 int sum = A[i] + A[lo] + A[hi];
//                 if(sum == X){
//                     return sum;
//                 }
//                 else if(sum < X){
//                     lo++;
//                 }
//                 else if(sum > X){
//                     hi--;
//                 }
//                 if(abs(sum - X) < mini){
//                     mini = abs(sum - X);
//                     ans = sum;
//                 }
//             } 
//         }

//         return ans;
//     }
// };