/* QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element as a pivot and
partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.


How does QuickSort work?
The key process in quickSort is a partition(). The target of partitions is to place the pivot (any element can be chosen to be a pivot)
at its correct position in the sorted array and put all smaller elements to the left of the pivot, and all greater elements to the
right of the pivot.
Partition is done recursively on each side of the pivot after the pivot is placed in its correct position and this finally
sorts the array.


Choice of Pivot:
There are many different choices for picking pivots.
1) Always pick the first element as a pivot.
2) Always pick the last element as a pivot (implemented below)
3) Pick a random element as a pivot.
4) Pick the middle as the pivot.


Partition Algorithm:
The logic is simple, we start from the leftmost element and keep track of the index of smaller (or equal) elements as i.
While traversing, if we find a smaller element, we swap the current element with arr[i]. Otherwise, we ignore the current element.


As the partition process is done recursively, it keeps on putting the pivot in its actual position in the sorted array.
Repeatedly putting pivots in their actual position makes the array sorted. 


Complexity Analysis of Quick Sort:

Time Complexity:

Best Case: Ω (N log (N))
The best-case scenario for quicksort occur when the pivot chosen at the each step divides the array into roughly equal halves.
In this case, the algorithm will make balanced partitions, leading to efficient Sorting.

Average Case: θ ( N log (N))
Quicksort’s average-case performance is usually very good in practice, making it one of the fastest sorting Algorithm.

Worst Case: O(N2)
The worst-case Scenario for Quicksort occur when the pivot at each step consistently results in highly unbalanced partitions. 
When the array is already sorted and the pivot is always chosen as the smallest or largest element. To mitigate the worst-case 
Scenario, various techniques are used such as choosing a good pivot (e.g., median of three) and using Randomized algorithm 
(Randomized Quicksort ) to shuffle the element before sorting.


Auxiliary Space: O(1), if we don’t consider the recursive stack space. If we consider the recursive stack space then, 
in the worst case quicksort could make O(N). */


/* Quick Sort Complexity
Depends on pivot
1) In best case,pivot would be median element            O(N logN)
2) In worst case,pivot could be end element              O(N^2)                 */


// Time Complexity: Worst Case = O(N^2),  Best Case = O(N logN),  Average Case = O(N logN)
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];                 // any element of arr can be taken as pivot (Here we have taken last element)
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // here i will be denoting the last number which is less than pivot
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);

        // Separately sort elements before partition and after partition
        // smaller element than pivot goes left and higher element goes right
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Array after Sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}