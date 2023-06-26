/* HERE ARRAY IS SORTED */

/* Solution:  */
// Time Complexity: O(logN)
// Space Complexity: O(1)


// #include<bits/stdc++.h>
// using namespace std;

// int findFloor(int arr[], int n, int x) {
// 	int low = 0, high = n - 1;
// 	int ans = -1;

// 	while (low <= high) {
// 		int mid = (low + high) / 2;
// 		// maybe an answer
// 		if (arr[mid] <= x) {
// 			ans = arr[mid];
// 			//look for larger index on the right
// 			low = mid + 1;
// 		}
// 		else {
// 			high = mid - 1; // look on the right
// 		}
// 	}
// 	return ans;
// }

// int findCeil(int arr[], int n, int x) {
// 	int low = 0, high = n - 1;
// 	int ans = -1;

// 	while (low <= high) {
// 		int mid = (low + high) / 2;
// 		// maybe an answer
// 		if (arr[mid] >= x) {
// 			ans = arr[mid];
// 			//look for smaller index on the left
// 			high = mid - 1;
// 		}
// 		else {
// 			low = mid + 1; // look on the right
// 		}
// 	}
// 	return ans;
// }

// pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
// 	int f = findFloor(arr, n, x);
// 	int c = findCeil(arr, n, x);
// 	return make_pair(f, c);
// }

// int main() {
// 	int arr[] = {3, 4, 4, 7, 8, 10};
// 	int n = 6, x = 5;
// 	pair<int, int> ans = getFloorAndCeil(arr, n, x);
// 	cout << "The floor and ceil are: " << ans.first
// 	     << " " << ans.second << endl;
// 	return 0;
// }



/* HERE ARRAY IS NOT SORTED */


/* Codestudio     Submission    (Ceil The Floor) */

/* Problem Statement: You're given an unsorted array 'A' of 'N' integers and an integer 'X'.
Find the floor and ceiling of 'X' in 'A[O.N-1]'.
Floor of 'X' is the largest element in the array which is smaller than or equal to 'X'.
Ceiling of 'X' is the smallest element in the array greater than or equal to 'X'. */


/* Solution:  */
// Time Complexity: O(N)
// Space Complexity: O(1)


// pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
// 	int tempFloor = -1, floor = -1;
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