/* GFG  Submission    (Job Sequencing Problem) */

/* Problem Statement: Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit 
associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the 
job is the time before which job needs to be completed to earn the profit. */



/* Solution 1: */
// Time Complexity: O(N*N)            
// Space Complexity: O(M)


// class Solution {
//   public:
//     vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
//         int n = deadline.size();
//         vector<pair<int, int>> jobs;
        
//         for(int i = 0; i < n; i++){
//             jobs.push_back({profit[i], deadline[i]});
//         }
        
//         // sort the jobs based on profit in decreasing order
//         sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        
//         vector<bool> slots(n, false);
        
//         int jobsCount = 0, jobsProfit = 0;
//         for(int i = 0; i < n; i++){
//             int start = min(n, jobs[i].second) - 1;
//             for(int j = start; j >= 0; j--){
//                 if(slots[j] == false){
//                     slots[j] = true;
//                     jobsCount++;
//                     jobsProfit += jobs[i].first;
//                     break;
//                 }
//             }
//         }
        
//         return {jobsCount, jobsProfit};
//     }
// };




/* Solution 2: Using Sorting and MinHeap  
1) Store jobs as pairs of (Deadline, Profit).
2) Sort Jobs array in ascending order of deadline.
3) For each job in the sorted list:
4) If the job can be scheduled within its deadline, push its profit into the heap.
5) If the heap is full (equal to deadline), replace the existing lowest profit job with the current job if it has a higher profit.
6) This ensures that we always keep the most profitable jobs within the available slots.
7) Traverse through the heap and store the total profit and the count of jobs. */

// Time Complexity: O(N * longN)            
// Space Complexity: O(M)



// class Solution {
//   public:
//     vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
//         int n = deadline.size();
//         vector<pair<int, int>> jobs;
        
//         for(int i = 0; i < n; i++){
//             jobs.push_back({deadline[i], profit[i]});
//         }
        
//         // sort the jobs based on deadline in ascending order
//         sort(jobs.begin(), jobs.end());
        
//         priority_queue<int, vector<int>, greater<int>> pq;      // minHeap
        
//         for(int i = 0; i < n; i++){
//             // if job can be scheduled within its deadline
//             // here pq.size() --> time
//             if(jobs[i].first > pq.size()){
//                 pq.push(jobs[i].second);
//             }
//             // replace the job with the lowest profit
//             else if(!pq.empty() && pq.top() < jobs[i].second){
//                 pq.pop();
//                 pq.push(jobs[i].second);
//             }
//         }
        
//         int jobsCount = 0, jobsProfit = 0;
//         while(!pq.empty()){
//             jobsProfit += pq.top();
//             pq.pop();
//             jobsCount++;
//         }
        
//         return {jobsCount, jobsProfit};
//     }
// };