/* Leetcode  Submission    (4. Median of Two Sorted Arrays) */


/* Problem Statement: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)). */



/* Solution 1: Brute Force      (Using Merge Sort)    */
// Time Complexity: O(n1 + n2)     
// Space Complexity: O(n1 + n2)


// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size(), n2 = nums2.size();
//         vector<int> vec(n1+n2);
//         int i = 0, j = 0, k = 0;
//         while(i < n1 && j < n2){
//             if(nums1[i] < nums2[j]){
//                 vec[k] = nums1[i];
//                 i++; k++;
//             }
//             else{                        // nums1[i] >= nums2[j]
//                 vec[k] = nums2[j];
//                 j++; k++;
//             }
//         }

//         while(i < n1){
//             vec[k] = nums1[i];
//             i++; k++;
//         }

//         while(j < n2){
//             vec[k] = nums2[j];
//             j++; k++;
//         }

//         double ans = 0;
//         int mid = (n1 + n2) / 2;
//         if((n1 + n2) % 2 == 0){
//             double num1 = vec[mid-1];
//             double num2 = vec[mid];

//             ans = (num1 + num2) / 2;
//         }
//         else{
//             double num = vec[mid];
//             ans =  num;
//         }

//         return ans;
//     }
// };



/* Solution 2: Better Solution      (Using Merge Sort)    */
// Time Complexity: O(n1 + n2)      
// Space Complexity: O(1)


// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size(), n2 = nums2.size();
//         int mid = (n1 + n2) / 2;
        
//         int cnt = 0;
//         double num1 = 0, num2 = 0;
//         int i = 0, j = 0;
//         while(i < n1 && j < n2){
//             if(nums1[i] < nums2[j]){
//                 if(cnt == mid-1){
//                    num1 = nums1[i];
//                 }
//                 else if(cnt == mid){
//                     num2 = nums1[i];
//                 }
//                 i++;
//             }
//             else{                           // nums1[i] >= nums2[j]
//                 if(cnt == mid-1){
//                    num1 = nums2[j];
//                 }
//                 else if(cnt == mid){
//                     num2 = nums2[j];
//                 }
//                 j++;
//             }
//             cnt++;
//         }

//         while(i < n1){
//             if(cnt == mid-1){
//                 num1 = nums1[i];
//             }
//             else if(cnt == mid){
//                 num2 = nums1[i];
//             }
//             i++;
//             cnt++;
//         }

//         while(j < n2){
//             if(cnt == mid-1){
//                 num1 = nums2[j];
//             }
//             else if(cnt == mid){
//                 num2 = nums2[j];
//             }
//             j++;
//             cnt++;
//         }


//         double ans = 0;
//         if((n1 + n2) % 2 == 0){
//             ans = (num1 + num2) / 2;
//         }
//         else{
//             ans =  num2;
//         }

//         return ans;
//     }
// };



/* Solution 3: Optimal Solution      */
// Time Complexity: O(log(min(n1, n2)))       
// Space Complexity: O(1)


// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         if(nums2.size() < nums1.size()){
//             return findMedianSortedArrays(nums2, nums1);
//         }

//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int low = 0, high = n1;
//         while(low <= high){
//             int cut1 = low + (high - low) / 2;
//             int cut2 = (n1 + n2 + 1) / 2 - cut1;

//             int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
//             int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

//             int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
//             int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

//             if(left1 <= right2 && left2 <= right1){
//                 if((n1 + n2) % 2 == 0){
//                     return (max(left1, left2) + min(right1, right2)) / 2.0;
//                 }
//                 else{
//                     return max(left1, left2);
//                 }
//             }
//             else if(left1 > right2){        // go left
//                 high = cut1 - 1;
//             }
//             else{       // left2 > right1   // go right
//                 low = cut1 + 1;
//             }
//         }

//         return 0.0;
//     }
// };