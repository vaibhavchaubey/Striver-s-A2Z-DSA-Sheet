/* Leetcode  Submission    (53. Maximum Subarray) */

/* Problem Statement: Given an integer array nums, find the subarray with the largest sum, and return its sum. */


/* Solution: Kadane's Algorithm */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int currentSum = 0;
//         int maxSum = INT_MIN;

//         for(int i = 0; i < n; i++){
//             currentSum += nums[i];
//             maxSum = max(maxSum, currentSum);
            
//             if(currentSum < 0){
//                 currentSum = 0;
//             }
//         }

//         return maxSum;
//     }
// };



/* Follow-up question 
There might be more than one subarray with the maximum sum. We need to print any of them. */

/* Intuition: Our approach is to store the starting index and the ending index of the subarray. 
Thus we can easily get the subarray afterward without actually storing the subarray elements.

If we carefully observe our algorithm, we can notice that the subarray always starts at the particular 
index where the sum variable is equal to 0, and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi). */


// #include <bits/stdc++.h>
// using namespace std;

// long long maxSubarraySum(int arr[], int n) {
//     long long maxi = LONG_MIN; // maximum sum
//     long long sum = 0;

//     int start = 0;
//     int ansStart = -1, ansEnd = -1;
//     for (int i = 0; i < n; i++) {

//         if (sum == 0) start = i; // starting index

//         sum += arr[i];

//         if (sum > maxi) {
//             maxi = sum;

//             ansStart = start;
//             ansEnd = i;
//         }

//         // If sum < 0: discard the sum calculated
//         if (sum < 0) {
//             sum = 0;
//         }
//     }

//     //printing the subarray:
//     cout << "The subarray is: [";
//     for (int i = ansStart; i <= ansEnd; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << "]n";

//     // To consider the sum of the empty subarray
//     // uncomment the following check:

//     //if (maxi < 0) maxi = 0;

//     return maxi;
// }

// int main()
// {
//     int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     long long maxSum = maxSubarraySum(arr, n);
//     cout << "The maximum subarray sum is: " << maxSum << endl;
//     return 0;
// }

