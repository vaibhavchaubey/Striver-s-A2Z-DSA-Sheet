/* Implement Upper Bound => Smallest index such that arr[ind] > x */

/*                               inbuilt function
int ind = upper_bound(vec.begin(), vec.end(), x) - vec.begin();              for vector
int ind = upper_bound(arr, arr + n, x) - arr;              for array      */



/* Solution 1: Brute Force  (Using linear search) */
// Time Complexity: O(N)
// Space Complexity: O(1)


// #include <bits/stdc++.h>
// using namespace std;

// int upperBound(vector<int> &arr, int x, int n) {
//     for (int i = 0; i < n; i++) {
//         if (arr[i] > x) {
//             // upper bound found:
//             return i;
//         }
//     }
//     return n;
// }

// int main()
// {
//     vector<int> arr = {3, 5, 8, 9, 15, 19};
//     int n = 6, x = 9;
//     int ind = upperBound(arr, x, n);
//     cout << "The upper bound is the index: " << ind << "\n";
//     return 0;
// }



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)



// #include <bits/stdc++.h>
// using namespace std;

// int upperBound(vector<int> &arr, int n, int x) {
//     int low = 0, high = n - 1;
//     int ans = n;

//     while (low <= high) {
//         int mid = low + (high - low) / 2;    
//         // maybe an answer
//         if (arr[mid] > x) {
//             ans = mid;
//             //look for smaller index on the left
//             high = mid - 1;
//         }
//         else {
//             low = mid + 1; // look on the right
//         }
//     }
//     return ans;
// }

// int main()
// {
//     vector<int> arr = {3, 5, 8, 9, 15, 19};
//     int n = 6, x = 9;
//     int ind = upperBound(arr, x, n);
//     cout << "The upper bound is the index: " << ind << "\n";
//     return 0;
// }




/* It is differnet from upper_bound but given in link */

/* GFG  Submission    (Ceil The Floor) */

/* Problem Statement: Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].
Floor of X is the largest element which is smaller than or equal to X. Floor of X doesn’t exist if X is smaller than smallest 
element of Arr[].
Ceil of X is the smallest element which is greater than or equal to X. Ceil of X doesn’t exist if X is greater than greatest 
element of Arr[]. */


/* Solution:  */
// Time Complexity: O(N)
// Space Complexity: O(1)


// pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
//     int tempFloor = -1, floor = -1;
//     int tempCeil = -1, ceil = INT_MAX;
//     for(int i = 0; i < n; i++){
//         if(arr[i] <= x){
//             tempFloor = arr[i];
//             floor = max(floor, tempFloor);
//         }
//         if(arr[i] >= x){
//             tempCeil = arr[i];
//             ceil = min(ceil, tempCeil);
//         }
//     }
    
//     if(ceil == INT_MAX){
//         ceil = -1;
//     }
    
//     return {floor, ceil};
// }