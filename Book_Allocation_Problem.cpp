/* Codestudio  Submission    (Allocate Books) */


/* Problem Statement: Given an array 'arr'of integer numbers, 'arr[i]' represents the number of pages in the 'i-th' book.
There are 'm'number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to 'm' students such that the maximum number
of pages assigned to a student is minimum.
If the allocation of books is not possible, return -1. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N) * O(sumAll - manEle)
// Space Complexity: O(1)

/* Range    [maxEle ................... sumAll]   =>  using Linear search for this range */


// bool isPossible(int pages, int m, int n, vector<int>& arr){
//     int students = 1;
//     long long sum = 0;
//     for(int i = 0; i < n; i++){
//         if(sum + arr[i] > pages){
//             students++;
//             sum = arr[i];
//         }
//         else{
//             sum += arr[i];
//         }
//     }

//     if(students <= m){
//         return true;
//     }

//     return false;
// }
// int findPages(vector<int>& arr, int n, int m) {
//     if(m > n){
//         return -1;
//     }

//     int maxEle = 0, sumAll = 0;
//     for(int i = 0; i < n; i++){
//         maxEle = max(maxEle, arr[i]);
//         sumAll += arr[i];
//     }

//     int low = maxEle, high = sumAll;
//     for(int i = low; i <= high; i++){
//         // checking if by having a pages mid can we allocate books to m students
//         if(isPossible(i, m, n, arr)){
//             return i;
//         }
//     }

//     return -1;
// }



/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N) * O(log(sumAll - manEle))
// Space Complexity: O(1)

/* Range    [maxEle ................... sumAll]   =>  using Binary search for this range */


// bool isPossible(int pages, int m, int n, vector<int>& arr){
//     int students = 1;
//     long long sum = 0;
//     for(int i = 0; i < n; i++){
//         if(sum + arr[i] > pages){
//             students++;
//             sum = arr[i];
//         }
//         else{
//             sum += arr[i];
//         }
//     }

//     if(students <= m){
//         return true;
//     }

//     return false;
// }
// int findPages(vector<int>& arr, int n, int m) {
//     if(m > n){
//         return -1;
//     }

//     int maxEle = 0, sumAll = 0;
//     for(int i = 0; i < n; i++){
//         maxEle = max(maxEle, arr[i]);
//         sumAll += arr[i];
//     }
//     int ans = -1;

//     int low = maxEle, high = sumAll;
//     while(low <= high){
//         int mid = low + (high - low) / 2;
//         // checking if by having a pages mid can we allocate books to m students
//         if(isPossible(mid, m, n, arr)){
//             ans = mid;
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }

//     return ans;
// }