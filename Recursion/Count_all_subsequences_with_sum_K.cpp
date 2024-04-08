/* Codestudio  Submission    (Subarrays with Sum ‘k') */

/* Problem Statement: You are given an array 'A' of size 'N' and an integer'K'’. You need to generate and return all 
subarrays of array ‘A’ whose sum = ‘K’.
Note: In the output, you will see the 2D array lexicographically sorted.

Example:
Input: ‘N’ = 6 ‘K’ = 3
‘A’ = [1, 2, 3, 1, 1, 1]
Output: 3
Explanation: Subarrays whose sum = ‘3’ are:
[1, 2], [3], and [1, 1, 1] */


/* Solution 1: Generate all subarrays and check their sum. */
// Time Complexity: O(N*N)
// Space Complexity: O(N)


// #include<bits/stdc++.h>
// vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
//     int n = a.size();
//     vector<vector<int>> ans;

//    for(int i = 0; i < n; i++){
//        vector<int> arr;
//        long long sum = 0;
//        for(int j = i; j < n; j++){
//            sum += a[j];
//            arr.push_back(a[j]);

//            if(sum == k){
//                ans.push_back(arr);
//            }

//        }
//    }

//    return ans;
// }



/* Solution 2: Use two-pointers to find a subarray whose sum >= ‘k’. */
// Time Complexity: O(N)
// Space Complexity: O(N)


// #include<bits/stdc++.h>
// vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
//     int n = a.size();
//     vector<vector<int>> ans;
//     long long sum = 0;

//    int start = 0, end = -1;
//    while(start < n){
//         // Increasing the right end till our sum <= ‘k’ or we are not out of bounds
//        while((end + 1 < n) && (sum + a[end+1] <= k)){
//            sum += a[end+1];
//            end++;
//        }

//        if(sum == k){
//            vector<int> arr;
//            for(int i = start; i <= end; i++){
//                arr.push_back(a[i]);
//            }
//            ans.push_back(arr);
//        }

//        // Shifting the start index
//        sum -= a[start];
//        start++;
//    }

//    return ans;
// }



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* Find all Subsequences with sum equals to K */
// Time Complexity: Exponential  (O(2^n))


// #include<bits/stdc++.h>
// using namespace std;
// void subsequencesWithKSum(int ind, int arr[], vector<int>& vec, int n, int k, int sum){
//     if(ind == n){
//         if(sum == k){
//             for(auto it : vec){
//                 cout<<it<<" ";
//             }
//             cout<<endl;
//         }
//         return;
//     }
//     //pick the current index into the subsequence.
//     sum += arr[ind];    
//     vec.push_back(arr[ind]);
//     subsequencesWithKSum(ind+1, arr, vec, n, k, sum);

//     //not picking the element into the subsequence.
//     sum -= arr[ind];
//     vec.pop_back();
//     subsequencesWithKSum(ind+1, arr, vec, n, k, sum);
// }
// int main()
// {
//     int arr[]={1, 2, 1};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     vector<int> vec;
//     int k = 2;
//     subsequencesWithKSum(0, arr, vec, n, k, 0);
    

//     return 0;
// }




/* Find any one Subsequences with sum equals to K */
// Time Complexity: Exponential  (O(2^n))


// #include<bits/stdc++.h>
// using namespace std;
// bool subsequencesWithKSum(int ind, int arr[], vector<int>& vec, int n, int k, int sum){
//     if(ind == n){
//         if(sum == k){
//             for(auto it : vec){
//                 cout<<it<<" ";
//             }
//             cout<<endl;
//             return true;
//         }
//         else{
//             return false;
//         }
//     }

//     //pick the current index into the subsequence.
//     sum += arr[ind];    
//     vec.push_back(arr[ind]);
//     if(subsequencesWithKSum(ind+1, arr, vec, n, k, sum) == true){
//         return true;
//     }
    
//     //not picking the element into the subsequence.
//     sum -= arr[ind];
//     vec.pop_back();
//     if(subsequencesWithKSum(ind+1, arr, vec, n, k, sum) == true){
//         return true;
//     }

//     return false;
// }
// int main()
// {
//     int arr[]={1, 2, 1};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     vector<int> vec;
//     int k = 2;
//     subsequencesWithKSum(0, arr, vec, n, k, 0);


//     return 0;
// }




/* Find Number of Subsequences with sum equals to K */
// Time Complexity: Exponential  (O(2^n))


// #include<bits/stdc++.h>
// using namespace std;
// int numSubsequences(int ind, int arr[], int n, int k, int sum){
//     // strictly done if array contains positives only
//     if(sum > k){
//         return 0;
//     }
//     if(ind == n){
//         if(sum == k){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }

//     //pick the current index into the subsequence.
//     sum += arr[ind];    
//     int l = numSubsequences(ind+1, arr, n, k, sum);
    
//     //not picking the element into the subsequence.
//     sum -= arr[ind];
//     int r = numSubsequences(ind+1, arr, n, k, sum);

//     return l + r;
// }
// int main()
// {
//     int arr[]={1, 2, 1};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k = 2;

//     cout<<numSubsequences(0, arr, n, k, 0);



//     return 0;
// }




/* Important Leetcode Question */


/* Leetcode  Submission    (2099. Find Subsequence of Length K With the Largest Sum) */


/* Problem Statement: You are given an integer array nums and an integer k. You want to find a subsequence of nums 
of length k that has the largest sum.
Return any such subsequence as an integer array of length k.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing 
the order of the remaining elements. */


/* Solution 1: Using Hashmap */
// Time Complexity: O(N logN)
// Space Complexity: O(N)


// class Solution {
// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//         vector<int> ans;
//         vector<int> temp = nums;
//         sort(temp.begin(), temp.end(), greater<int>());
//         unordered_map<int, int> mp;
//         for(int i = 0; i < k; i++){
//             mp[temp[i]]++;
//         }

//         for(auto it : nums){
//             if(mp[it] > 0){
//                 ans.push_back(it);
//                 mp[it]--;
//             }
//         }

//         return ans;
//     }
// };



/* Solution 2: */
// Time Complexity: O(N * K)            // N for iterating and K for searching min element in K size array
// Space Complexity: O(1)


// class Solution {
// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//         vector<int> ans;
//         int i = 0;
//         for(i = 0; i < k; i++){
//             ans.push_back(nums[i]);
//         }

//         for(int j = i; j < nums.size(); j++){
//             // min element index
//             int minIndex = min_element(ans.begin(), ans.end()) - ans.begin();
//             if(ans[minIndex] < nums[j]){
//                 // remove min element and add nums[j] at last
//                 ans.erase(ans.begin() + minIndex);
//                 ans.push_back(nums[j]);
//             }
//         }

//         return ans;
//     }
// };