/* GFG  Submission    (Searching an element in a sorted array) */

/* Problem Statement: Given an array arr[] sorted in ascending order of size N and an integer K. 
Check if K is present in the array or not. */


/* Solution 1: Using Map  */
// Time Complexity: O((n+m)log(m+n))
// Space Complexity: O(n+m)  


// class Solution{
//     public:
//     //arr1,arr2 : the arrays
//     // n, m: size of arrays
//     //Function to return a list containing the union of the two arrays. 
//     vector<int> findUnion(int arr1[], int arr2[], int n, int m)
//     {
//         vector<int> ans;
//         map<int,int> mp;
//         for(int i = 0; i < n; i++){
//             mp[arr1[i]]++;
//         }
        
//         for(int i = 0; i < m; i++){
//             mp[arr2[i]]++;
//         }
        
//         for(auto it : mp){
//             ans.push_back(it.first);
//         }
        
//         return ans;
//     }
// };



/* Solution 2: Two Pointers */
// Time Complexity: O(m+n)
// Space Complexity: O(1)  


// class Solution{
//     public:
//     //arr1,arr2 : the arrays
//     // n, m: size of arrays
//     //Function to return a list containing the union of the two arrays. 
//     vector<int> findUnion(int arr1[], int arr2[], int n, int m)
//     {
//         vector<int> ans;
//         int i = 0, j = 0;
//         while(i < n && j < m){
//             if(arr1[i] <= arr2[j]){
//                 if(ans.size() == 0 || ans.back() != arr1[i]){
//                     ans.push_back(arr1[i]);   
//                 }
//                 i++;
//             }
//             else{
//                 if(ans.size() == 0 || ans.back() != arr2[j]){
//                     ans.push_back(arr2[j]);   
//                 }
//                 j++;
//             }
//         }
        
//         while(i < n){           // IF any element left in arr1
//             if(ans.size() == 0 || ans.back() != arr1[i]){
//                 ans.push_back(arr1[i]);   
//             }
//             i++;
//         }
        
//         while(j < m){           // If any elements left in arr2
//             if(ans.size() == 0 || ans.back() != arr2[j]){
//                 ans.push_back(arr2[j]);   
//             }
//             j++;
//         }
        
//         return ans;
//     }
// };