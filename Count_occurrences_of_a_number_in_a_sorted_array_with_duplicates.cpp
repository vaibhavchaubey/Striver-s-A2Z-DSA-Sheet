/* GFG  Submission    (Number of occurrence) */

/* Problem Statement: Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr. */


/* Solution 1: Brute Force   */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution{
// public:	
// 	/* if x is present in arr[] then returns the count
// 		of occurrences of x, otherwise returns 0. */
// 	int count(int arr[], int n, int x) {
// 	    int count = 0;
// 	    for(int i = 0; i < n; i++){
// 	        if(arr[i] == x){
// 	            count++;
// 	        }
// 	    }
	    
// 	    return count;
// 	}
// };



/* Solution 2: Optimal Approach   (Using Binary Search) (lower_bound & upper_bound)    */
// Time Complexity: O(2 * logN)
// Space Complexity: O(1)


// class Solution{
// public:	
// 	/* if x is present in arr[] then returns the count
// 		of occurrences of x, otherwise returns 0. */
// 	int count(int arr[], int n, int x) {
// 	    int first = lower_bound(arr, arr + n, x) - arr;
// 	    if(first == n || arr[first] != x){
//             return 0;
//         }
//         int last = upper_bound(arr, arr + n, x) - arr - 1;

//         int count = last - first + 1;
	    
// 	    return count;
// 	}
// };