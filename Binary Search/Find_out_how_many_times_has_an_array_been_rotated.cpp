/* GFG  Submission    (Rotation) */

/* Problem Statement: Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. 
Find the value of K. */


/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution{
// public:	
// 	int findKRotation(int arr[], int n) {
// 	    for(int i = 0; i < n-1; i++){
// 	        if(arr[i] > arr[i+1]){
// 	            return i+1;
// 	        }
// 	    }
	    
// 	    return 0;
// 	}

// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)

/* Approach: Whenever we get min element we update min element and take index of that min element in ans. At last return ans. */


// class Solution{
// public:	
// 	int findKRotation(int arr[], int n) {
// 	    int minEle = INT_MAX;
//         int low = 0, high = n-1;
//         int ans = 0;

//         while(low <= high){
//             if(arr[low] <= arr[high]){
//                 if(arr[low] < minEle){
//                     minEle = arr[low];
//                     ans = low;
//                 }
//                 break;
//             }
//             int mid = low + (high - low) / 2;

//             // STEP 1: identifying sorted half

//             // left sorted
//             if(arr[low] <= arr[mid]){
//                 // STEP 2: take min from that sorted part
//                 if(arr[low] < minEle){
//                     minEle = arr[low];
//                     ans = low;
//                 }
//                 // STEP 3: then eliminate that part
//                 low = mid + 1;

//             }
//             // right sorted
//             else {                          // if(arr[mid] <= arr[high])
//                 // STEP 2: take min from that sorted part
//                 if(arr[mid] < minEle){
//                     minEle = arr[mid];
//                     ans = mid;
//                 }
//                 // STEP 3: then eliminate that part
//                 high = mid - 1;
//             }
//         }

//         return ans;
// 	}

// };




/* Codestudio  Submission    (Rotation) */

/* Problem Statement: You are given an array 'arr' having 'n' distinct integers sorted in ascending order. 
The array is right rotated 'r'times Find the minimum value of 'r' . Right rotating an array means shifting the element 
at 'ith' index to ('i+1') mod 'n' index, for all 'i' from 0 to 'n-1' */


/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// int findKRotation(vector<int> &arr){
//     int n = arr.size();
//     for(int i = 0; i < n-1; i++){
//         if(arr[i] > arr[i+1]){
//             return i+1;
//         }
//     }

//     return 0;
// }



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)

/* Approach: Whenever we get min element we update min element and take index of that min element in ans. At last return ans. */


// #include<bits/stdc++.h>
// int findKRotation(vector<int> &arr){
//     int n = arr.size();
//     int minEle = INT_MAX;
//     int ans = 0;
//     int low = 0, high = n-1;
//     while(low <= high){
//         if(arr[low] <= arr[high]){
//             if(arr[low] < minEle){
//                 minEle = arr[low];
//                 ans = low;
//             }
//             break;
//         }    

//         int mid = low + (high - low) / 2;

//         // STEP 1: identifying sorted half
        
//         // left sorted
//         if(arr[low] <= arr[mid]){
//             // STEP 2: take min from that sorted part
//             if(arr[low] < minEle){
//                 minEle = arr[low];
//                 ans = low;
//             }
//             // STEP 3: then eliminate that part
//             low = mid+1;
//         }
//         // right sorted
//         else{                              // if(arr[mid] <= arr[high])
//             // STEP 2: take min from that sorted part
//             if(arr[mid] < minEle){
//                 minEle = arr[mid];
//                 ans = mid;
//             }
//             // STEP 3: then eliminate that part
//             high = mid-1;
//         }
//     }

//     return ans;
// }