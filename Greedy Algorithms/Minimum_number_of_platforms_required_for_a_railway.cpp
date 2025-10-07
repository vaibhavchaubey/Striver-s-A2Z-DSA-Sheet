/* GFG  Submission    (Minimum Platforms) */

/* Problem Statement: Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900). */


/* Solution:  Using Recursion */
/* Approach: The idea is to consider all events in sorted order. Once the events are in sorted order, trace the number of trains 
at any time keeping track of trains that have arrived, but not departed. */
// Time Complexity: O(N logN)                  
// Space Complexity: O(1)


// class Solution {
//   public:
//     int minPlatform(vector<int>& arr, vector<int>& dep) {
//         int n = arr.size(); 
//         sort(arr.begin(), arr.end());
//         sort(dep.begin(), dep.end());
        
//         int i = 1, j = 0;
//         int result = 1, platform = 1;
//         while(i < n && j < n){
//             if(arr[i] <= dep[j]){
//                 platform++;
//                 i++;
//             }
//             else if(arr[i] > dep[j]){
//                 platform--;
//                 j++;
//             }
            
//             result = max(result, platform);
//         }
        
//         return result;
//     }
// };