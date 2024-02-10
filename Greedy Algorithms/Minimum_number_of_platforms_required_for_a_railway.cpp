/* GFG  Submission    (Minimum Platforms) */

/* Problem Statement: Given arrival and departure times of all trains that reach a railway station. 
Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time 
can never be the same for a train but we can have arrival time of one train equal to departure time of the other. 
At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. 
In such cases, we need different platforms. */


/* Solution:  Using Recursion */
/* Approach: The idea is to consider all events in sorted order. Once the events are in sorted order, trace the number of trains 
at any time keeping track of trains that have arrived, but not departed. */
// Time Complexity: O(N logN)                  
// Space Complexity: O(1)


// class Solution{
//     public:
//     //Function to find the minimum number of platforms required at the
//     //railway station such that no train waits.
//     int findPlatform(int arr[], int dep[], int n)
//     {
//     	sort(arr, arr+n);
//     	sort(dep, dep+n);
    	
//     	int result = 1, platform = 1;
//     	int i = 1, j = 0;
//     	while(i < n && j < n){
//     	    if(arr[i] <= dep[j]){
//     	        platform++;
//     	        i++;
//     	    }
//     	    else if(arr[i] > dep[j]){
//     	        platform--;
//     	        j++;
//     	    }
//     	    if(platform > result){
//     	        result = platform;
//     	    }
//     	}
    	
//     	return result;
//     }
// };