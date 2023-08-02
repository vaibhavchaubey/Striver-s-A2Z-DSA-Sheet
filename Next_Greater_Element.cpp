/* Leetcode  Submission    (496. Next Greater Element I) */

/* Problem Statement: The next greater element of some element x in an array is the first greater element that is to the right 
of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater 
element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above. */



/* Solution 1: (Using Hashmap) */
// Time Complexity: O(N2) + O(N1 * N2)
// Space Complexity: O(N2) 


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         unordered_map<int, int> mp;            // ele, idx
//         for(int i = 0; i < nums2.size(); i++){
//             mp[nums2[i]] = i;
//         }

//         for(int i = 0; i < nums1.size(); i++){
//             int idx = mp[nums1[i]];
//             int nextGreater = -1;
//             for(int j = idx+1; j < nums2.size(); j++){
//                 if(nums2[j] > nums2[idx]){
//                     nextGreater = nums2[j];
//                     break;
//                 }
//             }
//             ans.push_back(nextGreater);
//         }

//         return ans;
//     }
// };




/* Solution 2: (Using Stack )
Approach: Use an unordered map nextGreater to store the next greater element for each element in nums2.
Use a stack to keep track of elements in nums2 that we haven't found the next greater element for. */

// Time Complexity: O(N1) + O(N2)
// Space Complexity: O(N2) + O(N2) 


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> nextGreater;            // ele, nextGreater
//         stack<int> st;
//         // Store the next greater element for each element in nums2
//         for(int i = nums2.size()-1; i >= 0; i--){
//             while(!st.empty() && st.top() <= nums2[i]){
//                 st.pop();
//             }
//             if(st.empty()){
//                 nextGreater[nums2[i]] = -1;
//             }
//             else{
//                 nextGreater[nums2[i]] = st.top();
//             }
//             st.push(nums2[i]);
//         }

//         vector<int> ans;
//         for(auto num : nums1){
//             ans.push_back(nextGreater[num]);
//         }

//         return ans;
//     }
// };





/* Codestudio  Submission    (Next Greater Element) */

/* Problem Statement: You are given an array 'a'of size 'n' Print the Next Greater Element (NGE) for every element. 
The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, which is 
greater than 'x' If no greater elements exist to the right of 'x', consider the next greater element as - 1. */



/* Solution: (Using Stack)
Approach: Use an unordered map nextGreater to store the next greater element for each element in nums2.
Use a stack to keep track of elements in nums2 that we haven't found the next greater element for. */

// Time Complexity: O(N) + O(N)
// Space Complexity: O(N) 


// #include<bits/stdc++.h>
// vector<int> nextGreaterElement(vector<int>& arr, int n)
// {
// 	vector<int> ans(n, -1);
// 	stack<int> st;
// 	for(int i = n-1; i >= 0; i--){
// 		while(!st.empty() && st.top() <= arr[i]){
// 			st.pop();
// 		}
// 		if(!st.empty()){
// 			ans[i] = st.top();
// 		}
// 		st.push(arr[i]);
// 	}

// 	return ans;
// }



