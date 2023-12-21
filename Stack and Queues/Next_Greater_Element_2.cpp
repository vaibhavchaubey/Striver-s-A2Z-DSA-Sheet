/* Leetcode  Submission    (503. Next Greater Element II) */

/* Problem Statement: Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means 
you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number. */



/* Solution: */
// Time Complexity: O(2N + 2N) ~ O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, -1);
//         stack<int> st;
//         for(int i = 2*n-1; i >= 0; i--){
//             while(!st.empty() && st.top() <= nums[i%n]){
//                 st.pop();
//             }
//             if(i < n && !st.empty()){
//                 ans[i] = st.top();
//             }
//             st.push(nums[i%n]);
//         }

//         return ans;
//     }
// };




/* Similar Question As above (If Array is not Circular Array ) */

// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;
// vector<int> nextGreaterElements(vector<int> nums){        //Time Complexity: O(N) + O(N) ~ O(N)
//     int n = nums.size();
//     vector<int> ans(n,-1);
//     stack<int> st;
//     for (int i = n-1; i >= 0; i--)
//     {
//         while (!st.empty() && st.top() <= nums[i])
//         {
//             st.pop();
//         }
//         if(!st.empty()){
//             ans[i] = st.top();
//         }
//         st.push(nums[i]);
//     }
//     return ans;
// }
// int main()
// {
//     vector<int> nums = {2,10,12,1,11};

//     vector<int> ans = nextGreaterElements(nums);

//     for(auto i : ans){
//         cout<<i<<" ";
//     }
//     cout<<endl;

        
//     return 0;
// }
