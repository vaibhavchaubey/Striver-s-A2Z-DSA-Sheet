/* Codestudio  Submission    (Subset Sum) */

/* Problem Statement: You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of 
elements of 'A' that sums up to 'K'. Otherwise, return false.

For Example
'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
Subset [2, 3] has sum equal to 'K'.
So our answer is True. */


/* Solution: Using Recursion        (Can be done using DP)*/
// Time Complexity: O(2^N)
// Space Complexity: O(N)                 //  recursion stack


// bool helper(int ind, int n, int sum, int k, vector<int> &a){
//     if(sum == k){
//         return true;
//     }

//     if(sum > k || ind == n){
//         return false;
//     }


//     // element is picked
//     sum += a[ind];
//     if(helper(ind+1, n, sum, k, a)){
//         return true;
//     }

//     // element is not picked
//     sum -= a[ind];
//     if(helper(ind+1, n, sum, k, a)){
//         return true;
//     }

//     return false;
// }
// bool isSubsetPresent(int n, int k, vector<int> &a)
// {
//     return helper(0, n, 0, k, a);
// }