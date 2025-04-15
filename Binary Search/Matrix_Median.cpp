/* GFG  Submission    (Median in a row-wise sorted Matrix) */

/* Problem Statement: Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix. */

/* Solution 1: */
// Time Complexity: O(R * C) + O(R * C log(R * C))
// Space Complexity: O(R * C)

// class Solution{
// public:
//     int median(vector<vector<int>> &matrix, int R, int C){
//         vector<int> vec;

//         for(int i = 0; i < R; i++){
//             for(int j = 0; j < C; j++){
//                 vec.push_back(matrix[i][j]);
//             }
//         }

//         sort(vec.begin(), vec.end());

//         int idx = (R * C) / 2;

//         return vec[idx];
//     }
// };

/* Solution 2: Binary Search */
// Time Complexity: O(log 10^9 * R * logN)
/* Our search space lies between [0, 109] as the min(matrix) can be 0 and the max(matrix) can be 109. We are applying binary search in this search space and it takes O(log(109)) time complexity. Then we call countSmallEqual() function for every ‘mid’ and this function takes O(M(logN)) time complexity. */

// Space Complexity: O(1)

/* Range    [minEle ................... maxEle]   =>  using Binary search for this range */

// class Solution{
// public:
//     int countSmallEqualMid(vector<int> &row, int target){
//         int low = 0, high = row.size() - 1;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(row[mid] <= target){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }

//         return low;
//     }
//     int median(vector<vector<int>> &matrix, int R, int C){
//         int minEle = INT_MAX, maxEle = INT_MIN;
//         for(int i = 0; i < R; i++){
//             minEle = min(minEle, matrix[i][0]);
//             maxEle = max(maxEle, matrix[i][C-1]);
//         }

//         int low = minEle, high = maxEle;
//         while(low <= high){                                       // O(log 2^32)
//             int mid = low + (high - low) / 2;
//             int cnt = 0;                             // no. of elements <= mid
//             for(int i = 0; i < R; i++){                      // O(R * logC)
//                 cnt += countSmallEqualMid(matrix[i], mid);
//             }

//             if(cnt <= (R * C) / 2){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }

//         return low;
//     }
// };

/* OR */

/* We can also use upper_bound for finding countSmallEqualMid */

// class Solution{
// public:
//     int median(vector<vector<int>> &matrix, int R, int C){
//         int minEle = INT_MAX, maxEle = INT_MIN;
//         for(int i = 0; i < R; i++){
//             minEle = min(minEle, matrix[i][0]);
//             maxEle = max(maxEle, matrix[i][C-1]);
//         }

//         int low = minEle, high = maxEle;
//         while(low <= high){                                       // O(log 10^9)
//             int mid = low + (high - low) / 2;
//             int cnt = 0;                             // no. of elements <= mid
//             for(int i = 0; i < R; i++){                      // O(R * logC)
//                 cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
//             }

//             if(cnt <= (R * C) / 2){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }

//         return low;
//     }
// };

/* Codestudio  Submission    (Median in a row-wise sorted Matrix) */

/* Problem Statement: You are given a row-wise sorted matrix 'mat" of size m x n where 'm'and 'n' are the numbers of
rows and columns of the matrix, respectively. Your task is to find and return the median of the matrix.
Note: 'm' and 'n' will always be odd. */

/* Solution 1: */
// Time Complexity: O(row*col) + O(row*col log(row*col))
// Space Complexity: O(row*col)

// int median(vector<vector<int>> &matrix, int m, int n) {
//     vector<int> vec;

//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             vec.push_back(matrix[i][j]);
//         }
//     }

//     sort(vec.begin(), vec.end());

//     int idx = (m * n) / 2;

//     return vec[idx];
// }

/* Solution 2: Binary Search */
// Time Complexity: O(log 10^9 * R * logN)
/* Our search space lies between [0, 109] as the min(matrix) can be 0 and the max(matrix) can be 109. We are applying binary search in this search space and it takes O(log(109)) time complexity. Then we call countSmallEqual() function for every ‘mid’ and this function takes O(M(logN)) time complexity. */

// Space Complexity: O(1)

/* Range    [minEle ................... maxEle]   =>  using Binary search for this range */

// int countSmallEqualMid(vector<int> &row, int target){
//     int low = 0, high = row.size() - 1;
//     while(low <= high){
//         int mid = low + (high - low) / 2;
//         if(row[mid] <= target){
//             low = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }

//     return low;
// }
// int median(vector<vector<int>> &matrix, int m, int n) {
//     int minEle = INT_MAX, maxEle = INT_MIN;
//     for(int i = 0; i < m; i++){
//         minEle = min(minEle, matrix[i][0]);
//         maxEle = max(maxEle, matrix[i][n-1]);
//     }

//     int low = minEle, high = maxEle;
//     while(low <= high){                               // O(log 10^9)
//         int mid = low + (high - low) / 2;
//         int cnt = 0;                             // no. of elements <= mid
//         for(int i = 0; i < m; i++){                    // O(M * logN)
//             cnt += countSmallEqualMid(matrix[i], mid);
//         }

//         if(cnt <= (m * n) / 2){
//             low = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }

//     return low;
// }

/* OR */

/* We can also use upper_bound for finding countSmallEqualMid */

// int median(vector<vector<int>> &matrix, int m, int n) {
//     int minEle = INT_MAX, maxEle = INT_MIN;
//     for(int i = 0; i < m; i++){
//         minEle = min(minEle, matrix[i][0]);
//         maxEle = max(maxEle, matrix[i][n-1]);
//     }

//     int low = minEle, high = maxEle;
//     while(low <= high){                               // O(log 10^9)
//         int mid = low + (high - low) / 2;
//         int cnt = 0;                             // no. of elements <= mid
//         for(int i = 0; i < m; i++){                    // O(M * logN)
//             cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
//         }

//         if(cnt <= (m * n) / 2){
//             low = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }

//     return low;
// }