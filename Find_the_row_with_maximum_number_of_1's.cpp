/* GFG  Submission    (Row with max 1s) */

/* Problem Statement: Given a boolean 2D array of n x m dimensions where each row is sorted. 
Find the 0-based index of the first row that has the maximum number of 1's. */


/* Solution: */
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
	    
// 	    return index;
// 	}
// };