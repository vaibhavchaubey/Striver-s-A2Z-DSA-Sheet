/* GFG  Submission    (Leaders in an array) */

/* Problem Statement: Given an array A of positive integers. Your task is to find the leaders in the array.
An element of array is leader if it is greater than or equal to all the elements to its right side.
The rightmost element is always a leader.  */

/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)

// class Solution {
//     // Function to find the leaders in the array.
//   public:
//     vector<int> leaders(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> ans;
//         int maxRightElement = INT_MIN;
//         for(int i = n-1; i >= 0; i--){
//             if(arr[i] >= maxRightElement){
//                 ans.push_back(arr[i]);
//                 maxRightElement = arr[i];
//             }
//         }

//         reverse(ans.begin(), ans.end());

//         return ans;
//     }
// };