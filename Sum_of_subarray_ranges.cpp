/* Leetcode  Submission    (2104. Sum of Subarray Ranges) */

/* Problem Statement: You are given an integer array nums. The range of a subarray of nums is the difference between the 
largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array. */



/* Solution 1: Brute Force  (Find all subarray) */
// Time Complexity: O(N * N)                                           
// Space Complexity: O(1)


// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         int n = nums.size();
//         long long sum = 0;
//         for(int i = 0; i < n; i++){
//             int minEle = INT_MAX;
//             int maxEle = INT_MIN;
//             for(int j = i; j < n; j++){
//                 minEle = min(minEle, nums[j]);
//                 maxEle = max(maxEle, nums[j]);
//                 sum += maxEle - minEle;
//             }
//         }

//         return sum;
//     }
// };



/* Solution 2: Using Stack     (Findind prevSmaller & nextSmaller  and  prevGreater & nextGreater)  */
/* 
Intuition
1) Rather than checking for all subarrays of nums and finding the largest and smallest of all subarrays, we can reduce our calculations
2) We can simply find the contribution of each element of nums in the final answer
3) So now problem boils down to three tasks
    For each element in nums find the number of subarrays in which that element is minimum [Let count of such subarrays be minCount]
    For each element in nums find the number of subarrays in which that element is maximum [Let count of such subarrays be maxCount]
    (1)Contribution of each element = +(maxCount * nums[i])
    (2)Contribution of each element = -(minCount * nums[i])
    

Edge Case - Duplicate Elements
For handling duplicates, we do >= in left and > in right
Or, we can also do > for left and >= for right

And

For handling duplicates, we do <= in left and < in right
Or, we can also do < for left and <= for right 
*/

// Time Complexity: O(N) + O(N) + O(N)  ~  O(3N)                                         
// Space Complexity: O(N) + O(N)  ~  O(2N)


// class Solution {
// public:
//     long long sumSubarrayMins(vector<int>& arr) {
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
//         for(int i = 0; i < n; i++){
//             long long count = (prevSmaller[i] + 1) * (nextSmaller[i] + 1);
//             ans += arr[i] * count;
//         }

//         return ans;
//     }


//     long long sumSubarrayMaxs(vector<int>& arr) {
//         int n = arr.size();

//         /* For handling duplicates, we do <= in left and < in right
//         Or, we can also do < for left and <= for right */

//         // count of number smaller than arr[i] in left for which arr[i] is maximun element
//         vector<int> prevGreater(n, -1);    
//         stack<int> st1;
//         for(int i = 0; i < n; i++){
//             while(!st1.empty() && arr[st1.top()] < arr[i]){
//                 st1.pop();
//             }
//             if(st1.empty()){
//                 prevGreater[i] = i;
//             }
//             else{
//                 prevGreater[i] = i-st1.top()-1;
//             }
//             st1.push(i);
//         }

//         // count of number smaller than arr[i] in right for which arr[i] is maximun element
//         vector<int> nextGreater(n, -1);           
//         stack<int> st2;
//         for(int i = n-1; i >= 0; i--){
//             while(!st2.empty() && arr[st2.top()] <= arr[i]){
//                 st2.pop();
//             }
//             if(st2.empty()){
//                 nextGreater[i] = n-i-1;
//             }
//             else{
//                 nextGreater[i] = st2.top()-i-1;
//             }
//             st2.push(i);
//         }

//         long long ans = 0;
//         for(int i = 0; i < n; i++){
//             long long count = (prevGreater[i] + 1) * (nextGreater[i] + 1);
//             ans += arr[i] * count;
//         }

//         return ans;
//     }

//     long long subArrayRanges(vector<int>& nums) {
//         long long minVal = sumSubarrayMins(nums);
//         long long maxVal = sumSubarrayMaxs(nums);

//         long long sum = maxVal - minVal;

//         return sum;
//     }
// };