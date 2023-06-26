/* Leetcode  Submission    (493. Reverse Pairs) */

/* Problem Statement: Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].                  */



/* Solution 1: Brute Force   */
// Time Complexity: O(N*N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 if(nums[i] > 2 * nums[j]){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };



/* Solution 2: Optimal Approach  (Using mergeSort)  */
/* Time Complexity: O(2N * logN)
Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. 
Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating 
the left half once and the right half once in total. That is why, the time complexity is O(N). 
And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. 
Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).

Space Complexity: O(N)  */


// class Solution {
// public:
//     void merge(vector<int>& nums, int l, int mid, int r){       
//         int n1 = mid-l+1;
//         int n2 = r-mid;
//         int a[n1];
//         int b[n2];
//         for(int i = 0; i < n1; i++){
//             a[i] = nums[l+i];
//         }
//         for(int i = 0; i < n2; i++){
//             b[i] = nums[mid+1+i];
//         }

//         int i = 0, j = 0, k = l;
//         while(i < n1 && j < n2){
//             if(a[i] <= b[j]){
//                 nums[k] = a[i];
//                 k++; i++;
//             }
//             else{
//                 nums[k] = b[j];
//                 k++; j++;
//             }
//         }
//         while(i < n1){
//             nums[k] = a[i];
//             k++; i++;
//         }
//         while(j < n2){
//             nums[k] = b[j];
//             k++; j++;
//         }
//     }

//     int countPairs(vector<int>& nums, int l, int mid, int r){
//         int count = 0, right = mid+1; 
//         for(int i = l; i <= mid; i++){
//             while(right <= r && nums[i] > 2LL * nums[right]){
//                 right++;
//             }
//             /* nums[i] > 2 * nums[right] condition may cause overflow
//             rewrite as nums[i] > 2LL * nums[right]
//             OR
//             rewrite as 0.5 * nums[i] > nums[right] */

//             count += right - (mid+1);
//         }

//         return count;
//     }

//     int mergeSort(vector<int>& nums, int l, int r){
//         int count = 0;
//         if(l < r){
//             int mid = (l+r)/2;
        
//             count += mergeSort(nums, l, mid);
//             count += mergeSort(nums, mid+1, r);
//             count += countPairs(nums, l, mid, r);
        
//             merge(nums, l, mid, r);
//         }

//         return count;
//     }

//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         return mergeSort(nums, 0, n-1);
//     }
// };


/*                      OR                       */


// class Solution {
// public:
//     int merge(vector<int>& nums, int l, int mid, int r){
//         // countPairs
//         int count = 0, right = mid+1; 
//         for(int i = l; i <= mid; i++){
//             while(right <= r && nums[i] > 2LL * nums[right]){
//                 right++;
//             }

//             /* nums[i] > 2 * nums[right] condition may cause overflow
//             rewrite as nums[i] > 2LL * nums[right]
//             OR
//             rewrite as 0.5 * nums[i] > nums[right] */

//             count += right - (mid+1);
//         }

//         int n1 = mid-l+1;
//         int n2 = r-mid;
//         int a[n1];
//         int b[n2];
//         for(int i = 0; i < n1; i++){
//             a[i] = nums[l+i];
//         }
//         for(int i = 0; i < n2; i++){
//             b[i] = nums[mid+1+i];
//         }

//         int i = 0, j = 0, k = l;
//         while(i < n1 && j < n2){
//             if(a[i] <= b[j]){
//                 nums[k] = a[i];
//                 k++; i++;
//             }
//             else{
//                 nums[k] = b[j];
//                 k++; j++;
//             }
//         }
//         while(i < n1){
//             nums[k] = a[i];
//             k++; i++;
//         }
//         while(j < n2){
//             nums[k] = b[j];
//             k++; j++;
//         }

//         return count;
//     }

//     int mergeSort(vector<int>& nums, int l, int r){
//         int count = 0;
//         if(l < r){
//             int mid = (l+r)/2;
        
//             count += mergeSort(nums,l,mid);
//             count += mergeSort(nums,mid+1,r);
        
//             count += merge(nums,l,mid,r);
//         }
        
//         return count;
//     }

//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         return mergeSort(nums, 0, n-1);
//     }
// };