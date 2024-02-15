/* Leetcode  Submission    (57. Insert Interval) */

/* Problem Statement: You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent 
the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval 
newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not 
have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion. */



/* Solution 1: Brute Force */
//Time Complexity: O(NlogN) + O(N)
//Space Complexity: O(N) to return the answer of the merged intervals.


// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         sort(intervals.begin(), intervals.end());
//         vector<vector<int>> ans;
//         int start = intervals[0][0], end = intervals[0][1];
//         for(int i = 1; i < n; i++){
//             // new interval
//             if(intervals[i][0] > end){
//                 ans.push_back({start, end});
//                 start = intervals[i][0];
//                 end = intervals[i][1];
//             }
//             // merging with existing interval
//             else{
//                 end = max(end, intervals[i][1]);
//             }
//         }
//         ans.push_back({start, end});

//         return ans;
//     }
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         intervals.push_back(newInterval);
//         vector<vector<int>> ans = merge(intervals);

//         return ans;
//     }
// };


    
/* Solution 2: Optimal approach */
// Time Complexity: O(N)
// Space Complexity: O(N) to return the answer of the merged intervals.  


// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int n = intervals.size();
//         vector<vector<int>> ans;

//         for(int i = 0; i < n; i++){
//             // if interval to be merged is less than interval in array
//             if(newInterval[1] < intervals[i][0]){
//                 ans.push_back(newInterval);
//                 for(; i < n; i++){
//                     ans.push_back(intervals[i]);
//                 }
//                 return ans;
//             }
//             // If current interval is before newInterval
//             else if(intervals[i][1] < newInterval[0]){
//                 ans.push_back(intervals[i]);
//             }
//             else{
//                 newInterval[0] = min(newInterval[0], intervals[i][0]);
//                 newInterval[1] = max(newInterval[1], intervals[i][1]);
//             }
//         }
//         ans.push_back(newInterval);

//         return ans;
//     }
// };



