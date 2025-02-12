/* Codestudio  Submission    (Longest Subarray With Sum K) */


/* Problem Statement: Ninja and his friend are playing a game of subarrays. They have an array 'NUMS' of length 'N'. 
Ninja's friend gives him an arbitrary integer 'K' and asks him to find the length of the longest subarray in which the 
sum of elements is equal to 'K'. Ninjas asks for your help to win this game. Find the length of the longest subarray in 
which the sum of elements is equal to 'K'. If there is no subarray whose sum is 'K' then you should return 0.*/



/* Solution: Using Hashing */
// Time Complexity: O(N)
// Space Complexity: O(N)


// #include <bits/stdc++.h> 
// int getLongestSubarray(vector<int>& nums, int k){
//     int n = nums.size();
//     int curSum = 0;
//     int maxLen = 0;
//     unordered_map<int, int> mp;       // sum, index
//     for(int i = 0; i < n; i++){
//         curSum += nums[i];

//         if(curSum - k == 0){
//             maxLen = max(maxLen, i+1);
//         }

//         if(mp.count(curSum - k)){
//             int len = i - mp[curSum - k];
//             maxLen = max(maxLen, len);
//         }

//         if(mp.count(curSum) == 0){
//             mp[curSum] = i;
//         }
//     }

//     return maxLen;
// }





/* GFG  Submission    (Longest Sub-Array with Sum K) */

/* Problem Statement: Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array 
with the sum of the elements equal to the given value K. */


/* Solution: Using Hashing */
// Time Complexity: O(NlogN)
// Space Complexity: O(N)


// class Solution{
//     public:
//     int lenOfLongSubarr(int A[],  int N, int K) 
//     { 
//         int curSum = 0;
//         int maxLength = 0;
//         unordered_map<int, int> mp;        // sum, index
//         for(int i = 0; i < N; i++){
//             curSum += A[i];
//             if(curSum - K == 0){
//                 maxLength = max(maxLength, i+1);
//             }
//             if(mp.count(curSum - K)){
//                 int len = i - mp[curSum - K];
//                 maxLength = max(maxLength, len);
//             }
//             if(mp.count(curSum) == 0){
//                 mp[curSum] = i;
//             }
//         }
        
//         return maxLength;
//     } 

// };





/* In the above example their are Positive and Negative numbers both.
If we are given only Positive numbers then we can futher optimize above solution by Using 2 pointers. */


/* Solution: Using 2 pointers  (Only when there are Positive numbers) */
// Time Complexity: O(2*N)
// Space Complexity: O(1)


// #include <bits/stdc++.h>
// using namespace std;

// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size();                // size of the array.

//     int left = 0, right = 0;         // 2 pointers
//     long long sum = a[0];
//     int maxLen = 0;
//     while (right < n) {
//         // if sum > k, reduce the subarray from left
//         // until sum becomes less or equal to k:
//         while (left <= right && sum > k) {
//             sum -= a[left];
//             left++;
//         }

//         // if sum = k, update the maxLen i.e. answer:
//         if (sum == k) {
//             maxLen = max(maxLen, right - left + 1);
//         }

//         // Move forward through right pointer:
//         right++;
//         if (right < n) sum += a[right];
//     }

//     return maxLen;
// }

// int main()
// {
//     vector<int> a = {2, 3, 5, 1, 9};
//     long long k = 10;
//     int len = getLongestSubarray(a, k);
//     cout << "The length of the longest subarray is: " << len << "\n";
//     return 0;
// }

