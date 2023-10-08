/* Codestudio  Submission    (Painter's Partition Problem) */


/* Problem Statement: Given an array/list of length 'n*, where the array/list represents the boards and each element of the given 
array/list represents the length of each board. Some "'numbers of painters are available to paint these boards. 
Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get 
this job done of painting all the 'n' boards under a constraint that any painter will only paint the continuous sections of boards. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N) * O(sumAll - maxEle)
// Space Complexity: O(1)

/* Range    [maxEle ................... sumAll]   =>  using Linear search for this range */


// bool isPossible(int maxLen, int k, int n, vector<int> &boards){
//     int reqPainters = 1;
//     long long sum = 0;
//     for(int i = 0; i < n; i++){
//         if(sum + boards[i] > maxLen){
//             reqPainters++;
//             sum = boards[i];
//         }
//         else{
//             sum += boards[i];
//         }
//     }

//     if(reqPainters <= k){
//         return true;
//     }

//     return false;
// }
// int findLargestMinDistance(vector<int> &boards, int k)
// {
//     int n = boards.size();
//     int maxEle = 0, sumAll = 0;
//     for(int i = 0; i < n; i++){
//         maxEle = max(maxEle, boards[i]);
//         sumAll += boards[i];
//     }

//     int low = maxEle, high = sumAll;
//     for(int i = low; i <= sumAll; i++){
//         // checking if by having a maxLen i can we paint all the boards
//         if(isPossible(i, k, n, boards)){
//             return i;
//         }
//     }

//     return -1;
// }




/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N) * O(log(sumAll - maxEle))
// Space Complexity: O(1)

/* Range    [maxEle ................... sumAll]   =>  using Binary search for this range */


// bool isPossible(int maxLen, int k, int n, vector<int> &boards){
//     int reqPainters = 1;
//     long long sum = 0;
//     for(int i = 0; i < n; i++){
//         if(sum + boards[i] > maxLen){
//             reqPainters++;
//             sum = boards[i];
//         }
//         else{
//             sum += boards[i];
//         }
//     }

//     if(reqPainters <= k){
//         return true;
//     }

//     return false;
// }
// int findLargestMinDistance(vector<int> &boards, int k)
// {
//     int n = boards.size();
//     int maxEle = 0, sumAll = 0;
//     for(int i = 0; i < n; i++){
//         maxEle = max(maxEle, boards[i]);
//         sumAll += boards[i];
//     }

//     int ans = -1;
//     int low = maxEle, high = sumAll;
//     while(low <= high){
//         int mid = low + (high - low) / 2;
//         // checking if by having a maxLen mid can we paint all the boards
//         if(isPossible(mid, k, n, boards)){
//             ans = mid;
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }

//     return ans;
// }