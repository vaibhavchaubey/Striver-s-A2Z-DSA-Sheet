/* Problem Statement: Given an array Arr of size N, print second largest distinct element from an array. */


/* GFG  Submission    (Second Largest) */


/* Solution:  */
// Time Complexity: O(N)
// Space Complexity: O(1)  


// class Solution{
// public:	
// 	// Function returns the second
// 	// largest elements
// 	int print2largest(int arr[], int n) {
// 	    if(n < 2){
// 	        return -1;
// 	    }
	    
// 	    int large = INT_MIN, second_large = INT_MIN;
// 	    for(int i = 0; i < n; i++){
// 	        if(arr[i] > large){
// 	            second_large = large;
// 	            large = arr[i];
// 	        }
// 	        else if(arr[i] > second_large && arr[i] != large){
// 	            second_large = arr[i];
// 	        }
//         }
       
        
//         if(second_large == INT_MIN){
//             return -1;
//         }
        
//         return second_large;
// 	}
// };