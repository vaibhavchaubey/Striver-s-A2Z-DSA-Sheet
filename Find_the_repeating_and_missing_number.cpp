/* GFG  Submission    (Find Missing And Repeating) */

/* Problem Statement: Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} 
is missing and one number 'B' occurs twice in array. Find these two numbers. */



/* Solution 1: Brute Force   */
// Time Complexity: O(N*N)
// Space Complexity: O(1)


// class Solution{
// public:
//     vector<int> findTwoElement(vector<int> arr, int n) {
//         int repeating = -1, missing = -1;
//         for(int i = 1; i <= n; i++){
//             int cnt = 0;
//             for(int j = 0; j < n; j++){
//                 if(arr[j] == i){
//                     cnt++;
//                 }
//             }
//             if(cnt == 2){
//                 repeating = i;
//             }
//             else if(cnt == 0){
//                 missing = i;
//             }
            
//             if(repeating != -1 && missing != -1){
//                 break;
//             }
//         }
        
//         return {repeating, missing};
//     }
// };


    
/* Solution 2: Better Approach (using freq array to count)  */
// Time complexity: O(N) + O(N)
// Space Complexity: O(N) 


// class Solution{
// public:
//     vector<int> findTwoElement(vector<int> arr, int n) {
//         int repeating = -1, missing = -1;
//         vector<int> freq(n+1, 0);
//         for(int i = 0; i < n; i++){
//             freq[arr[i]]++;
//         }

//         for(int i = 1; i <= n; i++){
//             if(freq[i] == 2){
//                 repeating = i;
//             }
//             else if(freq[i] == 0){
//                 missing = i;
//             }
            
//             if(repeating != -1 && missing != -1){
//                 break;
//             }
//         }
        
//         return {repeating, missing};
//     }
// };



/* Solution 3: Optimal Approach 1 (Using Maths)  */
// Time complexity: O(N)
// Space Complexity: O(1) 


// class Solution{
// public:
//     vector<int> findTwoElement(vector<int> arr, int n) {
//         // we have to define N as long long to avoid overflow whereas n is already given
//         long long N = arr.size();   
//         // S - SN = x - y
//         // S2 - S2N
//         long long SN = (N * (N+1)) / 2;
//         long long S2N = (N * (N+1) * (2*N+1)) / 6;
//         long long S = 0, S2 = 0;
//         for(int i = 0; i < N; i++){
//             S += (long long)arr[i];
//             S2 += (long long)arr[i] * (long long)arr[i];
//         }
        
//         // S-Sn = X-Y:
//         long long val1 = S - SN;             // x - y
        
//         // S2-S2n = X^2-Y^2:
//         long long val2 = S2 - S2N;
        
//         // Find X+Y = (X^2-Y^2)/(X-Y):
//         val2 = val2 / val1;                 // x + y
        
//         // Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
//         // Here, X-Y = val1 and X+Y = val2:
//         long long x = (val1 + val2) / 2;
//         long long y = x - val1;
        
//         return {(int)x, (int)y};        // x = repeating, y = missing
//     }
// };


