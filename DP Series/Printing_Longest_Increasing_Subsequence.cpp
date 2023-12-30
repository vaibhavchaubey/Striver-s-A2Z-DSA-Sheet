/* Problem Statement: Given an integer array nums, print the longest strictly increasing subsequence. */


/* Solution: */
/* Tabulation algorithm */
// Time Complexity: O(N*N) 
// Space Complexity: O(N)


#include<bits/stdc++.h>
using namespace std;
void longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);

    int ans = -1;
    int lastIndex = -1;
    for(int i = 0; i < n; i++){
        hash[i] = i;                // initializing with current index  
        for(int prev_index = 0; prev_index < i; prev_index++){
            if(nums[prev_index] < nums[i] && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
        if(dp[i] > ans){
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex){     // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }

    // reverse the array 
    reverse(temp.begin(), temp.end());

    for(auto it : temp){
        cout<<it<<" ";
    }
}
int main()
{
    vector<int> nums = {5, 4, 11, 1, 16, 8};

    longestIncreasingSubsequence(nums);


    
    return 0;
}



/* Codestudio Submission    (Printing Longest Increasing Subsequence) */


/* Problem Statement: Problem Statement You are given an array 'arr' of length 'n' Find the Longest Increasing Subsequence 
of the array. A subsequence is a subset of an array achieved by removing some (possibly 0) elements without changing the 
order of the remaining elements. Increasing subsequence means a subsequence in which all the elements are strictly increasing. 
Longest increasing subsequence is an increasing subsequence that has the largest length possible. Please note that there may be 
more than one LIS (Longest Increasing Subsequence) possible. Return any one of the valid sequences. */



/* Solution: */
/* Tabulation algorithm */
// Time Complexity: O(N*N) 
// Space Complexity: O(N)



// vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
// 	vector<int> dp(n, 1), hash(n);

// 	int ans = -1;
// 	int lastIndex = -1;
// 	for(int i = 0; i < n; i++){
// 		hash[i] = i;                            // initializing with current index  
// 		for(int prev_index = 0; prev_index < i; prev_index++){
// 			if(arr[prev_index] < arr[i] && 1 + dp[prev_index] > dp[i]){
// 				dp[i] = 1 + dp[prev_index];
// 				hash[i] = prev_index;
// 			}
// 		}
// 		if(dp[i] > ans){
// 			ans = dp[i];
// 			lastIndex = i;
// 		}
// 	}

// 	vector<int> temp;
// 	temp.push_back(arr[lastIndex]);
// 	while(hash[lastIndex] != lastIndex){                // till not reach the initialization value
// 		lastIndex = hash[lastIndex];
// 		temp.push_back(arr[lastIndex]);
// 	}

// 	reverse(temp.begin(), temp.end());

// 	return temp;
// }
