/* GFG  Submission    (Row with max 1s) */

/* Problem Statement: Given a boolean 2D array of n x m dimensions where each row is sorted. 
Find the 0-based index of the first row that has the maximum number of 1's. */



/* Solution 1: Brute Force  */
// Time Complexity: O(N * M)
// Space Complexity: O(1) 


// class Solution{
// public:
// 	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
// 	    int maxOne = 0;
// 	    int rowIndex = -1;
// 	    for(int i = 0; i < n; i++){
// 	       int cntOne = 0;
// 	       for(int j = 0; j < m; j++){
// 	           cntOne += arr[i][j];
// 	       }
// 	       if(cntOne > maxOne){
// 	           maxOne = cntOne;
// 	           rowIndex = i;
// 	       }
// 	   }
	    
// 	    return rowIndex;
// 	}

// };




/* Solution 2: Better Approach (Using lower_bound)  */
// Time Complexity: O(N logM)
// Space Complexity: O(1) 


// class Solution{
// public:
//     int lowerBound(vector<int> arr, int n, int x) {
//         int low = 0, high = n - 1;
//         int ans = n;
    
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             // maybe an answer
//             if (arr[mid] >= x) {
//                 ans = mid;
//                 //look for smaller index on the left
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1; // look on the right
//             }
//         }
//         return ans;
//     }
    
// 	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
// 	    int maxOne = 0;
// 	    int rowIndex = -1;
// 	    for(int i = 0; i < n; i++){
// 	       // get the number of 1's:
// 	       int cntOne = m - lowerBound(arr[i], m, 1);
// 	       if(cntOne > maxOne){
// 	           maxOne = cntOne;
// 	           rowIndex = i;
// 	       }
// 	   }
	    
// 	    return rowIndex;
// 	}

// };




/* Solution 3: Optimal Solution */
// Time Complexity: O(N + M)
// Space Complexity: O(1) 


// class Solution{
// public:
// 	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
// 	    int r = 0, c = m-1;
// 	    int rowIndex = -1;
	    
// 	    // starting from top right corner
//         // go left if you encounter 1
//         // do down if you encounter 0
// 	    while(r < n && c >= 0){
// 	        if(arr[r][c] == 1){
// 	            rowIndex = r;
// 	            c--;
// 	        }
// 	        else{
// 	            r++;
// 	        }
// 	    }
	    
// 	    return rowIndex;
// 	}
// };