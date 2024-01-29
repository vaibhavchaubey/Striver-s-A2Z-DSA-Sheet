/* Given an array containing only 0,1 and 2. You have to sort the array in O(N) time,
single pass, and O(1) space. */


// Time Complexity: O(N^2)
// Space Complexity: O(1)


#include<bits/stdc++.h>
using namespace std;
void dnfSort(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++; mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else                        //arr[mid] == 2
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main()
{
    int arr[] = {1,1,2,0,0,1,2,2,1,0};                   //For Array Size   int n = sizeof(arr)/sizeof(arr[0]);      
    dnfSort(arr,10);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}


/* Leetcode  Submission    (75. Sort Colors) */

/* Problem Statement: Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int low = 0; 
//         int mid = 0;
//         int high = n-1;
//         while(mid <= high){
//             if(nums[mid] == 0){
//                 swap(nums[low], nums[mid]);
//                 low++; mid++;
//             }
//             else if(nums[mid] == 1){
//                 mid++;
//             }
//             else{           // nums[mid] == 2
//                 swap(nums[mid], nums[high]);
//                 high--;
//             }
//         }
//     }
// };

