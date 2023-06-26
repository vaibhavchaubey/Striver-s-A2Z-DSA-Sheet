/* Leetcode  Submission    (136. Single Number) */

/* Problem Statement: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space. */


/* Solution: XOR Approach */
// Time Complexity: O(N)
// Space Complexity: O(1) 


/* XOR Property */
// XOR of same number is 0   (2 ^ 2 = 0)
// XOR of any number with 0 is the number itself     (0 ^ 2 = 2)


// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int XOR = 0;
//         for(auto i : nums){
//             // Same number will cancel out and at last we get our single number
//             XOR ^= i;
//         }

//         return XOR;
//     }
// };



/* GFG  Submission    (Find the element that appears once) */

/* Problem Statement: Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice, 
except for one number which will occur only once. Find the number occurring only once. */


/* Solution:  Binary Search */
// Time Complexity: O(LogN)
// Space Complexity: O(1) 


// class Solution{
// public:	
// 	int search(int A[], int N){
// 	    int l = 0, r = N-1;
// 	    while(l < r){
// 	        int mid = l + (r - l) / 2;
// 	        // If mid is even
// 	        if(mid % 2 == 0){
// 	            if(A[mid] == A[mid+1]){
// 	                l = mid+2;
// 	            }
// 	            else{
// 	                r = mid;
// 	            }
// 	        }
// 	        // If mid is odd
// 	        else{
// 	            if(A[mid] == A[mid-1]){
// 	                l = mid+1;
// 	            }
// 	            else{
// 	                r = mid-1;
// 	            }
// 	        }
// 	    }
	    
// 	    return A[l];
// 	}
// };