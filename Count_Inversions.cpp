/* GFG  Submission    (Find Missing And Repeating) */

/* Problem Statement: Given an array of integers. Find the Inversion Count in the array. 
Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the 
inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N*N)
// Space Complexity: O(1)


// class Solution{
//   public:
//     // arr[]: Input Array
//     // N : Size of the Array arr[]
//     // Function to count inversions in the array.
//     long long int inversionCount(long long arr[], long long N)
//     {
//         int inv = 0;
//         for(int i = 0; i < N; i++){
//             for(int j = i+1; j < N; j++){
//                 if(arr[i] > arr[j]){
//                     inv++;
//                 }
//             }
//         }
        
//         return inv;
//     }

// };



/* Solution 2: Optimal Approach  (Using mergeSort)  */
// Time Complexity: O(NlogN)
// Space Complexity: O(N) 


// class Solution{
//   public:
//     // arr[]: Input Array
//     // N : Size of the Array arr[]
//     // Function to count inversions in the array.
//     long long merge(long long arr[], int l, int mid, int r){
//         long long inv = 0;
//         int n1 = mid-l+1;
//         int n2 = r-mid;
//         long long a[n1];
//         long long b[n2];
//         for(int i = 0; i < n1; i++){
//             a[i] = arr[l+i];
//         }
//         for(int i = 0; i < n2; i++){
//             b[i] = arr[mid+1+i];
//         }
    
//         int i = 0, j = 0, k = l;
//         while(i < n1 && j < n2){
//             if(a[i] <= b[j]){
//                 arr[k] = a[i];
//                 k++; i++;
//             }
//             else{
//                 arr[k] = b[j];
//                 inv += n1-i;
//                 // every element on the right of a[i] is also greater than b[j] as the array is sorted
//                 // a[i], a[i+1], a[i+2]....a[] > b[j] and i<j
//                 k++; j++;
//             }
//         }
//         while(i < n1){
//             arr[k] = a[i];
//             k++; i++;
//         }
//         while(j < n2){
//             arr[k] = b[j];
//             k++; j++;
//         }
//         return inv;
//     }
//     long long mergeSort(long long arr[], int l, int r){
//         long long inv = 0;
//         if(l < r){
//             int mid = (l+r)/2;
        
//             inv += mergeSort(arr,l,mid);
//             inv += mergeSort(arr,mid+1,r);
        
//             inv += merge(arr,l,mid,r);
//         }
//         return inv;
//     }
//     long long int inversionCount(long long arr[], long long N)
//     {
//         return mergeSort(arr, 0, N-1);
//     }

// };