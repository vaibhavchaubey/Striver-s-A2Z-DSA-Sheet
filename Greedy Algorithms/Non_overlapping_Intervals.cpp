/* Leetcode  Submission    (435. Non-overlapping Intervals) */

/* Problem Statement: Given an array of intervals intervals where intervals[i] = [starti, endi], return the 
minimum number of intervals you need to remove to make the rest of the intervals non-overlapping. */



/* Solution: 
Approach: we have to sort the intervals on the basis of their end points, then use a greedy approach to find the answer. */
//Time Complexity: O(NlogN) + O(N)
//Space Complexity: O(1)


// class Solution {
// public: 
//     // we have to sort the intervals on the basis of their end points, 
//     // then use a greedy approach to find the answer.
//     static bool comp(vector<int> &a, vector<int> &b){
//         return a[1] < b[1];
//     }
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         int count = 0;
//         sort(intervals.begin(), intervals.end(), comp);
//         int start = intervals[0][0], end = intervals[0][1];
//         for(int i = 1; i < n; i++){
//             if(intervals[i][0] >= end){
//                 start = intervals[i][0];
//                 end = intervals[i][1];
//             }
//             else{
//                 count++;
//             }
//         }

//         return count;
//     }
// };