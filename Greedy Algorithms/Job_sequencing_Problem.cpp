/* GFG  Submission    (Job Sequencing Problem) */

/* Problem Statement: Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit 
associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the 
job is the time before which job needs to be completed to earn the profit. */


/* Solution: */
// Time Complexity: O(N logN)    
/* O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every 
job we are checking from the last deadline, say M deadlines in the worst case. */              
// Space Complexity: O(M)


// class Solution 
// {
//     public:
//     static bool comp(Job a, Job b){
//         return a.profit > b.profit;
//     }
//     //Function to find the maximum profit and the number of jobs done.
//     vector<int> JobScheduling(Job arr[], int n) 
//     { 
//         //sort the jobs in descending order of profit
//         sort(arr, arr+n, comp);
        
//         int maxi = 0;
//         for(int i = 0; i < n; i++){
//             maxi = max(maxi, arr[i].dead);
//         }
        
// 	    //boolean array to keep track of free time slots.
// 	    bool slot[maxi]; 
	    
// 	    // initializing all slots to free.
//     	for (int i = 0; i < maxi; i++){
//     		slot[i] = false;
//         }
    
//         // vector<int> slot(maxi, 0);
//         int countJobs = 0, jobProfit = 0;
//     	for (int i = 0; i < n; i++) {
//     	    // finding a free slot for current job (Note that we start from the last possible slot). 
//     		for (int j = arr[i].dead-1; j >= 0; j--) {
//     			if (slot[j] == false) {
//     				slot[j] = true; 
//     				countJobs++;
//                     jobProfit += arr[i].profit;
//     				break;
//     			}
//     		}
//     	}
    	
//         return {countJobs, jobProfit};
//     } 
// };

