/* Problem Statement: Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting? */



/* Solution 1: Sorting */
// Time Complexity: O(N logN)  
// Space Complexity: O(1)     


// #include<bits/stdc++.h>
// using namespace std;

// int findKthLargest(vector<int>& nums, int k) {
//     sort(nums.begin(), nums.end(), greater<int>());
//     return nums[k-1];
// }

// int findKthSmallest(vector<int>& nums, int k) {
//     sort(nums.begin(), nums.end());
//     return nums[k-1];
// }

// int main()
// {
//     vector<int> nums = {3, 2, 1, 5, 6, 4};
//     int k = 2;


//     cout <<"kth Largest element: "<<findKthLargest(nums, k)<<endl;

//     cout <<"kth Largest element: "<<findKthSmallest(nums, k)<<endl;

    

//     return 0;
// }




/* Solution 2: Using MaxHeap (Priority Queue) */
// Time Complexity: O(N logK)  
/* Each of the n elements is processed once. However, heap operations take O(log⁡K) time, 
leading to an overall complexity of O(N logK)  . */
// Space Complexity: O(K)  



#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;           // minHeap
    for(int i = 0; i < nums.size(); i++){
        pq.push(nums[i]);
        
        if(pq.size() > k){
            pq.pop();
        }
    }

    return pq.top();
}

int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>> pq;                      // maxHeap
    for(int i = 0; i < nums.size(); i++){
        pq.push(nums[i]);
        
        if(pq.size() > k){
            pq.pop();
        }
    }
    
    return pq.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;


    cout <<"kth Largest element: "<<findKthLargest(nums, k)<<endl;

    cout <<"kth Largest element: "<<findKthSmallest(nums, k)<<endl;

    

    return 0;
}