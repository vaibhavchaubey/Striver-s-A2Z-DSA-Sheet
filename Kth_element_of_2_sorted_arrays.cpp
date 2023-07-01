/* GFG  Submission    (4. Median of Two Sorted Arrays) */


/* Problem Statement: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)). */



/* Solution 1: Brute Force      (Using Merge Sort)    */
// Time Complexity: O(n + m)         
// Space Complexity: O(n + m)


// class Solution{
//     public:
//     int kthElement(int arr1[], int arr2[], int n, int m, int k)
//     {
//         vector<int> vec(n+m);
//         int i = 0, j = 0, idx = 0;
//         while(i < n && j < m){
//             if(arr1[i] < arr2[j]){
//                 vec[idx] = arr1[i];
//                 i++; idx++;
//             }
//             else{                        // arr1[i] >= arr2[j]
//                 vec[idx] = arr2[j];
//                 j++; idx++;
//             }
//         }

//         while(i < n){
//             vec[idx] = arr1[i];
//             i++; idx++;
//         }

//         while(j < m){
//             vec[idx] = arr2[j];
//             j++; idx++;
//         }
        
//         return vec[k-1];
//     }
// };



/* Solution 2: Better Solution      (Using Merge Sort)    */
// Time Complexity: O(k)        
// Space Complexity: O(1)


// class Solution{
//     public:
//     int kthElement(int arr1[], int arr2[], int n, int m, int k)
//     {
//         int i = 0, j = 0, cnt = 0;
//         while(i < n && j < m){
//             if(arr1[i] < arr2[j]){
//                 cnt++;
//                 if(cnt == k){
//                     return arr1[i];
//                 }
//                 i++;
//             }
//             else{                        // arr1[i] >= arr2[j]
//                 cnt++;
//                 if(cnt == k){
//                     return arr2[j];
//                 }
//                 j++;
//             }
//         }
        
//         while(i < n){
//             cnt++;
//             if(cnt == k){
//                 return arr1[i];
//             }
//             i++;
//         }
        
//         while(j < m){
//             cnt++;
//             if(cnt == k){
//                 return arr2[j];
//             }
//             j++;
//         }
        
//         return -1;
//     }
// };



/* Solution 3: Optimal Solution      */
// Time Complexity: O(log(min(n, m)))       
// Space Complexity: O(1)


// class Solution{
//     public:
//     int kthElement(int arr1[], int arr2[], int n, int m, int k)
//     {
//         if(m < n){
//             return kthElement(arr2, arr1, m, n, k);
//         }
        
//         // n < m
        
//         int low = max(0, k-m), high = min(k, n);
//         while(low <= high){
//             int cut1 = low + (high - low) / 2;
//             int cut2 = k - cut1;        // inorder to maintain k elements on the left part
            
//             int left1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
//             int left2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            
//             int right1 = cut1 == n ? INT_MAX : arr1[cut1];
//             int right2 = cut2 == m ? INT_MAX : arr2[cut2];
            
//             if(left1 <= right2 && left2 <= right1){
//                 return max(left1, left2);       // as the kth element is in the left part always
//             }
//             else if(left1 > right2){        // go left
//                 high = cut1 - 1;
//             }
//             else{                   // left2 > right1       // go right
//                 low = cut1 + 1;
//             }
//         }
        
//         return -1;
//     }
// };