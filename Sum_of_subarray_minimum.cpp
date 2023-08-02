/* Leetcode  Submission    (907. Sum of Subarray Minimums) */

/* Problem Statement: Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7. */



/* Solution 1: Brute Force  (Find all subarray) */
// Time Complexity: O(N * N)                                           
// Space Complexity: O(1)


// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         int sum = 0;
//         for(int i = 0; i < n; i++){
//             int minEle = INT_MAX;
//             for(int j = i; j < n; j++){
//                 minEle = min(minEle, arr[j]);
//                 sum += minEle;
//             }
//         }

//         return sum;
//     }
// };



/* Solution 2: Using Stack     (Findind prevSmaller & nextSmaller)  */
/* Edge Case - Duplicate Elements
For handling duplicates, we do >= in left and > in right
Or, we can also do > for left and >= for right

One thing that we need to be careful about - we should make sure that we don't count the contribution by an element twice. 
This is possible in the cases such as [2, 2, 2]. While finding the boundary elements for a range, we look for elements that 
are strictly less than the current element on the left. To decide the right boundary, we look for the elements which are less 
than or equal to the current element. OR Vive Versa */

// Time Complexity: O(N) + O(N) + O(N)  ~  O(3N)                                         
// Space Complexity: O(N) + O(N)  ~  O(2N)


// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();

//         /* For handling duplicates, we do >= in left and > in right
//         Or, we can also do > for left and >= for right */

//         // count of number greater than arr[i] in left for which arr[i] is minimun element
//         vector<int> prevSmaller(n, -1);    
//         stack<int> st1;
//         for(int i = 0; i < n; i++){
//             while(!st1.empty() && arr[st1.top()] > arr[i]){
//                 st1.pop();
//             }
//             if(st1.empty()){
//                 prevSmaller[i] = i;
//             }
//             else{
//                 prevSmaller[i] = i-st1.top()-1;
//             }
//             st1.push(i);
//         }

//         // count of number greater than arr[i] in right for which arr[i] is minimun element
//         vector<int> nextSmaller(n, -1);           
//         stack<int> st2;
//         for(int i = n-1; i >= 0; i--){
//             while(!st2.empty() && arr[st2.top()] >= arr[i]){
//                 st2.pop();
//             }
//             if(st2.empty()){
//                 nextSmaller[i] = n-i-1;
//             }
//             else{
//                 nextSmaller[i] = st2.top()-i-1;
//             }
//             st2.push(i);
//         }

//         long long ans = 0;
//         int MOD = 1e9+7;
//         for(int i = 0; i < n; i++){
//             // ans = (ans + (arr[i] * (long long)(prevSmaller[i] + 1) * (nextSmaller[i] + 1)) % MOD) % MOD;

//             /* OR */

//             long long count = ((prevSmaller[i] + 1) * (nextSmaller[i] + 1)) % MOD;
//             ans += (arr[i] * count) % MOD;
//             ans %= MOD;
//         }

//         return (int)ans;
//     }
// };