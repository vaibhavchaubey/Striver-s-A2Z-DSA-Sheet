/* GFG  Submission    (Find Nth root of M) */


/* Problem Statement: You are given 2 numbers (n , m); the task is to find n√m (nth root of m). */



/* Solution 1: Brute Force   */
// Time Complexity: O(M * logN)
// Space Complexity: O(1)


// class Solution{
// 	public:
// 	int NthRoot(int n, int m)
// 	{
// 	    for(int i = 1; i < m; i++){             // O(M)
// 	        if(pow(i, n) == m){                // O(logN)
// 	            return i;
// 	        }
// 	        else if(pow(i, n) > m){
// 	            break;
// 	        }
// 	    }
	    
// 	    return -1;
// 	}  
// };



/*  As M > N    so Time Complexity of  O(M * logN)  >  O(N * logM)   */


/* Solution 2: Optimal Approach   (Using Binary Search)   */
// Time Complexity: O(N * logM)
// Space Complexity: O(1)


// class Solution{
// 	public:
// 	// return 1 if ans == m
// 	// return 0 if ans < m
// 	// return 2 if ans > m
// 	int func(int mid, int n, int m){            // O(N)
// 	    long long ans = 1;
// 	    for(int i = 1; i <= n; i++){
// 	        ans = ans * mid;
// 	        if(ans > m) return 2;
// 	    }
	    
// 	    if(ans == m) return 1;
// 	    return 0;
// 	}
// 	int NthRoot(int n, int m)
// 	{
// 	    int low = 1, high = m;
//         while(low <= high){                              // O(logM)
//             int mid = low + (high - low) / 2;
//             int midN = func(mid, n, m);                 // mid^n (mid to the power n)
//             if(midN == 1){
//                 return mid;
//             }
//             else if(midN == 0){
//                 low = mid + 1;
//             }
            
//             else{                   // midN > m
//                 high = mid - 1;
//             }
//         }
	    
// 	    return -1;
// 	}  
// };



/* By using inbuilt power function Overflow case will be an issue. So we implement power function */

// class Solution{
// 	public:
// 	int NthRoot(int n, int m)
// 	{
// 	    int low = 1, high = m;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             int midN = pow(mid, n);                 // mid^n (mid to the power n)
//             if(midN == m){
//                 return mid;
//             }
//             else if(midN < m){
//                 low = mid + 1;
//             }
            
//             else{                   // midN > m
//                 high = mid - 1;
//             }
//         }
	    
// 	    return -1;
// 	}  
// };