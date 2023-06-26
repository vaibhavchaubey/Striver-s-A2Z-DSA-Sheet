/* Implement Lower Bound => Smallest index such that arr[ind] >= x */

/*                               inbuilt function
int ind = lower_bound(vec.begin(), vec.end(), x) - vec.begin();              for vector
int ind = lower_bound(arr, arr + n, x) - arr;              for array      */



/* Solution 1: Brute Force  (Using linear search) */
// Time Complexity: O(N)
// Space Complexity: O(1)


// #include <bits/stdc++.h>
// using namespace std;

// int lowerBound(vector<int> arr, int n, int x) {
//     for (int i = 0; i < n; i++) {
//         if (arr[i] >= x) {
//             // lower bound found
//             return i;
//         }
//     }
//     return n;
// }

// int main()
// {
//     vector<int> arr = {3, 5, 8, 15, 19};
//     int n = 5, x = 9;
//     int ind = lowerBound(arr, n, x);
//     cout << "The lower bound is the index: " << ind << "\n";
//     return 0;
// }



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// #include <bits/stdc++.h>
// using namespace std;

// int lowerBound(vector<int> arr, int n, int x) {
//     int low = 0, high = n - 1;
//     int ans = n;

//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         // maybe an answer
//         if (arr[mid] >= x) {
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
//     vector<int> arr = {3, 5, 8, 15, 19};
//     int n = 5, x = 9;
//     int ind = lowerBound(arr, n, x);
//     cout << "The lower bound is the index: " << ind << "\n";
//     return 0;
// }




/* It is differnet from lower_bound but given in link */

/* GFG  Submission    (Floor in a Sorted Array) */

/* Problem Statement: Given a sorted array arr[] of size N without duplicates, and given a value x. 
Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
Find the index of K(0-based indexing). */



/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution{
//   public:
//     // Function to find floor of x
//     // n: size of vector
//     // x: element whose floor is to find
//     int findFloor(vector<long long> v, long long n, long long x){
//         int ans = -1;
//         for(int i = 0; i < n; i++){
//             if(v[i] <= x){
//                 ans = i;
//             }
//             else{
//                 break;
//             }
//         }
        
//         return ans;
//     }
// };



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// class Solution{
//   public:
//     // Function to find floor of x
//     // n: size of vector
//     // x: element whose floor is to find
//     int findFloor(vector<long long> v, long long n, long long x){
//         int ans = -1;
//         int low = 0, high = n-1;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(v[mid] <= x){
//                 ans = mid;
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
        
//         return ans;
//     }
// };