/* InterviewBit  Submission    (Nearest Smaller Element) */

/* Problem Statement: Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that 
the element has an index smaller than i.
More formally,
    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1. */



/* Solution: */
// Time Complexity: O(N) + O(N)
// Space Complexity: O(N)


// vector<int> Solution::prevSmaller(vector<int> &A) {
//     int n = A.size();
//     vector<int> ans(n, -1);
//     stack<int> st;
//     for(int i = 0; i < n; i++){
//         while(!st.empty() && st.top() >= A[i]){
//             st.pop();
//         }
//         if(!st.empty()){
//             ans[i] = st.top();
//         }
//         st.push(A[i]);
//     }
    
//     return ans;
// }




/* Codestudio  Submission    (Immediate Smaller Element) */

/* Problem Statement: You are given an integer array 'a' of size 'n'. For each element in the array, check whether the immediate 
right element of the array is smaller or not. If the next element is smaller, update the current index to that element. 
If not, then - 1. The last element does not have any elements on its right. */



/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// void immediateSmaller(vector<int>& a)
// {
// 	int n = a.size();
// 	for(int i = 0; i < n-1; i++){
// 		if(a[i] > a[i+1]){
// 			a[i] = a[i+1];
// 		}
// 		else{
// 			a[i] = -1;
// 		}

// 	}

// 	a[n-1] = -1;
// }
