/* Length of Smallest Subsequence such that sum of elements is greater than equal to K */

/* QUESTION
Given an array arr[] of size N and a number K, the task is to find the length of the smallest 
subsequence such that the sum of the subsequence is greater than or equal to number K. 
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int lengthOfSmallestSubsequence(vector<int> v, int k){
    priority_queue<int,vector<int>> pq;    //maxHeap
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    int sum = 0, count = 0;
    while (!pq.empty() && sum < k)
    {
        sum += pq.top();
        pq.pop();
        count++;
    }
    if(sum < k){
        return -1;
    }
    return count;    
}
int main()
{
    vector<int> v = {1,2,3,2,8};
    int k = 13;

    cout<<"Length of Smallest Subsequence: "<<lengthOfSmallestSubsequence(v,k)<<endl;


    return 0;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* 1) Find Kth Largest/Smallest Element in an Array */


//Kth Largest
/* Approach:
Implement Min Heap using a priority_queue.
Push first K array elements into the priority_queue.
From there on, after every insertion of an array element, pop the element at the top of the priority_queue.
After complete traversal of the array, print the element at the top of the priority queue as the required answer.
*/


// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std; 
// int KthLargestElement(vector<int> v, int k){                                //Time Complexity: O(NlogK)
//     priority_queue<int,vector<int>,greater<int>> pq;     //minHeap         //Space Complexity: O(K)
//     for (int i = 0; i < v.size(); i++)
//     {
//         pq.push(v[i]);

//         if(pq.size() > k){
//             pq.pop();
//         }
//     }
//     return pq.top();    
// }
// int main()
// {
//     vector<int> v = {20,10,60,30,50,40};
//     int k = 3;

//     cout<<"Kth largset element: "<<KthLargestElement(v,k)<<endl;


//     return 0;
// }



//Kth Smallest
/* Approach:
Implement Max Heap using a priority_queue.
Push first K array elements into the priority_queue.
From there on, after every insertion of an array element, pop the element at the top of the priority_queue.
After complete traversal of the array, print the element at the top of the priority queue as the required answer.
*/


// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;
// int KthSmallestElement(vector<int> v, int k){                               //Time Complexity: O(NlogK)
//     priority_queue<int,vector<int>> pq;        //maxHeap                      //Space Complexity: O(K)
//     for (int i = 0; i < v.size(); i++)
//     {
//         pq.push(v[i]);

//         if(pq.size() > k){
//             pq.pop();
//         }
//     }
//     return pq.top();    
// }
// int main()
// {
//     vector<int> v = {20,10,60,30,50,40};
//     int k = 3;

//     cout<<"Kth smallest element: "<<KthSmallestElement(v,k)<<endl;


//     return 0;
// }




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* 2) 378. Kth Smallest Element in a Sorted Matrix */

/* Leetcode  Submission    (378. Kth Smallest Element in a Sorted Matrix) */

/* Problem Statement: Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n^2). */



/* Solution 1: Brute Force (Using Priority Queue) */
// Time Complexity: O(N * N * logK)    =>   O(N^2 * logK) 
// Space Complexity: (K)


// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int N = matrix.size();
//         priority_queue<int> pq;
//         for(int r = 0; r < N; r++){
//             for(int c = 0; c < N; c++){
//                 pq.push(matrix[r][c]);
                
//                 if(pq.size() > k){
//                     pq.pop();
//                 }
//             }
//         }

//         return pq.top();
//     }
// };



/* Solution 2: Optimized Approach (Binary Search) */
// Time Complexity: O((N+N) * logD), where N <= 300 is the number of rows, N <= 300 is the number of columns, D <= 2*10^9 is the difference between the maximum element and the minimum element in the matrix.
// Space Complexity: (1)


// class Solution {
// public:
//     int countLessOrEqual(vector<vector<int>>& matrix, int x, int N){
//         // We start from top-right corner of matrix
//         int cnt = 0,  c = N-1;
//         for(int r = 0; r < N; r++){
//             while(c >= 0 && matrix[r][c] > x){
//                 c--;
//             }
//             cnt += (c + 1);
//         }

//         return cnt;
//     }
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int N = matrix.size();
//         int left = matrix[0][0], right = matrix[N-1][N-1];
//         int ans = -1;

//         while(left <= right){
//             int mid = (left + right) / 2;
//             if(countLessOrEqual(matrix, mid, N) >= k){
//                 ans = mid;
//                 right = mid-1;
//             }
//             else{
//                 left = mid+1;
//             }
//         }

//         return ans;
//     }
// };



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* 3) Connect N Ropes with minimum cost */

/* Problem Statement: There are given n ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost. */


/* Solution: Using priority queue */
// Time complexity : O(N * log N)       
// Space complexity : O(N)    


// #include<iostream>
// #include<vector>
// #include<queue>                                                  
// using namespace std;
// int minCost(vector<int> arr)
// {
//     int n = arr.size();
// 	priority_queue<int, vector<int>, greater<int>> pq;      // minHeap
//     for(int i = 0; i < n; i++){
//         pq.push(arr[i]);
//     }

//     int cost = 0;
//     while(pq.size() > 1){
//         // Here first and second are the smallest number in queue
//         int first = pq.top(); pq.pop();                         
//         int second = pq.top(); pq.pop();

//         int sum = first + second;
//         cost += sum;
//         pq.push(sum);
//     }

//     return cost;
// }
// int main()
// {
//     vector<int> arr = {2,5,4,8,6,9};

//     cout<<"Minimun Cost: "<<minCost(arr)<<endl;


//     return 0;
// }



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* 4) Furthest Building You Can Reach */

/* LeetCode Sumission   (1642. Furthest Building You Can Reach) */

/* Problem Statement: You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
While moving from building i to building i+1 (0-indexed),
    If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
    If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally. */



/* Solution: Using Priority Queue */
/* Approach :-
Heap is used store k height difference that we need to use ladders. Each move, if the height difference d > 0, 
we push d into the priority queue pq. If the size of queue exceed ladders, it means we have to use bricks for one move. 
Then we pop out the smallest difference, and reduce bricks. If bricks < 0, we can't make this move, then we return current index i. 
If we can reach the last building, we return heights.length() - 1. */

// Time Complexity: (N logK)  , where n is the number of buildings and k is the number of ladders available
// Space Complexity: (K)


// class Solution {
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         int n = heights.size();
//         // Inorder to get the minimum count of bricks required when all ladders are used
//         priority_queue<int, vector<int>, greater<int>> pq;      // minHeap;
        
//         for(int i = 0; i < n-1; i++){
//             int d = heights[i+1] - heights[i];
//             if(d > 0){
//                 pq.push(d);
//                 if(pq.size() > ladders){
//                     // Now we can't use ladders anymore (We need to use bricks and we will use bricks where d is minimum and pq.top() will give minimum d)
//                     bricks -= pq.top();
//                     pq.pop();
//                 }

//                 if(bricks < 0){
//                     return i;
//                 }
//             }
//         }

//         return n-1;
//     }
// };



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* 5) Find the Kth Largest Integer in the Array */

/* LeetCode Sumission   (1985. Find the Kth Largest Integer in the Array) */

/* Problem Statement: You are given an array of strings nums and an integer k. Each string in nums represents an 
integer without leading zeros.
Return the string that represents the kth largest integer in nums.
Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest 
integer, "2" is the second-largest integer, and "1" is the third-largest integer. */



/* Solution 1: Sorting */
// Time Complexity: O(N logN)  
// Space Complexity: O(1)  

/* Approach: 
This problem can be solved easily using inbuilt sort function with custom comparator.

Since, we know that numbers are stored in string format and length of thoes numbers is in range of [1, 100] which is larger than the range of int and long long int. So, we need to compare in form of strings itself for sorting.

Comparsion in string is done in lexicographical order (i.e similar to ordering in Dictionary) . For eg if a = "1000" and b = "20", then b > a lexicographically.

Therefore in order to compare any two numbers a, b in format of strings we need to follow these two step :
Step 1: Check length of both strings, if not equal than the string with larger size will be greater number, if equal than proceed to step (ii)
Step 2: Compare both the strings lexicographically. */

/* IMP
We will return true for what type of order we want to maintain. The order will be seen from bottom to top.

We will see the ordering from bottom to top. So, if i say that the order is ascending 
then it means that the smaller elements  will be at the bottom and the higher elements 
will be at the top. (I'm taking tree representation of the heap, if you consider array representation then the higher values will be at right and lower at the left)


Decreasing order from bottom   (array in decreasing order ex:- 3,2,1)   (minHeap)
return a.first > b.first

Increasing order from bottom   (array in increasing order ex:- 1,2,3)    (maxHeap)
return a.first < b.first
*/


// class Solution {
// public:
//     static bool comp(string& a, string& b) {
//         if (a.size() != b.size()){
//             return a.size() < b.size();
//         } 

//         // lexicographical comparision (when a.size() = b.size())
//         return a < b;
//     }
    
//     string kthLargestNumber(vector<string>& nums, int k) {
//         int n = nums.size();
//         // sorted in increasing order
//         sort(nums.begin(), nums.end(), comp);  

//         return nums[n-k];
//     }
// };



/* Solution 2: Using MinHeap (Priority Queue) */
// Time Complexity: O(N logK)  
/* Each of the n elements is processed once. However, heap operations take O(log⁡K) time, 
leading to an overall complexity of O(N logK). */
// Space Complexity: O(K)  

/* IMP
We will return true for what type of order we want to maintain. The order will be seen from bottom to top.

We will see the ordering from bottom to top. So, if i say that the order is ascending 
then it means that the smaller elements  will be at the bottom and the higher elements 
will be at the top. (I'm taking tree representation of the heap, if you consider array representation then the higher values will be at right and lower at the left)


Decreasing order from bottom   (array in decreasing order ex:- 3,2,1)   (minHeap)
return a.first > b.first

Increasing order from bottom   (array in increasing order ex:- 1,2,3)    (maxHeap)
return a.first < b.first
*/


// class Solution {
// public:
//     struct comparator{
//         bool operator()(string &a, string &b){
//             if(a.size() != b.size()){
//                 return a.size() > b.size();
//             }

//             return a > b;
            
//         }
//     };
//     string kthLargestNumber(vector<string>& nums, int k) {
//         priority_queue<string, vector<string>, comparator> pq;    // minHeap
//         for(auto i : nums){
//             pq.push(i);  
//             if(pq.size() > k){
//                 pq.pop();
//             }
//         }

//         return pq.top();
//     }
// };



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* Custom Camparator */


// #include <bits/stdc++.h>
// using namespace std;
// static bool comp(string &a, string &b)
// {
//     if (a.size() != b.size())
//     {
//         return a.size() < b.size();
//     }

//     // lexicographical comparision (when a.size() = b.size())
//     return a < b;
// }

// int main()
// {
//     vector<string> nums = {"3", "100", "7", "10"};

//     sort(nums.begin(), nums.end(), comp);

//     for (auto num : nums)
//     {
//         cout << num << " ";    // 3 7 10 100
//     }

//     return 0;
// }



