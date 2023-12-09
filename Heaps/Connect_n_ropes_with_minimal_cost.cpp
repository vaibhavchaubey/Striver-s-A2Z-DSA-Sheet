/* Codestudio  Submission    (Connect n ropes with minimum cost) */

/* Problem Statement: There are given n ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost. */



/* Solution: Using priority queue */
// Time complexity : O(N * log N)       
// Space complexity : O(N)           


// int minCost(int arr[], int n)
// {
// 	priority_queue<int, vector<int>, greater<int>> pq;      // minHeap
//     for(int i = 0; i < n; i++){
//         pq.push(arr[i]);
//     }

//     int cost = 0;
//     while(pq.size() > 1){
//         int first = pq.top(); pq.pop();
//         int second = pq.top(); pq.pop();

//         cost += first + second;
//         pq.push(first + second);
//     }

//     return cost;
// }
