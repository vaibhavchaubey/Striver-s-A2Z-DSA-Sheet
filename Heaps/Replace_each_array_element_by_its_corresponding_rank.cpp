/* Leetcode  Submission    (1331. Rank Transform of an Array) */

/* Problem Statement: Given an array of integers arr, replace each element with its rank.
The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible. */



/* Solution 1: Naive approach  (Using two for loops and calculate a rank for each element) */
// Time complexity : O(N * N)
// Space complexity : O(N)  


// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> ans;
//         for (int i = 0; i < n; i++) {
//             unordered_set<int> s;
//             for (int j = 0; j < n; j++) {
//                 if (arr[j] < arr[i]) {
//                     s.insert(arr[j]);
//                 }
//             }
//             ans.push_back(s.size() + 1);
//         }

//         return ans;
//     }
// };



/* Solution 2: Optimized  (Sorting the array and store the rank of the element in a map) */
// Time complexity : O(N logN)          (Sorting)
// Space complexity : O(N) + O(N)       (map, temp)


// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> temp = arr;
//         sort(temp.begin(), temp.end());

//         unordered_map<int, int> mp;             // num, rank
//         int rank = 1;
//         for(int i = 0; i < n; i++){
//             // if element is previously not store in the map
//             if(mp[temp[i]] == 0){
//                 mp[temp[i]] = rank;
//                 rank++;
//             }
//         }

//         vector<int> ans;
//         for(int i = 0; i < n; i++){
//             ans.push_back(mp[arr[i]]);
//         }

//         return ans;
//     }
// };



/* Solution 3: Using Priority Queue (Min Heap) and Map  */
// Time complexity : O(N)    
// Space complexity : O(N) + O(N)             (minHeap, map)


// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         int n = arr.size();
//         priority_queue<int, vector<int>, greater<int>> pq;    // minHeap
//         for(int i = 0; i < n; i++){
//             pq.push(arr[i]);
//         }

//         unordered_map<int, int> mp;             // num, rank
//         int rank = 1;
//         while(!pq.empty()){
//             // if element is previously not store in the map
//             if(mp[pq.top()] == 0){
//                 mp[pq.top()] = rank;
//                 rank++;
//             }
//             pq.pop();
//         }

//         vector<int> ans;
//         for(int i = 0; i < n; i++){
//             ans.push_back(mp[arr[i]]);
//         }

//         return ans;
//     }
// };



/* Solution 4: Using Priority Queue (Min Heap)  */
// Time complexity : O(N)    
// Space complexity : O(N)             (minHeap)


// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> ans(n);
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    // minHeap
//         for(int i = 0; i < n; i++){
//             pq.push({arr[i], i});       // push {elements,i} in pq
//         }

//         int rank = 0;
//         int lastElement = INT_MIN;
//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             // if the elements are not equal
//             if(it.first != lastElement){
//                 rank++;
//                 lastElement = it.first;
//             }
//             ans[it.second] = rank;
//         }

//         return ans;
//     }
// };





/* Codestudio  Submission    (Replace Each Element Of Array With Its Corresponding Rank) */

/* Problem Statement: Given an array of integers 'ARR' of size 'N'. Replace each element of this array with its corresponding 
rank and return the array. The rank of an element is an integer between 1 to 'N' inclusive that represents how large the element 
is in comparison to other elements of the array. The following rules can also define the rank of an element: 
1. It is an integer starting from 1. 
2. The larger the element, the larger the rank. If two elements are equal, their rank must be the same. 
3. It should be as small as possible. */



/* Solution 1: Naive approach  (Using two for loops and calculate a rank for each element) */
// Time complexity : O(N * N)
// Space complexity : O(N)  


// vector<int> replaceWithRank(vector<int> &arr, int n) {
//     vector<int> ans;
//     for (int i = 0; i < n; i++) {
// 		unordered_set<int> s;
// 		for (int j = 0; j < n; j++) {
// 			if (arr[j] < arr[i]) {
// 				s.insert(arr[j]);
// 			}
// 		}
// 		ans.push_back(s.size() + 1);
// 	}

//     return ans;
// }




/* Solution 2: Optimized  (Sorting the array and store the rank of the element in a map) */
// Time complexity : O(N logN)          (Sorting)
// Space complexity : O(N) + O(N)       (map, temp)


// vector<int> replaceWithRank(vector<int> &arr, int n) {
//     vector<int> temp = arr;
//     sort(temp.begin(), temp.end());

//     unordered_map<int, int> mp;             // num, rank
//     int rank = 1;
//     for(int i = 0; i < n; i++){
//         // if element is previously not store in the map
//         if(mp[temp[i]] == 0){
//             mp[temp[i]] = rank;
//             rank++;
//         }
//     }

//     vector<int> ans;
//     for(int i = 0; i < n; i++){
//         ans.push_back(mp[arr[i]]);
//     }

//     return ans;
// }




/* Solution 3: Using Priority Queue (Min Heap) and Map  */
// Time complexity : O(N)    
// Space complexity : O(N) + O(N)             (minHeap, map)


// vector<int> replaceWithRank(vector<int> &arr, int n) {
//     priority_queue<int, vector<int>, greater<int>> pq;    // minHeap
//     for(int i = 0; i < n; i++){
//         pq.push(arr[i]);
//     }

//     unordered_map<int, int> mp;             // num, rank
//     int rank = 1;
//     while(!pq.empty()){
//         // if element is previously not store in the map
//         if(mp[pq.top()] == 0){
//             mp[pq.top()] = rank;
//             rank++;
//         }
//         pq.pop();
//     }

//     vector<int> ans;
//     for(int i = 0; i < n; i++){
//         ans.push_back(mp[arr[i]]);
//     }

//     return ans;
// }



/* Solution: 2 and Solution: 3 is not passing only 1 test case giving TLE */



/* Solution 4: Using Priority Queue (Min Heap)  */
// Time complexity : O(N)    
// Space complexity : O(N)             (minHeap)


// vector<int> replaceWithRank(vector<int> &arr, int n) {
//     vector<int> ans(n);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    // minHeap
//     for(int i = 0; i < n; i++){
//         pq.push({arr[i], i});       // push {elements,i} in pq
//     }

//     int rank = 0;
//     int lastElement = INT_MIN;
//     while(!pq.empty()){
//         auto it = pq.top();
//         pq.pop();
//         // if the elements are not equal
//         if(it.first != lastElement){
//             rank++;
//             lastElement = it.first;
//         }
//         ans[it.second] = rank;
//     }

//     return ans;
// }

