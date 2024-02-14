/* Leetcode  Submission    (56. Merge Intervals) */

/* Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input. */


/* Solution 1: Brute Force    (It will give TLE) */
// Time Complexity: O(NlogN) + O(2*N)
// Space Complexity: O(N) to return the answer of the merged intervals.


// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         vector<vector<int>> ans;
//         sort(intervals.begin(), intervals.end());

//         for(int i = 0; i < n; i++){
//             int start = intervals[i][0], end = intervals[i][1];
//             if(!ans.empty()){
//                 if(start <= ans.back()[1]){
//                     continue;
//                 }
//             }
//             for(int j = i+1; j < n; j++){
//                 if(intervals[j][0] <= end){
//                     end = max(end, intervals[j][1]);
//                 }
//             }
//             end = max(end, intervals[i][1]);
//             ans.push_back({start,end});
//         }
        
//         return ans;
//     }
// };


    
/* Solution 2: Optimal approach */
// Time Complexity: O(NlogN) + O(N)
// Space Complexity: O(N) to return the answer of the merged intervals.    


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
// };

// OR

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         sort(intervals.begin(), intervals.end());
//         vector<vector<int>> ans;
//         for(int i = 0; i < n; i++){
//             // new interval
//             if(ans.empty() || intervals[i][0] > ans.back()[1]){
//                 ans.push_back(intervals[i]);
//             }
//             // merging with existing interval
//             else{
//                 ans.back()[1] = max(ans.back()[1], intervals[i][1]);
//             }
//         }

//         return ans;
//     }
// };