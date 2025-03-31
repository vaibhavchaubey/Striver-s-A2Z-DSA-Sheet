/* Leetcode  Submission    (88. Merge Sorted Array) */

/* Problem Statement: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n. */



/* Solution 1: Brute Force   */
// Time Complexity: O(n + m) + O(n + m)
// Space Complexity: O(n + m)


// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> temp;
//         int i = 0, j = 0;
//         while(i < m && j < n){
//             if(nums1[i] < nums2[j]){
//                 temp.push_back(nums1[i]);
//                 i++;
//             }
//             else{
//                 temp.push_back(nums2[j]);
//                 j++;
//             }
//         }

//         while(i < m){
//             temp.push_back(nums1[i]);
//             i++;
//         }

//         while(j < n){
//             temp.push_back(nums2[j]);
//             j++;
//         }

//         for(int i = 0; i < m+n; i++){
//             nums1[i] = temp[i];
//         }
//     }
// };


    
/* Solution 2: Optimal Solution 1  */
// Time complexity: O(NlogN) + O(n)         (N = n+m)
// Space Complexity: O(1) 


// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for(int i = 0; i < nums2.size(); i++){
//             nums1[m + i] = nums2[i];
//         }
//         sort(nums1.begin(), nums1.end());
//     }
// };



/* Solution 3: Optimal Solution 2   (Gap method)  */
// Time complexity: O(log(n + m)) * O(n + m)
// Space Complexity: O(1) 


// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int gap = ceil((float)(m + n) / 2);
//         while(gap > 0){
//             int i = 0; 
//             int j = gap;
//             while(j < m + n){
//                 // nums1 and nums1
//                 if(j < m && nums1[i] > nums1[j]){
//                     swap(nums1[i], nums1[j]);
//                 }
//                 // nums1 and nums2
//                 else if(j >= m && i < m && nums1[i] > nums2[j - m]){
//                     swap(nums1[i], nums2[j - m]);
//                 }
//                 // nums2 and nums2
//                 else if(j >= m && i >= m && nums2[i - m] > nums2[j - m]){
//                     swap(nums2[i - m], nums2[j - m]);
//                 }
//                 i++;
//                 j++;
//             }
//             if(gap == 1){
//                 break;
//             }
//             else{
//                 gap = ceil((float) gap / 2);
//             }
//         }

//         for(int i = 0; i < n; i++){
//             nums1[m + i] = nums2[i]; 
//         }
//     }
// };



/* GFG  Submission    (88. Merge Sorted Array) */

/* Problem Statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements 
and modify arr2 so that it contains the last M elements. */



/* Solution 1: Brute Force   */
// Time Complexity: O(n + m) + O(n + m)
// Space Complexity: O(n + m)


// class Solution{
//     public:
//         //Function to merge the arrays.
//         void merge(long long arr1[], long long arr2[], int n, int m) 
//         { 
//             vector<long long> temp;
//             int i = 0, j = 0;
//             while(i < n && j < m){
//                 if(arr1[i] < arr2[j]){
//                     temp.push_back(arr1[i]);
//                     i++;
//                 }
//                 else{
//                     temp.push_back(arr2[j]);
//                     j++;
//                 }
//             }
    
//             while(i < n){
//                 temp.push_back(arr1[i]);
//                 i++;
//             }
    
//             while(j < m){
//                 temp.push_back(arr2[j]);
//                 j++;
//             }
            
//             for(int i = 0; i < n+m; i++){
//                 if(i < n){
//                     arr1[i] = temp[i];
//                 }
//                 else{
//                     arr2[i-n] = temp[i];
//                 }
//             }
//         }
// };



/* Solution 2: Optimal Solution 1 */
// Time Complexity: O(min(n, m)) + O(n Log n) + O(m Log m)
// Space Complexity: O(1) 


// class Solution{
//     public:
//         //Function to merge the arrays.
//         void merge(long long arr1[], long long arr2[], int n, int m) 
//         { 
//             int i = n-1, j = 0;
//             while(i >= 0 && j < m){
//                 if(arr1[i] > arr2[j]){
//                     swap(arr1[i], arr2[j]);
//                     i--; j++;
//                 }
//                 else{
//                     break;
//                 }
//             }
            
//             sort(arr1, arr1 + n);
//             sort(arr2, arr2 + m);
//         } 
// };




/* Solution 3: Optimal Solution 2   (Gap method)     */
// Time complexity: O(log(n + m)) * O(n + m)
// Space Complexity: O(1) 


// class Solution{
//     public:
//         //Function to merge the arrays.
//         void merge(long long arr1[], long long arr2[], int n, int m) 
//         { 
//             int gap = ceil((float)(n + m) / 2);
//             while(gap > 0){
//                 int i = 0; 
//                 int j = gap;
//                 while(j < n + m){
//                     // arr1 and arr1
//                     if(j < n && arr1[i] > arr1[j]){
//                         swap(arr1[i], arr1[j]);
//                     }
//                     // arr1 and arr2
//                     else if(j >= n && i < n && arr1[i] > arr2[j - n]){
//                         swap(arr1[i], arr2[j - n]);
//                     }
//                     // arr2 and arr2
//                     else if(j >= n && i >= n && arr2[i - n] > arr2[j - n]){
//                         swap(arr2[i - n], arr2[j -n]);
//                     }
//                     i++;
//                     j++;
//                 }
//                 if(gap == 1){
//                     break;
//                 }
//                 else{
//                     gap = ceil((float) gap / 2);
//                 }
//             }
//         } 
// };