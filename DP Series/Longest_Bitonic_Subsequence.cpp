/* Codestudio  Submission    (Longest Bitonic Sequence) */


/* Problem Statement: A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing. 
A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same for a strictly descending 
order sequence. For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] and 
[1, 2, 2, 3] are not. You are given an array 'arr' consisting of 'n'positive integers. Find the length of the longest bitonic 
subsequence of arr'. */



/* Solution: */
/* Tabulation algorithm */
// Time Complexity: O(N*N)       
// Space Complexity: O(N)


// int longestBitonicSubsequence(vector<int>& arr, int n)
// {
// 	vector<int> dp1(n, 1);				// LIS from 0 to i
// 	for(int i = 0; i < n; i++){
// 		for(int prev_index = 0; prev_index < i; prev_index++){
// 			if(arr[prev_index] < arr[i]  && 1 + dp1[prev_index] > dp1[i]){
// 				dp1[i] = 1 + dp1[prev_index];
// 			}
// 		}
// 	}
	
// 	vector<int> dp2(n, 1);				// LIS from n-1 to i
// 	for(int i = n-1; i >= 0; i--){
// 		for(int prev_index = n-1; prev_index > i; prev_index--){
// 			if(arr[prev_index] < arr[i]  && 1 + dp2[prev_index] > dp2[i]){
// 				dp2[i] = 1 + dp2[prev_index];
// 			}
// 		}
// 	}

// 	int ans = -1;
// 	for(int i = 0; i < n; i++){
// 		ans = max(ans, dp1[i]+dp2[i]-1);
// 	}

// 	return ans;
// }





/* GFG   Submission    (Longest Bitonic subsequence) */


/* Problem Statement: Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. */



/* Solution: */
/* Tabulation algorithm */
// Time Complexity: O(N*N)       
// Space Complexity: O(N)


// class Solution{
// 	public:
// 	int LongestBitonicSequence(vector<int>nums)
// 	{
// 	    int n = nums.size();
	    
	    
// 	    vector<int> dp1(n, 1);
// 	    for(int i = 0; i < n; i++){
// 	        for(int prev = 0; prev < i; prev++){
// 	            if(nums[prev] < nums[i] && 1 + dp1[prev] > dp1[i]){
// 	                dp1[i] = 1 + dp1[prev]; 
// 	            }
// 	        }
// 	    }
	    
// 	    vector<int> dp2(n, 1);
// 	    // reverse the direction of nested loops
// 	    for(int i = n-1; i >= 0; i--){
// 	        for(int prev = n-1; prev > i; prev--){
// 	            if(nums[prev] < nums[i] && 1 + dp2[prev] > dp2[i]){
// 	                dp2[i] = 1 + dp2[prev]; 
// 	            }
// 	        }
// 	    }
	    
// 	    int ans = -1;
// 	    for(int i = 0; i < n; i++){
// 	        ans = max(ans, dp1[i] + dp2[i] - 1);
// 	    }
	    
// 	    return ans;
// 	}
// };