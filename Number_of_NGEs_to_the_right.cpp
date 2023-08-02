/* Codestudio  Submission    (Count Of Greater Elements To The Right) */

/* Problem Statement: You are given an array 'arr'of length 'N'. You are given ''queries, and for each query, you are given 
an index(0-based indexing). Answer to each query is the number of the strictly greater elements to the right of the given 
index element. You must return an array 'answer' of length 'N', where 'answer[i]' is the answer to the 'ith' query. */



/* Solution: 

Time Complexity: O(N * Q) + O(Q)
Where ‘N’ is the array ‘arr’ length and ‘Q’ is the array ‘query’ length. 
Space Complexity: O(1) */


// vector<int> countGreater(vector<int>&arr, vector<int>&query) {
//     vector<int> ans;
//     for(int i = 0; i < query.size(); i++){
//         int idx = query[i];
//         int cnt = 0;
//         for(int j = idx+1; j < arr.size(); j++){
//             if(arr[j] > arr[idx]){
//                 cnt++;
//             }
//         }
//         ans.push_back(cnt);
//     }

//     return ans;
// }