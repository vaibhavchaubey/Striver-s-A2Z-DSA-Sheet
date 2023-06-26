/* GFG  Submission    (Largest subarray with 0 sum) */

/* Problem Statement: Given an array having both positive and negative integers. The task is to compute the 
length of the largest subarray with sum 0. */


/* Solution: Using Hashing */
// Time Complexity: O(NlogN)
// Space Complexity: O(N)


// class Solution{
//     public:
//     int maxLen(vector<int>&A, int n)
//     {   
//         int sum = 0;
//         int maxLength = 0;
//         unordered_map<int, int> mp;        // sum, index
//         for(int i = 0; i < n; i++){
//             sum += A[i];
//             if(sum == 0){
//                 maxLength = i+1;
//             }
//             if(mp.count(sum)){
//                 int len = i - mp[sum];
//                 maxLength = max(maxLength, len);
//             }
//             if(mp.count(sum) == 0){
//                 mp[sum] = i;
//             }
//         }
        
//         return maxLength;
//     }
// };