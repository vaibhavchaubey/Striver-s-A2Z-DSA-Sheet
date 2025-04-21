/* GFG  Submission    (Minimize Max Distance to Gas Station) */

/* Problem Statement: We have an horizontal number line. On that number line, we have gas stations at positions
stations[0], stations[1], ..., stations[N-1], where N = size of the stations array. Now, we add K more gas stations so that D,
the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of D.
Find the answer exactly to 2 decimal places. */

/* Solution 1: Brute Force   (It will give TLE) */
// Time Complexity: O(K * N) + O(N)
// Space Complexity: O(N)

// class Solution {
//   public:
//     double findSmallestMaxDist(vector<int> &stations, int K){
//       int n = stations.size();
//       vector<int> howMany(n-1, 0);
//       for(int gasStations = 1; gasStations <= K; gasStations++){
//           double maxSection = -1;
//           int maxIdx = -1;
//           for(int i = 0; i < n-1; i++){
//               double diff = (stations[i+1] - stations[i]);
//               double sectionLength = diff / (double) (howMany[i] + 1);

//               if(sectionLength > maxSection){
//                   maxSection = sectionLength;
//                   maxIdx = i;
//               }
//           }
//           howMany[maxIdx]++;
//       }

//       double maxAns = -1;
//       for(int i = 0; i < n-1; i++){
//           double diff = (stations[i+1] - stations[i]);
//           double sectionLength = diff / (double) (howMany[i] + 1);
//           maxAns = max(maxAns, sectionLength);
//       }

//       return maxAns;
//     }
// };

/* Solution 2: Better Approach   (Using priority_queue for finding maxSextion in logN)      (It will give TLE)  */
// Time Complexity: O(N * logN) + O(K * logN)
// Space Complexity: O(N) + O(N)

// class Solution {
//   public:
//     double findSmallestMaxDist(vector<int> &stations, int K){
//       int n = stations.size();
//       priority_queue<pair<double, int>> pq;        // maxHeap     (sectionLength, index)
//       for(int i = 0; i < n-1; i++){
//           double diff = (stations[i+1] - stations[i]);
//           pq.push({diff, i});
//       }

//       vector<int> howMany(n-1, 0);
//       for(int gasStations = 1; gasStations <= K; gasStations++){
//            //Find the maximum section
//           //and insert the gas station:
//           auto topEle = pq.top();
//           pq.pop();
//           int maxIdx = topEle.second;

//           howMany[maxIdx]++;

//           double iniDiff = stations[maxIdx + 1] - stations[maxIdx];
//           double newSecLen = iniDiff / (double) (howMany[maxIdx] + 1);

//           pq.push({newSecLen, maxIdx});
//         }

//       return pq.top().first;
//     }
// };

/* Codestudio  Submission    (Minimize Max Distance to Gas Station) */

/* Problem Statement: You are given a sorted array 'arr' of length 'n', which contains positive integer positions of 'n'gas
stations on the X-axis. You are also given an integer 'K'. You have to place 'k' new gas stations on the X-axis.
You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' be the maximum
value of the distance between adjacent gas stations after adding 'k' new gas stations. Find the minimum value of dist. */

/* Solution 1: Brute Force   (It will give TLE) */
// Time Complexity: O(K * N) + O(N)
// Space Complexity: O(N)

// double minimiseMaxDistance(vector<int> &arr, int k){
// 	int n = arr.size();
//     vector<int> howMany(n-1, 0);
//     for(int gasStations = 1; gasStations <= k; gasStations++){
//         double maxSection = -1;
//         int maxIdx = -1;
//         for(int i = 0; i < n-1; i++){
//             double diff = (arr[i+1] - arr[i]);
//             double sectionLength = diff / (double) (howMany[i] + 1);

//             if(sectionLength > maxSection){
//                 maxSection = sectionLength;
//                 maxIdx = i;
//             }
//         }
//         howMany[maxIdx]++;
//     }

//     double maxAns = -1;
//     for(int i = 0; i < n-1; i++){
//         double diff = (arr[i+1] - arr[i]);
//         double sectionLength = diff / (double) (howMany[i] + 1);
//         maxAns = max(maxAns, sectionLength);
//     }

//     return maxAns;
// }

/* Solution 2: Better Approach   (Using priority_queue for finding maxSextion in logN) */
// Time Complexity: O(N * logN) + O(K * logN)
// Space Complexity: O(N) + O(N)

// #include<bits/stdc++.h>
// double minimiseMaxDistance(vector<int> &arr, int k){
// 	int n = arr.size();
//     priority_queue<pair<double, int>> pq;      // maxHeap   (sectionLength, index)
//     for(int i = 0; i < n-1; i++){
//         double diff = (arr[i+1] - arr[i]);
//         pq.push({diff, i});
//     }

//     vector<int> howMany(n-1, 0);
//     for(int gasStations = 1; gasStations <= k; gasStations++){
//         //Find the maximum section
//         //and insert the gas station:
//         auto topEle = pq.top();
//         pq.pop();
//         int maxIdx = topEle.second;

//         howMany[maxIdx]++;

//         double iniDiff = arr[maxIdx + 1] - arr[maxIdx];
//         double newSecLen = iniDiff / (double) (howMany[maxIdx] + 1);

//         pq.push({newSecLen, maxIdx});
//     }

//     return pq.top().first;
// }
