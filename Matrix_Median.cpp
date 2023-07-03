/* GFG  Submission    (Median in a row-wise sorted Matrix) */

/* Problem Statement: Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix. */


/* Solution 1: */
// Time Complexity: O(row*col) + O(row*col log(row*col))
// Space Complexity: O(row*col) 


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
// Time Complexity: O(log 2^32) * O(row*log col)   ~  O(32) * O(row*log col) 
// Space Complexity: O(1) 


// class Solution{   
// public:
//     int countSmallThanMid(vector<int> &row, int target){
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
//         int low = 1, high = 1e9;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             int cnt = 0;            // <=mid
//             for(int i = 0; i < R; i++){
//                 cnt += countSmallThanMid(matrix[i], mid);
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




