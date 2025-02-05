/* GFG  Submission    (Sorted Array Search) */

/* Problem Statement: Given an array, arr[] sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false. */

/* Solution:  */
// Time Complexity: O(N)
// Space Complexity: O(1)

// class Solution {
//   public:
//     // Function to find element in sorted array
//     // arr: input array
//     // k: element to be searched
//     bool searchInSorted(vector<int>& arr, int k) {
//         int N = arr.size();

//         int l = 0, r = N-1;
//         while(l <= r){
//            int mid = l + (r - l) / 2;
//            if(arr[mid] == k){
//                return true;
//            }
//            else if(arr[mid] > k){
//                r = mid - 1;
//            }
//            else{
//                l = mid + 1;
//            }
//        }

//        return false;
//     }
// };