/* Leetcode  Submission    (1539. Kth Missing Positive Number) */


/* Problem Statement: Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array. */



/* Solution 1: Brute Force (using set or map)   */
// Time Complexity: O(N) 
// Space Complexity: O(N)


// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         unordered_set<int> s(arr.begin(), arr.end());
//         int ans = -1;
//         int i = 1;
//         while(1){
//             if(s.count(i) == 0){
//                 k--;
//                 if(k == 0){
//                     ans = i;
//                     break;
//                 }
//             }
//             i++;
//         }

//         return ans;
//     }
// };



/* Solution 2: Brute Force (without using any space)   */
// Time Complexity: O(N) 
// Space Complexity: O(1)


// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int n = arr.size();
//         for(int i = 0; i < n; i++){
//             if(arr[i] <= k){
//                 k++;
//             }
//             else{
//                 break;
//             }
//         }
        
//         return k;
//     }
// };



/* Solution 3: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         if(k < arr[0]){
//             return k;
//         }
//         int n = arr.size();

//         int low = 0, high = n-1;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             // count of number missing till this index
//             int missing = arr[mid] - (mid + 1);
//             if(missing < k){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }

//         /* count of number missing till index high */
//         // int missing = arr[high] - (high + 1);
//         // int more = k - missing;
//         // int num = arr[high] + more;

//         /* OR (If we simplify above we get high + 1 + k)*/

//         int num = high + 1 + k;          /* OR   low + k   As  low = high + 1 */

//         return num;
//     }
// };




/* GFG  Submission    (K-th missing element) */


/* Problem Statement: Given an increasing sequence a[], we need to find the K-th missing contiguous element in the 
increasing sequence which is not present in the sequence. If no k-th missing element is there output -1. */



/* Solution 1: Brute Force (using set or map)   */
// Time Complexity: O(N) 
// Space Complexity: O(N)


// int KthMissingElement(int a[], int n, int k)
// {
//     unordered_set<int> s;
//     for(int i = 0; i < n; i++){
//         s.insert(a[i]);
//     }
//     int ans = -1;
    
//     for(int i = a[0]; i < a[n-1]; i++){
//         if(s.count(i) == 0){
//             k--;
//             if(k == 0){
//                 ans = i;
//                 break;
//             }
//         }
//     }
    
//     return ans;
// }

