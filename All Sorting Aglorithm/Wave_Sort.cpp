/* Given an unsorted array of integers, sort the array into a wave array. An array arr[0..n-1] is sorted in wave form if:
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= .... */


/* Follow the steps mentioned below to implement the idea:
Traverse all even positioned elements of the input array, and do the following. 
If the current element is smaller than the previous odd element, swap the previous and current. 
If the current element is smaller than the next odd element, swap next and current. */


// Time Complexity: O(N^2)
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;
void waveSort(int arr[], int n)
{
    // Traverse all even elements
    for (int i = 0; i < n; i += 2)
    {
        // If current even element is smaller than previous
        if (i > 0 && arr[i - 1] > arr[i])
            swap(arr[i], arr[i - 1]);

        // If current even element is smaller than next
        if (i < n - 1 && arr[i] < arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
}
int main()
{
    int arr[] = {1, 3, 4, 7, 5, 6, 2};
    waveSort(arr, 7);

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}