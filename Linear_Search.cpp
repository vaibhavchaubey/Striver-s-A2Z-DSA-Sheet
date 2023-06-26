/* GFG  Submission    (Searching an element in a sorted array) */

/* Problem Statement: Given an array arr[] sorted in ascending order of size N and an integer K. 
Check if K is present in the array or not. */


/* Solution:  */
// Time Complexity: O(N)
// Space Complexity: O(1)  


// class Solution{
//     public:
//     // Function to find element in sorted array
//     // arr: input array
//     // N: size of array
//     // K: element to be searche
//     int searchInSorted(int arr[], int N, int K) 
//     { 
    
//        int l = 0, r = N-1;
//        while(l <= r){
//            int mid = l + (r - l) / 2;
//            if(arr[mid] == K){
//                return 1;
//            }
//            else if(arr[mid] > K){
//                r = mid - 1;
//            }
//            else{
//                l = mid + 1;
//            }
//        }
       
//        return -1;
//     }
// };